#include "bsec.h"
#include <WiFi.h>
#include <ESPAsyncWebSrv.h>

const char* ssid = "OSRNET";
const char* password = "osr2023";
float iaq;
float temperature;
float co2;
float pressure;
float humidity;

AsyncWebServer server(80);
AsyncEventSource events("/events");

// Helper functions declarations
void checkIaqSensorStatus(void);
void errLeds(void);

// Create an object of the class Bsec
Bsec iaqSensor;

String output;

String processor(const String& var){
      //Serial.println(var);
      if(var == "iaq"){
        return String(iaq);    
      }else if(var == "temperature"){
        return String(temperature);    
      }else if(var == "pressure"){
        return String(pressure);    
      }else if(var == "humidity"){
        return String(humidity);    
      }else if(var == "co2"){
        return String(co2);    
      }
}


////////////////////////////////////////////////
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>BME680 sensor  / web server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <link rel="icon" href="data:,">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    p {  font-size: 1.2rem;}
    body {  margin: 0;}
    .topnav { overflow: hidden; background-color: #007700; color: white; font-size: 1.7rem; }
    .content { padding: 20px; }
    .card { background-color: white; box-shadow: 2px 2px 12px 1px rgba(140,140,140,.5); }
    .cards { max-width: 700px; margin: 0 auto; display: grid; grid-gap: 2rem; grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); }
    .reading { font-size: 2.8rem; }
    .card.temperature { color: #0e7c7b; }
  </style>
</head>
<body>
  <div class="topnav">
    <h3>BME680 sensor  / web server</h3>
  </div>
  <div class="content">
    <div class="cards">


    <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> IAQ</h4><p><span class="reading"><span id="iaq_">%iaq%</span> </span></p>
      </div>

    <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> TEMPERATURE</h4><p><span class="reading"><span id="temperature_">%temperature%</span> C</span></p>
      </div>

   <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> PRESSURE</h4><p><span class="reading"><span id="pressure_">%pressure%</span> Pa</span></p>
      </div>

     <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> HUMIDITY</h4><p><span class="reading"><span id="humidity_">%humidity%</span> &#37; </span></p>
      </div>
 
 
  <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> CO2</h4><p><span class="reading"><span id="co2_">%co2%</span> ppm</span></p>
      </div>


    </div>
  </div>

<script>
if (!!window.EventSource) {
 var source = new EventSource('/events');
 
 source.addEventListener('open', function(e) {
  console.log("Events Connected");
 }, false);
 source.addEventListener('error', function(e) {
  if (e.target.readyState != EventSource.OPEN) {
    console.log("Events Disconnected");
  }
 }, false);
 
 source.addEventListener('message', function(e) {
  console.log("message", e.data);
 }, false);
 
 source.addEventListener('temperature_Celsius', function(e) {
  console.log("temperature", e.data);
  document.getElementById("temp_celcius").innerHTML = e.data;
 }, false);
 
 source.addEventListener('temperature_Fahrenheit', function(e) {
  console.log("temperature", e.data);
  document.getElementById("temp_fahrenheit").innerHTML = e.data;
 }, false);

  source.addEventListener('temperature', function(e) {
  console.log("temperature", e.data);
  document.getElementById("temperature_").innerHTML = e.data;
 }, false);

 // Add the following lines to reload the page every 20 seconds
 setInterval(function(){
    location.reload();
 }, 1000);
}
</script>


</body>
</html>)rawliteral";

////////////////////////////////////////////////

// Entry point for the example
void setup(void)
{
  /* Initializes the Serial communication */
  Serial.begin(115200);
  delay(1000);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  // WiFi.softAP(ssid, password);
  WiFi.softAP(ssid);

  IPAddress IP = WiFi.softAPIP();

  Serial.println();
  Serial.println("--------------------------");
  Serial.print("Access Point SSID: ");
  Serial.print(ssid);
  Serial.print(" --- IP address: ");
  Serial.println(IP);
  Serial.println("--------------------------");



    // Handle Web Server
    // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    //   request->send_P(200, "text/html", index_html, processor);
    // });

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", index_html, processor);
    });
    // Handle Web Server Events
    events.onConnect([](AsyncEventSourceClient *client){
      if(client->lastId()){
        Serial.printf("Client reconnected! Last message ID that it got is: %u\n", client->lastId());
      }
      // send event with message "hello!", id current millis
      // and set reconnect delay to 1 second
      client->send("hello!", NULL, millis(), 10000);
    });
    server.addHandler(&events);
    server.begin();

  pinMode(LED_BUILTIN, OUTPUT);
  // iaqSensor.begin(BME68X_I2C_ADDR_LOW, Wire);
  iaqSensor.begin(BME68X_I2C_ADDR_HIGH, Wire);
  output = "\nBSEC library version " + String(iaqSensor.version.major) + "." + String(iaqSensor.version.minor) + "." + String(iaqSensor.version.major_bugfix) + "." + String(iaqSensor.version.minor_bugfix);
  Serial.println(output);
  checkIaqSensorStatus();

  bsec_virtual_sensor_t sensorList[13] = {
    BSEC_OUTPUT_IAQ,
    BSEC_OUTPUT_STATIC_IAQ,
    BSEC_OUTPUT_CO2_EQUIVALENT,
    BSEC_OUTPUT_BREATH_VOC_EQUIVALENT,
    BSEC_OUTPUT_RAW_TEMPERATURE,
    BSEC_OUTPUT_RAW_PRESSURE,
    BSEC_OUTPUT_RAW_HUMIDITY,
    BSEC_OUTPUT_RAW_GAS,
    BSEC_OUTPUT_STABILIZATION_STATUS,
    BSEC_OUTPUT_RUN_IN_STATUS,
    BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE,
    BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY,
    BSEC_OUTPUT_GAS_PERCENTAGE
  };

  iaqSensor.updateSubscription(sensorList, 13, BSEC_SAMPLE_RATE_LP);
  checkIaqSensorStatus();

  // Print the header
  output = "Timestamp [ms], IAQ, IAQ accuracy, Static IAQ, CO2 equivalent, breath VOC equivalent, raw temp[°C], pressure [hPa], raw relative humidity [%], gas [Ohm], Stab Status, run in status, comp temp[°C], comp humidity [%], gas percentage";
  Serial.println(output);
}

// Function that is looped forever
void loop(void)
{
  unsigned long time_trigger = millis();
  if (iaqSensor.run()) { // If new data is available
    digitalWrite(LED_BUILTIN, LOW);
    output = String(time_trigger);
    output += ", " + String(iaqSensor.iaq);
    iaq = iaqSensor.iaq;
    events.send(String(iaqSensor.iaq).c_str(),"iaq",millis());
    output += ", " + String(iaqSensor.iaqAccuracy);
    output += ", " + String(iaqSensor.staticIaq);
    output += ", " + String(iaqSensor.co2Equivalent);
    co2 = iaqSensor.co2Equivalent;
    events.send(String(iaqSensor.co2Equivalent).c_str(),"co2",millis());

    output += ", " + String(iaqSensor.breathVocEquivalent);
    output += ", " + String(iaqSensor.rawTemperature);
    temperature = iaqSensor.rawTemperature;
    events.send(String(iaqSensor.rawTemperature).c_str(),"temperature",millis());

    output += ", " + String(iaqSensor.pressure);
    pressure = iaqSensor.pressure;
    events.send(String(iaqSensor.pressure).c_str(),"pressure",millis());

    output += ", " + String(iaqSensor.rawHumidity);
    humidity = iaqSensor.rawHumidity;
    events.send(String(iaqSensor.rawHumidity).c_str(),"humidity",millis());

    output += ", " + String(iaqSensor.gasResistance);
    output += ", " + String(iaqSensor.stabStatus);
    output += ", " + String(iaqSensor.runInStatus);
    output += ", " + String(iaqSensor.temperature);
    output += ", " + String(iaqSensor.humidity);
    output += ", " + String(iaqSensor.gasPercentage);
    Serial.println(output);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    checkIaqSensorStatus();
  }

      // Send Events to the Web Server with the Sensor Readings
    // events.send(String(iaqSensor.iaq).c_str(),"iaq",millis());

}

// Helper function definitions
void checkIaqSensorStatus(void)
{
  if (iaqSensor.bsecStatus != BSEC_OK) {
    if (iaqSensor.bsecStatus < BSEC_OK) {
      output = "BSEC error code : " + String(iaqSensor.bsecStatus);
      Serial.println(output);
      for (;;)
        errLeds(); /* Halt in case of failure */
    } else {
      output = "BSEC warning code : " + String(iaqSensor.bsecStatus);
      Serial.println(output);
    }
  }

  if (iaqSensor.bme68xStatus != BME68X_OK) {
    if (iaqSensor.bme68xStatus < BME68X_OK) {
      output = "BME68X error code : " + String(iaqSensor.bme68xStatus);
      Serial.println(output);
      for (;;)
        errLeds(); /* Halt in case of failure */
    } else {
      output = "BME68X warning code : " + String(iaqSensor.bme68xStatus);
      Serial.println(output);
    }
  }
}

void errLeds(void)
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include <WiFi.h>
#include "ESPAsyncWebServer.h"

#define SEALEVELPRESSURE_HPA (1013.25) /* check your local Sea LEvel Pressure Hpa */

Adafruit_BME680 bme; // I2C


// Replace with your network credentials
const char* ssid = "OSRNET_10";
const char* password = "osr2023";


float temperature;
float pressure;
float humidity;
float gas;
float altitude;
// float sea_level_coeff = 1013.25;

unsigned long lastTime = 0;  
unsigned long timerDelay = 5000;  // send readings timer

AsyncWebServer server(80);
AsyncEventSource events("/events");

////////////////////////////////////////////////
void getBME680Readings(){
 
  // begin BME680 measurement.
  unsigned long endTime = bme.beginReading();
  if (endTime == 0) {
    Serial.println(F("Failed to begin reading :("));
    return;
  }

   if (!bme.endReading()) {
    Serial.println(F("Failed to complete reading :("));
    return;
  }


 ///////
    temperature = bme.temperature;
    Serial.print(F("Temperature = "));
    Serial.print(temperature);
    Serial.println(" *C");
    
    pressure = bme.pressure / 100.0;
    Serial.print(F("Pressure = "));
    Serial.print(pressure);
    Serial.println(" hPa");

    humidity = bme.humidity;
    Serial.print(F("Humididty = "));
    Serial.print(humidity);
    Serial.println(" %");

    gas = bme.gas_resistance / 1000.0;
    Serial.print(F("Gas esistance = "));
    Serial.print(gas);
    Serial.println(" KOhms");   

    altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
    Serial.print(F("Approx altitude = "));
    Serial.print(altitude); /* Adjusted (in hPa) to local forecast! */
    Serial.println(" m");

    Serial.println();

}

////////////////////////////////////////////////
String processor(const String& var){
  getBME680Readings();
  //Serial.println(var);
  if(var == "temperature"){
    return String(temperature);
  }
  else if(var == "pressure"){
    return String(pressure);
  }
   else if(var == "altitude"){
    return String(altitude);
  }
   else if(var == "humidity"){
    return String(humidity);
  }
   else if(var == "gas"){
    return String(gas);
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
        <h4><i class="fas fa-thermometer-half"></i> TEMPERATURE</h4><p><span class="reading"><span id="temperature_">%temperature%</span> &deg;C</span></p>
      </div>

   <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> PRESSURE</h4><p><span class="reading"><span id="pressure_">%pressure%</span> hPa</span></p>
      </div>

     <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> HUMIDITY</h4><p><span class="reading"><span id="huidity_">%humidity%</span> &#37; </span></p>
      </div>
 
     <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> ALTITUDE</h4><p><span class="reading"><span id="altitude_">%altitude%</span> mt</span></p>
      </div>
 
  <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> GAS</h4><p><span class="reading"><span id="gas_">%gas%</span> KOhm</span></p>
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


 
}
</script>
</body>
</html>)rawliteral";

////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  while ( !Serial ) delay(100);   // wait for native usb


/*

    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Setting as a Wi-Fi Station..");
    }
    Serial.print("Station IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.println();
*/

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




    if (!bme.begin()) {
      Serial.println(F("Could not find a valid BME680 sensor, check wiring!"));
      while (1);
    }

    // Set up oversampling and filter initialization
    bme.setTemperatureOversampling(BME680_OS_8X);
    bme.setHumidityOversampling(BME680_OS_2X);
    bme.setPressureOversampling(BME680_OS_4X);
    bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
    bme.setGasHeater(320, 150); // 320*C for 150 ms

}





////////////////////////////////////////////////
void loop() {
 if ((millis() - lastTime) > timerDelay) {
   
    getBME680Readings(); // read data from sensor

    // Send Events to the Web Server with the Sensor Readings
    events.send("ping",NULL,millis());
    events.send(String(temperature).c_str(),"temperature_",millis());
    events.send(String(pressure).c_str(),"pressure_",millis()); 
    events.send(String(humidity).c_str(),"humidity",millis()); 
    events.send(String(altitude).c_str(),"altitude_",millis()); 
    events.send(String(gas).c_str(),"gas_",millis()); 

   lastTime = millis();
  }
}




#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <WiFi.h>
#include "ESPAsyncWebServer.h"


#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)



Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);


// Replace with your network credentials
// const char* ssid = "Xenolalia";
// const char* password = "EuglenaNeuron";
const char* ssid = "YOUR_NETWORK_ID"; 
const char* password = "YOUR_PASSWORD";



float temperature;
float pressure;
float altitude;
float sea_level_coeff = 1013.25;

unsigned long lastTime = 0;  
unsigned long timerDelay = 5000;  // send readings timer

AsyncWebServer server(80);
AsyncEventSource events("/events");

////////////////////////////////////////////////
void getBMP280Readings(){
 
    temperature = bmp.readTemperature();
    Serial.print(F("Temperature = "));
    Serial.print(temperature);
    Serial.println(" *C");
    
    pressure = bmp.readPressure();
    Serial.print(F("Pressure = "));
    Serial.print(pressure);
    Serial.println(" Pa");

    altitude = bmp.readAltitude(sea_level_coeff);
    Serial.print(F("Approx altitude = "));
    Serial.print(altitude); /* Adjusted (in hPa) to local forecast! */
    Serial.println(" m");

    Serial.println();

}

////////////////////////////////////////////////
String processor(const String& var){
  getBMP280Readings();
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
}

////////////////////////////////////////////////
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>BMP280 Web Server</title>
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
    <h3>BME280 WEB SERVER</h3>
  </div>
  <div class="content">
    <div class="cards">

    <!--
      <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> TEMPERATURE</h4><p><span class="reading"><span id="temp_celcius">%TEMPERATURE_C%</span> &deg;C</span></p>
      </div>
      <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> TEMPERATURE</h4><p><span class="reading"><span id="temp_fahrenheit">%TEMPERATURE_F%</span> &deg;F</span></p>
      </div>
      -->


    <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> BME280 TEMPERATURE</h4><p><span class="reading"><span id="temperature_">%temperature%</span> &deg;C</span></p>
      </div>

     <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> BME280 PRESSURE</h4><p><span class="reading"><span id="pressure_">%pressure%</span> Pa</span></p>
      </div>

     <div class="card temperature">
        <h4><i class="fas fa-thermometer-half"></i> BME280 ALTITUDE</h4><p><span class="reading"><span id="altitude_">%altitude%</span> mt</span></p>
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

  Serial.println(F("BMP280 test"));
  unsigned status;
  //status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
  status = bmp.begin(0x76);
  if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);

  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}



////////////////////////////////////////////////
void loop() {
 if ((millis() - lastTime) > timerDelay) {
   
    getBMP280Readings(); // read data from sensor

    // Send Events to the Web Server with the Sensor Readings
    events.send("ping",NULL,millis());
    events.send(String(temperature).c_str(),"temperature_",millis());
    events.send(String(pressure).c_str(),"pressure_",millis()); 
    events.send(String(altitude).c_str(),"altitude_",millis()); 

   lastTime = millis();
  }
}




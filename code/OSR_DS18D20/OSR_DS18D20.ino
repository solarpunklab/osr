#include <ThingSpeak.h>
#include <SPI.h>
#include <WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 4

char ssid[] = "xxxxxxxx"; // your network SSID (name)
char pass[] = "yyyyyyyy"; // your network password
int keyIndex = 0;          // your network key Index number (needed only for WEP)
WiFiClient client;
unsigned long myChannelNumber = 1;
const char *myWriteAPIKey = "xyxyxyxyxyxy";

OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup()
{
  Serial.begin(115200); //Initialize serial
  sensors.begin();
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client); // Initialize ThingSpeak
}

void loop()
{
 // Connect or reconnect to WiFi
 if (WiFi.status() != WL_CONNECTED)
 {
   Serial.print("Attempting to connect to SSID: ");
   Serial.println(ssid);
   while (WiFi.status() != WL_CONNECTED)
   {
     WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
     Serial.print(".");
     delay(3000);
   }
   Serial.println("\nConnected.");
 }

 Serial.print("Requesting temperature:  ");
 sensors.requestTemperatures(); // Send the command to get temperatures
//  int x = ThingSpeak.writeField(myChannelNumber, 1, sensors.getTempCByIndex(0), myWriteAPIKey);


  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");

   int x = ThingSpeak.writeField(myChannelNumber, 1, temperatureC, myWriteAPIKey);

  Serial.println(temperatureC);

 delay(2000); // Wait 2 seconds to update the channel again
}

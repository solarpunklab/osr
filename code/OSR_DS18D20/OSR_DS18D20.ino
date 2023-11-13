#include <SPI.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature.

//////////////////////////////////////////
void setup()
{
  Serial.begin(115200); //Initialize serial
  sensors.begin();
}

//////////////////////////////////////////
void loop()
{
 Serial.println("Requesting temperature:  ");
 sensors.requestTemperatures(); // Send the command to get temperatures

  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);

  Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");

  delay(2000); // Wait 2 seconds to update the channel again
}

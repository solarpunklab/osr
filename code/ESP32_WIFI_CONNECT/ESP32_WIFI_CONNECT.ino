#include <WiFi.h>
 
// Replace with your own network credentials
const char* ssid = "YOUR_NETWORK_NAME";
const char* password = "YOUR_PASSWORD";

//////////////////////////////  
void setup(){
 
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting to WiFi Network ..");
 
    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(250);
    }
 
    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());
}

////////////////////////////// 
void loop(){
    // Do Nothing
}
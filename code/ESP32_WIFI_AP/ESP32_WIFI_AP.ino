
// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "TEZNET";
const char* password = "";

///////////////////////
void setup() {
  Serial.begin(115200);


  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  // WiFi.softAP(ssid, password);
  WiFi.softAP(ssid);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
}

///////////////////////
void loop(){
 // NADA
}


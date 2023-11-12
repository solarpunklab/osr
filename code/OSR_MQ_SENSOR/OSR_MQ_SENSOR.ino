#define LED 2
#define SENSOR 35
#define DELAY 100

int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Sensor start");
}

void loop() {
  // digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  // delay(DELAY);              // wait for a second
  
  // read the value from the sensor:
  sensorValue = analogRead(SENSOR);
  // Serial.print("Value: "); 
  Serial.println(sensorValue);
 
  // digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(DELAY);
}
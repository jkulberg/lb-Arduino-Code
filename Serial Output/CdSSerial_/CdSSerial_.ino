/*
 CdSSerial based on AnalogReadSerial
 Reads a cDs SENSOR on pin 0, prints the result to the serial monitor.
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1000);
}


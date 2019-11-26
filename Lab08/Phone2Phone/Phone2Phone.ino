#include <Wire.h>

char x;

void setup() {
  Wire.begin(9);
  Serial.begin(9600);// Interfata Serial 0, pentruPC
  Serial2.begin(9600);  // Interfata Serial 1, pentru Bluetooth
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
}
void loop() {
}

void requestEvent() {
 if(Serial2.available())// Citire de la PC, trimite la Bluetooth
  Wire.write(Serial2.read());
  
}

void receiveEvent(int bytes) {
  x = Wire.read();
  Serial2.print((char) x);
}

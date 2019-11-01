#include <LiquidCrystal.h>// include I2Clibrary
#include <Wire.h>

String inputString = "";         // create an empty string to hold the incoming serial data
// Boolean flag to test whether a complete string has been received (enter pressed in serial monitor)
boolean stringComplete = false;

int x = 0;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  // Start i2C slave at address 9
  Serial.begin(9600);
  Wire.begin(9);
  // attach a function to be called when we receive something on the I2C bus
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  lcd.begin(16, 2);
  lcd.print("Slave");
  inputString.reserve(200);
}

void receiveEvent(int bytes) {
  x = Wire.read();
  Serial.print((char)x);
  if (x == 0)
    Serial.println();
}
//readI2Creceived character

void loop() {
  lcd.setCursor(0, 1); // display received character
  lcd.print(x);
}

void serialEvent() {
  while (Serial.available()) {
    // read the new received byte
    char inChar = (char)Serial.read();
    // check if new line character has been received; if not, add it to the string
    // we do not add new line in input string since it will show an extra character in the LCD
    if (inChar != '\n')
      inputString += inChar;
    // dif the receive character is new line, set the flag so that the loop will know to display the received data
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void requestEvent() {
  if (stringComplete) {
    inputString += '\n';
    for (int i = 0; i < inputString.length(); i++) {
      //Serial.println(inputString[i]);
      Wire.write(inputString[i]); // respond with message of 6 bytes
      // as expected by maste
    }
    inputString = "";// reset the flag
    stringComplete = false;
  }
}

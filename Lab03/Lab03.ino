#include "avr/interrupt.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
volatile int buttonVariable = 0;
// = 0;

byte twelve[8] = {
  0b00000,
  0b01010,
  0b01010,
  0b01010,
  0b01010,
  0b01110,
  0b01110,
  0b00000
};

byte three[8] = {
  0b00000,
  0b01110,
  0b01110,
  0b01110,
  0b01000,
  0b01110,
  0b01110,
  0b00000
};

byte six[8] = {
  0b00000,
  0b01110,
  0b01110,
  0b01110,
  0b01010,
  0b01010,
  0b01010,
  0b00000
};

byte nine[8] = {
  0b00000,
  0b01110,
  0b01110,
  0b01110,
  0b00010,
  0b01110,
  0b01110,
  0b00000
};

byte up[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111
};

byte down[8] = {
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};


void setup() {

  buttonVariable = 0;

  lcd.begin(16, 2);

  lcd.createChar(0, twelve);
  lcd.createChar(1, three);
  lcd.createChar(2, six);
  lcd.createChar(3, nine);
  lcd.createChar(4, up);
  lcd.createChar(5, down);

  pinMode(20 , INPUT);
  pinMode(21 , INPUT);
  //digitalWrite(20, HIGH);
  //digitalWrite(21, HIGH);

  attachInterrupt(digitalPinToInterrupt(20), functieUnu, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(21), functieDoi, FALLING);

  lcd.setCursor(0, 0);

  Serial.begin(9600);

}

int timer;

void loop() {

  Serial.println(digitalRead(20));

  timer++;
  if(timer >= 16)
  {
    timer=0;
    lcd.clear();
    lcd.setCursor(0,0);
  }
  if (buttonVariable == 1)
    lcd.write(byte(4));
  else
    lcd.write(byte(5));

  //lcd.clear();
  //lcd.setCursor(0, 0);
  //lcd.print(timer);
  //delay(1000);

  //lcd.setCursor(0, 0);
  //lcd.write(byte((timer%4)));
  delay(50);

}

void functieUnu() {
  buttonVariable = 1- buttonVariable;
  //lcd.clear();
  //lcd.setCursor(0, 0);
  //lcd.print("Functia Unu");
}
void functieDoi() {
  buttonVariable = 1;
}

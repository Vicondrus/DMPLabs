﻿/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

extern "C" void Serial_Setup();
extern "C" void Print_Hello();
extern "C" uint8_t myarray[10]={1, 30, 3, 4, 5, 6, 7, 8, 10, 11};

void setup() {
  Serial_Setup();
}
void loop() {
  //ldi ZL, lo8(asd)         ; r30
  //ldi ZH, hi8(asd)         ; r31
  //lpm r18, Z+ 
  Print_Hello();
  delay(500);
}

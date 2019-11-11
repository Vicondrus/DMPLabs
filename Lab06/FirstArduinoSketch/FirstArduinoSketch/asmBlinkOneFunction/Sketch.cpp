/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

extern "C" void setpin();
extern "C" char turnspecified(char c);
void setup() {
  setpin();
}
void loop() {
  turnspecified(1);
 // delay(1000);
  turnspecified(0);
 // delay(1000);
}

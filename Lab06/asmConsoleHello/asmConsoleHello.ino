extern "C" void Serial_Setup();
extern "C" void Print_Hello();
char[] asd = {'1','2','3'};

void setup() {
  Serial_Setup();
}
void loop() {
  ldi ZL, lo8(asd)         ; r30
  ldi ZH, hi8(asd)         ; r31
  lpm r18, Z+ 
  Print_Hello();
  delay(500);
}

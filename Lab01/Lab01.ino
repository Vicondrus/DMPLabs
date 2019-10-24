//int b1;
//int b2;
//int b3;
//int b4;
//
//int stat = 0;
//
//int timp, start = millis();
//
//void setup() {
//  pinMode(4, INPUT_PULLUP);
//  pinMode(5, INPUT_PULLUP);
//  pinMode(6, INPUT_PULLUP);
//  pinMode(7, INPUT_PULLUP);
//  Serial.begin(9600);
//}
//
//void loop(){
//  b1=digitalRead(4);
//  b2=digitalRead(5);
//  b3=digitalRead(6);
//  b4=digitalRead(7);
//  timp = millis() - start;
//  if(b1 == 0)
//    Serial.println(timp);
//  if(b2 == 0)
//    Serial.println((millis()-start)/1000);
//  if(b3 == 0)
//    Serial.println("Button pressed");
//  delay(100);
//}

int b1;
int b2;
int b3;
int b4;

unsigned char stat = 0;

void setup() {
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

  DDRD = 0b11111111;
  
  Serial.begin(9600);
}

void loop(){
  b1=digitalRead(10);
  b2=digitalRead(11);
  b3=digitalRead(12);
  b4=digitalRead(13);

  if(b1 == 1){
    if ((stat and 0b000001) == 0)
      stat = (stat>>1) + 0b100000;
      else
        stat = stat>>1;
  }else{
    if ((stat << 6) == 0)
      stat = (stat<<1) + 1;
      else
        stat = stat<<1;
  }
  
  PORTD = stat;
  delay(100);
}

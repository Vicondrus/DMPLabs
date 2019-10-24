int latchPin = 4;
int clockPin = 7;
int dataPin = 8; // SSD pins

int count = 0;

const unsigned char ssdlut[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
const unsigned char anodelut[]   = {0b00000001, 0b00000010, 0b00000100, 0b00001000};

int buttonState1;             // the current reading from the input pin
int lastButtonState1 = LOW;   // the previous reading from the input pin

int buttonState2;             // the current reading from the input pin
int lastButtonState2 = LOW;

int buttonState3;             // the current reading from the input pin
int lastButtonState3 = LOW;


int buttonPin1 = 55;
int buttonPin2 = 56;
int buttonPin3 = 57;

unsigned long lastDebounceTime1 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay1 = 50;

unsigned long lastDebounceTime2 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay2 = 50;

unsigned long lastDebounceTime3 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay3 = 50;

unsigned char digits[] = {1, 2, 3, 4};
int x;
int nr = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  x = millis();

}

void loop() {
  // put your main code here, to run repeatedly:

  int reading1 = digitalRead(buttonPin1);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading1 != lastButtonState1) {
    // reset the debouncing timer
    lastDebounceTime1 = millis();
  }

  if ((millis() - lastDebounceTime1) > debounceDelay1) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading1 != buttonState1) {
      buttonState1 = reading1;

      // only toggle the LED if the new button state is HIGH
      if (buttonState1 == LOW) {
        count = 1;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState1 = reading1;

  int reading2 = digitalRead(buttonPin2);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading2 != lastButtonState2) {
    // reset the debouncing timer
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay2) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading2 != buttonState2) {
      buttonState2 = reading2;

      // only toggle the LED if the new button state is HIGH
      if (buttonState2 == LOW) {
        count = 0;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState2 = reading2;

  int reading3 = digitalRead(buttonPin3);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading3 != lastButtonState3) {
    // reset the debouncing timer
    lastDebounceTime3 = millis();
  }

  if ((millis() - lastDebounceTime3) > debounceDelay3) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading3 != buttonState3) {
      buttonState3 = reading3;

      // only toggle the LED if the new button state is HIGH
      if (buttonState3 == LOW) {
        nr = 0;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState3 = reading3;



  digits[0] = nr / 1000;
  digits[1] = (nr / 100) % 10;
  digits[2] = (nr / 10) % 10;
  digits[3] = nr % 10;
  for (char i = 0; i <= 3; i++) // For each of the 4 digits
  {
    unsigned char digit = digits[i];  // the current digit
    unsigned  char  cathodes  =  ~ssdlut[digit]; //  The  cathodes  of  the  current  digit,  we’ll  negate the value from the original LUT
    digitalWrite(latchPin, LOW); // Activate the latch to allow writing
    shiftOut(dataPin, clockPin, MSBFIRST, cathodes); // shift out the cathode byte
    shiftOut(dataPin, clockPin, MSBFIRST, anodelut [i] ); // shift out the anode byte
    digitalWrite(latchPin, HIGH); // De-activate the latch signal
    delay(2); // Short wait
  }
  if (millis() - x >= 10)
  {
    if (count == 1)
      nr++;
    x = millis();
  }
}

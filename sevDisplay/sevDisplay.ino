const unsigned char ssdlut[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
const int lutsize = 100;

int nr = 0;
int cpos = 0;
int cdigit = 0;
int cz, cu;
unsigned char outvalue = 0;

void setup() {
  // put your setup code here, to run once:
  DDRA = 0b11111111;
}

void loop() {
  // put your main code here, to run repeatedly:
  cz = nr / 10;
  cu = (nr % 10);
  //  we  make  an  OR  between  the  value  from  the  LUT  and  the selected cathode // we increment the current position
  for (int i = 0; i < 32500; i++)
  {
    cdigit ^= 1;
    outvalue = cdigit > 0 ? 0x80 : 0;
    if (i % 2 == 0)
      cpos = cz;
    else
      cpos = cu;
    PORTA = (ssdlut[cpos]  |  outvalue);
  }
  nr++;
  if (nr >= 100) { // if we reached the final position
    nr = 0;
  }  // wait 0.5 sec
}


// Shift registers
#define latch 4
#define clock_pin 5
#define data 6
int leds[] = {7, 8, 9, 10};

void setup() {
  pinMode(latch, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(data, OUTPUT);

  for(int x=7; x<=10; ++x){
  pinMode(x, OUTPUT);
  }// end for
  
  Serial.begin(9600);
}

void loop() {
  for (int i = 1; i < 13; ++i) {
    showPeriod(i);
    delay(100);
  }
}// end main loop

void showPeriod(int n) {
  // Turn off all LEds initially
  for(int x=7; x<=10; ++x){
  digitalWrite(x, LOW);
  }// end for

// Use shift reg for all periods less than or equal to 8
  if (n <=  8) {
    byte p[] = {
      0b10000000,  //1
      0b01000000,  //2
      0b00100000,  //3
      0b00010000,  //4
      0b00001000,  //5
      0b00000100,  //6
      0b00000010,  //7
      0b00000001  //8
    };// end array
    digitalWrite(latch, 0);
    shiftOut(data, clock_pin, MSBFIRST, p[n - 1]);
    digitalWrite(latch, 1);
  }// end if
  
  else {
    digitalWrite(latch, 0);
    shiftOut(data, clock_pin, MSBFIRST, 0);
    digitalWrite(latch, 1);
    digitalWrite(n - 2, 1);
  }// end else
}// end showPeriod function

 void showPeriod(int n) {
  // Turn off all LEds initially
  for (int x = 7; x <= 10; ++x) {
    digitalWrite(x, LOW);
  }// end for

  // Use shift reg for all periods less than or equal to 8
  if (n <=  8) {
    byte p[] = {
      0b10000000,  //1
      0b01000000,  //2
      0b00100000,  //3
      0b00010000,  //4
      0b00001000,  //5
      0b00000100,  //6
      0b00000010,  //7
      0b00000001   //8
    };// end array
    digitalWrite(latch, 0);
    shiftOut(data, clock_pin, MSBFIRST, p[n - 1]);
    digitalWrite(latch, 1);
  }// end if

  else {
    digitalWrite(latch, 0);
    shiftOut(data, clock_pin, MSBFIRST, 0);
    digitalWrite(latch, 1);
    digitalWrite(n - 2, 1);
  }// end else
}// end showPeriod function

void display(int d) {
  int ledPins = {4,5,6,7,8,9,10};

  byte digit[10] = {
  //0bABCDEFG
  0b1111110,  //0
  0b0110000,  //1
  0b1101101,  //2
  0b1111001,  //3
  0b0110011,  //4
  0b1011011,  //5
  0b1011111,  //6
  0b1110000,  //7
  0b1111111,  //8
  0b1111011   //9
};
  
  for (int x = 0; x < sizeof(digit[d]); ++x) {
    int last_didgit = (digit[d] >> x) & 1;
    if (last_digit == 1) {
      digitalWrite(ledPins[7 - x], HIGH);
    }// end if
    else {
      digitalWrite(ledPins[7 - x], LOW);
    }// end else
  }// end for
}  // end display

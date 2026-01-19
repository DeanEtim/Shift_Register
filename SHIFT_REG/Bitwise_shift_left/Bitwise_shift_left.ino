byte num;
byte r_num;

// Shift registers
#define latch 4
#define clock_pin 5
#define data 6

void send_byte(byte bin_val) {
  digitalWrite(latch, 0);
  shiftOut(data, clock_pin, MSBFIRST, bin_val);
  digitalWrite(latch, 1);
}

void setup() {
  Serial.begin(9600);
  pinMode(latch, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(data, OUTPUT);
}

void loop() {
  num = 0b11111111;

  for (int x = 0; x < 9; ++x) {
    send_byte(num);
    Serial.print("Byte sent: ");
    Serial.println(num, BIN);
    num = num >> 1;
    delay(500);
  }// end for

  num = 0b00000001;

  for (int x = 0; x < 9; ++x) {
    send_byte(num);
    Serial.print("Byte sent: ");
    Serial.println(num, BIN);
    num = (num << 1) + 1;
    delay(500);
  }// end for

}

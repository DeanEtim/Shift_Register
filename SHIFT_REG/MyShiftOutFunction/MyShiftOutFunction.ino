const int dataPin = 3;
const int clockPin = 4;
const int latchPin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  //make certain that all pins are low
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    displayT(i);
    Serial.print(i, BIN);
    Serial.print("\t\t");
    Serial.println(i);
    delay(1000);
  }// end loop
}// end main loop

void shift(int dP, int cP, byte bt, char bitOrder[2]) {
  if (bitOrder == "LSB")
  {
    for (int x = 0; x <= 7; x++)
    {
      digitalWrite(cP, LOW);
      ((bt >> x) & 1 == 1) ? digitalWrite(dP, HIGH) : digitalWrite(dP, LOW);
      digitalWrite(cP, HIGH);
    }// end for
  }// end if
}// end shift function

void displayT(int value) {
  digitalWrite(latchPin, LOW);
  shift(dataPin, clockPin, value, "LSB");
  digitalWrite(latchPin, HIGH);
}// end display function

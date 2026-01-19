int ledPins[6] = {7, 8, 9, 10, 11, 12};

int sensorVal;
int mic = A4;

void setup() {
  Serial.begin(9600);
  pinMode(mic, INPUT);
  //declare all led pins as output
  for (int x = 0; x < 6; ++x) {
    pinMode(ledPins[x], OUTPUT);
  }
}// end setup


void loop() {
  sensorVal = analogRead(mic);
  int calibLow = 0; int calibHigh = 1023;
  sensorVal = map(analogRead(mic), calibLow, calibHigh, 0, 100);
  Serial.println(sensorVal);
  delay(50);

  digitalWrite(ledPins[4], sensorVal < 10 ? HIGH : LOW);
  digitalWrite(ledPins[3], sensorVal < 20 ? HIGH : LOW);
  digitalWrite(ledPins[2], sensorVal < 30 ? HIGH : LOW);
  digitalWrite(ledPins[1], sensorVal < 40 ? HIGH : LOW);
  digitalWrite(ledPins[0], sensorVal < 50 ? HIGH : LOW);
}

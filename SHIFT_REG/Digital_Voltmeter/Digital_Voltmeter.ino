#include <Servo.h>
int servoPin = 5;
int ledPins[6] = {7, 8, 9, 10, 11, 12};

int sensorVal;
int ldr = A6;
Servo machine;

void setup() {
  machine.attach(servoPin);
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  //declare all led pins as output
  for (int x = 0; x < 6; ++x) {
    pinMode(ledPins[x], OUTPUT);
  }
}// end setup


void loop() {
//  sensorVal = analogRead(ldr);
  int calibLow = 25; int calibHigh = 950;
  sensorVal = map(analogRead(ldr), calibLow, calibHigh, 0, 100);
  Serial.println(sensorVal);
  delay(50);

  digitalWrite(ledPins[4], sensorVal < 20 ? HIGH : LOW);
  digitalWrite(ledPins[3], sensorVal < 40 ? HIGH : LOW);
  digitalWrite(ledPins[2], sensorVal < 60 ? HIGH : LOW);
  digitalWrite(ledPins[1], sensorVal < 80 ? HIGH : LOW);
  digitalWrite(ledPins[0], sensorVal < 100 ? HIGH : LOW);
}

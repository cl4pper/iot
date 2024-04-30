#include <Arduino.h>

int switchState = 0;
int buttonPin = 2;
int greenLedPin = 3;
int redLedPrimaryPin = 4;
int redLedSecondaryPin = 5;

void switchLeds(uint8_t, uint8_t, uint8_t);

void setup() {
  // OUTPUTS
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPrimaryPin, OUTPUT);
  pinMode(redLedSecondaryPin, OUTPUT);
  // INPUTS
  pinMode(buttonPin, INPUT);
}

void loop() {
  switchState = digitalRead(buttonPin);

  if(switchState == LOW) {
    switchLeds(HIGH, LOW, LOW);
  } else {
    switchLeds(LOW, LOW, HIGH);

    delay(250);
    digitalWrite(redLedPrimaryPin, HIGH);
    digitalWrite(redLedSecondaryPin, LOW);
    delay(250);
  }
}

void switchLeds(uint8_t valueA, uint8_t valueB, uint8_t valueC) {
  digitalWrite(greenLedPin, valueA);
  digitalWrite(redLedPrimaryPin, valueB);
  digitalWrite(redLedSecondaryPin, valueC);
}
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

const int buttonPin = 2;

const int motorEnable = 5;
const int motorIn1 = 7;
const int motorIn2 = 8;

int lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(motorEnable, OUTPUT);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);
  analogWrite(motorEnable, 0);
  Serial.begin(9600);
  BTSerial.begin(9600);
}
void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    delay(30);
    buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState) {
      if (buttonState == LOW) {
        BTSerial.write('1');
        Serial.println("Button Pressed -> Send 1");
      } else {
        BTSerial.write('0');
        Serial.println("Button Released -> Send 0");
      }
      lastButtonState = buttonState;
    }
  }
  if (BTSerial.available() > 0) {
    byte motorSpeed = BTSerial.read();
    analogWrite(motorEnable, motorSpeed);
    Serial.print("Motor Speed = ");
    Serial.println(motorSpeed);
  }
}
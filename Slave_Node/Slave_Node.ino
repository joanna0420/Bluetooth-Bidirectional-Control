#include <SoftwareSerial.h>

// RX: 10 (接 HC-05 TX), TX: 11 (接 HC-05 RX)
SoftwareSerial BTSerial(10, 11);

const int potPin = A0;
const int ledPin = 9;

int lastMotorVal = -1;
unsigned long lastSendTime = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);    
  BTSerial.begin(9600);  
}

void loop() {
  if (BTSerial.available()) {
    char cmd = BTSerial.read();
    if (cmd == '1') {
      digitalWrite(ledPin, HIGH);
    } else if (cmd == '0') {
      digitalWrite(ledPin, LOW);
    }
  }

  if (millis() - lastSendTime > 50) {
    int potVal = analogRead(potPin);
    int motorVal = map(potVal, 0, 1023, 0, 255); // 轉為 PWM 0~255

    if (abs(motorVal - lastMotorVal) > 2) {
      BTSerial.write(motorVal);  
      lastMotorVal = motorVal;
    }
    lastSendTime = millis();
  }
}
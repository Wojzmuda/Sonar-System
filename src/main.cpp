#include <Arduino.h>
#include "SonarHandler.h"
#include "ServoHandler.h"
#include"ScannerHandler.h"

const byte trigPin = 3;
const byte echoPin = 4;
const byte servoPin = 5;
const int BUTTON_PIN = 2;

SonarHandler sonar(trigPin, echoPin);
ServoHandler servo(servoPin);
ScannerHandler scanner(servo, sonar);

void setup(){
    Serial.begin(9600);
    scanner.init();
    Serial.println("Scanner is initalized...");
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    while (digitalRead(BUTTON_PIN) == HIGH) {
    delay(10); 
  }
}

void loop(){
    scanner.runFullScan();

}

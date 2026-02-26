#include <Arduino.h>
#include "SonarHandler.h"
#include "ServoHandler.h"
#include"ScannerHandler.h"
#include "JoystickHandler.h"

const byte trigPin = 3;
const byte echoPin = 4;
const byte servoPin = 5;
const byte pinX = A1;
const byte pinY = A0;
const byte pinSW = 6;
const int BUTTON_PIN = 2;

SonarHandler sonar(trigPin, echoPin);
ServoHandler servo(servoPin);
ScannerHandler scanner(servo, sonar);
JoystickHandler joystick(pinX, pinY, pinSW);
void setup(){
    Serial.begin(9600);
    scanner.init();
    joystick.init();
    Serial.println("Scanner is initalized...");
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    //while (digitalRead(BUTTON_PIN) == HIGH) {
    //delay(10); 
  //}
}

void loop(){
    int dir = joystick.getDirectionFromX();
    int angle = servo.getAngle();
    angle +=dir;
    ScannerData wynik = scanner.getSingleMeasurment(angle);
    Serial.print("Scanning");
    Serial.print("degree - ");
    Serial.print(wynik.angle);
    Serial.print(" ODLEGLOSC: ");
    Serial.print(wynik.distance);
    Serial.println("cm");
}

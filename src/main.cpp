#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

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

const byte buttonPin = 2;

const byte SSPin = 10;
const byte RstPin = 7;

MFRC522 reader(SSPin, RstPin);
SonarHandler sonar(trigPin, echoPin);
ServoHandler servo(servoPin);
ScannerHandler scanner(servo, sonar);
JoystickHandler joystick(pinX, pinY, pinSW);

void setup(){
    Serial.begin(9600);
    SPI.begin();
    reader.PCD_Init();
    delay(10);
    scanner.init();
    joystick.init();
    Serial.println("Scanner is initalized...");
    pinMode(buttonPin, INPUT_PULLUP);
    delay(4);
    reader.PCD_DumpVersionToSerial();
    Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
    //while (digitalRead(BUTTON_PIN) == HIGH) {
    //delay(10); 
  //}
}

void loop(){
    /*
    int dir = joystick.getDirectionFromX();
    int angle = servo.getAngle();
    angle +=2*
    dir;
    ScannerData wynik = scanner.getSingleMeasurment(angle);
    Serial.print("Scanning");
    Serial.print("degree - ");
    Serial.print(wynik.angle);
    Serial.print(" ODLEGLOSC: ");
    Serial.print(wynik.distance);
    Serial.println("cm");*/
}

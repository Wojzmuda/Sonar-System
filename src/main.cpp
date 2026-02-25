#include <Arduino.h>
#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64

const int trigPin = 11;
const int echoPin = 12;
const int servoPin = 3;
const int buzzerPin = 8;
const int switchPin = 2;
const int bluetoothTX = 4;
const int bluetoothRX = 5;

SoftwareSerial bt(bluetoothTX, bluetoothRX);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo servo;

int servoAngle = 0;
unsigned long lastBeepTime = 0;

int calculateDistance();
void handleSonar(int angle);
void handleBeep(int distance);
void printDistance( int distance,int angle);

void setup(){
    Serial.begin(9600);
    servo.attach(servoPin);
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    display.clearDisplay();
    pinMode(1, INPUT_PULLUP);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    bt.begin(9600);
}


void loop(){/*
    for(servoAngle = 0; servoAngle <= 180; servoAngle+=2) 
    {
        handleSonar(servoAngle);
    }
    for(servoAngle = 180; servoAngle >= 0; servoAngle-= 2) 
    {
        handleSonar(servoAngle);
    }
        */
       int x = analogRead(A1); // Czytamy 0-1023
  int y = analogRead(A0); // Czytamy 0-1023
  bool klik = !digitalRead(1);

  // Mapujemy (skalujemy) wartości 0-1023 na rozmiar ekranu
  int posX = map(x, 0, 1023, 0,128);
  int posY = map(y, 0, 1023, 64,16); // Startujemy od 16, żeby nie wchodzić na żółtą górę

  display.clearDisplay();

  // Żółta góra - status
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("JOYSTICK TEST");
  if(klik) display.print(" -> KLIK!");

  // Niebieski dół - celownik
  display.drawCircle(posX, posY, 5, WHITE); // Kółko celownika
  display.drawFastHLine(posX-10, posY, 20, WHITE); // Linia pozioma celownika
  display.drawFastVLine(posX, posY-10, 20, WHITE); // Linia pionowa celownika

  display.display();
  if (bt.available()) {
    char data = bt.read();
    Serial.print("Telefon wyslal: ");
    Serial.println(data);
  }
  delay(10); // Bardzo szybkie odświeżanie
  
}


int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  if (duration == 0) return 400;
  return duration * 0.034 / 2;
}

void handleSonar(int angle){
    servo.write(angle);
    delay(100);
    int distance = calculateDistance();
    handleBeep(distance);
    printDistance(distance, angle);
}

void handleBeep(int distance){
    int beepinterval;
    if(distance > 0 && distance<10){
        beepinterval=100;
    }else if(distance>=10 && distance<=20){
        beepinterval = 300;
    }else{
        beepinterval = 1500;
    }
    if(millis() - lastBeepTime >=beepinterval){
        tone(buzzerPin, 1000, 40);
        lastBeepTime = millis();
    }
}

void printDistance(int distance, int angle){
    Serial.print(angle);
    Serial.print(": ");
    Serial.println(distance);
}
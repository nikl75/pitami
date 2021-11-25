#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h> // für LiquidCrystal
#include <AccelStepper.h>
#include <string.h>
#include <math.h>

// neues lcd initialisieren und pins setzen
LiquidCrystal mlcd(14, 15, 16, 17, 18, 19);

// pin stepper setzen
#define STEPPER_01_ST 3
#define STEPPER_01_DIR 4
AccelStepper mStepper01(AccelStepper::DRIVER, STEPPER_01_ST, STEPPER_01_DIR);

// poti pin zum lesen setzen 
const int potiPin = A0;
float sensorwert = 0; //Variable für den Sensorwert mit 0 als Startwert

// -------------------------------------------------------- //

void setup()
{
  // Seriellen Monitor starten
  Serial.begin(9600);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // lcd starten
  mlcd.clear();
  mlcd.begin(16, 2); // wieviel reihen und zeilen das display hat

  // stepper einrichten
  mStepper01.setMaxSpeed(100);
  mStepper01.setAcceleration(10);
  mStepper01.moveTo(-100);
}

void resetStepSet()
{
  mStepper01.setMaxSpeed(rand() % 500 + 300);
  mStepper01.setAcceleration(rand() % 200 + 1);
  mStepper01.moveTo((rand() % 200 + 1)-100);
}

void printLCD()
{
  mlcd.setCursor(0, 0);
  mlcd.print("STEP"); // write on lcd
}
void printS(String content){

  Serial.println(content);
}


// the loop function runs over and over again forever
void loop()
{
  mStepper01.run();
  if (!mStepper01.isRunning())
  {
    resetStepSet();
  }
  sensorwert = analogRead(potiPin)*100000;
  Serial.print(sensorwert/100000);
  Serial.print(" |  1/4: ");
  Serial.print(pow(sensorwert, 1/4.)*100);
  Serial.print(" |  1/32: ");
  Serial.print(pow(sensorwert, 1/32.)*100);
  Serial.print(" |  best: ");
  Serial.println(pow(sensorwert, 1/64.)*100-119);
}

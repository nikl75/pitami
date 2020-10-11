#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h> // für LiquidCrystal
#include <AccelStepper.h>

// neues lcd initialisieren und pins setzen --------------------------------------------------------//
LiquidCrystal mlcd(14, 15, 16, 17, 18, 19);

// pin stepper setzen
#define STEPPER_01_ST 3
#define STEPPER_01_DIR 4
AccelStepper mStepper01(AccelStepper::DRIVER, STEPPER_01_ST, STEPPER_01_DIR);

void setup()
{
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

// the loop function runs over and over again forever
void loop()
{
  mStepper01.run();
  if (!mStepper01.isRunning())
  {
    resetStepSet();
  }
}

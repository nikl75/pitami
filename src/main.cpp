#include <Arduino.h>

#include <potiN.h>

#include <AccelStepper.h>

#include <string.h>
#include <math.h>

#include <LiquidCrystal.h>
#include <Wire.h> // für LiquidCrystal


// poti pin zum lesen setzen
const int potiPin01 = A1;
const int potiPin02 = A2;
const int potiPin03 = A3;

potiN p01(potiPin01, -5, 5);
potiN p02(potiPin02, 0, 10);
potiN p03(potiPin03, 200, 299);

// pin stepper setzen
#define STEPPER_01_ST 3
#define STEPPER_01_DIR 4
AccelStepper mStepper01(AccelStepper::DRIVER, STEPPER_01_ST, STEPPER_01_DIR);

// -------------------------------------------------------- //

void setup()
{
  // Seriellen Monitor starten
  Serial.begin(9600);
}


// the loop function runs over and over again forever
void loop()
{
  Serial.println("P01: " + String(p01.get()) + " | P02: " + String(p02.get()) + " | P03: " + String(p03.get()) + " | ");
  delay(200);
}


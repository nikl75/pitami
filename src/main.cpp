#include <Arduino.h>
#include <potiN.h>

// poti pin zum lesen setzen
const int potiPin01 = A1;
const int potiPin02 = A2;
const int potiPin03 = A3;
// float sensorwert = 0; //Variable für den Sensorwert mit 0 als Startwert

  potiN p01(potiPin01);
  potiN p02(potiPin02);
  potiN p03(potiPin03);

// -------------------------------------------------------- //

// poti pin zum lesen setzen 
const int potiPin = A0;
float sensorwert = 0; //Variable für den Sensorwert mit 0 als Startwert

// -------------------------------------------------------- //

void setup()
{
  // Seriellen Monitor starten
  Serial.begin(9600);
}


// the loop function runs over and over again forever
void loop()
{
  Serial.print("P01: " + String(p01.get()) + " | ");
  Serial.print("P02: " + String(p02.get()) + " | ");
  Serial.println("P03: " + String(p03.get()) + " | ");
  delay(200);
}


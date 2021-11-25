#include <Arduino.h>

// poti pin zum lesen setzen
const int potiPin01 = A1;
const int potiPin02 = A2;
const int potiPin03 = A3;
// float sensorwert = 0; //Variable für den Sensorwert mit 0 als Startwert

// -------------------------------------------------------- //

void setup()
{
  // Seriellen Monitor starten
  Serial.begin(9600);
}


// the loop function runs over and over again forever
void loop()
{
  Serial.print("P01: " + String(analogRead(potiPin01)) + " | ");
  Serial.print("P02: " + String(analogRead(potiPin02)) + " | ");
  Serial.println("P03: " + String(analogRead(potiPin03)) + " | ");
  delay(200);
}

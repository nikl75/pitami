#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h> // für LiquidCrystal

// neues lcd initialisieren und pins setzen --------------------------------------------------------//
LiquidCrystal mlcd(14, 15, 16, 17, 18 ,19);

// pin stepper setzen
int pStSt = 3;
int pStDi = 4;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // lcd starten
  mlcd.clear();
  mlcd.begin(16,2); // wieviel reihen und zeilen das display hat
  

}

void step(){
  digitalWrite(pStSt, HIGH);
  delay(10);
  digitalWrite(pStSt, LOW);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on 
  delay(1000);                       // wait for half a second
  
  step();
  mlcd.setCursor(0,0);
  mlcd.print("STEP"); // write on lcd

  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off 
  delay(1000);                       // wait for half a second
  mlcd.setCursor(0,0);
  mlcd.clear(); // write on lcd

}


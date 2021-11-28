#include "potiN.h"
potiN::potiN(byte tPin) {
  // Use 'this->' to make the difference between the
  // 'pin' attribute of the class and the 
  // local variable 'pin' created from the parameter.
  this->pin = tPin;
  init();
}
void potiN::init() {
}
float potiN::get(){
  return analogRead(pin);
}

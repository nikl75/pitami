#include "potiN.h"
potiN::potiN(byte tPin, float tRangeMin, float tRangeMax)
{
  // Use 'this->' to make the difference between the
  // 'pin' attribute of the class and the
  // local variable 'pin' created from the parameter.
  this->pin = tPin;
  this->rangeMin = tRangeMin;
  this->rangeMax = tRangeMax;
  init();
}
void potiN::init()
{
  potiMin = 0;
  potiMax = 1023;
  setRangeRatio();
}
void potiN::setRangeRatio()
{
  rangeDelta = rangeMax - rangeMin;
  rangeRatio = rangeDelta/(potiMax);
}
float potiN::get()
{
  return analogRead(pin)*rangeRatio+rangeMin;
}

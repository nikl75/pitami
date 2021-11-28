#ifndef POTI_N_H
#define POTI_N_H
#include <Arduino.h>
class potiN {
  
  private:
    byte pin;
    float rangeMin;
    float rangeMax;
    float rangeDelta;
    float rangeRatio;
    float potiMin;
    float potiMax;
    void setRangeRatio();
    
  public:
    potiN(byte tPin, float tRangeMin, float tRangeMax);
    void init();
    float get();
};
#endif
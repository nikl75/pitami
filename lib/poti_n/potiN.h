#ifndef POTI_N_H
#define POTI_N_H
#include <Arduino.h>
class potiN {
  
  private:
    byte pin;
    
  public:
    potiN(byte pin);
    void init();
    float get();
};
#endif
#ifndef Classtest_h
#define Classtest_h

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

class Classtest{
public:
  Classtest(int pin);
  void dot();
  void dash();
};

#endif

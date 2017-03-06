#ifndef TimerThing_h
#define TimerThing_h

#include <Arduino.h>



class TimerThing{
public:
  TimerThing();
  unsigned long start();
  unsigned long lap();
  unsigned long stop();
};

#endif

#ifndef PlayData_h
#define PlayData_h

#include <Arduino.h>
#include "SD.h"
#include "SPI.h"



class PlayData{
public:
  //PlayData(const char *p1, const char *p2, const char *c1, const char *c2);
  PlayData(int p1, int p2, int c1, int c2);

};

#endif

#include <Arduino.h>
#include <TimerThing.h>


//initialize variables
unsigned long t1;
unsigned long t2;
unsigned long dt;
//Initializing objects

//Constructor
TimerThing::TimerThing(){
  //Serial.println("Timer Created");
}

void TimerThing::start(){
  //Start Timer
  t1 = millis();
}

void TimerThing::stop(){
  t2 = millis();
  int dt = (t2-t1);

  Serial.println("Time Delta is = " + String(dt));
}

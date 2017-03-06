#include <Arduino.h>
#include <TimerThing.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


//initialize variables
unsigned long t1;
unsigned long t2;
unsigned long dt;
unsigned long t[3];
int laps;

//Initializing objects

//Constructor
TimerThing::TimerThing(){
  //Serial.println("Timer Created");
}

unsigned long TimerThing::start(){
  //Start Timer
  t1 = millis();
  laps = 0;
  t[laps] = t1;
  return t1;
}

unsigned long TimerThing::lap(){
  laps++;
  t2 = millis();
  t[laps] = t2-t1;
  for (int i = 0; i <= laps;i++){
    Serial.print(t[i]);
    Serial.print(" ");
  }
  Serial.println();
  return t[laps];
}

unsigned long TimerThing::stop(){
  t2 = millis();
  int dt = (t2-t1);
  Serial.println("Time Delta is = " + String(dt));
  return t2;
}

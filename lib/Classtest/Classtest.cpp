#include <Arduino.h>
#include <Classtest.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int _pin;
Classtest::Classtest(int pin){
  pinMode(pin,OUTPUT);
  _pin = pin;
}

void Classtest::dot(){
  digitalWrite(_pin,HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);
}

void Classtest::dash(){
  digitalWrite(_pin,HIGH);
  delay(1000);
  digitalWrite(_pin,LOW);
  delay(1000);
}

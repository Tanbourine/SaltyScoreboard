#include <Arduino.h>
#include <Test2.h>
//#include <string>
Test2::Test2(){

}

int Test2::createString(){
  String yes = "Hello";
  Serial.println(yes);
  return 0;
/*
  char yes[] = {"Hello World"};
  return *yes;
  */
}

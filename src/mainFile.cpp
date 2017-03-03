#include <Arduino.h>
#include <PlayData.h>
#include <TimerThing.h>

//Declare objects and variables
int a;
int P1 = 1;
int P2 = 2;
int C1 = 4;
int C2 = 6;
TimerThing timer;


void setup(){
  timer.start();
  Serial.begin(9600);
  while(!Serial){ //wait for Serial communication to begin
                  //delete when going headless
  }
  PlayData playData(P1, P2, C1, C2);
  timer.stop();
  //Show Loading Screen with Version # for debug purposes

  //Retrieve Character and Name Index and save into local memory

  //Display Singles Screen
}

//Define functions

//Printing Strings from pointers
void printString(const char *str){
  const char *p;
  p = str;
  while(*p){
    Serial.print(*p);
    p++;
  }
}

//Read SD card to collect char and player names >> Load into memory



void loop(){
  //AKA Main()
  timer.start();
  delay(1000);
  timer.stop();
//if statements to check button preses

//if singlesScreen >>

}

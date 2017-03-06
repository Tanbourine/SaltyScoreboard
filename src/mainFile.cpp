/*
  CS - 10
  MOSI - 11
  MISO - 12
  SCK - 13
  SDA - A4
  SCL - A5
*/

#include <Arduino.h>
//#include <PlayData.h>
#include <TimerThing.h>
#include <SD.h>
#include <SPI.h>
#include <string.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define CS_PIN 10
//Declare objects and variables
int P1 = 1;
int P2 = 2;
int C1 = 4;
int C2 = 6;
int delayTime = 5000;
const char *PNAMES = {"names.txt"};
const char *CNAMES = {"chars.txt"};
char playerNames[91];
//char *playerNames[91]; //Create container for player names
char charNames[157]; //Create container for character names

TimerThing timer;
File myFile;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);


//Printing Strings from pointers
void printString(char *str){
  const char *p;
  p = str;
  while(*p){
    Serial.print(*p);
    p++;
  }
}



void setup(){
  timer.start();
  Serial.begin(9600);
  while(!Serial){ //wait for Serial communication to begin
                  //delete when going headless
  }

  lcd.begin(20,4);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();

  Serial.print("PlayData -- Initializing SD card...");
  lcd.print("Initializing SD...");
  if(!SD.begin(CS_PIN)){
    Serial.println("Initialization failed!");
    lcd.setCursor(0,1);
    lcd.print("Initialization failed!");
    return;
  }
  Serial.println("...Initialization done!");
  lcd.setCursor(12,1);
  lcd.print("...done!");
  unsigned int t_lap1 = timer.lap();
  lcd.setCursor(0,3);
  lcd.print(t_lap1);
  lcd.print(" mils");
  delay(delayTime);

  //Retrieve Player Names
  myFile = SD.open(PNAMES, FILE_READ);  //PNAMES defined above for ease change
  if (myFile){
    lcd.clear();
    Serial.print("Reading names.txt...");
    lcd.home();
    lcd.print("Reading...");
    lcd.setCursor(0,1);
    lcd.print("names.txt...");

    for (unsigned int i = 0; i < myFile.size();i++){
      playerNames[i] = char(myFile.read());
      if (playerNames[i] == '0'){
        if (char(myFile.read()) == '0'){
          if (char(myFile.read()) == '0'){
            for(unsigned int j = 0;j < i; j++){
              //Serial.print(playerNames[j]);
            }
            break;
          }
        }
      }
    }
  }
  myFile.close();
  Serial.println("...done!");
  lcd.setCursor(0,2);
  lcd.print("...done!");
  unsigned long t_lap2 = timer.lap();
  lcd.setCursor(0,3);
  lcd.print(t_lap2-delayTime);
  lcd.print(" mils");
  delay(delayTime);

   //finished retrieving player names

   //Retrieve Character names
   myFile = SD.open(CNAMES, FILE_READ);  //PNAMES defined above for ease change
   if (myFile){
    lcd.clear();
    Serial.print("Reading chars.txt...");
    lcd.home();
    lcd.print("Reading...");
    lcd.setCursor(0,1);
    lcd.print("chars.txt...");
    lcd.setCursor(0,2);
     for (unsigned int i = 0; i < myFile.size();i++){
       charNames[i] = char(myFile.read());
       //Serial.print(charNames[i]);
     }
    }
    myFile.close();
    Serial.println("...done!");
    lcd.print("...done!");
    unsigned long t_lap3 = timer.lap();
    lcd.setCursor(0,3);
    lcd.print(t_lap3-2*delayTime);
    lcd.print(" mils");
    delay(delayTime);
    //lcd.clear();
    //Finished retrieving char names

    //Version Screen



  } //end of setup


  //Show Loading Screen with Version # for debug purposes


  //Display Singles Screen


//Define functions


//Read SD card to collect char and player names >> Load into memory



void loop(){
  //AKA Main()


//if singlesScreen >>

}

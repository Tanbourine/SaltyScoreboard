#include <Arduino.h>
//#include <PlayData.h>
#include <TimerThing.h>
#include <SD.h>
#include <SPI.h>
#include <string.h>

#define CS_PIN 10
//Declare objects and variables
int P1 = 1;
int P2 = 2;
int C1 = 4;
int C2 = 6;
const char *PNAMES = {"names.txt"};
const char *CNAMES = {"chars.txt"};
char playerNames[91];
//char *playerNames[91]; //Create container for player names
char charNames[157]; //Create container for character names

TimerThing timer;
File myFile;


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
  Serial.begin(9600);
  while(!Serial){ //wait for Serial communication to begin
                  //delete when going headless
  }


  Serial.print("PlayData -- Initializing SD card...");
  if(!SD.begin(CS_PIN)){
    Serial.println("Initialization failed!");
    return;
  }
  Serial.println("...Initialization done.");


  //Retrieve Player Names
  myFile = SD.open(PNAMES, FILE_READ);  //PNAMES defined above for ease change
  if (myFile){
    Serial.print("Reading names.txt...");
    //  while (myFile.available() > 0){
    for (unsigned int i = 0; i < myFile.size();i++){
      playerNames[i] = char(myFile.read());
      //Serial.println(playerNames[i]);
      if (playerNames[i] == '0'){
        if (char(myFile.read()) == '0'){
          if (char(myFile.read()) == '0'){
            for(unsigned int j = 0;j < i; j++){
              Serial.print(playerNames[j]);
            }
            break;
          }
        }
      }
    }
   }
   myFile.close();
   Serial.println("...done!");
   //finished retrieving player names

   //Retrieve Character names
   myFile = SD.open(CNAMES, FILE_READ);  //PNAMES defined above for ease change
   if (myFile){
     Serial.print("Reading chars.txt...");

     for (unsigned int i = 0; i < myFile.size();i++){
       charNames[i] = char(myFile.read());
       Serial.print(charNames[i]);
     }
    }
    myFile.close();
    Serial.println("...done!");
    //Finished retrieving char names
   }


  //Show Loading Screen with Version # for debug purposes


  //Display Singles Screen


//Define functions


//Read SD card to collect char and player names >> Load into memory



void loop(){
  //AKA Main()


//if singlesScreen >>

}

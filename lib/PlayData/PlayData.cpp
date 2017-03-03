#include <Arduino.h>
#include <PlayData.h>
#include <SD.h>
#include <SPI.h>

#define CSpin 10
const char *PNAMES = {"names.txt"};
const char *CNAMES = {"chars.txt"};


//initialize variables
char playerNames[166];

//Initializing objects
File myFile;
//PlayData::PlayData(const char *p1, const char *p2, const char *c1, const char *c2){
PlayData::PlayData(int p1, int p2, int c1, int c2){
  //Read SD Card and retrive data
  //formula for parsing data

  //Initialize SD card!
  Serial.print("PlayData -- Initializing SD card...");
  if(!SD.begin(CSpin)){
    Serial.println("Initialization failed!");
    return;
  }
  Serial.println("...Initialization done.");

   myFile = SD.open(PNAMES, FILE_READ);  //PNAMES defined above for ease change
   if (myFile){
     Serial.print("Reading names.txt...");
     while (myFile.available() > 0){
      for (unsigned int i = 0; i < myFile.size();i++){
        playerNames[i] = char(myFile.read());
      }

     }
     myFile.close();
     Serial.println("...done!");
   }
   for(int i = 0;i < 90; i++){
     Serial.print(playerNames[i]);
   }
   Serial.println();
}

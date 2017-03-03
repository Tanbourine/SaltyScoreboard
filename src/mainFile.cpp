#include <Arduino.h>
//#include <PlayData.h>
#include <TimerThing.h>
#include <SD.h>
#include <SPI.h>

#define CS_PIN 10
//Declare objects and variables
int a;
int P1 = 1;
int P2 = 2;
int C1 = 4;
int C2 = 6;
const char *PNAMES = {"names.txt"};
const char *CNAMES = {"chars.txt"};
char inRead[91]; //Create container for names
//char *playerNames[] = {"asdfjkl;asdfjkl;asdfjkl;asdfjkl;asdfjkl;asdfjkl;asdfjkl;asdfjkl;asdfjkl;asdfjkl;0"};
//char playerNames[91];
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


    myFile = SD.open(PNAMES, FILE_READ);  //PNAMES defined above for ease change
    if (myFile){
      Serial.print("Reading names.txt...");
    //  while (myFile.available() > 0){
      for (unsigned int i = 0; i < myFile.size();i++){
        inRead[i] = char(myFile.read());
        if (inRead[i] == '\n'){
          inRead[i] = '0'; //add null termination for char array
          for(unsigned int j = 0;j < i; j++){
            Serial.print(inRead[j]);
            //*playerNames[j] = inRead[j];
          }
          break;
        }
      }
     }
     myFile.close();
     Serial.println("...done!");
   }


  //Show Loading Screen with Version # for debug purposes

  //Retrieve Character and Name Index and save into local memory

  //Display Singles Screen


//Define functions


//Read SD card to collect char and player names >> Load into memory



void loop(){
  //AKA Main()

//if statements to check button preses
for(int i = 0;i < 90; i++){
  if (inRead[i] == '0'){
    Serial.println();
    break; 
  }
  Serial.print(inRead[i]);
}
//Serial.println();
delay(2000);


//if singlesScreen >>

}

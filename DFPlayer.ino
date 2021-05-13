/*
 * myDFPlayer.begin(DFPlayerSerial)
 * myDFPlayer.volume(volume); 0-30
 * myDFPlayer.play(); 
 * myDFPlayer.play(5);  Reproduce el archivo 0005
 * myDFPlayer.next();
 * myDFPlayer.previous();
 * myDFPlayer.pause();
 * myDFPlayer.start();
 * myDFPlayer.randomAll();
 * myDFPlayer.enableLoop();
 * myDFPlayer.disableLoop();
 */


#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"


const int BUTTON = 2;
const int threshold = 200;
volatile int lastTime = 0;
volatile bool nextSong = false;

SoftwareSerial DFPlayerSerial(10,11);   //Rx, Tx
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(9600);
  DFPlayerSerial.begin(9600);
  myDFPlayer.begin(DFPlayerSerial);
  myDFPlayer.volume(15);   //De 0 a 30
  myDFPlayer.randomAll();

  pinMode(BUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonPressed, RISING);
}

void loop() {
  if(nextSong == true){
    //myDFPlayer.next();
    //myDFPlayer.enableLoopAll();
    //myDFPlayer.enableLoop();
    myDFPlayer.randomAll();
    nextSong = false;
  }
  
  delay(1000);
}

void buttonPressed(){
  if((millis() - lastTime) > threshold){
    nextSong = true;
    lastTime = millis();
  }
}

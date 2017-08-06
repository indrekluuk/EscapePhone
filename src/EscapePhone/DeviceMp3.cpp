//
// Created by indrek on 21.07.2017.
//

#include "DeviceMp3.h"



DeviceMp3::DeviceMp3(uint8_t pinRx, uint8_t pinTx) : softwareSerial(pinRx, pinTx) {
  softwareSerial.begin(9600);

  if (!player.begin(softwareSerial)) {  //Use softwareSerial to communicate with mp3.
    // mp3 int failed
  }
  player.volume(10);  //Set volume value. From 0 to 30
  player.play(1);
  player.stop();
}



void DeviceMp3::play() {
  if (!isPlaying) {
    player.next();
    isPlaying = true;
  }
}


void DeviceMp3::stop() {
  if (isPlaying) {
    player.stop();
    isPlaying = false;
  }
}


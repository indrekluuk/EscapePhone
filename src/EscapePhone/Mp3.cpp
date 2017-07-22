//
// Created by indrek on 21.07.2017.
//

#include "Mp3.h"



Mp3::Mp3(uint8_t pinRx, uint8_t pinTx) : softwareSerial(pinRx, pinTx) {
  softwareSerial.begin(9600);

  if (!player.begin(softwareSerial)) {  //Use softwareSerial to communicate with mp3.
    // mp3 int failed
  }
  player.volume(10);  //Set volume value. From 0 to 30
  player.play(1);
  player.stop();
}



void Mp3::play() {
  if (!isPlaying) {
    player.next();
    player.next(); // ignore hidden file.
    isPlaying = true;
  }
}


void Mp3::stop() {
  if (isPlaying) {
    player.stop();
    isPlaying = false;
  }
}

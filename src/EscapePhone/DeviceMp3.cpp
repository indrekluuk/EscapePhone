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
}



void DeviceMp3::play(Mp3 mp3) {
  if (playing != mp3) {
    if (mp3 == MP3_NONE) {
      player.stop();
    } else {
      player.play(mp3);
    }
    playing = mp3;
  }
}


bool DeviceMp3::isPlaying() {
  return !player.available();
}


void DeviceMp3::stop() {
  play(MP3_NONE);
}


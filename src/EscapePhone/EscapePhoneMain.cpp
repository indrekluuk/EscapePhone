//
// Created by indrek on 21.07.2017.
//

#include "EscapePhoneMain.h"
#include "Arduino.h"




EscapePhoneMain::EscapePhoneMain() {
  Serial.begin(9600);
}



void EscapePhoneMain::run() {
  currentSate = &stateFactory.getHangUp();

  while(true) {
    currentSate = &currentSate->processState();

    if (devices.getHangUp().isHangUp()) {
      devices.getMp3().play();
    } else {
      devices.getMp3().stop();
    }


    if (devices.getHangUp().isHangUp()) {
      //ringer.ring();
    } else {
      //ringer.stop();
    }

    if (devices.getDial().getDialedNumber().isNumberDialed()) {
      Serial.println(devices.getDial().getDialedNumber().getDialedNumber());
      devices.getDial().getDialedNumber().reset();
    }


    devices.getRinger().process();
    devices.getDial().process();
  }
}





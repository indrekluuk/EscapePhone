//
// Created by indrek on 21.07.2017.
//

#include "EscapePhoneMain.h"
#include "Arduino.h"




EscapePhoneMain::EscapePhoneMain() {
  Serial.begin(9600);
}



void EscapePhoneMain::run() {
  currentSate = &stateFactory.initHangUpState();

  while(true) {
    currentSate = &currentSate->process();
    devices.process();
  }
}





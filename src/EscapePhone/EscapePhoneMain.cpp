//
// Created by indrek on 21.07.2017.
//

#include "EscapePhoneMain.h"
#include "Arduino.h"




EscapePhoneMain::EscapePhoneMain() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}



void EscapePhoneMain::run() {
  currentSate = &stateFactory.initHangUpState();

  Timer blink(1000);
  blink.start();
  bool blinkStatus = true;

  while(true) {
    currentSate = &currentSate->process();
    devices.process();

    if (blink.isReady()) {
      digitalWrite(13, blinkStatus);
      blinkStatus = !blinkStatus;
      blink.start();
    }
  }
}





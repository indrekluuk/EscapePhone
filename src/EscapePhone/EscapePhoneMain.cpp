//
// Created by indrek on 21.07.2017.
//

#include "EscapePhoneMain.h"

#include "Arduino.h"




EscapePhoneMain::EscapePhoneMain() {
  digitalWrite(PIN_HANG_UP, HIGH);
  Serial.begin(9600);
}




void EscapePhoneMain::run() {
  while(true) {

    if (isHangUp()) {
      mp3.play();
    } else {
      mp3.stop();
    }


    if (isHangUp()) {
      //ringer.ring();
    } else {
      //ringer.stop();
    }

    if (dial.getDialedNumber().isNumberDialed()) {
      Serial.println(dial.getDialedNumber().getDialedNumber());
      dial.getDialedNumber().reset();
    }


    ringer.process();
    dial.process();
  }
}



bool EscapePhoneMain::isHangUp() {
  return digitalRead(PIN_HANG_UP);
}




//
// Created by indrek on 21.07.2017.
//

#include "EscapePhoneMain.h"

#include "Arduino.h"



void EscapePhoneMain::run() {

  delay(5000);


  ringer.ring();
  while(true) {
    ringer.process();
  }
}





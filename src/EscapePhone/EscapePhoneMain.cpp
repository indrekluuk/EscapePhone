//
// Created by indrek on 21.07.2017.
//

#include "EscapePhoneMain.h"

#include "Arduino.h"




EscapePhoneMain::EscapePhoneMain() {
  digitalWrite(PIN_HANG_UP, HIGH);
}




void EscapePhoneMain::run() {

  while(true) {

    if (isHangUp()) {
      mp3.stop();
    } else {
      mp3.play();
    }

    /*
    if (isHangUp()) {
      ringer.ring();
    } else {
      ringer.stop();
    }
     */

    ringer.process();
  }


}





bool EscapePhoneMain::isHangUp() {
return digitalRead(PIN_HANG_UP);
}




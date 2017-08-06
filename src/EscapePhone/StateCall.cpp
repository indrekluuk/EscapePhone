//
// Created by indrek on 6.08.2017.
//

#include "StateCall.h"
#include "StateFactory.h"



void StateCall::setMp3(DeviceMp3::Mp3 mp3) {
  playMp3 = mp3;
}


StateBase & StateCall::processState() {
  if (devices.getHangUp().isHangUp()) {
    return stateFactory.getHangUpState();
  }

  devices.getMp3().play(playMp3);

  return *this;
}




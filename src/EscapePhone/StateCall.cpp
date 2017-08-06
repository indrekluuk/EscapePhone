//
// Created by indrek on 6.08.2017.
//

#include "StateCall.h"
#include "StateFactory.h"



void StateCall::init(DeviceMp3::Mp3 mp3) {
  devices.getMp3().play(mp3);
}


StateBase & StateCall::process() {
  if (devices.getHangUp().isHangUp()) {
    return stateFactory.initHangUpState();
  }

  return *this;
}




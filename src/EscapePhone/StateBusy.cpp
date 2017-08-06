//
// Created by indrek on 6.08.2017.
//

#include "StateBusy.h"
#include "StateFactory.h"



void StateBusy::init() {
  devices.getMp3().play(DeviceMp3::MP3_BUSY_TONE);
}


StateBase & StateBusy::process() {
  if (devices.getHangUp().isHangUp()) {
    return stateFactory.initHangUpState();
  }
  return *this;
}


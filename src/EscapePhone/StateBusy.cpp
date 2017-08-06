//
// Created by indrek on 6.08.2017.
//

#include "StateBusy.h"
#include "StateFactory.h"



StateBase & StateBusy::processState() {
  if (devices.getHangUp().isHangUp()) {
    return stateFactory.getHangUpState();
  }

  devices.getMp3().play(DeviceMp3::MP3_BUSY_TONE);

  return *this;
}


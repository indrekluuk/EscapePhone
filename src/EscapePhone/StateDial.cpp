//
// Created by indrek on 6.08.2017.
//

#include "StateDial.h"
#include "StateFactory.h"




void StateDial::reset() {
  devices.getDial().getDialedNumber().reset();
}


StateBase & StateDial::processState() {
  if (devices.getHangUp().isHangUp()) {
    return stateFactory.getHangUpState();
  }

  if (devices.getDial().getDialedNumber().isNumberDialed()) {
    return phoneBook.getStateForNumber(devices.getDial().getDialedNumber());
  } else if (devices.getDial().isDialInProgress()) {
    devices.getMp3().stop();
  } else {
    devices.getMp3().play(DeviceMp3::MP3_DIAL_TONE);
  }

  return *this;
}




//
// Created by indrek on 6.08.2017.
//

#include "StateDial.h"
#include "StateFactory.h"




void StateDial::init() {
  devices.getDial().getDialedNumber().reset();
  devices.getMp3().play(DeviceMp3::MP3_DIAL_TONE);
  dialTimeout.start();
}


StateBase & StateDial::process() {
  if (devices.getHangUp().isHangUp()) {
    return stateFactory.initHangUpState();
  }

  if (devices.getDial().getDialedNumber().isNumberDialed()) {
    return phoneBook.getStateForNumber(devices.getDial().getDialedNumber());
  } else if (devices.getDial().isDialInProgress()) {
    devices.getMp3().stop();
  } else if (dialTimeout.isReady()) {
    return stateFactory.initBusyState();
  }

  return *this;
}




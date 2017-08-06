//
// Created by indrek on 6.08.2017.
//

#include "StateFactory.h"






StateHangUp & StateFactory::initHangUpState() {
  stateHangUp.init();
  return stateHangUp;
}


StateDial & StateFactory::initDialState() {
  stateDial.init();
  return stateDial;
}

StateBusy & StateFactory::initBusyState() {
  stateBusy.init();
  return stateBusy;
}

StateCall & StateFactory::initCallState(DeviceMp3::Mp3 mp3) {
  stateCall.init(mp3);
  return stateCall;
}



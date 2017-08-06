//
// Created by indrek on 6.08.2017.
//

#include "StateFactory.h"






StateHangUp & StateFactory::getHangUpState() {
  return stateHangUp;
}


StateDial & StateFactory::getDialState() {
  stateDial.reset();
  return stateDial;
}

StateBusy & StateFactory::getBusyState() {
  return stateBusy;
}

StateCall & StateFactory::getCallState(DeviceMp3::Mp3 mp3) {
  stateCall.setMp3(mp3);
  return stateCall;
}



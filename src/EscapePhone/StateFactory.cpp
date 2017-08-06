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


StateRinging & StateFactory::initRingingState(DeviceMp3::Mp3 mp3) {
  stateRinging.init(mp3);
  return stateRinging;
}


void StateFactory::setCallBack(uint32_t time_sec, DeviceMp3::Mp3 mp3) {
  callBackTime = time_sec;
  callBackMp3 = mp3;
}


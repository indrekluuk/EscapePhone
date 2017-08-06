//
// Created by indrek on 6.08.2017.
//

#include "StateHangUp.h"
#include "StateFactory.h"



void StateHangUp::init() {
  devices.getMp3().stop();

  if (stateFactory.callBackTime > 0) {
    callbackTimer.set(stateFactory.callBackTime);
    callbackTimer.start();
  } else {
    callbackTimer.stop();
  }
}


StateBase & StateHangUp::process() {
  if (devices.getHangUp().isHangUp()) {

    if (callbackTimer.isReady()) {
      return stateFactory.initRingingState(stateFactory.callBackMp3);
    }

    return *this;
  } else {
    return stateFactory.initDialState();
  }
}




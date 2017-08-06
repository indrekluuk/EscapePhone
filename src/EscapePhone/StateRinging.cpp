//
// Created by indrek on 6.08.2017.
//

#include "StateRinging.h"
#include "StateFactory.h"



void StateRinging::init(DeviceMp3::Mp3 mp3) {
  callMp3 = mp3;
  devices.getRinger().ring();
  giveUpTimer.start();
}


StateBase & StateRinging::process() {
  if (devices.getHangUp().isHangUp()) {
    if (giveUpTimer.isReady()) {
      devices.getRinger().stop();
      return stateFactory.initHangUpState();
    }
    return *this;
  } else {
    devices.getRinger().stop();
    stateFactory.setCallBack(0, DeviceMp3::MP3_NONE);
    return stateFactory.initCallState(callMp3);
  }
}




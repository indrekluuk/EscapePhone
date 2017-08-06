//
// Created by indrek on 6.08.2017.
//

#include "StateHangUp.h"
#include "StateFactory.h"


StateBase & StateHangUp::processState() {
  devices.getMp3().stop();
  if (devices.getHangUp().isHangUp()) {
    return *this;
  } else {
    return stateFactory.getDialState();
  }
}




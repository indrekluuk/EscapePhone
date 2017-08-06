//
// Created by indrek on 6.08.2017.
//

#include "StateHangUp.h"
#include "StateFactory.h"



void StateHangUp::init() {
  devices.getMp3().stop();
}


StateBase & StateHangUp::process() {
  if (devices.getHangUp().isHangUp()) {
    return *this;
  } else {
    return stateFactory.initDialState();
  }
}




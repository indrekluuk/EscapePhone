//
// Created by indrek on 6.08.2017.
//

#include "StateFactory.h"






StateHangUp & StateFactory::getHangUpState() {
  return hangUpState;
}


StateDial & StateFactory::getDialState() {
  dialState.reset();
  return dialState;
}

StateBusy & StateFactory::getBusyState() {
  return busyState;
}


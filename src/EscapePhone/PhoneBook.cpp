//
// Created by indrek on 6.08.2017.
//

#include "PhoneBook.h"
#include "StateFactory.h"



StateBase & PhoneBook::getStateForNumber(DeviceDialedNumber & dialedNumber) {
  if (dialedNumber.isNumber("112") || dialedNumber.isNumber("911") || dialedNumber.isNumber("999")) {
    return stateFactory.initCallState(DeviceMp3::MP3_NEW_EMERGENCY_SERVICES);
  } else {
    return stateFactory.initBusyState();
  }
}




//
// Created by indrek on 6.08.2017.
//

#include "DeviceDialedNumber.h"




DeviceDialedNumber::DeviceDialedNumber() {
  reset();
}


void DeviceDialedNumber::reset() {
  dialedNumber[0] = 0;
  dialEndTimer.stop();
}



void DeviceDialedNumber::addNumber(uint8_t number) {
  if (!dialEndTimer.isRunning() || !dialEndTimer.isReady()) {
    uint8_t length = getNumberLength(dialedNumber);
    if (length < MAX_NUMBER_LENGTH) {
      dialedNumber[length] = '0' + number;
      dialedNumber[length + 1] = 0;
    }
  }
}


void DeviceDialedNumber::resetDialEndTimer() {
  dialEndTimer.start();
}


bool DeviceDialedNumber::isNumberDialed() {
  return dialEndTimer.isReady();
}


const char * DeviceDialedNumber::getDialedNumber() {
  return dialedNumber;
}


bool DeviceDialedNumber::isNumber(const char * checkNumber) {
  uint8_t dialedNumberLength = getNumberLength(dialedNumber);
  uint8_t checkNumberLength = getNumberLength(checkNumber);

  if (dialedNumberLength != checkNumberLength) {
    return false;
  }

  for (uint8_t i=0; i<dialedNumberLength; i++) {
    if (dialedNumber[i] != checkNumber[i]) {
      return false;
    }
  }
  return true;
}




uint8_t DeviceDialedNumber::getNumberLength(const char * n) {
  uint8_t length = 0;
  while(n[length] != 0) {
    length++;
  }
  return length;
}





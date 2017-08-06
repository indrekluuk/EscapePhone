//
// Created by indrek on 22.07.2017.
//

#include "Dial.h"
#include "Arduino.h"









void Dial::process() {
  switch (getDialPinStatus()) {
    case DIAL_NONE:
      break;
    case DIAL_FALLING:
      dialEndTimer.stop();
      break;
    case DIAL_RISING:
      dialEndTimer.start();
      risingEdgeCount++;
      break;
  }

  if (dialEndTimer.isReady()) {
    dialEndTimer.stop();
    if (risingEdgeCount > 1) {
      addNumber(risingEdgeCount == 11 ? 0 : (risingEdgeCount - 1));
    }
    risingEdgeCount = 0;
  }

  if (pinStatus == 0) {
    dialedNumber.resetDialEndTimer();
  }
}



Dial::Edge Dial::getDialPinStatus() {
  Dial::Edge edge = DIAL_NONE;

  int8_t currentPinStatus = digitalRead(dialPin);
  if (currentPinStatus != pinStatus) {
    if (!pulseEdgeTimer.isRunning()) {
      pulseEdgeTimer.start();
    }
    if (pulseEdgeTimer.isReady()) {
      if (currentPinStatus < pinStatus) {
        edge = DIAL_FALLING;
      } else if (currentPinStatus > pinStatus) {
        edge = DIAL_RISING;
      }
      pinStatus = currentPinStatus;
    }
  } else {
    pulseEdgeTimer.stop();
  }

  return edge;
}




void Dial::addNumber(uint8_t n) {
  dialedNumber.addNumber(n);
}




DialedNumber & Dial::getDialedNumber() {
  return dialedNumber;
}




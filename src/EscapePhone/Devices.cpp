//
// Created by indrek on 6.08.2017.
//

#include "Devices.h"



DeviceMp3 & Devices::getMp3() {
  return mp3;
}


DeviceRinger & Devices::getRinger() {
  return ringer;
}


DeviceHangUp & Devices::getHangUp() {
  return hangUp;
}


DeviceDial & Devices::getDial() {
  return dial;
}



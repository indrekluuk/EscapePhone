//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_DEVICES_H
#define ESCAPEPHONE_DEVICES_H


#include "stdint.h"
#include "DeviceMp3.h"
#include "DeviceRinger.h"
#include "DeviceDial.h"
#include "DeviceHangUp.h"


class Devices {

    static const uint8_t PIN_MP3_TX = 2;
    static const uint8_t PIN_MP3_RX = 3;
    static const uint8_t PIN_RING_1 = 6;
    static const uint8_t PIN_RING_2 = 7;
    static const uint8_t PIN_HANG_UP = 8;
    static const uint8_t PIN_DIAL = 9;


    DeviceMp3 mp3 = DeviceMp3(PIN_MP3_RX, PIN_MP3_TX);
    DeviceRinger ringer = DeviceRinger(PIN_RING_1, PIN_RING_2);
    DeviceHangUp hangUp = DeviceHangUp(PIN_HANG_UP);
    DeviceDial dial = DeviceDial(PIN_DIAL);


public:

    Devices();

    DeviceMp3 & getMp3();
    DeviceRinger & getRinger();
    DeviceHangUp & getHangUp();
    DeviceDial & getDial();

    void process();

};


#endif //ESCAPEPHONE_DEVICES_H

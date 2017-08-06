//
// Created by indrek on 22.07.2017.
//

#ifndef ESCAPEPHONE_DEVICEDIAL_H
#define ESCAPEPHONE_DEVICEDIAL_H

#include "stdint.h"
#include "Timer.h"
#include "DeviceDialedNumber.h"


class DeviceDial {

    enum Edge {
        DIAL_FALLING,
        DIAL_RISING,
        DIAL_NONE
    };


    static const uint32_t DIAL_PULSE_EDGE_ms = 15;
    static const uint32_t DIAL_END_ms = 150;



    uint8_t dialPin;
    int8_t pinStatus = 1;
    uint8_t risingEdgeCount = 0;
    Timer pulseEdgeTimer = Timer(DIAL_PULSE_EDGE_ms);
    Timer dialEndTimer = Timer(DIAL_END_ms);

    DeviceDialedNumber dialedNumber;

public:

    DeviceDial(uint8_t pin) : dialPin(pin) {}
    void process();
    bool isDialInProgress();
    DeviceDialedNumber & getDialedNumber();



private:
    Edge getDialPinStatus();
    void addNumber(uint8_t n);


};


#endif //ESCAPEPHONE_DEVICEDIAL_H

//
// Created by indrek on 22.07.2017.
//

#ifndef ESCAPEPHONE_DIAL_H
#define ESCAPEPHONE_DIAL_H

#include "stdint.h"
#include "Timer.h"
#include "DialedNumber.h"


class Dial {

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

    DialedNumber dialedNumber;

public:

    Dial(uint8_t pin) : dialPin(pin) {}
    void process();
    DialedNumber & getDialedNumber();


private:
    Edge getDialPinStatus();
    void addNumber(uint8_t n);


};


#endif //ESCAPEPHONE_DIAL_H

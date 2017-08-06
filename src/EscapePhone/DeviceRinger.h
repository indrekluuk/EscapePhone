//
// Created by indrek on 21.07.2017.
//

#ifndef ESCAPEPHONE_DEVICERINGER_H
#define ESCAPEPHONE_DEVICERINGER_H

#include <stdint.h>
#include "Timer.h"


class DeviceRinger {
    static const uint32_t RING_TIME_ms = 2000;
    static const uint32_t PAUSE_TIME_ms = 4000;
    static const uint32_t HIT_INTERVAL_ms = 30;
    static const uint32_t HIT_DURATION_ms = 15;


    uint8_t ringerPin1;
    uint8_t ringerPin2;

    bool isRinging = false;
    bool hitDirection = false;
    Timer ringTimer = Timer(RING_TIME_ms);
    Timer pauseTimer = Timer(PAUSE_TIME_ms);
    Timer hitInterval = Timer(HIT_INTERVAL_ms);
    Timer hitDuration = Timer(HIT_DURATION_ms);

public:
    DeviceRinger(uint8_t pin1, uint8_t pin2);

    void ring();
    void stop();

    void process();

private:
    void ringerOff();
    void processRing();

};


#endif //ESCAPEPHONE_DEVICERINGER_H

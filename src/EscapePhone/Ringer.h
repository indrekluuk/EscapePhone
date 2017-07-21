//
// Created by indrek on 21.07.2017.
//

#ifndef ESCAPEPHONE_RINGER_H
#define ESCAPEPHONE_RINGER_H

#include <stdint.h>


class Ringer {
    static const uint32_t PAUSE_TIME_ms = 4000;
    static const uint32_t RING_TIME_ms = 2000;

    static const uint32_t HIT_TIME_ms = 20;
    static const uint32_t RING_PERIOD_ms = 60;


    uint8_t ringerPin1;
    uint8_t ringerPin2;

    uint32_t timer = 0;
    bool isPause = false;

public:
    Ringer(uint8_t pin1, uint8_t pin2);

    void ring();
    void stop();

    void process();

private:
    bool processPause(uint32_t time);
    bool processRing(uint32_t time);

};


#endif //ESCAPEPHONE_RINGER_H

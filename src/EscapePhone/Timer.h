//
// Created by indrek on 22.07.2017.
//

#ifndef ESCAPEPHONE_TIMER_H
#define ESCAPEPHONE_TIMER_H

#include "stdint.h"



class Timer {


    uint32_t time : 31;
    uint32_t ready : 1;
    uint32_t endTime;

public:
    Timer(uint32_t timerTime) {
      time = timerTime;
      ready = true;
    };

    bool isReady();
    void start();


};


#endif //ESCAPEPHONE_TIMER_H

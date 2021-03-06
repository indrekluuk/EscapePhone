//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATEHANGUP_H
#define ESCAPEPHONE_STATEHANGUP_H


#include "StateBase.h"
#include "Timer.h"


class StateHangUp : public StateBase {


    Timer callbackTimer = Timer(0);


public:
    StateHangUp(StateFactory & stateFactory, Devices & devices)
        : StateBase(stateFactory, devices) {};


    void init();
    StateBase & process() override;


};


#endif //ESCAPEPHONE_STATEHANGUP_H

//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATEHANGUP_H
#define ESCAPEPHONE_STATEHANGUP_H


#include "StateBase.h"


class StateHangUp : public StateBase {


public:
    StateHangUp(StateFactory & stateFactory, Devices & devices)
        : StateBase(stateFactory, devices) {};


    StateBase & processState() override;


};


#endif //ESCAPEPHONE_STATEHANGUP_H

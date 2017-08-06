//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATEFACTORY_H
#define ESCAPEPHONE_STATEFACTORY_H


#include "Devices.h"
#include "StateHangUp.h"
#include "StateDial.h"


class StateFactory {


    Devices & devices;
    StateHangUp hangUpState;
    StateDial dialState;



public:
    StateFactory(Devices & devices) :
        devices(devices),
        hangUpState(*this, devices),
        dialState(*this, devices)
    {}


    StateHangUp & getHangUpState();
    StateDial & getDialState();



};


#endif //ESCAPEPHONE_STATEFACTORY_H

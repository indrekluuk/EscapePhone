//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATEFACTORY_H
#define ESCAPEPHONE_STATEFACTORY_H


#include "Devices.h"
#include "StateHangUp.h"
#include "StateDial.h"
#include "StateBusy.h"
#include "StateCall.h"


class StateFactory {


    Devices & devices;
    StateHangUp stateHangUp;
    StateDial stateDial;
    StateBusy stateBusy;
    StateCall stateCall;



public:
    StateFactory(Devices & devices) :
        devices(devices),
        stateHangUp(*this, devices),
        stateDial(*this, devices),
        stateBusy(*this, devices),
        stateCall(*this, devices)
    {}


    StateHangUp & initHangUpState();
    StateDial & initDialState();
    StateBusy & initBusyState();
    StateCall & initCallState(DeviceMp3::Mp3 mp3);




};


#endif //ESCAPEPHONE_STATEFACTORY_H

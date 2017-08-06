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
#include "StateRinging.h"


class StateFactory {


    Devices & devices;
    StateHangUp stateHangUp;
    StateDial stateDial;
    StateBusy stateBusy;
    StateCall stateCall;
    StateRinging stateRinging;




public:
    uint32_t callBackTime = 0;
    DeviceMp3::Mp3 callBackMp3 = DeviceMp3::MP3_NONE;


    StateFactory(Devices & devices) :
        devices(devices),
        stateHangUp(*this, devices),
        stateDial(*this, devices),
        stateBusy(*this, devices),
        stateCall(*this, devices),
        stateRinging(*this, devices)
    {}


    StateHangUp & initHangUpState();
    StateDial & initDialState();
    StateBusy & initBusyState();
    StateCall & initCallState(DeviceMp3::Mp3 mp3);
    StateRinging & initRingingState(DeviceMp3::Mp3 mp3);

    void setCallBack(uint32_t time_sec, DeviceMp3::Mp3 mp3);




};


#endif //ESCAPEPHONE_STATEFACTORY_H

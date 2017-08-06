//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATEBUSY_H
#define ESCAPEPHONE_STATEBUSY_H

#include "StateBase.h"


class StateBusy : public StateBase {


public:
    StateBusy(StateFactory & stateFactory, Devices & devices)
        : StateBase(stateFactory, devices) {};

    StateBase & processState() override;

};


#endif //ESCAPEPHONE_STATEBUSY_H

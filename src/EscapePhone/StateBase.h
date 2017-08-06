//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATEBASE_H
#define ESCAPEPHONE_STATEBASE_H



class StateFactory;
class Devices;


class StateBase {

protected:
    StateFactory & stateFactory;
    Devices & devices;

public:
    StateBase(StateFactory & stateFactory, Devices & devices)
        : stateFactory(stateFactory), devices(devices) {};

    virtual StateBase & process() = 0;

};


#endif //ESCAPEPHONE_STATEBASE_H

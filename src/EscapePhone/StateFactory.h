//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATEFACTORY_H
#define ESCAPEPHONE_STATEFACTORY_H


#include "StateHangUp.h"



class StateFactory {


    StateHangUp hangUp;


public:


    StateHangUp & getHangUp();



};


#endif //ESCAPEPHONE_STATEFACTORY_H

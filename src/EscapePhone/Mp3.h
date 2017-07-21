//
// Created by indrek on 21.07.2017.
//

#ifndef ESCAPEPHONE_MP3_H
#define ESCAPEPHONE_MP3_H


#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"



class Mp3 {


    SoftwareSerial softwareSerial;
    DFRobotDFPlayerMini player;

    bool isPlaying = false;

public:
    Mp3(uint8_t pinRx, uint8_t pinTx);

    void play();
    void stop();

};


#endif //ESCAPEPHONE_MP3_H

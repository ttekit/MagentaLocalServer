//
// Created by tekit on 11/21/2023.
//

#ifndef MAGENTASERV_SWITCHMANAGER_H
#define MAGENTASERV_SWITCHMANAGER_H

#include "SwitchControl.h"

class SwitchManager {
private:
    SwitchControl *switchList[10];
    int switchCount;

public:
    SwitchManager() : switchCount(0) {}

    void addSwitch(int pin, String pathOn, String pathOff, String pathState, WiFiServer &server);

    void beginAll(WiFiServer &server);

    void handleClients(WiFiServer &server);
};


#endif //MAGENTASERV_SWITCHMANAGER_H

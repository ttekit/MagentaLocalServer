//
// Created by tekit on 11/21/2023.
//

#ifndef MAGENTASERV_SWITCHCONTROL_H
#define MAGENTASERV_SWITCHCONTROL_H

#include <WiFi.h>

class SwitchControl {
private:
    int pin;
    String pathOn;
    String pathOff;
    String pathState;
    WiFiServer *server;

public:
    SwitchControl(int p, String on, String off, String state, WiFiServer &srv);
    void handleClient(WiFiClient *client);
    String getState();
    void turnOn();
    void turnOff();
};



#endif //MAGENTASERV_SWITCHCONTROL_H

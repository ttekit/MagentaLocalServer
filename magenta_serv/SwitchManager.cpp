//
// Created by tekit on 11/21/2023.
//

#include "SwitchManager.h"

void SwitchManager::addSwitch(int pin, String pathOn, String pathOff, String pathState, WiFiServer &server) {
    if (switchCount < sizeof(switchList) / sizeof(switchList[0])) {
        switchList[switchCount] = new SwitchControl(pin, pathOn, pathOff, pathState, server);
        switchCount++;
    } else {
        Serial.println("Max number of switches reached. Cannot add more.");
    }
}

void SwitchManager::beginAll(WiFiServer &server) {
    for (int i = 0; i < switchCount; i++) {
        WiFiClient client = server.available();
        if (client) {
            switchList[i]->handleClient(&client);
        }
    }
}

void SwitchManager::handleClients(WiFiServer &server) {
    WiFiClient client = server.available();
    if (client) {
        for (int i = 0; i < switchCount; i++) {
            switchList[i]->handleClient(&client);
        }
    }
}
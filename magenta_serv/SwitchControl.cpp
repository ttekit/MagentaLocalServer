//
// Created by tekit on 11/21/2023.
//

#include "SwitchControl.h"

SwitchControl::SwitchControl(int p, String on, String off, String state, WiFiServer &srv)
        : pin(p), pathOn(on), pathOff(off), pathState(state), server(&srv) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

String SwitchControl::handleClient(String link) {
    String response = "";
    if (link.indexOf(pathOn) != -1) {
        turnOn();
        Serial.println("Action: ON");
        response = "on";
    } else if (link.indexOf(pathOff) != -1) {
        turnOff();
        Serial.println("Action: OFF");
        response = "off";
    } else {
        response = getState();
    }
    return response;
}

String SwitchControl::getState() {
    return digitalRead(pin) == HIGH ? "on" : "off";
}

void SwitchControl::turnOn() {
    digitalWrite(pin, HIGH);
}

void SwitchControl::turnOff() {
    digitalWrite(pin, LOW);
}

String SwitchControl::PathOn() {
    return pathOn;
}
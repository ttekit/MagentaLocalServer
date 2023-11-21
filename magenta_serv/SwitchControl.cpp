//
// Created by tekit on 11/21/2023.
//

#include "SwitchControl.h"

SwitchControl::SwitchControl(int p, String on, String off, String state, WiFiServer &srv)
        : pin(p), pathOn(on), pathOff(off), pathState(state), server(&srv) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void SwitchControl::handleClient(WiFiClient *client) {
    // Check if there is a client connected
    if (!client || !client->connected()) return;

    // Read the client's request
    String request = client->readStringUntil('\r');
    client->flush();
    client->println("HTTP/1.1 200 OK");
    client->println("Content-Type: application/json");

    String response;
    if (request.indexOf(pathOn) != -1) {
        turnOn();
        response = "{\"status\":\"on\"}";
    } else if (request.indexOf(pathOff) != -1) {
        turnOff();
        response = "{\"status\":\"off\"}";
    } else {
        response = "{\"status\":\"" + "getState()" + "\"}";
    }

    // Send the HTTP response headers
    client->println("HTTP/1.1 200 OK");
    client->println("Content-Type: application/json");
    client->println("Connection: close");
    client->println("Access-Control-Allow-Origin: *");
    client->println();

    client->println(response);

    Serial.println("Request received:");
    Serial.println(request);
    Serial.println("Response sent:");
    Serial.println(response);

    client->stop();
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
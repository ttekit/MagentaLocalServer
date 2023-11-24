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
    handleClients(server);
}

void SwitchManager::handleClients(WiFiServer &server) {
    WiFiClient client = server.available();
    if (client) {
        String currentLine = "";
        String response = "";
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();
                Serial.write(c);
                currentLine += c;

                if (currentLine.endsWith("\n")) {
                    String request = currentLine;
                    int slashIndex = request.indexOf('/', request.indexOf('/') + 1);
                    String controller = request.substring(request.indexOf('/') + 1, slashIndex);
                    Serial.println("Controller: " + controller);
                    Serial.println("URL: " + request);
                    for (int i = 0; i < switchCount; i++) {
                        if (switchList[i]->PathOn().indexOf(controller) != -1) {
                            response = switchList[i]->handleClient(currentLine);
                            break;
                        }
                    }
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: application/json");
                    client.println("Connection: close");
                    client.println("Access-Control-Allow-Origin: *");
                    client.println();
                    client.println(response);
                    break;
                }
            }
        }
        client.stop();
    }
}
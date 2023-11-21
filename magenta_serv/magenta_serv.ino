#include <Arduino.h>
#include "SwitchControl.h"
#include "SwitchManager.h"

const char* ssid = "ASUS";
const char* password = "34307077";

WiFiServer server(80);

SwitchManager switchManager;

void setup() {
    Serial.begin(115200);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    server.begin();

    // Adding switches
    switchManager.addSwitch(5, "/switch1/on", "/switch1/off", "/switch1/state", server);
    switchManager.addSwitch(4, "/switch2/on", "/switch2/off", "/switch2/state", server);
    switchManager.addSwitch(2, "/switch3/on", "/switch3/off", "/switch3/state", server);
    switchManager.addSwitch(15, "/switch4/on", "/switch4/off", "/switch4/state", server);

    switchManager.beginAll(server);
}

void loop() {
    switchManager.handleClients(server);
    delay(100);
}

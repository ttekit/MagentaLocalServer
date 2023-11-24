# MagentaLocalServer: An ESP32 Server for Project MAGENTA
The MagentaLocalServer is an ESP32-based server designed specifically for Project MAGENTA. To set up this system, you'll need to purchase the [ESP32 microcontroller](https://rozetka.com.ua/ua/392229477/p392229477/?gad_source=1&gclid=CjwKCAiAjfyqBhAsEiwA-UdzJIEiiKFLnRaxWSjVDkKj9XkDKw73bivocHei5bVkdFm7e8C5qA5L-BoCJvcQAvD_BwE), download the Arduino IDE, and follow the steps to load the code onto the ESP32.
Once your server is up and running, adding a new device is simple. Just use the following command:
```
switchManager.addSwitch(PIN, ONLINK, OFFLINK, STATELINK, server);
```
Replace PIN with the pin number of the device, ONLINK and OFFLINK with the respective links for turning the device on and off, STATELINK with the link to check the device's state, and server with the server reference.

After loading this configuration, you can control the device by using the provided links to turn it on or off remotely. To integrate the newly added device into voice control using MAGENTA, follow the MAGENTA setup instructions.

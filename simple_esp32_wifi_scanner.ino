#include <WiFi.h>

void setup() {
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);

    int networks = WiFi.scanNetworks();

    for (int i = 0; i < networks; i++) {
        Serial.print(WiFi.SSID(i));
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        Serial.println(" dBm)");
    }
}

void loop() {

}
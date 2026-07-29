#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Open-drain verification test");
  
  Serial0.begin(1000000, SERIAL_8N1, D7, D6);
  pinMode(D6, OUTPUT_OPEN_DRAIN);
  pinMode(D7, INPUT);
  delay(100);
  
  // Manually drive D6 LOW for 3 seconds, measure data line with multimeter
  Serial.println("Driving D6 LOW for 5 seconds...");
  Serial.println("PROBE THE DATA LINE WITH MULTIMETER NOW");
  digitalWrite(D6, LOW);
  delay(5000);
  
  // Now release D6 (high Z via open-drain)
  Serial.println("Releasing D6 (high-Z)...");
  Serial.println("Probe data line again - should jump back to ~3V");
  digitalWrite(D6, HIGH);
  delay(5000);
  
  Serial.println("Done.");
}

void loop() {}
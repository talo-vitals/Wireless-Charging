#include <Arduino.h>

// ================== CONFIGURATION ==================

const int CURRENT_SENSOR_PIN = 34;   
const int RELAY_PIN          = 26;   

bool charging = false;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);     
  
  Serial.println("\n=== Wireless Charger Started ===");
  Serial.println("Relay ON - Ready for charging\n");
}

void loop() {
  // Read current with averaging
  float raw = 0;
  for (int i = 0; i < 80; i++) {
    raw += analogRead(CURRENT_SENSOR_PIN);
    delay(2);
}
  raw = raw / 80.0; // Average of 80 readings

  float current_mA = (((raw * (5000.0 / 4095.0)) - 2500.0) / 0.185);

  // Control relay 
  if (current_mA > 3800) {
    digitalWrite(RELAY_PIN, HIGH);
    if (!charging) {
      Serial.println(">>> POWER DETECTED -  CHARGING STARTED");
      charging = true;
    }
  } else {
    digitalWrite(RELAY_PIN, LOW);
    if (charging) {
      Serial.println(">>> POWER REMOVED- CHARGING OFF");
      charging = false;
    }
  }
  
  //  Status print
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 800) {
    Serial.printf("Current: %.0f mA | Relay: %s\n", current_mA, charging ? "ON" : "OFF");
    lastPrint = millis();
  }

  delay(100);
}

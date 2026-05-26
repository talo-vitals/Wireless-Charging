 # Wireless Charger Project

ESP32 project for a wireless charging demo with a 1.8" touchscreen, a 5V relay module, and an ACS712 current sensor.

## Hardware connections

Relay module:
- `VCC` → 5V supply
- `GND` → common ground with ESP32
- `IN` → GPIO 26
- `COM` → 5V supply
- `NO` → ACS712 `+` terminal
- `NC` → not connected (or optional)

> The relay switches the 5V power to the transmitter through the ACS712 current sensor. When the relay is ON, power flows from 5V supply → COM → NO → ACS712 + → transmitter 5V.

> The ACS712 measures current by placing the transmitter’s 5V feed through its high-current path. Do not connect both transmitter wires directly to 5V and ground; the transmitter’s positive feed must pass through the ACS712 terminals.

## Summary wiring table

| Component | Pin | Connects to |
|---|---|---|
| Relay VCC | VCC | 5V supply |
| Relay GND | GND | common ground |
| Relay IN | IN | ESP32 GPIO 26 |
| Relay COM | COM | 5V supply |
| Relay NO | NO | ACS712 `+` terminal |
| Relay NC | NC | not connected |
| ACS712 VCC | VCC | 5V supply |
| ACS712 GND | GND | common ground |
| ACS712 OUT | OUT | ESP32 GPIO 34 |
| ACS712 + | + | Relay NO |
| ACS712 - | - | Transmitter 5V |
| Transmitter 5V | 5V | ACS712 `-` terminal |
| Transmitter GND | GND | common ground |
| TFT CS | CS | ESP32 GPIO 5 |
| TFT DC | DC | ESP32 GPIO 16 |
| TFT RST | RST | ESP32 GPIO 17 |
| TFT MOSI | MOSI | ESP32 GPIO 23 |
| TFT SCK | SCK | ESP32 GPIO 18 |
| Touch XP | XP | ESP32 GPIO 32 |
| Touch XM | XM | ESP32 GPIO 33 |
| Touch YP | YP | ESP32 GPIO 25 |
| Touch YM | YM | ESP32 GPIO 27 |

## Transmitter wiring details

- The wireless charger transmitter has two wires: positive (+) and negative (-).
- Connect the **positive (+) wire** from the transmitter to the **ACS712 `-` terminal**.
- Connect the **negative (-) wire** from the transmitter to **common ground**.

> This setup allows the ACS712 to measure the current flowing to the transmitter. Do not connect the transmitter directly to 5V and ground; the positive wire must pass through the ACS712.
// ================== CONFIGURATION ==================

const int CURRENT_SENSOR_PIN = 34;   // ACS712 OUT
const int RELAY_PIN          = 26;   // Relay control pin

bool charging = false;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);     //  Start with relay ON
  
  Serial.println("\n=== Wireless Charger Starting ===");
  Serial.println("Waiting for phone... \n");
}

void loop() {
  // Read current with averaging
  float raw = 0;
  for (int i = 0; i < 80; i++) {
    raw += analogRead(CURRENT_PIN);
    delay(2);
  }

  raw = raw / 80.0;  // Average of 80 samples

  float volatage = raw * (5000.0 / 4095.0); // Convert ADC value to voltage
  float current_mA = (voltage - 2500.0) / 0.185;




  // Automatic relay control
  if (current_mA > 3800) {
      digitalWrite(RELAY_PIN, HIGH);
      if (!charging) {}
      Serial.println(">>> POWER DETECTED -  CHARGING STARTED");
      charging = true;


    }
  }  else {
    digitalWrite(RELAY_PIN, LOW);
    if (charging) {
      Serial.println(">>> POWER REMOVED- CHARGING STOPPED");
      charging = false;
    }
  }
  
  // Print status
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 800) {
    Serial.printf("Current: %.0f mA | Relay: %s\n", current_mA, charging ? "ON" : "OFF");
    lastPrint = millis();
  }

  delay(100);
}



## Notes

- The ESP32, relay module, ACS712 sensor, and transmitter must share a common ground.
- Use a stable 5V supply for the relay module, ACS712, and wireless transmitter.
- The touchscreen is calibrated at startup and can be recalibrated from the UI.

# Wiring Diagram

## ESP32 Connections

| Component              | ESP32 Pin | Notes                    |
|------------------------|-----------|--------------------------|
| ACS712 Current Sensor  | 5V        | VCC                      |
| ACS712 Current Sensor  | GND       | GND                      |
| ACS712 Current Sensor  | GPIO34    | OUT (Analog)             |
| Relay Module           | 5V        | VCC                      |
| Relay Module           | GND       | GND                      |
| Relay Module           | GPIO26    | IN (Control)             |

## Power Supply
- 5V 5A Power Supply → Wireless Charging Transmitter VCC
- All GND connected together

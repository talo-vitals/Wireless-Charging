 # Wireless Charger Project

ESP32 project for a wireless charging (FUTURE demo with a 1.8" touchscreen), a 5V relay module, and an ACS712 current sensor.

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

# Smart Wireless Charger

IoT wireless charging system with automatic power control using current sensing and ESP32.

## Overview
This project demonstrates wireless power transfer with intelligent power management. The system detects when a device is placed on the charging pad using a current sensor and automatically activates the wireless transmitter only when needed, improving efficiency and safety.

## Components Used

| Category       | Component                          | Description                                      |
|----------------|------------------------------------|--------------------------------------------------|
| Microcontroller| ESP32 Dev Board with Touch Screen  | Main controller, WiFi, and user interface        |
| Sensor         | ACS712 5A Current Sensor           | Detects presence of device being charged         |
| Power Control  | 5V Relay Module                    | Switches power to the wireless transmitter       |
| Wireless Power | Qi-compatible 5V 2A Modules        | Wireless power transmitter and receiver          |
| Power Supply   | 5V 5A Switching Power Supply       | Main power source for the system                 |

## Features
- Automatic device detection
- Power saving relay control
- Live current monitoring on TFT screen
- Web interface for remote monitoring
- Real-time charging status display

## Build Notes
The project is built using PlatformIO in VS Code. The ESP32 uses the TFT_eSPI library to drive the touch screen and a simple web server to provide remote status monitoring.


## Notes

- The ESP32, relay module, ACS712 sensor, and transmitter must share a common ground.
- Use a stable 5V supply for the relay module, ACS712, and wireless transmitter.
- The touchscreen is calibrated at startup and can be recalibrated from the UI.

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

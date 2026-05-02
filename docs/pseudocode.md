# Pseudocode - Smart Wireless Charger

## System Overview
The system automatically detects when a device is placed on the charging pad and controls power to the wireless transmitter using current sensing.

## Main Logic

| Step | Action                                      | Condition                          |
|------|---------------------------------------------|------------------------------------|
| 1    | Connect to WiFi and initialise display      | On startup                         |
| 2    | Read current from ACS712 sensor             | Every 500ms                        |
| 3    | Apply moving average filter                 | Last 5 readings                    |
| 4    | Turn relay ON                               | Current > 0.4A                     |
| 5    | Display "CHARGING" + current value          | When charging                      |
| 6    | Turn relay OFF                              | Current < 0.2A for 3 readings      |
| 7    | Display "STANDBY"                           | When not charging                  |
| 8    | Update web interface                        | Real-time status                   |

## Future Improvements
- Add timeout after 30 minutes of inactivity
- Add temperature monitoring of the coil
- Data logging to SD card

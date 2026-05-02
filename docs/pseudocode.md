#Pseudocode - Wireless Charger

## System Overview
The system detects when a device is placedon a charging pad using cureent sensing and automatically power to the transmitter coil.

## main Logic

Connect to WIFI and initialise display + web server
Continuosly read current from AC712 sensor
Apply moving average filter to reduce noise 
If current > 0.4A -> Turn relay ON, show "Charging Active" on screen 
If current < 0.2A for 3 consecutive readings -> Turn relay OFF, show "STANDBY"
Update web interface whit live current and status 
Auto power-off after 30 minutes of inactivity 

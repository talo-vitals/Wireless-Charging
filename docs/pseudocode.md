Connect to WIFI
Initilize TFT display and web server
Read current from ACS712 every 500ms
Calculate moving average to filter noise
If current > 0.4A -> Turn relay ON + display "CHARGING"
If current < 0.2A for 3 readings -> Turn relay OFF + display "STANDBY"
Update web page with live current and status
Auto time out after 30 minutes 

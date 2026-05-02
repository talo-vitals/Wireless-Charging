# Pseudocode: Smart Wireless Charger

// Wireless Charger with Current Sensing and Automatic Control

DEFINE CURRENT_SENSOR_PIN as 34
DEFINE RELAY_PIN as 26
DEFINE CHARGING_THRESHOLD as 0.4
DEFINE STANDBY_THRESHOLD as 0.2

DEFINE currentReading as 0
DEFINE movingAverage as 0
DEFINE isCharging as FALSE

FUNCTION setup
    INITIALISE WiFi connection
    INITIALISE TFT display
    INITIALISE web server
    SET RELAY_PIN as OUTPUT
    SET RELAY_PIN to LOW
    PRINT "Wireless Charger Ready"
END FUNCTION

FUNCTION loop
    READ current from CURRENT_SENSOR_PIN
    CALCULATE movingAverage of last 5 readings
    
    IF movingAverage > CHARGING_THRESHOLD THEN
        SET RELAY_PIN to HIGH
        SET isCharging to TRUE
        UPDATE display with "CHARGING" and current value
    ELSE IF movingAverage < STANDBY_THRESHOLD FOR 3 readings THEN
        SET RELAY_PIN to LOW
        SET isCharging to FALSE
        UPDATE display with "STANDBY"
    END IF
    
    UPDATE web interface with live data
    WAIT 500 milliseconds
END FUNCTION
  

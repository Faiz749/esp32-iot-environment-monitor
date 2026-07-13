# Day 4: WiFi Web Dashboard and System Check

## Project Description

On Day 4, I upgraded the ESP32 IoT Environment Monitor by adding WiFi connectivity, a local web dashboard, Serial Monitor diagnostics, OLED display logic, LED and buzzer alert systems, and a simple `/status` endpoint.

The system reads temperature and humidity data from a DHT11 sensor and light conditions from a digital LDR module. The ESP32 displays the readings through the Serial Monitor, the local web dashboard, and the OLED display logic.

The LED is controlled according to the room’s light level, while the buzzer is activated when the temperature or humidity exceeds the configured threshold values.

The hardware was tested and responded correctly. The DHT11 sensor, LDR module, LED, buzzer, Serial Monitor, and web dashboard are working as expected.

The OLED display is currently unsoldered, so physical OLED testing will be completed after soldering.

Calibration will be carried out using readings from different rooms before the final temperature, humidity, and light threshold values are selected.

---

## Components Used

* ESP32 38-pin development board
* DHT11 temperature and humidity sensor
* Digital LDR light sensor module
* 0.96-inch I2C OLED display
* LED
* Buzzer
* Breadboard
* Jumper wires
* USB cable
* WiFi network

---

## Features Completed

* DHT11 temperature reading
* DHT11 humidity reading
* DHT11 error handling using `isnan()`
* Digital LDR reading
* Light-condition detection:

  * `0 = BRIGHT`
  * `1 = DARK`
* LED control based on the LDR status
* Buzzer control based on temperature and humidity conditions
* Serial Monitor dashboard
* Serial Monitor system check
* OLED display logic
* OLED system-summary logic
* WiFi connectivity
* Local web dashboard
* Web dashboard system check
* Plain-text `/status` endpoint
* Device uptime display on the web dashboard

---

## Mistakes Fixed and Lessons Learned

* Learned that the DHT11 and LDR statuses should be handled separately.
* A DHT11 error affects the temperature, humidity, and buzzer logic.
* The LDR can continue controlling the LED even when the DHT11 sensor fails.
* Added system-check logic that can display multiple active issues at the same time.
* Added separate system-check functions for the Serial Monitor and web dashboard.
* Learned that the information shown on the web dashboard must match the actual hardware-control logic.
* Added brackets to the buzzer-status logic on the web dashboard to prevent incorrect evaluation of `&&` and `||` conditions.
* Added a `/status` endpoint for quickly checking the device status.
* Added the OLED code, but physical testing is still pending because the display has not yet been soldered.

---

## Current Status

Day 4 software development is complete for now.

The hardware is responding correctly, except for the OLED display, which still needs to be soldered and tested.

Calibration and final threshold tuning will be completed after collecting readings from different rooms. The updated values will then be included before the final project push.

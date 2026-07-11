# Day 2: OLED, Alerts, and Hardware Test

## Project Description

This is Day 2 of my ESP32 IoT Environment Monitor project.

In this session, I upgraded the project by adding an OLED dashboard, LED alert logic, and buzzer alert logic. I also tested the hardware setup and confirmed that the connected components were working.

The ESP32 now reads values from the DHT11 sensor and digital LDR module, checks if the DHT11 reading is valid, prints system data on the Serial Monitor, displays important information on the OLED screen, and controls the LED/buzzer outputs based on simple conditions.

Real calibration was not finalized today. The threshold functions are included in the code, but the actual threshold values will be adjusted after taking real room readings in the next session.

## Components Used

* ESP32 38-pin board
* DHT11 temperature and humidity sensor
* Digital LDR module
* 0.96 inch I2C OLED display
* LED
* Buzzer
* 220Ω resistor
* Breadboard
* Jumper wires
* USB cable

## Wiring Flow

DHT11:

```text
VCC → 3.3V
GND → GND
DATA → GPIO 4
```

Digital LDR Module:

```text
VCC → 3.3V
GND → GND
DO → GPIO 34
```

OLED Display:

```text
VCC → 3.3V
GND → GND
SDA → GPIO 21
SCL → GPIO 22
```

LED:

```text
GPIO 2 → 220Ω or 330Ω resistor → LED positive leg
LED negative leg → GND
```

Buzzer:

```text
Buzzer positive leg → GPIO 5
Buzzer negative leg → GND
```

## Concepts Practiced

* Initializing and using an OLED display with the Adafruit SSD1306 library
* Displaying sensor information on an OLED screen
* Showing different OLED output for normal and failed DHT11 readings
* Reading temperature and humidity using the DHT11 sensor
* Checking failed DHT11 readings using `isnan()`
* Reading digital light status using `digitalRead()`
* Controlling an LED based on light status
* Controlling a buzzer based on temperature and humidity status
* Using `millis()` for timed execution
* Organizing the project using separate functions

## Progress

### Completed Today

* Added OLED display support
* Added an OLED initialization function
* Created an OLED dashboard function
* Added LED alert control logic
* Added buzzer alert control logic
* Kept DHT11 and LDR reading logic working
* Kept Serial Monitor output in the code
* Tested the hardware setup
* Took a hardware picture as proof

### Remaining for Next Session

* Take a Serial Monitor screenshot
* Take an OLED output photo
* Take real temperature and humidity readings
* Finalize real threshold values after calibration
* Add WiFi connection
* Print the ESP32 IP address
* Add a basic web server
* Show sensor readings on a browser

## Alert Logic

The LED and buzzer are controlled using simple logic for now.

Light logic:

```text
Light Status: DARK   → LED ON
Light Status: BRIGHT → LED OFF
```

Climate alert logic:

```text
Temperature/Humidity above threshold → Buzzer ON
Normal temperature/humidity          → Buzzer OFF
```

The exact threshold values will be finalized after real calibration.

## Notes

Real calibration was not completed today. The main goal was to make sure the OLED, LED, buzzer, DHT11, and LDR could work together in the same project.

The threshold functions are already included, but the real values will be updated after testing the system in normal room conditions.

## Mistakes Fixed

* I tested the hardware step by step instead of assuming everything would work together immediately.
* I kept the OLED output simple so the text could fit properly on the 128x64 display.
* I made sure failed DHT11 readings are handled instead of printing invalid values.
* I kept Serial Monitor output in the code so debugging remains easier.
* I understood that calibration should be based on real sensor readings, not guessed values.

## Demo

A hardware setup photo is included in this folder.

Hardware photo file:

```text
day-02-hardware-test-photo.jpeg
```

Serial Monitor screenshot and OLED output photo will be added in the next session.

## Embedded Systems Relevance

This day focused on moving from simple sensor reading to a more complete embedded system structure.

The ESP32 is now reading sensors, checking sensor status, controlling output devices, and showing information on an OLED dashboard.

This is important because real embedded systems usually combine inputs, outputs, displays, status logic, and debugging together instead of working as separate small tests.

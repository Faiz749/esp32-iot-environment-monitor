# Day 1: DHT11 + LDR Base Reader

## Project Description

This is Day 1 of my ESP32 IoT Environment Monitor project.

Today, I worked on the base code for reading temperature, humidity, and light status using a DHT11 sensor and a digital LDR module. The hardware readings have not been tested yet. The main focus was setting up clean code structure, sensor reading logic, error checking, and Serial Monitor output.

Hardware wiring and real sensor testing will be done in the next session.

## Concepts Practiced

* Reading temperature and humidity using a DHT11 sensor
* Checking failed DHT11 readings using `isnan()`
* Reading digital light status using `digitalRead()`
* Creating readable status labels
* Using `millis()` for timed execution
* Organizing code with separate functions
* Printing clean output to the Serial Monitor

## Progress

### Completed Today

* Wrote the base DHT11 reading logic
* Added DHT11 error checking using `isnan()`
* Added digital LDR reading logic
* Created a light status function
* Added a Serial Monitor output function
* Used `millis()` for basic timing
* Improved the code structure with separate functions

### Remaining for Tomorrow

* Wire the DHT11 sensor
* Wire the LDR module
* Test real temperature and humidity readings
* Confirm the LDR `0` and `1` behavior
* Take a Serial Monitor screenshot
* Take a wiring photo if needed

## Mistakes Fixed

* Fixed an issue where the code was reading DHT11 values too frequently while only printing output every 2 seconds. The sensor reading now follows proper timing logic.
* Fixed a spelling mistake from `therashold` to `threshold`.
* Moved helper functions below the main logic to make the code easier to read.

## Current Status

The Day 1 code structure is ready.

Hardware testing is still pending and will be completed in the next session.

## Embedded Systems Relevance

This project connects to embedded systems because it focuses on reading sensor data, handling failed readings, and displaying system information clearly. These are important basics for building reliable monitoring and automation systems.

Instead of only printing raw values, the code also prepares readable sensor status messages. This will be useful in the next stages of the ESP32 IoT Environment Monitor.

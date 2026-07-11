# Day 3: WiFi Web Dashboard

## Project Description

This is Day 3 of my ESP32 IoT Environment Monitor project.

In this session, I added WiFi connectivity and a basic local web dashboard. The ESP32 can now connect to a WiFi network, print its IP address in the Serial Monitor, and display the latest sensor and system status data on a webpage.

The project now includes DHT11 temperature and humidity readings, LDR light detection, Serial Monitor output, an OLED dashboard, LED alert logic, buzzer alert logic, WiFi connectivity, and a basic web server.

The main goal for today was to make the ESP32 accessible through a browser connected to the same WiFi network. The webpage is intentionally simple and focuses on displaying useful system information clearly.

The final calibration values have not been determined yet. Threshold functions are already included in the code, but the actual values will be adjusted after collecting real room readings.

## Components Used

* ESP32 38-pin development board
* DHT11 temperature and humidity sensor
* Digital LDR module
* 0.96-inch I2C OLED display
* LED
* Buzzer
* 220Ω or 330Ω resistor
* Breadboard
* Jumper wires
* USB cable
* WiFi network

## Concepts Practiced

* Connecting the ESP32 to WiFi
* Printing the ESP32 IP address in the Serial Monitor
* Starting a local web server using `WiFiServer`
* Handling browser requests using `WiFiClient`
* Sending a basic HTML response from the ESP32
* Displaying sensor values on a webpage
* Storing the latest sensor readings in global variables
* Keeping the Serial Monitor, OLED, LED, buzzer, and web server working together
* Using `millis()` for timed sensor updates
* Separating sensor-reading logic from display and web-output logic

## Progress

### Completed Today

* Added WiFi library support
* Added a WiFi connection function
* Printed the ESP32 IP address in the Serial Monitor
* Added a local web server on port 80
* Created a basic browser dashboard
* Displayed the sensor status on the webpage
* Displayed temperature and humidity when the DHT11 status is `OK`
* Displayed a DHT11 failure message when the sensor status is `ERROR`
* Displayed the light status on the webpage
* Displayed the LED alert status on the webpage
* Displayed the buzzer alert status on the webpage
* Displayed the system uptime in seconds
* Kept the OLED and Serial Monitor output working alongside the web server

### Remaining for the Next Session

* Take real room temperature and humidity readings
* Finalize threshold values after calibration
* Take a screenshot of the Serial Monitor
* Take a screenshot of the web dashboard
* Take a photo of the OLED output, if needed
* Improve the webpage structure, if required
* Add a `/status` endpoint later
* Keep WiFi credentials hidden before pushing the project to GitHub

## Mistakes Fixed and Lessons Learned

I learned that the ESP32 IP address should not be stored as a floating-point value.

I also learned that the IP address can be printed directly using `WiFi.localIP()`.

I kept the WiFi connection messages separate from the repeated sensor dashboard output.

I added the IP address to the Serial Monitor output so the webpage is easier to access during testing.

I used global variables so the web server can display the latest sensor values without reading the sensors again for every browser request.

I learned that the alert status displayed on the webpage should match the actual LED and buzzer logic.

I kept the webpage simple instead of adding too many features too early.

## Notes

The webpage is intentionally simple at this stage.

The main goal was to confirm that the ESP32 can host a local webpage and display project data in a browser.

WiFi credentials should never be pushed to GitHub. Before uploading the project, the real WiFi network name and password should be replaced with placeholders or moved to a separate configuration file that is excluded from version control.

The pins on my OLED display are not soldered, and I currently do not have access to soldering equipment. As a result, the OLED connection is unstable, and I have to hold the pins in place for the display to work properly.

## Embedded Systems Relevance

This session was important because the project progressed from local hardware output to network-based monitoring.

The ESP32 is now not only reading sensors and controlling outputs, but also sharing system data over WiFi through a local webpage.

This is an important embedded IoT skill because many real-world monitoring systems must collect sensor data, process it locally, and make it available to users through a simple interface.

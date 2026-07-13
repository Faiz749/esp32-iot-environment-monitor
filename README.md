# ESP32 IoT Environment Monitor

## Project Overview

This project is an ESP32-based IoT Environment Monitor that reads temperature, humidity, and light conditions using a DHT11 sensor and a digital LDR module.

The system displays live readings on the Serial Monitor, OLED display, and a local web dashboard hosted by the ESP32. It also controls an LED and buzzer based on environmental conditions.

This project was built as part of my embedded systems learning roadmap to practice sensor interfacing, hardware control, error handling, WiFi communication, web dashboards, system-state logic, and calibration-based engineering decisions.

---

## Features

* DHT11 temperature reading
* DHT11 humidity reading
* DHT11 error handling using `isnan()`
* Digital LDR light detection
* LED alert for dark-room conditions
* Buzzer alert for temperature and humidity warnings
* OLED dashboard
* OLED system summary
* Serial Monitor dashboard
* Serial Monitor system check
* ESP32 WiFi connection
* Local web dashboard
* Web dashboard system check
* Plain-text `/status` endpoint
* Device uptime display
* Threshold calibration using real room readings
* Hardware photo, screenshots, and demo video proof

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

## Pin Connections

| Component          | ESP32 Pin |
| ------------------ | --------- |
| DHT11 Data         | GPIO 4    |
| Digital LDR Output | GPIO 34   |
| LED                | GPIO 2    |
| Buzzer             | GPIO 5    |
| OLED SDA           | GPIO 21   |
| OLED SCL           | GPIO 22   |

---

## Required Libraries

* DHT sensor library
* Adafruit Unified Sensor
* Adafruit GFX
* Adafruit SSD1306
* WiFi library

---

## Final Thresholds

| Measurement | Condition          | Status  |
| ----------- | ------------------ | ------- |
| Temperature | Below 32°C         | SAFE    |
| Temperature | 32°C to below 35°C | WARNING |
| Temperature | 35°C and above     | DANGER  |
| Humidity    | Below 30%          | DRY     |
| Humidity    | 30% to below 70%   | SAFE    |
| Humidity    | 70% and above      | HUMID   |

---

## Alert Logic

* The LED turns ON when the room is dark.
* The buzzer turns ON for temperature warnings, danger conditions, or high humidity.
* The buzzer remains OFF when DHT11 readings are invalid.
* The LDR and LED continue working independently if the DHT11 fails.

---

## How to Run

1. Connect the components using the pin table.
2. Install the required Arduino libraries.
3. Open `05-calibration-final-testing/main.ino`.
4. Add your WiFi name and password.
5. Select the correct ESP32 board and port.
6. Upload the code.
7. Open the Serial Monitor at `115200` baud.
8. Copy the ESP32 IP address shown in the Serial Monitor.
9. Open the IP address in a browser to view the dashboard.
10. Add `/status` to the IP address to view the plain-text status endpoint.

---

## Demo and Results

* [Hardware circuit photo](05-calibration-final-testing/hardware-circuit-working.jpeg)
* [Demo video](05-calibration-final-testing/hardware-demo-video.mp4)
* [Serial Monitor output](05-calibration-final-testing/serial-monitor-output.png)
* [Web dashboard](05-calibration-final-testing/web-dashboard-output.png)
* [Status endpoint](05-calibration-final-testing/status-endpoint-output.png)

---

## Limitations

* The DHT11 has limited accuracy and a slow response time.
* The digital LDR provides only DARK or BRIGHT output.
* The dashboard is available only on the local WiFi network.
* WiFi credentials are entered in the source code during testing and should be replaced with placeholders before pushing to GitHub.

---

## Learning Outcomes

This project provided practical experience with sensor interfacing, I2C displays, digital outputs, ESP32 WiFi, local web servers, error handling, system-state logic, calibration, and hardware testing.

---

## Project Folder Structure

```text
esp32-iot-environment-monitor/
│
├── 01-dht11-ldr-base-reader/
│   ├── main.ino
│   └── README-1.md
│
├── 02-oled-alert-hardware-test/
│   ├── main.ino
│   └── README-2.md
│
├── 03-wifi-web-dashboard/
│   ├── main.ino
│   └── README-3.md
│
├── 04-software-integration-hardware-test/
│   ├── main.ino
│   └── README-4.md
│
├── 05-calibration-final-testing/
│   ├── main.ino
│   ├── README-5.md
│   ├── hardware-circuit-working.jpeg
│   ├── hardware-demo-video.mp4
│   ├── serial-monitor-output.png
│   ├── web-dashboard-output.png
│   └── status-endpoint-output.png
│
└── README.md
```

---

## Project Status

The project is complete and tested with real hardware.

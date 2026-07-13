# Day 5: Calibration and Final Testing

## Project Description

On Day 5, I completed the final calibration and testing stage of the ESP32 IoT Environment Monitor.

I tested the complete system with real hardware, collected readings under different room conditions, adjusted the temperature and humidity thresholds, verified the Serial Monitor, checked the local web dashboard, tested the `/status` endpoint, and recorded final proof.

---

## Final Project Features

* DHT11 temperature and humidity readings
* DHT11 error handling using `isnan()`
* Digital LDR light detection
* LED alert for dark conditions
* Buzzer alert for temperature and humidity warnings
* Serial Monitor dashboard and system check
* OLED dashboard and system summary
* WiFi connection
* Local web dashboard
* Plain-text `/status` endpoint
* Device uptime display
* Calibration-based thresholds
* Hardware photo and demo proof

---

## Components Used

* ESP32 38-pin development board
* DHT11 sensor
* Digital LDR module
* 0.96-inch I2C OLED display
* LED
* Buzzer
* Breadboard
* Jumper wires
* USB cable
* WiFi network

---

## Final Pin Connections

| Component          | ESP32 Pin |
| ------------------ | --------- |
| DHT11 Data         | GPIO 4    |
| Digital LDR Output | GPIO 34   |
| LED                | GPIO 2    |
| Buzzer             | GPIO 5    |
| OLED SDA           | GPIO 21   |
| OLED SCL           | GPIO 22   |

---

## Calibration Summary

### Temperature Calibration

| Test Condition |       Reading | Result  |
| -------------- | ------------: | ------- |
| Cool AC room   |  22°C to 29°C | SAFE    |
| Warm room      |  32°C to 33°C | WARNING |
| High heat      | 35°C or above | DANGER  |

### Humidity Calibration

| Test Condition    |    Reading | Result |
| ----------------- | ---------: | ------ |
| Dry condition     |  Below 30% | DRY    |
| Normal room       | 45% to 63% | SAFE   |
| Closed humid room | Around 75% | HUMID  |

---

## Alert Logic

### LED Alert

The LED is controlled only by the digital LDR.

| Light Status | LED |
| ------------ | --- |
| DARK         | ON  |
| BRIGHT       | OFF |

The LDR and LED continue working even if the DHT11 fails.

### Buzzer Alert

The buzzer depends on valid DHT11 readings.

| Condition           | Buzzer |
| ------------------- | ------ |
| Temperature WARNING | ON     |
| Temperature DANGER  | ON     |
| Humidity HUMID      | ON     |
| Normal readings     | OFF    |
| DHT11 error         | OFF    |

---

## System Check Logic

The system check can show multiple active issues at the same time.

```text
System Check:
WARNING: Temperature is rising
WARNING: Humidity is high
WARNING: Room is dark
```

The full system check is shown on the Serial Monitor and web dashboard.

The OLED shows a short summary:

```text
SYS: NORMAL
SYS: WARNING
SYS: DANGER
SYS: ERROR
```

---

## Serial Monitor Output

The Serial Monitor shows:

* Sensor status
* System check
* Temperature and status
* Humidity and status
* LDR value
* Light status
* ESP32 IP address

Proof file:

```text
serial-monitor-output.png
```

---

## Web Dashboard

The ESP32 hosts a local web dashboard using `WiFiServer`.

```text
http://ESP32-IP-ADDRESS
```

The dashboard shows sensor readings, system status, LED and buzzer states, and device uptime.

Proof file:

```text
web-dashboard-output.png
```

---

## Status Endpoint

A plain-text `/status` endpoint provides a quick device status check.

```text
http://ESP32-IP-ADDRESS/status
```

Proof file:

```text
status-endpoint-output.png
```

---

## OLED Output

The OLED displays temperature, humidity, light status, and a short system summary.

---

## Final Demo Proof

```text
hardware-circuit-working.jpg
hardware-demo-video.mp4
serial-monitor-output.png
web-dashboard-output.png
status-endpoint-output.png
```

These files show the working circuit, Serial Monitor output, web dashboard, and `/status` endpoint.

---

## Mistakes Fixed and Lessons Learned

* Handled DHT11 and LDR status separately.
* Kept the buzzer OFF when DHT11 readings are invalid.
* Allowed the LDR to control the LED independently.
* Added support for multiple active warnings.
* Matched the web dashboard logic with the hardware logic.
* Fixed buzzer conditions using brackets with `&&` and `||`.
* Added a plain-text `/status` endpoint.
* Adjusted thresholds using real sensor readings.
* Learned the difference between a web dashboard and a status endpoint.

---

## Final Status

Day 5 calibration and final testing are complete.

The ESP32 IoT Environment Monitor now works with calibrated thresholds, hardware alerts, Serial Monitor diagnostics, OLED output, a WiFi web dashboard, and a `/status` endpoint.

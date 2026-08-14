# 🚦 Smart Traffic Light with Pedestrian Crossing (ESP32)

A smart traffic light system built using the ESP32 that simulates a real pedestrian crossing. The system cycles through Green, Yellow, and Red traffic lights automatically. When a pedestrian presses the button, the ESP32 stores the request and activates the walk signal during the red phase. A LOW-triggered passive buzzer provides an audible indication for pedestrians.

---

## Features

- Automatic traffic light sequence
- Pedestrian request button
- Walk indicator LED
- LOW-triggered passive buzzer
- Event-based pedestrian request handling
- Built using ESP32 GPIO

---

## Components Used

- ESP32 DevKit V1
- Breadboard
- 3 × LEDs (Red, Yellow, Green)
- 1 × Blue LED (Walk Signal)
- 4 × 330Ω Resistors
- Push Button
- LOW-triggered Passive Buzzer
- Jumper Wires

---

## Pin Connections

| Component | GPIO |
|-----------|------|
| Red LED | GPIO2 |
| Yellow LED | GPIO4 |
| Green LED | GPIO5 |
| Walk LED | GPIO18 |
| Push Button | GPIO19 |
| Passive Buzzer | GPIO21 |

---

## Working

1. The traffic lights cycle automatically.
2. Pressing the pedestrian button stores a crossing request.
3. The current traffic cycle continues safely.
4. During the red phase:
   - Walk LED turns ON.
   - Passive buzzer beeps for 5 seconds.
5. The system then resumes the normal traffic light sequence.

---

## Concepts Learned

- GPIO Input and Output
- INPUT_PULLUP
- HIGH vs LOW Logic
- LOW-triggered Passive Buzzer
- Functions
- Boolean Variables
- millis()
- digitalRead()
- digitalWrite()
- Event-driven Programming

---


## Challenges Faced

During development, the buzzer did not work as expected.

### Issue 1
Initially, we assumed the buzzer module was **HIGH-triggered**. After testing, we discovered it was actually **LOW-triggered**, meaning:

- LOW → Buzzer ON
- HIGH → Buzzer OFF

The buzzer control logic was updated accordingly.

### Issue 2
The pedestrian button worked during the Green and Yellow phases but did not respond during the Red phase. This happened because the program used a blocking `delay()`, which prevented the ESP32 from checking the button.

The solution was to replace the blocking delay with a `millis()`-based loop that continuously monitored the button during the red phase.

## Future Improvements

- OLED countdown timer
- Voice announcements
- LDR-based night mode
- IoT monitoring using Wi-Fi
- Emergency vehicle priority

---


## Author
**Nireeksha**
B.E. Computer Science Engineering (AI & ML)
Learning: Embedded Systems · ESP32 · Electronics · IoT
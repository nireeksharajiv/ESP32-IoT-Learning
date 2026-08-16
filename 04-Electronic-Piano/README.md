# 🎹 ESP32 Electronic Piano

A simple ESP32-based electronic piano that uses four push buttons to play four different musical notes through a buzzer. Each button is assigned to a different GPIO pin and frequency.

## Project Overview

This project demonstrates how an ESP32 can read multiple digital inputs and use them to control a buzzer.

Each push button represents one piano key:

* Button 1 → C4
* Button 2 → D4
* Button 3 → E4
* Button 4 → F4

The buttons use the ESP32's internal `INPUT_PULLUP`, so no external pull-up resistors are required.

## Components Used

* ESP32 38-Pin Development Board
* 4 × Push Buttons
* Passive Buzzer Module
* Breadboard
* Jumper Wires

## Pin Connections

### Push Buttons

| Button   | ESP32 GPIO | Note | Frequency |
| -------- | ---------: | ---- | --------: |
| Button 1 |    GPIO 19 | C4   |    262 Hz |
| Button 2 |    GPIO 18 | D4   |    294 Hz |
| Button 3 |    GPIO 14 | E4   |    330 Hz |
| Button 4 |    GPIO 13 | F4   |    349 Hz |

Each button is connected between its GPIO pin and GND.

```text
GPIO → Button → GND
```

The buttons use `INPUT_PULLUP`, so:

```text
Button released → HIGH
Button pressed  → LOW
```

### Buzzer

| Buzzer Pin | ESP32   |
| ---------- | ------- |
| I/O        | GPIO 23 |
| VCC        | 5V      |
| GND        | GND     |

## How It Works

When a button is pressed, the ESP32 detects the button as `LOW`.

The program then sends the corresponding frequency to the buzzer using `tone()`.

For example:

```text
Press Button 1
      ↓
GPIO 19 reads LOW
      ↓
262 Hz selected
      ↓
Buzzer plays C4
```

The four buttons produce:

```text
GPIO 19 → 262 Hz → C4
GPIO 18 → 294 Hz → D4
GPIO 14 → 330 Hz → E4
GPIO 13 → 349 Hz → F4
```

When no button is pressed, `noTone()` stops the buzzer.

**Signal flow:**

```text
Press button
     ↓
ESP32 detects LOW
     ↓
Corresponding frequency selected
     ↓
tone() generates the frequency
     ↓
Buzzer produces the note
```

## Concepts Learned

* Digital input
* GPIO pins
* `INPUT_PULLUP`
* `digitalRead()`
* `tone()`
* `noTone()`
* Passive buzzer
* Frequency and pitch
* Button-to-GPIO mapping
* Internal pull-up resistor
* Basic ESP32 input/output control

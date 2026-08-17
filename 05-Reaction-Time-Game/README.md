# 🎮 Reaction Time Game

An ESP32-based reaction game where three LEDs cycle continuously. After a random delay, the LEDs stop and the blue LED signals the player to press the button as quickly as possible. The reaction time is measured using `millis()`.

## Components Used

* ESP32 38-Pin Development Board
* 3 × LEDs (Red, Green, Blue)
* 3 × 330Ω Resistors
* 1 × Push Button
* Breadboard
* Jumper Wires

## Pin Connections

| Component    | ESP32 GPIO |
| ------------ | ---------: |
| 🔴 Red LED   |    GPIO 25 |
| 🟢 Green LED |    GPIO 26 |
| 🔵 Blue LED  |    GPIO 27 |
| 🔘 Button    |    GPIO 19 |

The LEDs use 330Ω resistors and the button uses the ESP32's internal `INPUT_PULLUP`.

## How It Works

```text
Press button
    ↓
🔴 → 🟢 → 🔵 continuously
    ↓
Random 2–5 second delay
    ↓
🔵 GO!
    ↓
Press button quickly
    ↓
Reaction time displayed
```

Example:

```text
Your reaction time: 287 ms
```

## Concepts Learned

* Digital input/output
* `INPUT_PULLUP`
* `millis()`
* Random delays
* LED control
* Push buttons
* Serial Monitor
* Basic game logic

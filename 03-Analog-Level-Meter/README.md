# 🎛️ Analog Level Meter

An ESP32-based analog level indicator that uses a potentiometer to control five LEDs. As the potentiometer is turned, the ESP32 reads the changing analog voltage and lights up the LEDs progressively.

## Project Overview

This project demonstrates how an ESP32 can read an analog signal and convert it into a simple visual level indicator.

The potentiometer produces a variable voltage between 0V and 3.3V. The ESP32 reads this voltage using its ADC and converts the reading into a value between approximately 0 and 4095.

Based on the value, between one and five LEDs are turned ON.

## Components Used

- ESP32 38-Pin Development Board
- 10K Potentiometer
- 5 × LEDs
- 5 × 330Ω Resistors
- Breadboard
- Jumper Wires

## Pin Connections

### Potentiometer

| Potentiometer Pin | ESP32 |
|---|---|
| Outer Pin | 3.3V |
| Middle Pin (Wiper) | GPIO 34 |
| Other Outer Pin | GND |

### LEDs

| LED | ESP32 GPIO | Resistor |
|---|---:|---:|
| LED 1 | GPIO 2 | 330Ω |
| LED 2 | GPIO 4 | 330Ω |
| LED 3 | GPIO 5 | 330Ω |
| LED 4 | GPIO 13 | 330Ω |
| LED 5 | GPIO 14 | 330Ω |

Each LED is connected through a 330Ω resistor, with its cathode connected to GND.

## How It Works

The potentiometer changes the voltage supplied to the ESP32's analog input.

The ESP32 reads this voltage using `analogRead()`.

The ADC reading is approximately:

```
0V    → 0
1.65V → 2048
3.3V  → 4095
```

The program divides this range into five levels:

```
Low level     → 1 LED
Higher level  → 2 LEDs
Higher level  → 3 LEDs
Higher level  → 4 LEDs
Maximum level → 5 LEDs
```

**Signal flow:**

```
Turn knob
    ↓
Potentiometer voltage changes
    ↓
ESP32 reads analog value
    ↓
Value is compared with thresholds
    ↓
Corresponding number of LEDs turn ON
```

## Concepts Learned

- Analog input
- ADC (Analog-to-Digital Conversion)
- `analogRead()`
- GPIO output
- Threshold-based logic
- Potentiometer operation
- Voltage measurement using a multimeter
- Basic sensor-style input processing
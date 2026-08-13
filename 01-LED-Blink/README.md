# LED Blink

## Objective
Blink an external LED connected to an ESP32 using GPIO2.

## Components Used
- ESP32 Dev Board (38-pin)
- Breadboard
- LED
- 220Ω Resistor
- Jumper Wires
- USB Cable

## Circuit Connections

| ESP32 | Component |
|-------|-----------|
| GPIO2 | 220Ω Resistor → LED Anode (+) |
| GND   | LED Cathode (-) |

## How It Works
The ESP32 turns GPIO2 HIGH for one second and LOW for one second, causing the LED to blink continuously.

## Folder Structure
```
01-LED-Blink/
├── README.md
├── LED_Blink.ino
├── circuit.jpg
└── blink_demo.mp4
```

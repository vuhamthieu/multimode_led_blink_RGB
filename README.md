# Multimode LED Blink RGB

This is a simple Arduino project demonstrating how to cycle through multiple LED colors using a push button. Each button press advances to the next color in the sequence: red, green, blue, and off.

## Hardware Requirements

- Arduino Uno (or compatible board)
- RGB LED (common cathode)
- 3 x 220Ω resistors
- 1 x push button
- Breadboard and jumper wires

## Wiring Diagram

| Arduino Pin | LED Color | Note        |
|-------------|-----------|-------------|
| 9           | Red       | 220Ω resistor in series |
| 10          | Green     | 220Ω resistor in series |
| 11          | Blue      | 220Ω resistor in series |
| 2           | Button    | Use with internal pull-up |

## Circuit Diagram

Here is the schematic for the RGB LED blinking project:

![Screenshot from 2025-05-18 22-56-13](https://github.com/user-attachments/assets/152e3ca0-d0d2-4f32-bf5e-7d20ad5bd7ee)

## How It Works

- The RGB LED is connected to three PWM-capable pins on the Arduino.
- The push button is configured with `INPUT_PULLUP`, so its default state is HIGH.
- When the button is pressed (logic LOW), the program switches to the next color.
- After cycling through red, green, and blue, the LED turns off and restarts the sequence.

## File

- `Led_blink_RGB.ino` – Main source code

## Notes

This project is designed for beginners to learn how to:
- Use digital I/O with push buttons
- Control RGB LEDs
- Implement simple state machines

Tested on Arduino Uno R3.

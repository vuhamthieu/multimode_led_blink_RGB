# Multimode LED Blink RGB

This is a simple Arduino project demonstrating how to cycle through multiple LED colors using a push button. Each button press advances to the next color in the sequence: red, green, blue,constant blink with 3 colors, fading and off.

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

![image](https://github.com/user-attachments/assets/a167fe3c-7b6c-4b7e-9884-89eceab36f10)


## How It Works

- The RGB LED is connected to three PWM-capable pins on the Arduino.
- The push button is configured with `INPUT_PULLUP`, so its default state is HIGH.
- When the button is pressed (logic LOW), the program switches to the next color.
- After cycling through red, green, blue, constantly blink with 3 colors mode, and fade light, the LED turns off and restarts the sequence.

## File

- `Led_blink_RGB.ino` – Main source code

## Notes

This project is designed for beginners to learn how to:
- Use digital I/O with push buttons
- Control RGB LEDs
- Implement simple state machines

Tested on Arduino Uno R3.

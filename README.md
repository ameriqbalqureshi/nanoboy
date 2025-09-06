# NanoBoy Library

NanoBoy is a tiny handheld console created by **Mikrotronics Pakistan** to make learning embedded systems programming playful and game-oriented.  
It is built around an Arduino Nano with:

- a 128×64 pixel OLED display (SSD1306 or SH1106),
- six input buttons (Up, Down, Left, Right, A, B),
- a user LED,
- and a piezo buzzer.

With the NanoBoy Library you can draw graphics, display text, read buttons, play sounds and build your own games with minimal wiring.

---

## Features

- Simple API for text, shapes, sprites and tile maps
- Input handling for six buttons
- LED and buzzer control
- Collision detection between sprites
- Built on Adafruit\_GFX and SSD1306/SH1106 drivers

---

## Hardware Overview

| Function | Arduino Nano Pin |
|----------|------------------|
| Button UP | D2 |
| Button DOWN | D3 |
| Button LEFT | D4 |
| Button RIGHT | D5 |
| Button A | D6 |
| Button B | D7 |
| LED | D8 |
| Buzzer | D9 |
| OLED SDA | A4 |
| OLED SCL | A5 |

**Power supply:** USB 5 V (or 7–12 V via VIN pin)

---

## Installation

1. Download the latest release ZIP from this repository.  
2. In the Arduino IDE go to **Sketch → Include Library → Add .ZIP Library…**  
3. Select the downloaded `NanoBoy.zip`.  
4. After installation, check under **File → Examples → NanoBoy** to see sample sketches.

---

## Selecting OLED Type

NanoBoy supports both SSD1306 (0.96") and SH1106 (1.3") OLEDs.  
Open `NanoBoy/src/NanoBoy.h` and at the top:

```cpp
// #define NANOboy_USE_SSD1306    // for 0.96" OLED
#define NANOboy_USE_SH1106       // for 1.3" OLED

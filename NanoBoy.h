#ifndef NANOboy_H
#define NANOboy_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define NANOboy_SCREEN_WIDTH 128
#define NANOboy_SCREEN_HEIGHT 64
#define NANOboy_OLED_RESET -1

// Default button pins
#define BTN_UP     2
#define BTN_DOWN   3
#define BTN_LEFT   4
#define BTN_RIGHT  5
#define BTN_A      6
#define BTN_B      7

// Sound pin
#define NANOboy_SPEAKER 9

class NanoBoy {
public:
    NanoBoy();

    void begin();
    void clear();
    void display();
    void printText(int16_t x, int16_t y, const char* text);

    // Input
    bool pressed(uint8_t button);

    // Sound
    void beep(uint16_t freq, uint16_t duration);

    // Access display directly if needed
    Adafruit_SSD1306 displayObj;

private:
    void initButtons();
};

#endif

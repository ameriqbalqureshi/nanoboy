#ifndef NANOboy_H
#define NANOboy_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Button & IO pin definitions
#define BTN_UP     2
#define BTN_DOWN   3
#define BTN_LEFT   4
#define BTN_RIGHT  5
#define BTN_A      6
#define BTN_B      7
#define LED_PIN    8
#define BUZZER_PIN 9

// Tile size for tile-based games
#define _T_SIZE 8

// Sprite structure
struct Sprite {
    int x, y;
    int w, h;
    const uint8_t* bitmap;  
    bool active;
};

class NanoBoy {
public:
    NanoBoy();

    void begin();

    // Display handling
    void clear();
    void display();

    // Text
    void setCursor(int x, int y);
    void print(const char* text);
    void print(int num);
    void print(float num);

    // Drawing
    void drawPixel(int x, int y, int color = SSD1306_WHITE);
    void drawLine(int x0, int y0, int x1, int y1, int color = SSD1306_WHITE);
    void drawRect(int x, int y, int w, int h, int color = SSD1306_WHITE);
    void fillRect(int x, int y, int w, int h, int color = SSD1306_WHITE);
    void drawCircle(int x, int y, int r, int color = SSD1306_WHITE);
    void fillCircle(int x, int y, int r, int color = SSD1306_WHITE);
    void drawBitmap(int x, int y, const uint8_t* bitmap, int w, int h, int color = SSD1306_WHITE);
    void drawText(int x, int y, const char* text);
    void drawText(int x, int y, String text);

    // Basic graphics passthrough
    // void drawLine(int x0, int y0, int x1, int y1, int color);
    // void drawRect(int x, int y, int w, int h, int color);
    // void fillRect(int x, int y, int w, int h, int color);
    // void drawCircle(int x, int y, int r, int color);
    // void fillCircle(int x, int y, int r, int color);

    // Sprites
    void drawSprite(const Sprite& sprite);
    bool checkCollision(const Sprite& a, const Sprite& b);

    // Tilemaps
    void drawTileMap(const uint8_t* map, int rows, int cols, const uint8_t* tiles[]);

    // Input
    bool buttonPressed(int btn);
    bool buttonReleased(int btn);

    // Feedback
    void setLED(bool state);
    void beep(int freq, int dur);
    void beep(int freq);              // one-arg version


private:
    Adafruit_SSD1306 displayObj;
};

#endif

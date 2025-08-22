#include "NanoBoy.h"

NanoBoy::NanoBoy()
: displayObj(NANOboy_SCREEN_WIDTH, NANOboy_SCREEN_HEIGHT, &Wire, NANOboy_OLED_RESET) {}

void NanoBoy::begin() {
    // Init display
    if (!displayObj.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        for (;;); // Loop forever if display not found
    }
    displayObj.clearDisplay();
    displayObj.setTextSize(1);
    displayObj.setTextColor(SSD1306_WHITE);

    // Init buttons
    initButtons();
}

void NanoBoy::clear() {
    displayObj.clearDisplay();
}

void NanoBoy::display() {
    displayObj.display();
}

void NanoBoy::printText(int16_t x, int16_t y, const char* text) {
    displayObj.setCursor(x, y);
    displayObj.print(text);
}

bool NanoBoy::pressed(uint8_t button) {
    return digitalRead(button) == LOW; // Assume buttons pull LOW when pressed
}

void NanoBoy::beep(uint16_t freq, uint16_t duration) {
    tone(NANOboy_SPEAKER, freq, duration);
}

void NanoBoy::initButtons() {
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_LEFT, INPUT_PULLUP);
    pinMode(BTN_RIGHT, INPUT_PULLUP);
    pinMode(BTN_A, INPUT_PULLUP);
    pinMode(BTN_B, INPUT_PULLUP);
}

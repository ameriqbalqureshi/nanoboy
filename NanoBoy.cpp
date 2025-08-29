#include "NanoBoy.h"

NanoBoy::NanoBoy() : displayObj(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1) {}

void NanoBoy::begin() {
    displayObj.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    displayObj.clearDisplay();
    displayObj.display();

    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_LEFT, INPUT_PULLUP);
    pinMode(BTN_RIGHT, INPUT_PULLUP);
    pinMode(BTN_A, INPUT_PULLUP);
    pinMode(BTN_B, INPUT_PULLUP);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
}

// Display
void NanoBoy::clear() {
    displayObj.clearDisplay();
}
void NanoBoy::display() {
    displayObj.display();
}

// Text
void NanoBoy::setCursor(int x, int y) {
    displayObj.setCursor(x, y);
}
void NanoBoy::print(const char* text) {
    displayObj.setTextColor(SSD1306_WHITE);
    displayObj.print(text);
}
void NanoBoy::print(int num) {
    displayObj.setTextColor(SSD1306_WHITE);
    displayObj.print(num);
}
void NanoBoy::print(float num) {
    displayObj.setTextColor(SSD1306_WHITE);
    displayObj.print(num);
}

// Drawing
void NanoBoy::drawPixel(int x, int y, int color) {
    displayObj.drawPixel(x, y, color);
}
void NanoBoy::drawLine(int x0, int y0, int x1, int y1, int color) {
    displayObj.drawLine(x0, y0, x1, y1, color);
}

void NanoBoy::drawRect(int x, int y, int w, int h, int color) {
    displayObj.drawRect(x, y, w, h, color);
}
void NanoBoy::fillRect(int x, int y, int w, int h, int color) {
    displayObj.fillRect(x, y, w, h, color);
}
void NanoBoy::drawCircle(int x, int y, int r, int color) {
    displayObj.drawCircle(x, y, r, color);
}
void NanoBoy::fillCircle(int x, int y, int r, int color) {
    displayObj.fillCircle(x, y, r, color);
}
void NanoBoy::drawBitmap(int x, int y, const uint8_t* bitmap, int w, int h, int color) {
    displayObj.drawBitmap(x, y, bitmap, w, h, color);
}
void NanoBoy::drawText(int x, int y, const char* text) {
    displayObj.setCursor(x, y);
    displayObj.print(text);
}
void NanoBoy::drawText(int x, int y, String text) {
    displayObj.setCursor(x, y);
    displayObj.print(text);
}

// Sprites
void NanoBoy::drawSprite(const Sprite& sprite) {
    if (!sprite.active) return;
    drawBitmap(sprite.x, sprite.y, sprite.bitmap, sprite.w, sprite.h, SSD1306_WHITE);
}
bool NanoBoy::checkCollision(const Sprite& a, const Sprite& b) {
    return !(a.x + a.w <= b.x || a.x >= b.x + b.w ||
             a.y + a.h <= b.y || a.y >= b.y + b.h);
}

// Tilemaps
void NanoBoy::drawTileMap(const uint8_t* map, int rows, int cols, const uint8_t* tiles[]) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            uint8_t tileIndex = map[r * cols + c];
            if (tiles[tileIndex] == nullptr) continue;
            const uint8_t* tile = tiles[tileIndex];
            for (int ty = 0; ty < _T_SIZE; ty++) {
                for (int tx = 0; tx < _T_SIZE; tx++) {
                    if (tile[ty * _T_SIZE + tx]) {
                        drawPixel(c * _T_SIZE + tx, r * _T_SIZE + ty);
                    }
                }
            }
        }
    }
}

// Input
bool NanoBoy::buttonPressed(int btn) {
    return digitalRead(btn) == LOW;
}
bool NanoBoy::buttonReleased(int btn) {
    return digitalRead(btn) == HIGH;
}

// Feedback
void NanoBoy::setLED(bool state) {
    digitalWrite(LED_PIN, state ? HIGH : LOW);
}
void NanoBoy::beep(int freq, int dur) {
    tone(BUZZER_PIN, freq, dur);
}
void NanoBoy::beep(int freq) {
    tone(BUZZER_PIN, freq, 100); // default duration 100 ms
}

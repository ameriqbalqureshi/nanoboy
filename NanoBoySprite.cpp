#include "NanoBoySprite.h"

NanoBoySprite::NanoBoySprite(int16_t x, int16_t y, const unsigned char* bitmap,
                             uint8_t w, uint8_t h)
: _x(x), _y(y), _bitmap(bitmap), _w(w), _h(h) {}

void NanoBoySprite::draw(NanoBoy &nb) {
    nb.displayObj.drawBitmap(_x, _y, _bitmap, _w, _h, SSD1306_WHITE);
}

void NanoBoySprite::move(int16_t dx, int16_t dy) {
    _x += dx;
    _y += dy;
}

void NanoBoySprite::setPosition(int16_t x, int16_t y) {
    _x = x;
    _y = y;
}

// ✅ Corrected: use private members (_x, _y, _w, _h)
bool NanoBoySprite::collidesWith(const NanoBoySprite &other) {
    return !(_x + _w <= other._x ||
             other._x + other._w <= _x ||
             _y + _h <= other._y ||
             other._y + other._h <= _y);
}

int16_t NanoBoySprite::getX() { return _x; }
int16_t NanoBoySprite::getY() { return _y; }

#ifndef NANOboy_SPRITE_H
#define NANOboy_SPRITE_H

#include <Arduino.h>
#include "NanoBoy.h"

class NanoBoySprite {
public:
    NanoBoySprite(int16_t x, int16_t y, const unsigned char* bitmap,
                  uint8_t w, uint8_t h);

    void draw(NanoBoy &nb);
    void move(int16_t dx, int16_t dy);
    void setPosition(int16_t x, int16_t y);
    int16_t getX();
    int16_t getY();
    // Collision detection
    bool collidesWith(const NanoBoySprite &other);

private:
    int16_t _x, _y;
    const unsigned char* _bitmap;
    uint8_t _w, _h;
};

#endif

#ifndef NANOboy_TILEMAP_H
#define NANOboy_TILEMAP_H

#include <Arduino.h>
#include "NanoBoy.h"

class NanoBoyTilemap {
public:
    NanoBoyTilemap(uint8_t tileW, uint8_t tileH, const unsigned char** tiles);

    void draw(NanoBoy &nb, const uint8_t* map, uint8_t mapW, uint8_t mapH);

    // --- Collision detection helpers ---
    uint8_t getTileAt(int x, int y, const uint8_t* map, uint8_t mapW, uint8_t mapH);
    bool isWallAt(int x, int y, const uint8_t* map, uint8_t mapW, uint8_t mapH);
    bool isPelletAt(int x, int y, const uint8_t* map, uint8_t mapW, uint8_t mapH);
    void clearPelletAt(int x, int y, uint8_t* map, uint8_t mapW, uint8_t mapH);

private:
    uint8_t _tileW, _tileH;
    const unsigned char** _tiles;
};

#endif

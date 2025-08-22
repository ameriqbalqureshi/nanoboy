#include "NanoBoyTilemap.h"

NanoBoyTilemap::NanoBoyTilemap(uint8_t tileW, uint8_t tileH, const unsigned char** tiles)
: _tileW(tileW), _tileH(tileH), _tiles(tiles) {}

void NanoBoyTilemap::draw(NanoBoy &nb, const uint8_t* map, uint8_t mapW, uint8_t mapH) {
    for (uint8_t y = 0; y < mapH; y++) {
        for (uint8_t x = 0; x < mapW; x++) {
            uint8_t tileIndex = map[y * mapW + x];
            if (_tiles[tileIndex] != nullptr) {
                nb.displayObj.drawBitmap(
                    x * _tileW,
                    y * _tileH,
                    _tiles[tileIndex],
                    _tileW, _tileH,
                    SSD1306_WHITE
                );
            }
        }
    }
}

uint8_t NanoBoyTilemap::getTileAt(int x, int y, const uint8_t* map, uint8_t mapW, uint8_t mapH) {
    int tileX = x / _tileW;
    int tileY = y / _tileH;
    if (tileX < 0 || tileY < 0 || tileX >= mapW || tileY >= mapH) return 1; // treat out-of-bounds as wall
    return map[tileY * mapW + tileX];
}

bool NanoBoyTilemap::isWallAt(int x, int y, const uint8_t* map, uint8_t mapW, uint8_t mapH) {
    return (getTileAt(x, y, map, mapW, mapH) == 1);
}

bool NanoBoyTilemap::isPelletAt(int x, int y, const uint8_t* map, uint8_t mapW, uint8_t mapH) {
    return (getTileAt(x, y, map, mapW, mapH) == 2);
}

void NanoBoyTilemap::clearPelletAt(int x, int y, uint8_t* map, uint8_t mapW, uint8_t mapH) {
    int tileX = x / _tileW;
    int tileY = y / _tileH;
    if (tileX < 0 || tileY < 0 || tileX >= mapW || tileY >= mapH) return;
    if (map[tileY * mapW + tileX] == 2) {
        ((uint8_t*)map)[tileY * mapW + tileX] = 0; // pellet → empty
    }
}

#ifndef TILEMAN_H
#define TILEMAN_H

#include <SDL.h>
#include <unordered_map>

class Tilemap {
    private:
        std::unordered_map<int, SDL_Texture *> tileTextures;
        int map[18][32];
        SDL_Rect srcRect, dstRect;

    public:
        Tilemap();
        ~Tilemap();
        void loadMap();
        void render();
};

#endif
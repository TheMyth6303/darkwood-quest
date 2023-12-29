#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>

class GameObject {
    private:
        int xpos, ypos;
        SDL_Texture *objectTexture;
        SDL_Rect srcRect, dstRect;

    public:
        GameObject(SDL_Texture *objectTexture, int x, int y);
        ~GameObject();
        void update();
        void render();
};

#endif
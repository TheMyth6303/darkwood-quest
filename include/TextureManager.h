#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <unordered_map>

class TextureManager {
    private:
        TextureManager();
        TextureManager(TextureManager const &);
        TextureManager &operator=(const TextureManager &);
        static std::unordered_map<const char *, SDL_Texture *> textures;

    public:
        static SDL_Texture *getTexture(const char *filepath, SDL_Renderer *renderer);
        static void destroyTextures();
};

#endif
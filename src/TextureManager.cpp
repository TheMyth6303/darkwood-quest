#include <TextureManager.h>

std::unordered_map<const char *, SDL_Texture *> TextureManager::textures;

TextureManager::TextureManager(TextureManager const &) {}

TextureManager &TextureManager::operator=(const TextureManager &) { return *this; }

TextureManager::TextureManager() {}

SDL_Texture *TextureManager::getTexture(const char *filepath, SDL_Renderer *renderer) {
    if (textures.count(filepath) == 0) {
        SDL_Surface *surface = IMG_Load(filepath);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        std::cout << "Created texture: " << filepath << std::endl;
        textures.insert(std::make_pair(filepath, texture));
    }
    return textures[filepath];
}

void TextureManager::destroyTextures() {
    for (auto &pair : textures) {
        SDL_DestroyTexture(pair.second);
        std::cout << "Destroyed texture: " << pair.first << std::endl;
    }
    textures.clear();
}

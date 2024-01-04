#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include <ECS.h>
#include <Game.h>
#include <SDL.h>
#include <TextureManager.h>

class SpriteComponent : public Component {
    private:
        SDL_Texture *texture;
        SDL_Rect srcRect, dstRect;

    public:
        SpriteComponent();
        SpriteComponent(const char *filepath);
        void init() override;
        void update() override;
        void render() override;
};

#endif
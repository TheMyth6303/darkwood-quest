#include <Components.h>

SpriteComponent::SpriteComponent() {}

SpriteComponent::SpriteComponent(const char *filepath) { texture = TextureManager::getTexture(filepath); }

void SpriteComponent::init() {
    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = 128;
    dstRect.x = entity->getComponent<PositionComponent>().x();
    dstRect.y = entity->getComponent<PositionComponent>().y();
    dstRect.w = dstRect.h = 64;
}

void SpriteComponent::update() {
    dstRect.x = entity->getComponent<PositionComponent>().x();
    dstRect.y = entity->getComponent<PositionComponent>().y();
}

void SpriteComponent::render() { SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect); }
#include <Components/ControlComponent.h>
#include <Game.h>
#include <SDL.h>
#include <components/PositionComponent.h>
#include <iostream>

ControlComponent::ControlComponent() {}
ControlComponent::~ControlComponent() {}
void ControlComponent::update() {
    if (Game::event.type == SDL_KEYDOWN) {
        switch (Game::event.key.keysym.sym) {
        case SDLK_w:
            positionComponent->yVelocity = -1;
            break;
        case SDLK_a:
            positionComponent->xVelocity = -1;
            break;
        case SDLK_s:
            positionComponent->yVelocity = 1;
            break;
        case SDLK_d:
            positionComponent->xVelocity = 1;
            break;
        }
    }
    if (Game::event.type == SDL_KEYUP) {
        switch (Game::event.key.keysym.sym) {
        case SDLK_w:
            positionComponent->yVelocity = 0;
            break;
        case SDLK_a:
            positionComponent->xVelocity = 0;
            break;
        case SDLK_s:
            positionComponent->yVelocity = 0;
            break;
        case SDLK_d:
            positionComponent->xVelocity = 0;
            break;
        }
    }
}
void ControlComponent::render() {}
void ControlComponent::init() { positionComponent = &entity->getComponent<PositionComponent>(); }

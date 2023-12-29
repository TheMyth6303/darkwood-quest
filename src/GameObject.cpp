#include <Game.h>
#include <GameObject.h>

GameObject::GameObject(SDL_Texture *objectTexture, int x, int y) {
    this->objectTexture = objectTexture;
    xpos = x;
    ypos = y;
}

GameObject::~GameObject() {}

void GameObject::update() {}

void GameObject::render() { SDL_RenderCopy(Game::renderer, objectTexture, NULL, NULL); }

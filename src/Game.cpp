#include <Components.h>
#include <ECS.h>
#include <Game.h>
#include <TextureManager.h>
#include <Tilemap.h>
#include <iostream>

SDL_Window *Game::window = nullptr;
SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

Manager manager;
Entity &player = manager.addEntity();

Game::Game(){};
Game::~Game(){};

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    isRunning = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Could not initialize SDL video subsystem" << std::endl;
        isRunning = false;
    }

    int flags;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    } else {
        flags = SDL_WINDOW_SHOWN;
    }

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window == nullptr) {
        std::cout << "Could not initialize window" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Could not initialize renderer" << std::endl;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    player.addComponent<PositionComponent>(30, 30);
    player.addComponent<SpriteComponent>("assets/temp_tiles/dirt.png");
    player.addComponent<ControlComponent>();
}

void Game::handleEvents() {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
        isRunning = false;
    }
};

void Game::update() {
    manager.refresh();
    manager.update();
};

void Game::render() {
    SDL_RenderClear(renderer);
    manager.render();
    SDL_RenderPresent(renderer);
};

void Game::clean() {
    TextureManager::destroyTextures();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
};

bool Game::running() { return isRunning; }
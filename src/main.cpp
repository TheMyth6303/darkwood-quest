#include <Game.h>
#include <SDL.h>
#include <iostream>
#include <vector>

const int WIDTH = 960, HEIGHT = 540;
const int FPS = 24;
Game *game = nullptr;

int main(int argc, char *argv[]) {

    uint32_t frameStart;
    int frameTime;

    game = new Game();

    game->init("Darkwood Quest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);

    while (game->running()) {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < 1000 / FPS) {
            SDL_Delay(1000 / FPS - frameTime);
        }
    }

    game->clean();

    return 0;
}

#ifndef GAME_H
#define GAME_H

#include <SDL.h>

class Game {
    private:
        bool isRunning;
        static SDL_Window *window;

    public:
        static SDL_Renderer *renderer;

        Game();
        ~Game();

        void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();
        bool running();
};

#endif
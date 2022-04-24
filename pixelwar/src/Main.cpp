#include "Game.h"
#include "SDL.h"
#include <iostream>

Game* game = nullptr;

int main(int argc, char* argv[]) {
    // limit frame
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("Pixel War", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    while (game->running()) {
        // limit frame
        frameStart = SDL_GetTicks();

        game->handleEvent();
        game->update();
        game->render();

        // limit frame
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();
    return 0;
}
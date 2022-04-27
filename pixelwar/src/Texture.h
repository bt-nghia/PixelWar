#pragma once
#include "Game.h"

class Texture {
public:
    static SDL_Texture* LoadTexture(const char* texturefile);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);
};

#pragma once
#include "Game.h"
#include "Texture.h"

class BackGround {
public:
    BackGround(const char* path, int x, int y);
    ~BackGround();
    void RenderBackGround();
    void UpdateBackGround();

private:
    int xpos, ypos;
    SDL_Texture* backgr;
    SDL_Rect srcbg, destbg;
};
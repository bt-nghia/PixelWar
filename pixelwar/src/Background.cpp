#include "BackGround.h"
#include "Game.h"

BackGround::BackGround(const char* path, int x, int y) {
    backgr = Texture::LoadTexture(path);
    xpos = x; ypos = y;
}

BackGround::~BackGround() {

}

void BackGround::RenderBackGround() {
    SDL_RenderCopy(Game::renderer, backgr, &srcbg, &destbg);
}

void BackGround::UpdateBackGround() {
    xpos = 0;
    ypos = 0;
    srcbg.h = 640;
    srcbg.w = 800;
    srcbg.x = 0;
    srcbg.y = 0;
    destbg.x = 0;
    destbg.y = 0;
    destbg.w = srcbg.w;
    destbg.h = srcbg.h;
}
#include "Texture.h"
#include "Game.h"

SDL_Texture* Texture::LoadTexture(const char* texturefile) {
    SDL_Surface* tmpSurface = IMG_Load(texturefile);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}

void Texture::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, NULL, NULL, flip);
}
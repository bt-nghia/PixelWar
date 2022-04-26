#pragma once
#include "SDL.h"
#include "Texture.h"

class Map {
public:
    Map();
    ~Map();
    void LoadMap(int Pixel[20][25]);
    void DrawMap();
private:
    SDL_Rect src, dest;
    SDL_Texture* floor_1;
    SDL_Texture* floor_2;
    SDL_Texture* floor_3;
    SDL_Texture* floor_4;
    SDL_Texture* floor_5;
    SDL_Texture* wall_1;
    SDL_Texture* wall_2;
    SDL_Texture* wall_3;
    SDL_Texture* wall_4;
    SDL_Texture* wall_5;
    SDL_Texture* wall_6;
    SDL_Texture* wall_7;
    SDL_Texture* wall_8;
    SDL_Texture* wall_9;
    SDL_Texture* wall_10;
    int map[20][25];
};
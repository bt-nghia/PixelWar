#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"
#include <iostream>
#include <vector>
#include "ECS/ECS.h"

class ColliderComponent;
class TileComponent;

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvent();
    void update();
    void render();
    void clean();
    void pickcharacter();
    bool running() { return isRunning; };

    static void changeplayerimg(const char* path, int frames);
    static void AddTile(int id, int x, int y);
    static std::vector<ColliderComponent*> colliders;
    static std::vector<TileComponent*> tilecomponents;
    static std::vector<int> timecount;
    static std::vector<int> timetodestroy;
    static SDL_Renderer* renderer;
    static SDL_Event event;
    static int keynum;
    static int gamescore;
    static bool winthegame;
    static int bombcount;

private:
    bool isRunning;
    bool menustart;
    SDL_Window* window;
};
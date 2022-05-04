#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"
#include <iostream>
#include <vector>

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

    static void PlantTheBomb(int x, int y);
    static void AddTile(int id, int x, int y);
    static std::vector<ColliderComponent*> colliders;
    static std::vector<TileComponent*> tilecomponents;
    static std::vector<ColliderComponent*> bombs;
    static std::vector<int> timecount;
    static std::vector<int> timetodestroy;
    static SDL_Renderer* renderer;
    static SDL_Event event;
    // static std::vector<ColliderComponent*> enemies;

private:
    bool isRunning;
    bool menustart;
    SDL_Window* window;
};
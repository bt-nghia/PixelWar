#include "Game.h"
#include "BackGround.h"
#include "TileMap.h"
#include "ECS/ECS.h"
#include "ECS/Component.h"
#include "Collision.h"

BackGround* bg;

Map* map;
int x = 1;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());
auto& wall2(manager.addEntity());

auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());


std::vector<ColliderComponent*> Game::colliders;

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        // std::cout << "subsystems init! ...\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            // std::cout << "window created\n";
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            // std::cout << "Renderer created\n";
        }
        isRunning = true;
    }
    else {
        isRunning = false;
    }

    // back ground
    bg = new BackGround("gameimg/tiles/floor/floor_5.png", 0, 0);

    //map
    map = new Map();

    //ECS

    //player
    player.addComponent<TransformComponent>(100, 403);
    player.addComponent<SpriteComponent>("gameimg/heroes/knight/knight_idle_anim_f0.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    
    //wall
    wall.addComponent<TransformComponent>(30, 30, 32, 32, 1);
    wall.addComponent<SpriteComponent>("gameimg/tiles/wall/door_anim_opening_f6.png");
    wall.addComponent<ColliderComponent>("wall");

    wall2.addComponent<TransformComponent>(100,100, 32, 32, 1);
    wall2.addComponent<SpriteComponent>("gameimg/tiles/wall/wall_side_right.png");
    wall2.addComponent<ColliderComponent>("wall2");
}

void Game::handleEvent() {
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }

}

void Game::update() {
    bg->UpdateBackGround();
    manager.refresh();
    manager.update();

    for(int i = 1; i < colliders.size(); i++) {
        if(Collision::AABB(player.getComponent<ColliderComponent>(), *colliders[i])) {
            player.getComponent<TransformComponent>().scale = 1;
            player.getComponent<TransformComponent>().velocity * -1;
            Collision::hit(player.getComponent<ColliderComponent>(), *colliders[i]);
        }
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    bg->RenderBackGround();
    map->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);// delete window
    SDL_DestroyRenderer(renderer);// delete renderer
    SDL_Quit();
    // std::cout << "game cleaned\n";
}
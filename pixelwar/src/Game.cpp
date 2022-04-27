#include "Game.h"
#include "BackGround.h"
#include "TileMap.h"
#include "ECS/ECS.h"
#include "ECS/Component.h"
#include "Collision.h"
#include <iostream>
#include <vector>

BackGround* bg;
// Map* map;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Manager manager;
auto& player(manager.addEntity());
auto& rock(manager.addEntity());
auto& ene1(manager.addEntity());
auto& ene2(manager.addEntity());
auto& ene3(manager.addEntity());
std::vector<ColliderComponent*> Game::colliders;
std::vector<TileComponent*> Game::tilecomponents;

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "subsystems init! ...\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "window created\n";
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created\n";
        }
        isRunning = true;
    }
    else {
        isRunning = false;
    }

    // back ground
    bg = new BackGround("gameimg/tiles/floor/floor_5.png", 0, 0);

    //ECS
    // map = new Map();

    // player
    player.addComponent<TransformComponent>(300, 300);
    player.addComponent<SpriteComponent>("gameimg/heroes/knight/knight_run_spritesheet.png", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");

    tilecomponents.push_back(nullptr);

    // rock
    rock.addComponent<TileComponent>(200, 200, 32, 32, 1);
    rock.addComponent<ColliderComponent>("rock");
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
    // player.getComponent<SpriteComponent>().setTexture("gameimg/heroes/knight/knight_idle_spritesheet.png");
}

void Game::update() {
    bg->UpdateBackGround();
    manager.refresh();
    manager.update();
    for(int i = 1; i < colliders.size(); i++) {
        if(Collision::AABB(player.getComponent<ColliderComponent>(), *colliders[i]) && (tilecomponents[i]->tileID==1)) {
            // player.getComponent<TransformComponent>().scale = 1;
            player.getComponent<TransformComponent>().velocity * -1;
            Collision::hit(player.getComponent<ColliderComponent>(), *colliders[i]);
            // player.getComponent<TransformComponent>().levelup();
        }
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    bg->RenderBackGround();
    // map->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleaned\n";
}

void Game::AddTile(int id, int x, int y) {
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    tile.addComponent<ColliderComponent>("wall");
}
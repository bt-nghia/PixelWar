#include "Game.h"
#include "BackGround.h"
#include "Map.h"
#include "ECS/ECS.h"
#include "ECS/Component.h"
#include "Collision.h"
#include <iostream>
#include <vector>

BackGround* bg;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Manager manager;

auto& rock(manager.addEntity());
auto& ene1(manager.addEntity());
auto& ene2(manager.addEntity());
auto& ene3(manager.addEntity());
auto& player(manager.addEntity());
auto& hp(manager.addEntity());

std::vector<ColliderComponent*> Game::colliders;
std::vector<TileComponent*> Game::tilecomponents;

bool gameover = false;

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

    ene1.addComponent<TransformComponent>(400, 400);
    ene1.addComponent<SpriteComponent>("gameimg/enemies/flyingcreature/fly_anim_spritesheet.png", true, 4);
    ene1.addComponent<ColliderComponent>("flyingcreature");

    Map::LoadMap();

    player.addComponent<TransformComponent>(392, 312);
    player.addComponent<SpriteComponent>("gameimg/heroes/knight/knight_run_spritesheet.png", true, 6);
    // player.addComponent<SpriteComponent>("gameimg/heroes/char_blue.png", true, 6);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");

    hp.addComponent<TransformComponent>(10, 10, 16, 80, 2);
    hp.addComponent<SpriteComponent>("gameimg/uinew/health_ui.png");
}

void Game::handleEvent() {
    if(player.getComponent<KeyboardController>().animations == 1) {
        player.getComponent<SpriteComponent>().setTexture("gameimg/heroes/knight/knight_run_spritesheet.png");
        player.getComponent<SpriteComponent>().setframes(6);
        // player.getComponent<SpriteComponent>().change_width_height(16);
    }
    else if(player.getComponent<KeyboardController>().animations == 2) {
        player.getComponent<SpriteComponent>().setTexture("gameimg/ex16x16.png");
        player.getComponent<SpriteComponent>().setframes(1);
        // player.getComponent<SpriteComponent>().change_width_height(32);
        //player.getComponent<SpriteComponent>().
    }
    else {
        player.getComponent<SpriteComponent>().setTexture("gameimg/heroes/knight/knight_idle_spritesheet.png");
        player.getComponent<SpriteComponent>().setframes(6);
        // player.getComponent<SpriteComponent>().change_width_height(16);
    }

    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }

    if(gameover == true) {
        isRunning = false;
        std::cout << "game over!\n";
    }
}

void Game::update() {
    bg->UpdateBackGround();
    manager.refresh();
    manager.update();

    bool col = false;
    if(player.getComponent<TransformComponent>().hp>=1) {
        for(int i = 0; i < colliders.size()-1; i++) {
            if(Collision::AABB(player.getComponent<ColliderComponent>(), *colliders[i])) {
                Collision::hit(player.getComponent<ColliderComponent>(), *colliders[i]);
                col = true;
                if(colliders[i]->tag=="flyingcreature") {
                    if(player.getComponent<TransformComponent>().scale >= 2) {
                        ene1.destroy();
                        colliders.erase(colliders.begin() + i);
                        tilecomponents.erase(tilecomponents.begin() + i);
                    }
                    else {
                        player.getComponent<TransformComponent>().hurt();
                        std::cout << player.getComponent<TransformComponent>().hp << "\n";
                    }
                }
            }
        }

        if(col) {
            player.getComponent<TransformComponent>().setvelocity();
        }
    }
    else {
        gameover = true;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    bg->RenderBackGround();
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
    tile.addComponent<TileComponent>(x, y, 31, 31, id);
    tile.addComponent<ColliderComponent>("wall");
}
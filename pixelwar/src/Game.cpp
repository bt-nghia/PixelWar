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
// static auto& player(manager.addEntity());
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
    // Map::LoadMap(/*"map6x6.txt",*/ 6, 6);
    // player
    // player.addComponent<TransformComponent>(300, 300);
    // player.addComponent<SpriteComponent>("gameimg/heroes/knight/knight_run_spritesheet.png", true, 6);
    // player.addComponent<KeyboardController>();
    // player.addComponent<ColliderComponent>("player");

    // tilecomponents.push_back(nullptr);

    // rock
    // rock.addComponent<TileComponent>(200, 200, 32, 32, 1);
    // rock.addComponent<ColliderComponent>("rock");

    ene1.addComponent<TransformComponent>(400, 400);
    ene1.addComponent<SpriteComponent>("gameimg/enemies/flyingcreature/fly_anim_spritesheet.png", true, 4);
    ene1.addComponent<ColliderComponent>("flyingcreature");

    // tilecomponents.push_back(nullptr);
    Map::LoadMap();

    player.addComponent<TransformComponent>(300, 300);
    player.addComponent<SpriteComponent>("gameimg/heroes/knight/knight_run_spritesheet.png", true, 6);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    // player.getComponent<SpriteComponent>().setTexture("gameimg/heroes/knight/knight_idle_spritesheet.png");

    hp.addComponent<TransformComponent>(10, 10, 16, 80, 2);
    hp.addComponent<SpriteComponent>("gameimg/uinew/health_ui.png");
    // hp.addComponent<ColliderComponent>("health");
}

void Game::handleEvent() {
    if(player.getComponent<KeyboardController>().run == true) {
        player.getComponent<SpriteComponent>().setTexture("gameimg/heroes/knight/knight_run_spritesheet.png");
    }
    else {
        player.getComponent<SpriteComponent>().setTexture("gameimg/heroes/knight/knight_idle_spritesheet.png");
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
    // std::cout << colliders.size() << " " << tilecomponents.size();
    if(player.getComponent<TransformComponent>().hp>=1) {
        for(int i = 0; i < colliders.size()-1; i++) {
            if(Collision::AABB(player.getComponent<ColliderComponent>(), *colliders[i])) {
                // player.getComponent<TransformComponent>().velocity * -1;
                Collision::hit(player.getComponent<ColliderComponent>(), *colliders[i]);
                col = true;
                // if(colliders[i]->tag=="flyingcreature") {
                //     if(player.getComponent<TransformComponent>().scale >= 4) {
                //         ene1.destroy();
                //         colliders.erase(colliders.begin() + i);
                //     tilecomponents.erase(tilecomponents.begin() + i);
                //     }
                //     else {
                //         player.getComponent<TransformComponent>().hurt();
                //         std::cout << player.getComponent<TransformComponent>().hp << "\n";
                //     }
                // }
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
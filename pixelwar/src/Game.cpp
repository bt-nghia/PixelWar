#include "Game.h"
#include "BackGround.h"
#include "Map.h"
#include "ECS/ECS.h"
#include "ECS/Component.h"
#include "Collision.h"
#include <iostream>
#include <vector>

int mpp[6][6] = {
    {1,1,2,2,3,3},
    {2,3,2,3,2,1},
    {1,1,1,1,1,1},
    {1,2,2,2,1,1},
    {1,1,1,1,1,1},
    {2,2,1,1,3,3}
};

BackGround* bg;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Manager manager;
static auto& player(manager.addEntity());
auto& rock(manager.addEntity());
auto& ene1(manager.addEntity());
auto& ene2(manager.addEntity());
auto& ene3(manager.addEntity());
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
    // map = new Map();
    // Map::LoadMap(/*"map6x6.txt",*/ 6, 6);
    // player
    player.addComponent<TransformComponent>(300, 300);
    player.addComponent<SpriteComponent>("gameimg/heroes/knight/knight_run_spritesheet.png", true, 6);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");

    tilecomponents.push_back(nullptr);

    // rock
    rock.addComponent<TileComponent>(200, 200, 32, 32, 1);
    rock.addComponent<ColliderComponent>("rock");

    ene1.addComponent<TransformComponent>(400, 400);
    // ene1.addComponent<TileComponent>(10);
    ene1.addComponent<SpriteComponent>("gameimg/enemies/flyingcreature/fly_anim_spritesheet.png", true, 4);
    // ene1.addComponent<TileComponent>(10);
    ene1.addComponent<ColliderComponent>("flyingcreature");

    // Map::LoadMap(/*"map6x6.txt",*/ 6, 6);
    Game::AddTile(1,1*32,1*32);
    Game::AddTile(2, 2*32, 4*32);
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            Game::AddTile(mpp[i][j], i*32, j*32);
        }
    }
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
    if(gameover == true) {
        isRunning = false;
        std::cout << "game over!\n";
    }
}

void Game::update() {
    bg->UpdateBackGround();
    manager.refresh();
    manager.update();
    // if(player.getComponent<TransformComponent>().scale>=1) {
    //     for(int i = 1; i < colliders.size(); i++) {
    //         if(Collision::AABB(player.getComponent<ColliderComponent>(), *colliders[i]) && (colliders[i]->tag=="rock" || colliders[i]->tag == "flyingcreature")) {
    //             // player.getComponent<TransformComponent>().scale = 1;
    //             player.getComponent<TransformComponent>().velocity * -1;
    //             Collision::hit(player.getComponent<ColliderComponent>(), *colliders[i]);
    //             // player.getComponent<TransformComponent>().levelup();
    //             // if(tilecomponents[i]->tileID==1 ) {rock.destroy();}
    //             // if(tilecomponents[i]->tileID==1) {
    //             //     if(player.getComponent<TransformComponent>().scale==1) {
    //             //         std::cout << "dead!\n";
    //             //         colliders.erase(colliders.begin());
    //             //         tilecomponents.erase(tilecomponents.begin());
    //             //         player.destroy();
    //             //     }
    //             // }
    //             if(colliders[i]->tag=="flyingcreature") {
    //                 if(player.getComponent<TransformComponent>().scale >= 4) {
    //                     ene1.destroy();
    //                     colliders.erase(colliders.begin() + i);
    //                 tilecomponents.erase(tilecomponents.begin() + i);
    //                 }
    //                 else {
    //                     player.getComponent<TransformComponent>().levelup(-1);
    //                 }
    //             }
    //             // ene1.destroy();
    //             // colliders.erase(colliders.begin() + i);
    //             // tilecomponents.erase(tilecomponents.begin() + i);       
    //         }
    //         else {
    //             if(player.getComponent<KeyboardController>().time%5==1) {
    //             // SDL_Delay(2000);
    //                 // player.getComponent<KeyboardController>().time+=2;
    //                 ene1.getComponent<TransformComponent>().monstercome(1, 400, 320);
    //                 player.getComponent<KeyboardController>().time+=2;
    //             // SDL_Delay(2000);
    //             }
    //         }
    //     }
    // }
    // else {
    //     // std::cout << "gameover!";
    //     gameover = true;
    // }
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
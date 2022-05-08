#include "Game.h"
#include "BackGround.h"
#include "Map.h"
#include "ECS/ECS.h"
#include "ECS/Component.h"
#include "Collision.h"
#include <iostream>
#include <vector>

BackGround* bg;
BackGround* menu;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Manager manager;

auto& ene1(manager.addEntity());
auto& ene2(manager.addEntity());
auto& ene3(manager.addEntity());
auto& ene4(manager.addEntity());
auto& ene5(manager.addEntity());
auto& ene6(manager.addEntity());
auto& ene7(manager.addEntity());
auto& blood1(manager.addEntity());
auto& blood2(manager.addEntity());
auto& blood3(manager.addEntity());
auto& blood4(manager.addEntity());
auto& player(manager.addEntity());
auto& hp(manager.addEntity());


std::vector<ColliderComponent*> Game::colliders;
std::vector<TileComponent*> Game::tilecomponents;
int Game::keynum = 0;
int Game::gamescore = 0;

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
        menustart = true;
    }
    else {
        isRunning = false;
    }
    // back ground
    bg = new BackGround("gameimg/tiles/floor/floor_5.png", 0, 0);
    //ECS
    ene1.addComponent<TransformComponent>(500, 480);
    ene1.addComponent<SpriteComponent>("gameimg/enemies/flyingcreature/fly_anim_spritesheet.png", true, 4);
    ene1.addComponent<ColliderComponent>("flyingcreature");

    ene4.addComponent<TransformComponent>(420, 530);
    ene4.addComponent<SpriteComponent>("gameimg/enemies/flyingcreature/fly_anim_spritesheet.png", true, 4);
    ene4.addComponent<ColliderComponent>("flyingcreature");

    ene5.addComponent<TransformComponent>(450, 580);
    ene5.addComponent<SpriteComponent>("gameimg/enemies/flyingcreature/fly_anim_spritesheet.png", true, 4);
    ene5.addComponent<ColliderComponent>("flyingcreature");

    ene2.addComponent<TransformComponent>(150, 300);
    ene2.addComponent<SpriteComponent>("gameimg/enemies/goblin/goblin_idle_spritesheet.png", true, 6);
    ene2.addComponent<ColliderComponent>("goblin");

    ene3.addComponent<TransformComponent>(150, 140);
    ene3.addComponent<SpriteComponent>("gameimg/enemies/slime/slime_idle_spritesheet.png", true, 6);
    ene3.addComponent<ColliderComponent>("slime");

    ene6.addComponent<TransformComponent>(440, 150);
    ene6.addComponent<SpriteComponent>("gameimg/enemies/slime/slime_idle_spritesheet.png", true, 6);
    ene6.addComponent<ColliderComponent>("slime");
    
    ene7.addComponent<TransformComponent>(640, 300);
    ene7.addComponent<SpriteComponent>("gameimg/enemies/goblin/goblin_idle_spritesheet.png", true, 6);
    ene7.addComponent<ColliderComponent>("goblin");

    Map::LoadMap();

    hp.addComponent<TransformComponent>(10, 10, 16, 80, 2);
    hp.addComponent<SpriteComponent>("gameimg/uinew/health_ui.png");

    blood1.addComponent<TransformComponent>(48, 18, 7, 13, 2);
    blood1.addComponent<SpriteComponent>("gameimg/blood.png");

    blood2.addComponent<TransformComponent>(48 + 13*2 + 4, 10 + 4*2, 7, 13, 2);
    blood2.addComponent<SpriteComponent>("gameimg/blood.png");

    blood3.addComponent<TransformComponent>(48 + 13 * 4 + 8, 10 + 4*2, 7, 13, 2);
    blood3.addComponent<SpriteComponent>("gameimg/blood.png");

    blood4.addComponent<TransformComponent>(48 + 13 * 6 + 12, 10 + 4*2, 7, 13, 2);
    blood4.addComponent<SpriteComponent>("gameimg/blood.png");

    player.addComponent<TransformComponent>(392, 312);
    player.addComponent<SpriteComponent>("gameimg/heroes/knight/knight_run_spritesheet.png", true, 6);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    
    menu = new BackGround("gameimg/menulast.png", 0, 0);
}

void Game::handleEvent() {
    if(menustart==false) {
        if(player.getComponent<KeyboardController>().animations == 1) {
            player.getComponent<SpriteComponent>().setTexture("gameimg/heroes/knight/knight_run_spritesheet.png");
            player.getComponent<SpriteComponent>().setframes(6);
        }
        else {
            player.getComponent<SpriteComponent>().setTexture("gameimg/heroes/knight/knight_idle_spritesheet.png");
            player.getComponent<SpriteComponent>().setframes(6);
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
    else {
        SDL_PollEvent(&event);
        switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }

        if(event.type==SDL_KEYDOWN) {

            switch (event.key.keysym.sym)
            {
            case SDLK_p:
                menustart = false;
                break;
            case SDLK_q:
                isRunning = false;
                break;
            default:
                break;
            }
        }
    }
}

void Game::update() {
    if(menustart==false) {
        bg->UpdateBackGround();
        manager.refresh();
        manager.update();
        std::vector<int> index;
        bool col = false;
        if(player.getComponent<TransformComponent>().hp >= 1) {
            for(int i = 0; i < colliders.size(); i++) {
                if(colliders[i]->tag!="player" && colliders[i]->tag!="ex") {
                    if(Collision::AABB(player.getComponent<ColliderComponent>(), *colliders[i])) {
                        Collision::hit(player.getComponent<ColliderComponent>(), *colliders[i]);
                        col = true;
                        if(colliders[i]->tag=="chest" && keynum > 0) {gamescore+=100; keynum--;}
                        if(colliders[i]->tag=="key") {keynum++;}
                        if(colliders[i]->tag=="flyingcreature" || colliders[i]->tag=="goblin" || colliders[i]->tag=="slime") {
                            // player.getComponent<TransformComponent>().setvelocity();

                            if(player.getComponent<TransformComponent>().scale >= 4) {
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene1.getComponent<ColliderComponent>())) {
                                    ene1.getComponent<SpriteComponent>().setTexture("");
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene2.getComponent<ColliderComponent>())) {
                                    ene2.getComponent<SpriteComponent>().setTexture("");
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene3.getComponent<ColliderComponent>())) {
                                    ene3.getComponent<SpriteComponent>().setTexture("");
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene4.getComponent<ColliderComponent>())) {
                                    ene4.getComponent<SpriteComponent>().setTexture("");
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene5.getComponent<ColliderComponent>())) {
                                    ene5.getComponent<SpriteComponent>().setTexture("");
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene6.getComponent<ColliderComponent>())) {
                                    ene6.getComponent<SpriteComponent>().setTexture("");
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene7.getComponent<ColliderComponent>())) {
                                    ene7.getComponent<SpriteComponent>().setTexture("");
                                }
                                index.push_back(i);
                            }

                            else {
                                Collision::hit(player.getComponent<ColliderComponent>(), *colliders[i]);
                                player.getComponent<TransformComponent>().hurt();
                                std::cout << player.getComponent<TransformComponent>().hp << "\n";
                            }    
                        }
                    }
                }
            }

            if(col) {
                player.getComponent<TransformComponent>().setvelocity();
                int cnt = 0;
                for(auto i : index) {
                    tilecomponents.erase(tilecomponents.begin() + i - cnt);
                    colliders.erase(colliders.begin() + i - cnt);
                    cnt++;
                }
                if(player.getComponent<TransformComponent>().hp==3) {blood4.destroy();}
                if(player.getComponent<TransformComponent>().hp==2) {blood3.destroy();}
                if(player.getComponent<TransformComponent>().hp==1) {blood2.destroy();}
                if(player.getComponent<TransformComponent>().hp==0) {blood1.destroy();}
            }
        }
        else {
            gameover = true;
        }
    }
    else {
        menu->UpdateBackGround();
    }
    std::cout << gamescore << "\n";
}

void Game::render() {
    SDL_RenderClear(renderer);
    if(menustart==false) {
        bg->RenderBackGround();
        manager.draw();
    }
    else {
        menu->RenderBackGround();
    }
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
    if(id==6) {tile.addComponent<ColliderComponent>("key");}
    else if(id == 5) {tile.addComponent<ColliderComponent>("chest");}
    else {tile.addComponent<ColliderComponent>("wall");}
}

void Game::PlantTheBomb(int x, int y) {
    auto& explo(manager.addEntity());
    explo.addComponent<TransformComponent>(x-16*3, y-16*3, 32, 32, 4);
    explo.addComponent<SpriteComponent>("gameimg/effectsnew/explosion_anim_spritesheet.png", true, 7);
    explo.addComponent<ColliderComponent>("ex");
}
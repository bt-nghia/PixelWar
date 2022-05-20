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
BackGround* youwinbg;
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
auto& chest1(manager.addEntity());
auto& chest2(manager.addEntity());
auto& chest3(manager.addEntity());


std::vector<ColliderComponent*> Game::colliders;
std::vector<TileComponent*> Game::tilecomponents;
int Game::keynum = 0;
int Game::gamescore = 0;
bool Game::winthegame = false;
int Game::bombcount = 0;

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
        youwin = false;
        isRunning = true;
        menustart = true;
    }
    else {
        isRunning = false;
    }
    // back ground
    bg = new BackGround("gameimg/tiles/floor/floor_5.png", 0, 0);
    // bg = new BackGround("gameimg/winbg.png", 0, 0);
    // youwinbg = new BackGround("gameimg/winbg.png", 0, 0);
    menu = new BackGround("gameimg/menucolor.png", 0, 0);

    //ECS
    chest1.addComponent<TransformComponent>(32* 4, 32* 18);
    chest1.addComponent<SpriteComponent>("gameimg/props_itens/chest_closed_anim_f0.png");
    chest1.addComponent<ColliderComponent>("chest");

    chest2.addComponent<TransformComponent>(32* 14, 32* 1);
    chest2.addComponent<SpriteComponent>("gameimg/props_itens/chest_closed_anim_f0.png");
    chest2.addComponent<ColliderComponent>("chest");

    chest3.addComponent<TransformComponent>(32* 21, 32* 18);
    chest3.addComponent<SpriteComponent>("gameimg/props_itens/chest_closed_anim_f0.png");
    chest3.addComponent<ColliderComponent>("chest");

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
    
    ene7.addComponent<TransformComponent>(670, 300);
    ene7.addComponent<SpriteComponent>("gameimg/enemies/goblin/goblin_idle_spritesheet.png", true, 6);
    ene7.addComponent<ColliderComponent>("goblin");

    // map level 1
    Map::LoadMap(1);

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

    player.addComponent<TransformComponent>(392, 312, 56, 56, 1.1);
    player.addComponent<SpriteComponent>("gameimg/char_blue.png", true, 6);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    
    // menu = new BackGround("gameimg/menucolor.png", 0, 0);
}

void Game::handleEvent() {
    if(menustart==false) {
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

                        if(colliders[i]->tag == "door" && keynum > 0) {
                            std::cout << "you win the game with score : " << gamescore << "\n";
                            // isRunning = false;
                            youwin = true;
                            break;
                        }
                        if(colliders[i]->tag=="chest"&& keynum > 0) {
                            if(Collision::AABB(player.getComponent<ColliderComponent>(), chest1.getComponent<ColliderComponent>())) {
                                chest1.getComponent<SpriteComponent>().setTexture("gameimg/props_itens/chest_open.png");
                            }
                            if(Collision::AABB(player.getComponent<ColliderComponent>(), chest2.getComponent<ColliderComponent>())) {
                                chest2.getComponent<SpriteComponent>().setTexture("gameimg/props_itens/chest_open.png");
                            }
                            if(Collision::AABB(player.getComponent<ColliderComponent>(), chest3.getComponent<ColliderComponent>())) {
                                chest3.getComponent<SpriteComponent>().setTexture("gameimg/props_itens/chest_open.png");
                            }
                            if(player.getComponent<TransformComponent>().hp < 4) {player.getComponent<TransformComponent>().hp++;}
                            gamescore+=100; 
                            keynum--;
                            std::cout << gamescore << "\n";
                        }
                        if(colliders[i]->tag=="key") {keynum++;}
                        if(colliders[i]->tag=="flyingcreature" || colliders[i]->tag=="goblin" || colliders[i]->tag=="slime") {

                            if(player.getComponent<TransformComponent>().atkmode) {
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene1.getComponent<ColliderComponent>())) {
                                    ene1.getComponent<SpriteComponent>().setTexture("");
                                    gamescore+=100;
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene2.getComponent<ColliderComponent>())) {
                                    ene2.getComponent<SpriteComponent>().setTexture("");
                                    gamescore+=100;
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene3.getComponent<ColliderComponent>())) {
                                    ene3.getComponent<SpriteComponent>().setTexture("");
                                    gamescore+=100;
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene4.getComponent<ColliderComponent>())) {
                                    ene4.getComponent<SpriteComponent>().setTexture("");
                                    gamescore+=100;
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene5.getComponent<ColliderComponent>())) {
                                    ene5.getComponent<SpriteComponent>().setTexture("");
                                    gamescore+=100;
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene6.getComponent<ColliderComponent>())) {
                                    ene6.getComponent<SpriteComponent>().setTexture("");
                                    gamescore+=100;
                                }
                                if(Collision::AABB(player.getComponent<ColliderComponent>(), ene7.getComponent<ColliderComponent>())) {
                                    ene7.getComponent<SpriteComponent>().setTexture("");
                                    gamescore+=100;
                                }
                                index.push_back(i);
                                std::cout << gamescore << "\n";
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
                if(player.getComponent<TransformComponent>().hp==4) {
                    blood1.getComponent<SpriteComponent>().setTexture("gameimg/blood.png");
                    blood2.getComponent<SpriteComponent>().setTexture("gameimg/blood.png");
                    blood3.getComponent<SpriteComponent>().setTexture("gameimg/blood.png");
                    blood4.getComponent<SpriteComponent>().setTexture("gameimg/blood.png");
                }
                else if(player.getComponent<TransformComponent>().hp==3) {
                    blood1.getComponent<SpriteComponent>().setTexture("gameimg/blood.png");
                    blood2.getComponent<SpriteComponent>().setTexture("gameimg/blood.png");
                    blood3.getComponent<SpriteComponent>().setTexture("gameimg/blood.png");
                    blood4.getComponent<SpriteComponent>().setTexture("");
                }
                else if(player.getComponent<TransformComponent>().hp==2) {
                    blood1.getComponent<SpriteComponent>().setTexture("gameimg/blood.png");
                    blood2.getComponent<SpriteComponent>().setTexture("gameimg/blood.png");
                    blood3.getComponent<SpriteComponent>().setTexture("");
                    blood4.getComponent<SpriteComponent>().setTexture("");
                }
                else if(player.getComponent<TransformComponent>().hp==1) {
                    blood1.getComponent<SpriteComponent>().setTexture("gameimg/blood.png");
                    blood2.getComponent<SpriteComponent>().setTexture("");
                    blood3.getComponent<SpriteComponent>().setTexture("");
                    blood4.getComponent<SpriteComponent>().setTexture("");
                }
                else {
                    blood1.getComponent<SpriteComponent>().setTexture("");
                    blood2.getComponent<SpriteComponent>().setTexture("");
                    blood3.getComponent<SpriteComponent>().setTexture("");
                    blood4.getComponent<SpriteComponent>().setTexture("");
                }
            }

        }
        else {
            gameover = true;
        }
    }
    else {
        menu->UpdateBackGround();
    }
    //check
    // std::cout << "score : " << gamescore << " key : " << keynum << "\n";
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
    // std::cout << "game cleaned\n";
}

void Game::AddTile(int id, int x, int y) {
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    if(id==6) {tile.addComponent<ColliderComponent>("key");}
    else if(id == 5) {tile.addComponent<ColliderComponent>("chest");}
    else if(id == 4) {tile.addComponent<ColliderComponent>("door");}
    else {tile.addComponent<ColliderComponent>("wall");}
}
#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Component.h"
// #include "Collision.h"

class KeyboardController : public Component {
private:
    int lastkey = 0;

public:
    bool run = false;
    int time = 1;
    TransformComponent* transform;
    SpriteComponent* sprite;
    void init() override {
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    // controller
    void update() override {
        if(Game::event.type == SDL_KEYDOWN) {
            run = true;
            // player.getComponent<SpriteComponent>().setTexture("gameimg/heroes/knight/knight_run_spritesheet.png");
            time++;
            switch (Game::event.key.keysym.sym) {
                case SDLK_LEFT:
                    transform->velocity.x = -1;
                    lastkey = 1;
                    sprite->Play("Walk");
                    sprite->flip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_RIGHT:
                    transform->velocity.x = 1;
                    lastkey = 0;
                    sprite->Play("Walk");
                    break;
                case SDLK_UP:
                    transform->velocity.y = -1;
                    break;
                case SDLK_DOWN:
                    transform->velocity.y = 1;
                    break;
                case SDLK_z:
                    transform->scale = 4;
                    transform->xyset(-16);
                    break;
                case SDLK_x:
                    transform->scale = 1;
                    transform->xyset(8);
                    break;
                default:
                    break;
            }
        }
        if(Game::event.type == SDL_KEYUP) {
            // player.getComponent<SpriteComponent>().setTexture("gameimg/heroes/knight/knight_idle_spritesheet.png");
            run = false;
            switch(Game::event.key.keysym.sym) {
                case SDLK_LEFT:
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
                    sprite->flip = SDL_FLIP_NONE;
                    break;
                case SDLK_RIGHT:
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
                    break;
                case SDLK_UP:
                    transform->velocity.y = 0;
                    sprite->Play("Idle");
                    break;
                case SDLK_DOWN:
                    transform->velocity.y = 0;
                    sprite->Play("Idle");
                    break;
                case SDLK_z:
                    transform->scale = 2;
                    transform->xyset(16);
                    break;
                case SDLK_x:
                    transform->scale = 2;
                    transform->xyset(-8);
                    break;
                default:
                    break;
            }
        }
        if(lastkey==1) {
            sprite->flip = SDL_FLIP_HORIZONTAL;
        }
        else {
            sprite->flip = SDL_FLIP_NONE;
        }
    }
};
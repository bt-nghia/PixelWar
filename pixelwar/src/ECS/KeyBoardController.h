#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Component.h"
// #include "Collision.h"

class KeyboardController : public Component {
private:
    int lastkey = 0;
    
public:
    TransformComponent* transform;
    SpriteComponent* sprite;
    void init() override {
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    // controller
    void update() override {
        if(Game::event.type == SDL_KEYDOWN) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_LEFT:
                    transform->velocity.x = -1;
                    // sprite->setTexture("gameimg/heros/knight/knight_run_spritesheet");
                    lastkey = 1;
                    sprite->Play("Walk");
                    sprite->flip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_RIGHT:
                    transform->velocity.x = 1;
                    // sprite->setTexture("gameimg/heros/knight/knight_run_spritesheet");
                    lastkey = 0;
                    sprite->Play("Walk");
                    // sprite->flip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_UP:
                    transform->velocity.y = -1;
                    // sprite->setTexture("gameimg/heros/knight/knight_run_spritesheet");
                    sprite->Play("Walk");
                    break;
                case SDLK_DOWN:
                    transform->velocity.y = 1;
                    // sprite->setTexture("gameimg/heros/knight/knight_run_spritesheet");
                    sprite->Play("Walk");
                    break;
                case SDLK_SPACE:
                    transform->scale = 4;
                    transform->xyset(-16);
                    break;
                default:
                    break;
            }
        }
        if(Game::event.type == SDL_KEYUP) {
            switch(Game::event.key.keysym.sym) {
                case SDLK_LEFT:
                    transform->velocity.x = 0;
                    // sprite->setTexture("gameimg/heroes/knight/knight_run_spritesheet.png");
                    sprite->Play("Idle");
                    sprite->flip = SDL_FLIP_NONE;
                    break;
                case SDLK_RIGHT:
                    transform->velocity.x = 0;
                    // sprite->setTexture("gameimg/heros/knight/knight_idle_spritesheet.png");
                    sprite->Play("Idle");
                    // sprite->flip = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_UP:
                    transform->velocity.y = 0;
                    // sprite->setTexture("gameimg/heros/knight/knight_idle_spritesheet.png");
                    sprite->Play("Idle");
                    break;
                case SDLK_DOWN:
                    transform->velocity.y = 0;
                    // sprite->setTexture("gameimg/heros/knight/knight_idle_spritesheet.png");
                    sprite->Play("Idle");
                    break;
                case SDLK_SPACE:
                    transform->scale = 2;
                    transform->xyset(16);
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
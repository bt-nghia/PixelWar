#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Component.h"
#include "TransformComponent.h"

class KeyboardController : public Component {
private:
    int lastkey = 0;

public:
    int max_bombs = INT_MAX;
    int animations = 0;
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
            time++;
            switch (Game::event.key.keysym.sym) {
                case SDLK_LEFT:
                    animations = 1;
                    transform->velocity.x = -1;
                    lastkey = 1;
                    sprite->flip = SDL_FLIP_HORIZONTAL;
                    sprite->Play("Walk");
                    break;
                case SDLK_RIGHT:
                    animations = 1;
                    transform->velocity.x = 1;
                    lastkey = 0;
                    sprite->Play("Walk");
                    break;
                case SDLK_UP:
                    animations = 1;
                    transform->velocity.y = -1;
                    sprite->Play("Walk");
                    break;
                case SDLK_DOWN:
                    animations = 1;
                    transform->velocity.y = 1;
                    sprite->Play("Walk");
                    break;
                case SDLK_SPACE:
                    transform->changeatkmodeon();
                    if(lastkey==1) {transform->position.x-=5;}
                    if(lastkey==0) {transform->position.x+=5;}
                    sprite->Play("Atk");
                    break;
                default:
                    break;
            }
        }
        
        if(Game::event.type == SDL_KEYUP) {
            animations = 0;
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
                case SDLK_SPACE:
                    transform->changeatkmodeoff();
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
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
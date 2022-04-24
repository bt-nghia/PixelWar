#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Component.h"
// #include "Collision.h"

class KeyboardController : public Component {
public:
    TransformComponent* transform;

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
    }

    // controller
    void update() override {
        if(Game::event.type == SDL_KEYDOWN) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_LEFT:
                    transform->velocity.x = -1;
                    break;
                case SDLK_RIGHT:
                    transform->velocity.x = 1;
                    break;
                case SDLK_UP:
                    transform->velocity.y = -1;
                    break;
                case SDLK_DOWN:
                    transform->velocity.y = 1;
                default:
                    break;
            }
        }
        if(Game::event.type == SDL_KEYUP) {
            switch(Game::event.key.keysym.sym) {
                case SDLK_LEFT:
                    transform->velocity.x = 0;
                    break;
                case SDLK_RIGHT:
                    transform->velocity.x = 0;
                    break;
                case SDLK_UP:
                    transform->velocity.y = 0;
                    break;
                case SDLK_DOWN:
                    transform->velocity.y = 0;
                default:
                    break;
            }
        }
    }
};
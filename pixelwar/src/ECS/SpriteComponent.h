#pragma once

#include "Component.h"
#include "../Texture.h"
#include "SDL.h"

class SpriteComponent : public Component {
private:
    TransformComponent* transfrom;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;

    bool animated = false;
    int speed = 100;
    int frames = 0;

public:
    SpriteComponent() = default;

    SpriteComponent(const char* path) {
        setTexture(path);
    }

    SpriteComponent(const char* path, int _frames, int _speed) {
        setTexture(path);
        animated = true;
        speed = _speed;
        frames = _frames;
    }

    ~SpriteComponent() {
        SDL_DestroyTexture(texture);
    }

    void setTexture(const char* path) {
        texture = Texture::LoadTexture(path);
    }

    void init() override {
        transfrom = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = transfrom->width;
        srcRect.h = transfrom->height;
    }

    void update() override {
        if(animated) {
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }

        destRect.x = static_cast<int>(transfrom->position.x);
        destRect.y = static_cast<int>(transfrom->position.y);
        destRect.w = transfrom->width * transfrom->scale;
        destRect.h = transfrom->height * transfrom->scale;
    }

    void draw() override {
        Texture::Draw(texture, srcRect, destRect);
    }
};
#pragma once

#include "Component.h"
#include "../Texture.h"
#include "SDL.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component {
private:
    TransformComponent* transfrom;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;

    bool animated = false;
    int speed = 100;
    int frames = 0;
    int animIndex = 0;

public:
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    std::map<const char*, Animation> animations;

    SpriteComponent() = default;

    SpriteComponent(const char* path) {
        setTexture(path);
    }

    SpriteComponent(const char* path, bool isAnimated, int frame) {
        animated = isAnimated;
        // SDL_RendererFlip fLip = SDL_FLIP_HORIZONTAL;
        Animation idle = Animation(0, frame, 100);
        Animation walk = Animation(0, frame, 100);

        animations.emplace("Idle", idle);
        animations.emplace("Walk", walk);

        Play("Idle");
        Play("Walk");
        setTexture(path);
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

        // * animindex in img
        srcRect.y = animIndex * transfrom->height;


        destRect.x = static_cast<int>(transfrom->position.x);
        destRect.y = static_cast<int>(transfrom->position.y);
        destRect.w = transfrom->width * transfrom->scale;
        destRect.h = transfrom->height * transfrom->scale;
    }

    void draw() override {
        Texture::Draw(texture, srcRect, destRect, flip);
    }

    void Play(const char* animName) {
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;
    }
};
#pragma once

#include "ECS.h"
#include "TransformComponent.h"
#include "SDL.h"
#include "SpriteComponent.h"

class TileComponent : public Component {
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    const char* path = "gameimg/tiles/wall/wall_bottom.png";
    SDL_Rect tileRect;
    int tileID;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id) {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;

        
        // switch (tileID) {
        //     case 0:
        //         path = const_cast<char*>("gameimg/tiles/wall/wall_bottom.png");
        //         break;
        //     case 1:
        //         path = const_cast<char*>("gameimg/tiles/floor/floor_1.png");
        //         break;
        //     case 2:
        //         path = const_cast<char*>("gameimg/tiles/floor/floor_3.png");
        //         break;
        //     default:
        //         break;
        // }
    }

    void init() override {
        entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 0);
        transform = &entity->getComponent<TransformComponent>();
        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};
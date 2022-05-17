#pragma once

#include "SDL.h"

class ColliderComponent;

class Collision {
public:
    int id;
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
    static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
    static bool PlayerHitEnemies(const SDL_Rect& player, const SDL_Rect& enemies);
    static void hit(const ColliderComponent& colA, const ColliderComponent& colB);
};
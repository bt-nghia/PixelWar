#include "Collision.h"
#include "ECS\ColliderComponent.h"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB) {
    // if( recA.x + recA.w >= recB.x &&
    //     recB.x + recB.w >= recA.x &&
    //     recA.y + recA.h >= recB.y &&
    //     recB.y + recB.h >= recA.y
    // ) {
    //     return true;
    // }
    // else {
    //     return false;
    // }
    // if((recA.y <= recB.y <= recA.y + recA.h) && ((recB.x <= recA.x) || (recB.x + recB.w >= recA.x + recA.w))) {
    //         return true;
    // }
    // return false;
    int leftX = std::max(recA.x, recB.x);
    int rightX = std::min(recA.x + recA.w, recB.x + recB.w);
    int topY = std::max(recA.y, recB.y);
    int bottomY = std::min(recA.y + recA.h, recB.y + recB.h);
    if(leftX <= rightX && topY <= bottomY) {return true;}
    else {return false;}
}

bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB) {
    if(AABB(colA.collider, colB.collider)) {
        // std::cout << colA.tag << " hit " << colB.tag << "\n";
        return true;
    }
    return false;
}

void Collision::hit(const ColliderComponent& colA, const ColliderComponent& colB) {
    std::cout << colA.tag << " hit " << colB.tag << "\n";
}
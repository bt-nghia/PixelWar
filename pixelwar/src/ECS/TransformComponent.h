#pragma once
#include "Component.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
public:
    Vector2D position;
    Vector2D velocity;

    static int laststep;
    int level = 1;
    float speed = 2;
    float height = 16;
    float width = 16;
    float scale = 2;
    int hp = 4;
    bool atkmode = false;

    TransformComponent() {
        position.Zero();
    }

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    TransformComponent(float x, float y, float h, float w, float sc) {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }

    void resetall(float x, float y, float h, float w, float sc) {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }

    int x() {return position.x;}
    int y() {return position.y;}

    void init() override {
        velocity.Zero();
    }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

    void setPosition(float x, float y) {
        position.x = x;
        position.y = y;
    }

    void levelup(int le) {
        level+=le;
        scale+=le;
    }

    void xyset(int len) {
        position.x+=len;
        position.y+=len;
    }

    void monstercome(int step, int x, int y) {
        position.x+=1;
        position.y+=1;
    }

    void hurt() {
        hp--;
    }

    void setvelocity() {
        if(velocity.x != 0) {
            velocity.x = -velocity.x;
        }
        if(velocity.y != 0) {
            velocity.y = -velocity.y;
        }
    }

    void changeatkmodeon() {
        atkmode = true;
    }

    void changeatkmodeoff() {
        atkmode = false;
    }
};


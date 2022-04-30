#pragma once
#include "Component.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
public:
    Vector2D position;
    Vector2D velocity;

    int level = 1;
    int speed = 3;
    int height = 16;
    int width = 16;
    int scale = 2;
    int hp = 4;

    TransformComponent() {
        position.Zero();
    }

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    TransformComponent(float x, float y, int h, int w, int sc) {
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
};


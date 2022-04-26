#pragma once
#include "Component.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
public:
    Vector2D position;
    Vector2D velocity;

    int level = 1;
    int speed = 2;
    int height = 16;
    int width = 16;
    int scale = 2;

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

    void levelup() {
        level++;
        scale++;
    }

    void xyset(int len) {
        position.x+=len;
        position.y+=len;
    }
};


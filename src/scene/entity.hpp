#pragma once

#include "raylib.h"
#include "collision.hpp"
#include "numberf.hpp"
#include "scene/object.hpp"

class Entity : public Object
{
private:
    /* data */
    float gravity = 0;
    int speed = 10;

public:
    Vector2 collider = {20, 60};
    Entity();
    ~Entity();
    void update();
    void draw();
    void moveAndSlide(Vector2 velocity = Vector2{0, 0}, int iterations = 4);
};

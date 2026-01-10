#pragma once

#include "raylib.h"

class Object
{
private:
    /* data */
public:
    Vector2 position = {0, 0};
    Object(/* args */);
    ~Object();
    virtual void update();
};


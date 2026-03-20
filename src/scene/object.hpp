#pragma once

#include "raylib.h"
#include "global.hpp"

class Object
{
private:
    int object_id;

public:
    Vector2 position = {0, 0};

    Object();
    ~Object();
    int getObjectId();
    void setObjectId(int value);
    virtual void update();
    virtual void draw();
};

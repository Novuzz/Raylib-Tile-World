#pragma once

#include <raylib.h>
#include "object.hpp"
class MainCamera
{
private:
    static Camera2D camera;
    static Object * target;
    /* data */
public:
    static void init();
    static void update();
    static void setTarget(Object * obj);
    static Camera2D getCamera();
};


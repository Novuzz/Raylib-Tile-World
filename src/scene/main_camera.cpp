#include "main_camera.hpp"
#include "config.hpp"

Camera2D MainCamera::camera;
Object* MainCamera::target;


void MainCamera::init()
{
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera.offset = {(float)SCREEN_WIDTH * 0.5f, (float)SCREEN_HEIGHT * 0.5f};
}

void MainCamera::update()
{
    if(target != nullptr)
    camera.target = target->position;
}

void MainCamera::setTarget(Object * obj)
{
    target = obj;
}

Camera2D MainCamera::getCamera()
{
    return camera;
}

#include "object.hpp"


Object::Object()
{
}

Object::~Object()
{
}

int Object::getObjectId()
{
    return object_id;
}

void Object::setObjectId(int value)
{
    object_id = value;
}

void Object::update()
{
}

void Object::draw()
{
            DrawRectangle(position.x,
                      position.y,
                      32,
                      32,
                      GREEN);
}

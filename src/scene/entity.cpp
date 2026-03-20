#include "entity.hpp"

Entity::Entity(/* args */)
{
}

Entity::~Entity()
{
}
void Entity::update()
{
    moveAndSlide();
    Vector2 mapPos = mouseMap(position);
    Rectangle r = {
        mapPos.x * 32 - collider.x * 0.5f,
        mapPos.y * 32 - collider.y * 0.5f,
        collider.x + 32,
        collider.y + 32};
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        map[(int)mapPos.y][(int)mapPos.x] = 0;
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) &&
        map[(int)mapPos.y][(int)mapPos.x] == 0 &&
        !CheckCollisionPointRec(position, r))
        {
            map[(int)mapPos.y][(int)mapPos.x] = 2;
            if(map[(int)mapPos.y + 1][(int)mapPos.x] == 2)
            map[(int)mapPos.y + 1][(int)mapPos.x] = 1;
            if(map[(int)mapPos.y - 1][(int)mapPos.x] != 0)
            map[(int)mapPos.y ][(int)mapPos.x] = 1;



        }
}
void Entity::draw()
{
    DrawRectangle(position.x - collider.x * 0.5f,
                      position.y - collider.y * 0.5f,
                      collider.x,
                      collider.y,
                      GREEN);
}
Vector2 defVec = {0};
void Entity::moveAndSlide(Vector2 velocity, int iterations)
{
    if (velocity == Vector2{0, 0})
    {

        velocity = Vector2{(float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)), gravity};
        velocity.x *= speed;
    }

    if (IsKeyPressed(KEY_SPACE))
    {
        gravity = -10;
        velocity.y = gravity;
    }
    Vector2 normal = {0};
    Rectangle col = {0};
    position += Collision({position.x, position.y, collider.x, collider.y}, velocity, &normal, &col);
    if (normal != Vector2{0, -1})
    {
        gravity += .5f;
    }
    else
    {
        gravity = 0;
    }
    velocity = projectTo(velocity, normal);
    if (normal != Vector2{0, 0} && iterations > 0 && normal != defVec && velocity != Vector2Zero())
    {
        defVec = normal;
        moveAndSlide(velocity, iterations - 1);
    }
    defVec = {0};
}
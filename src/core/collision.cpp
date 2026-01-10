#include "collision.hpp"

Vector2 projectTo(const Vector2 vec1, const Vector2 vec2)
{
    return vec1 - vec2 * (vec1.x * vec2.x + vec1.y * vec2.y);
}
bool RayCast(Vector2 point, Vector2 vel, Rectangle col, float *near, Vector2 *normal)
{

    float txMin = (col.x - point.x) / vel.x;
    float txMax = (col.width + col.x - point.x) / vel.x;

    float tyMin = (col.y - point.y) / vel.y;
    float tyMax = (col.height + col.y - point.y) / vel.y;
    float txNear = min(txMax, txMin);
    float txFar = max(txMax, txMin);

    float tyNear = min(tyMax, tyMin);
    float tyFar = max(tyMax, tyMin);

    float tNear = max(txNear, tyNear);
    float tFar = min(txFar, tyFar);

    if (txNear > tyNear)
        if (vel.x < 0)
            *normal = {1, 0};
        else
            *normal = {-1, 0};
    else if (txNear < tyNear)
        if (vel.y < 0)
            *normal = {0, 1};
        else
            *normal = {0, -1};

    *near = tNear;
    bool hit = tNear < tFar && tNear <= 1 && tNear >= 0;
    if (!hit)
        *near = 1;

    // std::cout << tNear << "\n";

    return hit;
}

bool RectCol(Rectangle col)
{
    Vector2 pos = {col.x, col.y};
    Vector2 size = {col.width, col.height};
    Vector2 m = globalToMap(pos);
    Vector2 s = globalToMap(size + pos);
    for (int j = m.y; j <= s.y; j++)
    {
        for (int i = m.x; i <= s.x; i++)
        {
            if (map[j][i] != 0)
                return true;
        }
    }

    return false;
}

Vector2 Collision(Rectangle point, Vector2 vel, Vector2 *normal, Rectangle *collider)
{
    float near = 1;
    Vector2 position = {point.x, point.y};

    Vector2 norm = Vector2{sign(vel.x), sign(vel.y)};
    Vector2 end = {vel.x, vel.y};
    // This whole rect area is used for optimization
    // it only check tiles in the rect area, the rect
    // being the area where the actor moved
    Rectangle areaRect = {
        end.x < 0 ? end.x + position.x + norm.x * TILE_SIZE * 0.5f : position.x - TILE_SIZE * 0.5f,
        end.y < 0 ? end.y + position.y + norm.y * TILE_SIZE : position.y - TILE_SIZE,
        max(abs(end.x) + TILE_SIZE, TILE_SIZE),
        max(abs(end.y) + TILE_SIZE * 2, TILE_SIZE * 2)};
    Vector2 pos = {areaRect.x, areaRect.y};
    Vector2 size = {areaRect.width, areaRect.height};
    Vector2 m = globalToMap(pos);
    Vector2 s = globalToMap(size + pos);
    for (int j = m.y; j <= s.y; j++)
    {
        for (int i = m.x; i <= s.x; i++)
        {
            if (map[j][i] != 0)
            {
                float n = 1;
                Rectangle rect = {i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE};
                rect.x -= point.width * 0.5f;
                rect.y -= point.height * 0.5f;
                rect.width += point.width;
                rect.height += point.height;
                // this normal prevent the ray check between the gaps
                Vector2 _normal = {0};
                if (CheckCollisionPointRec(position, rect))
                {

                    *collider = rect;
                }
                if (RayCast(position, vel, rect, &n, &_normal) && n <= near && map[j + (int)_normal.y][i + (int)_normal.x] == 0)
                {
                    // std::cout << vel.x << " " << vel.y << "\n";
                    *normal = _normal;
                    near = Clamp(n - 0.008f, 0, 1);
                }
            }
        }
    }

    return vel * near;
}

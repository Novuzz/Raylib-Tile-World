#include "tile.hpp"
int map[25][250] = {0};
Vector2 globalToMap(Vector2 pos)
{
    return Vector2{floorf(pos.x / TILE_SIZE), floorf(pos.y / TILE_SIZE)};
}

Vector2 mouseMap(Vector2 position)
{
    Vector2 mousePos = {GetMouseX() + position.x - SCREEN_WIDTH * 0.5f, GetMouseY() + position.y - (float)SCREEN_HEIGHT * 0.5f};
    Vector2 mapPos = {(int)(mousePos.x / TILE_SIZE), (int)(mousePos.y / TILE_SIZE)};
    return mapPos;
}

void loadMap()
{
    Color *noise = LoadImageColors(GenImagePerlinNoise(250, 250, 50 + GetRandomValue(0, 1000), 50, 1));
    for (int j = 0; j < 25; j++)
    {
        for (int i = 0; i < 250; i++)
        {
            float h = (float)noise[i].r / 255;
            if (h * 35 < j)
                map[j][i] = GetRandomValue(1, 3);
        }
    }
    UnloadImageColors(noise);
}

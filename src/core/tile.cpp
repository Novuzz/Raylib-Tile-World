#include "tile.hpp"
int map[100][250] = {0};

std::unordered_set<int> exception ={0, 5, 6, -1};

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
    for (int j = 0; j < 100; j++)
    {
        for (int i = 0; i < 250; i++)
        {
            float h = (float)noise[i].r / 255;
            if (h * 35 < j)
            {
                if(map[j - 1][i] == 0)
                map[j][i] = 2;
                else
                map[j][i] = 1;
            }
            if( h * 45 < j)
            {
                if(GetRandomValue(0, 100) > 10)
                map[j][i] = 3;
                else
                map[j][i] = 4;
            }
            if(j > 15 && map[j][i] == 0)
            {
                if(map[j - 1][i] == 0)
                map[j][i] = 5;
                else
                map[j][i] = 6;
            }

        }
    }
    UnloadImageColors(noise);
}

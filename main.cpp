#include "raylib.h"
#include <iostream>
#include "numberf.hpp"
#include "collision.hpp"
#include "tile.hpp"
#include "entity.hpp"
#include "config.hpp"
#include "string"

using namespace std;

int main()
{
    //Guess there's a better way to do this
    string path = (string)GetApplicationDirectory() + "/../assets";
    ChangeDirectory(path.c_str());
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tile World");
    Texture2D texture = LoadTexture("placeholder.png");
    std::cout << GetDirectoryPath("core") << "\n";

    float index = 2;

    Camera2D camera = {0};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera.offset = {(float)SCREEN_WIDTH * 0.5f, (float)SCREEN_HEIGHT * 0.5f};
    Vector2 position = {0, 64};
    float gravity = 0;
    loadMap();
    Entity *player = new Entity();
    while (!WindowShouldClose())
    {



        Vector2 point = GetMousePosition() - Vector2{(float)SCREEN_WIDTH * 0.5f, (float)SCREEN_HEIGHT * 0.5f};
        player->update();
        camera.target = player->position;
        
        
        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(RAYWHITE);
        DrawRectangle(player->position.x - player->collider.x * 0.5f,
                      player->position.y - player->collider.y * 0.5f,
                      player->collider.x,
                      player->collider.y,
                      GREEN);
        for (int j = 0; j < 100; j++)
            for (int i = 0; i < 250; i++)
            {
                DrawTexturePro(
                    texture,
                    {0 + (float)(map[j][i]) * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE},
                    {0, 0, TILE_SIZE, TILE_SIZE},
                    {-TILE_SIZE * (float)i, -TILE_SIZE * (float)j},
                    0,
                    WHITE);
            }

        EndMode2D();
        EndDrawing();
    }
    delete player;
    UnloadTexture(texture);
}
#include "raylib.h"
#include <iostream>
#include "numberf.hpp"
#include "collision.hpp"
#include "tile.hpp"
#include "entity.hpp"
#include "config.hpp"
#include "string"
#include "tree.hpp"
#include "main_camera.hpp"

using namespace std;

int main()
{
    // Guess there's a better way to do this
    string path = (string)GetApplicationDirectory() + "/../assets";
    ChangeDirectory(path.c_str());
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tile World");
    Texture2D texture = LoadTexture("placeholder.png");
    std::cout << GetDirectoryPath("core") << "\n";

    float index = 2;


    loadMap();
    MainCamera::init();
    Entity * player = new Entity();
    MainCamera::setTarget(player);
    Tree::instantiate(player);
    while (!WindowShouldClose())
    {
        Tree::iterate();
        MainCamera::update();


        BeginDrawing();
        BeginMode2D(MainCamera::getCamera());
        Tree::iterateDraw();
        ClearBackground({0, 155, 255});

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
    UnloadTexture(texture);
}
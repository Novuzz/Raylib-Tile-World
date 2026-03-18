#pragma once

#include "iostream"
#include "raylib.h"
#include "raymath.h"
#include "config.hpp"

extern int map[100][250];

Vector2 globalToMap(Vector2 pos);

Vector2 mouseMap(Vector2 position);

void loadMap();

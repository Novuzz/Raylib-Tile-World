#pragma once

#include "iostream"
#include "raylib.h"
#include "raymath.h"
#include "config.hpp"
#include "unordered_set"

extern int map[100][250];
extern std::unordered_set<int> exception;

Vector2 globalToMap(Vector2 pos);

Vector2 mouseMap(Vector2 position);

void loadMap();

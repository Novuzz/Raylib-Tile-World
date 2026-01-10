#pragma once

#include "raylib.h"
#include "raymath.h"
#include "iostream"
#include "tile.hpp"
#include "numberf.hpp"

Vector2 projectTo(const Vector2 vec1, const Vector2 vec2);

bool RayCast(Vector2 point, Vector2 vel, Rectangle col, float * near, Vector2 * normal);

bool RectCol(Rectangle col);

Vector2 Collision(Rectangle point, Vector2 vel, Vector2 * normal, Rectangle * collider);

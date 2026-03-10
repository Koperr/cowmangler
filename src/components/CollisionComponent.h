#pragma once

#include "raylib.h"
#include "raymath.h"

BoundingBox GetBoundingBox(Model model, Vector3 pos);

bool CheckCollision(BoundingBox bb1, BoundingBox bb2);
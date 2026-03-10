#pragma once

#include "raylib.h"

class Entity {
public:
    Vector3 position;
    Vector3 velocity;
    BoundingBox boundingBox;
    Model model;
    float health;
private:

};
#pragma once

#include "raylib.h"

class Entity {
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 direction;
    Vector3 up;
    Model model;
    BoundingBox bbox;

    Entity(Vector3 position, Model model)
        : position(position),
          model(model),
          velocity {0.0f, 0.0f, 0.0f},
          direction {1.0f, 0.0f, 0.0f},
          up {0.0f, 1.0f, 0.0f},
          bbox {0}
          {}
};
#pragma once

#include "raylib.h"
#include "raymath.h"
#include "Entity.h"

class MovementComponent {
public:
    float acceleration = 40.0f;
    float friction = 5.0f;
    
    MovementComponent(Entity& owner) : owner(owner) {}

    void Accelerate(Vector3 direction);
    void Move();
    Vector3 GetNextPosition();
private:
    Entity& owner;
};
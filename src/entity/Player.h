#pragma once
#include "raylib.h"
#include "raymath.h"

#include "Entity.h"
#include "MovementComponent.h"

//#include "camera.h"

class Player : public Entity {
public:
    MovementComponent movement;

    Player (Vector3 position, Model model) 
        : movement(*this),
          Entity(position, model)
    {

        movement.acceleration = 40.0f;
        movement.friction = 5.0f;

        camera.position = {0.0f, 5.0f, 0.0f};
        camera.target   = {0.0f, 0.0f, 0.0f};
        camera.up       = {0.0f, 1.0f, 0.0f};
        camera.fovy     = 45.0f;
        camera.projection = CAMERA_PERSPECTIVE;
        camera_mode = CAMERA_THIRD_PERSON;
    }

    Camera3D camera;
    int camera_mode;
    void UpdateCamera();


private:

};

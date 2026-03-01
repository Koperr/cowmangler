#pragma once
#include "raylib.h"
#include "raymath.h"

//#include "camera.h"

class Player{
public:
    Player (Vector3 position, Model model) {
        position = position;
        this->model = model;

        camera.position = {0.0f, 5.0f, 0.0f};
        camera.target   = {0.0f, 0.0f, 0.0f};
        camera.up       = {0.0f, 1.0f, 0.0f};
        camera.fovy     = 45.0f;
        camera.projection = CAMERA_PERSPECTIVE;
    }

    // Camera
    Camera3D camera;
    int camera_mode = CAMERA_THIRD_PERSON;
    void UpdateCamera();

    
    Model model;
    Vector3 direction = {0.0f, 0.0f, 0.0f};
    Vector3 position =  {0.0f, 0.0f, 0.0f};
    Vector3 up =        {0.0f, 1.0f, 0.0f};
    Vector3 velocity =  {0.0f, 0.0f, 0.0f};
    float speed = 10.0f; // not going to be used
    float acceleration = 0.08f;
    void Accelerate(Vector3 direction);
    void Move();
private:

};

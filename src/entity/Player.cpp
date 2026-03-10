#include "Player.h"
#include <iostream>

void Player::UpdateCamera()
{
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.position = position;

    if (camera_mode == CAMERA_FIRST_PERSON) {
        camera.position = Vector3{position.x, position.y + 2.5f, position.z};
    }
    if (camera_mode == CAMERA_THIRD_PERSON) {
        camera.position = Vector3{position.x, position.y + 1.5f, position.z} - Vector3Normalize(direction) * 5;
    }
    camera.target = camera.position + direction;
}

void Player::Accelerate(Vector3 direction)
{
    float dt = GetFrameTime();
    velocity += direction * acceleration * dt;
}

void Player::Move()
{
    float dt = GetFrameTime();
    this->position += velocity * dt;
}

Vector3 Player::GetNextPosition()
{
    float dt = GetFrameTime();
    Vector3 next_pos = position + (velocity * dt);
    return next_pos;
}

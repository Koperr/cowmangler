#include "MovementComponent.h"

void MovementComponent::Accelerate(Vector3 direction)
{
    float dt = GetFrameTime();
    owner.velocity += direction * acceleration * dt;
}

void MovementComponent::Move()
{
    float dt = GetFrameTime();
    owner.position += owner.velocity * dt;
}

Vector3 MovementComponent::GetNextPosition()
{
    float dt = GetFrameTime();
    Vector3 next_pos = owner.position + (owner.velocity * dt);
    return next_pos;
}
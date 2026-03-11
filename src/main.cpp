#include <iostream>

#include "Window.h"

#include "Renderer.h"
#include "CollisionSystem.h"

int main()
{
    Window window(1920 + 700, 1080 + 700, "cowmangler", 144);

    float speed = 5.0f;

    float pitch = 0.0f;
    float yaw = -90.0f;
    float mouse_sens = 0.05f;
    

    Model player_model = LoadModelFromMesh(GenMeshCylinder(1.0f, 2.0f, 10));
    Player player(Vector3{0.0f, 0.0f, 0.0f}, player_model);

    Level level1(&player);
    level1.Load("this shit is going to be implemented soon");

    Renderer renderer;
    
    while (!window.ShouldClose()) {
        float dt = GetFrameTime();
        
        
        // input
        yaw   -= GetMouseDelta().x * mouse_sens;
        pitch -= GetMouseDelta().y * mouse_sens;
        if (pitch > 89)  pitch =  89;
        if (pitch < -89) pitch = -89;
        player.direction.x = sin(yaw * DEG2RAD) * cos(pitch * DEG2RAD);
        player.direction.y = sin(pitch * DEG2RAD);
        player.direction.z = cos(yaw * DEG2RAD) * cos(pitch * DEG2RAD);

        if (GetMouseWheelMove()) {
            player.camera.fovy -= GetMouseWheelMove() * 2;
        }if (IsKeyDown(KEY_W)) {
            player.movement.Accelerate(Vector3{sin(yaw * DEG2RAD), 0.0f, cos(yaw * DEG2RAD)});
        }if (IsKeyDown(KEY_S)) {
            player.movement.Accelerate(Vector3{sin(yaw * DEG2RAD), 0.0f, cos(yaw * DEG2RAD)} * (-1));
        }if (IsKeyDown(KEY_A)) {
            player.movement.Accelerate(Vector3CrossProduct(Vector3{sin(yaw * DEG2RAD), 0.0f, cos(yaw * DEG2RAD)}, player.up) * (-1));
        }if (IsKeyDown(KEY_D)) {
            player.movement.Accelerate(Vector3CrossProduct(Vector3{sin(yaw * DEG2RAD), 0.0f, cos(yaw * DEG2RAD)}, player.up));
        }if (IsKeyDown(KEY_SPACE)) {
            player.position.y += speed * dt;
            // TODO player.Jump()
        }if (IsKeyDown(KEY_LEFT_SHIFT)) {
            player.position.y -= speed * dt;
        }

        player.velocity.x -= player.velocity.x * player.movement.friction * dt;
        player.velocity.z -= player.velocity.z * player.movement.friction * dt;
        
        bool collision = false;
        BoundingBox player_bb = GetBoundingBox(player.model, player.position + player.movement.GetNextPosition());
        for (const auto& obj : level1.objects) {
            BoundingBox obj_bb = GetBoundingBox(obj.model, obj.position);
            if (CheckCollision(player_bb, obj_bb)) {
                collision = true;
                break;
            }
        }
        if (!collision) player.movement.Move();

        player.UpdateCamera();
        renderer.Draw(level1, player);

    }
    return 0;
}
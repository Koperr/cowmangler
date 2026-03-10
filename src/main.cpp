#include <iostream>

#include "Window.h"

#include "Player.h"
#include "CollisionComponent.h"

int main()
{
    Window window(1920 + 700, 1080 + 700, "cowmangler", 144);
    
    Mesh ground_mesh = GenMeshPlane(10.0f, 10.0f, 1.0f, 1.0f);
    for (int i = 0; i < ground_mesh.vertexCount; i++) {
    ground_mesh.texcoords[i*2] *= 10.0f;
    ground_mesh.texcoords[i*2 + 1] *= 10.0f;
    }
    //UpdateMeshBuffer(ground_mesh, 1, ground_mesh.texcoords, ground_mesh.vertexCount * 2 * sizeof(float), 0);

    Model ground = LoadModelFromMesh(ground_mesh);
    Texture2D floor_tiles_txt = LoadTexture("resources/textures/floor_tiles.png");
    SetTextureFilter(floor_tiles_txt, TEXTURE_FILTER_BILINEAR);
    SetTextureWrap(floor_tiles_txt, TEXTURE_WRAP_REPEAT);
    SetTextureFilter(floor_tiles_txt, TEXTURE_FILTER_ANISOTROPIC_8X);

    ground.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = floor_tiles_txt;
    Vector3 ground_pos = {0.0f, 0.0f, 0.0f};
    //SetMaterialTexture(&ground.materials[0], MATERIAL_MAP_ALBEDO, floor_tiles_txt);

    float speed = 5.0f;

    float pitch = 0.0f;
    float yaw = -90.0f;
    float mouse_sens = 0.05f;
    

    Model player_model = LoadModelFromMesh(GenMeshCylinder(1.0f, 2.0f, 10));
    Player player(Vector3{0.0f, 0.0f, 0.0f}, player_model);
    
    while (!window.ShouldClose()) {
        float dt = GetFrameTime();
        
        
        // input
        yaw   -= GetMouseDelta().x * mouse_sens;
        pitch -= GetMouseDelta().y * mouse_sens;
        if (pitch > 89)  pitch =  89;
        if (pitch < -89) pitch = -89;
        // TODO change player.direction to player.CAMERA.direction
        player.direction.x = sin(yaw * DEG2RAD) * cos(pitch * DEG2RAD);
        player.direction.y = sin(pitch * DEG2RAD);
        player.direction.z = cos(yaw * DEG2RAD) * cos(pitch * DEG2RAD);

        if (GetMouseWheelMove()) {
            player.camera.fovy -= GetMouseWheelMove() * 2;
        }
        if (GetMouseWheelMove()) std::cout << GetMouseWheelMove()  << "g" << std::endl;
        if (IsKeyDown(KEY_W)) {
            player.Accelerate(Vector3{sin(yaw * DEG2RAD), 0.0f, cos(yaw * DEG2RAD)});
        }if (IsKeyDown(KEY_S)) {
            player.Accelerate(Vector3{sin(yaw * DEG2RAD), 0.0f, cos(yaw * DEG2RAD)} * (-1));
        }if (IsKeyDown(KEY_A)) {
            player.Accelerate(Vector3CrossProduct(Vector3{sin(yaw * DEG2RAD), 0.0f, cos(yaw * DEG2RAD)}, player.up) * (-1));
        }if (IsKeyDown(KEY_D)) {
            player.Accelerate(Vector3CrossProduct(Vector3{sin(yaw * DEG2RAD), 0.0f, cos(yaw * DEG2RAD)}, player.up));
        }if (IsKeyDown(KEY_SPACE)) {
            player.position.y += speed * dt;
            // TODO player.Jump()
        }if (IsKeyDown(KEY_LEFT_SHIFT)) {
            player.position.y -= speed * dt;
        }

        float friction = 5.0f;
        player.velocity.x -= player.velocity.x * friction * dt;
        player.velocity.z -= player.velocity.z * friction * dt;

        BoundingBox player_bb = GetBoundingBox(player.model, player.position + player.GetNextPosition());
        BoundingBox ground_bb = GetBoundingBox(ground, ground_pos);
        if (!CheckCollision(player_bb, ground_bb)){
            player.Move();
        } else {
            //TODO implement collide & slide
        }
        player.UpdateCamera();
        
        //drawing
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(player.camera);

        DrawModelWires(player.model, player.position, 1.0f, GREEN);
        DrawBoundingBox(player_bb, BLUE);
        DrawLine3D(player.position, player.position + player.velocity, PURPLE);
        DrawModel(ground, ground_pos, 1.0f, WHITE);
        
        EndMode3D();
        DrawText(TextFormat("player position  X: %f Y: %f Z: %f", player.position.x, player.position.y, player.position.z), 50, 50, 30, WHITE);
        DrawText(TextFormat("player direction X: %f Y: %f Z: %f", player.direction.x, player.direction.y, player.direction.z), 50, 100, 30, WHITE);
        DrawText(TextFormat("player velocity  X: %f Y: %f Z: %f", player.velocity.x, player.velocity.y, player.velocity.z), 50, 150, 30, WHITE);
        DrawText(TextFormat("camera position  X: %f Y: %f Z: %f", player.camera.position.x, player.camera.position.y, player.camera.position.z), 50, 200, 30, WHITE);
        // TODO fix "calculating" speed
        DrawText(TextFormat("speed: %f ", player.velocity.x + player.velocity.z), 50, 250, 30, WHITE);
        EndDrawing();
    }
    return 0;
}
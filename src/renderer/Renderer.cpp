#include "Renderer.h"

void Renderer::Draw(const Level &level, const Player &player)
{
    if (IsKeyPressed(KEY_F1)) debug = !debug;

    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(player.camera);
        DrawWorld(level);
        DrawEntities(level);
    EndMode3D();

    DrawHUD(player);
    if(debug) DrawDebug(player);

    EndDrawing();
}
// DO WYWALENIA
BoundingBox GettBoundingBox(Model model, Vector3 pos){
    BoundingBox bb = GetModelBoundingBox(model);
    bb.min = Vector3Add(bb.min, pos);
    bb.max = Vector3Add(bb.max, pos);
    return bb;
}

void Renderer::DrawWorld(const Level &level)
{
    for (const auto& obj : level.objects) {
        //DrawModel(obj.model, obj.position, 1.0f, WHITE);
        DrawBoundingBox(GettBoundingBox(obj.model, obj.position), WHITE);
    }
}

void Renderer::DrawEntities(const Level &level)
{
    for (const auto& entitie : level.entities) {
        //DrawModel(entitie->model, entitie->position, 1.0f, WHITE);
        DrawBoundingBox(GettBoundingBox(entitie->model, entitie->position), WHITE);
    }
}

void Renderer::DrawHUD(const Player &player)
{

}

void Renderer::DrawDebug(const Player &player)
{
    DrawText(TextFormat("player position  X: %f Y: %f Z: %f", player.position.x, player.position.y, player.position.z), 50, 50, 30, WHITE);
    DrawText(TextFormat("player direction X: %f Y: %f Z: %f", player.direction.x, player.direction.y, player.direction.z), 50, 100, 30, WHITE);
    DrawText(TextFormat("player velocity  X: %f Y: %f Z: %f", player.velocity.x, player.velocity.y, player.velocity.z), 50, 150, 30, WHITE);
    DrawText(TextFormat("camera position  X: %f Y: %f Z: %f", player.camera.position.x, player.camera.position.y, player.camera.position.z), 50, 200, 30, WHITE);
        
}

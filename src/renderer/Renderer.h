#pragma once

#include "raylib.h"

#include "Level.h"

class Renderer {
public:
    void Draw(const Level& level, const Player& player);
    
private:
    void DrawWorld(const Level& level);
    void DrawEntities(const Level& level);
    void DrawHUD(const Player& player);
    void DrawDebug(const Player& player);

    bool debug = false;
};
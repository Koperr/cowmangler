#pragma once

#include <vector>
#include <string>

#include "raylib.h"

#include "Player.h"

struct Object {
    Vector3 position;
    Model model;
    Texture texture;
};

class Level {
public:
    Level(Player* player) {
        entities.push_back(player);
    }

    std::vector<Object> objects;
    std::vector<Entity*> entities;

    void Load(const std::string& path);
    void Unload();
private:

};
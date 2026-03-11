#include "Level.h"

void Level::Load(const std::string& path) {
    // TODO
    // make it load content from some file
    // for this time its hardcoded

    // ground plane
    Texture2D floor_tiles_txt = LoadTexture("resources/textures/floor_tiles.png");
    SetTextureWrap(floor_tiles_txt, TEXTURE_WRAP_REPEAT);
    SetTextureFilter(floor_tiles_txt, TEXTURE_FILTER_ANISOTROPIC_8X);

    Object floor;
    floor.position = {0.0f, 0.0f, 0.0f};
    floor.model = LoadModelFromMesh(GenMeshPlane(10.0f, 10.0f, 1.0f, 1.0f));
    floor.texture = floor_tiles_txt;
    floor.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = floor_tiles_txt;
    
    // box1
    Texture2D box_txt = LoadTexture("resources/textures/box.png");
    SetTextureWrap(box_txt, TEXTURE_WRAP_REPEAT);
    SetTextureFilter(box_txt, TEXTURE_FILTER_ANISOTROPIC_8X);

    Object box;
    box.position = {0.0f, 1.0f, 5.0f};
    box.model = LoadModelFromMesh(GenMeshCube(2.0f, 2.0f, 2.0f));
    box.texture = box_txt;
    box.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = box_txt;


    objects.push_back(floor);
    objects.push_back(box);

}

void Level::Unload() {
    for (auto& object : objects) {
        UnloadModel(object.model);
        UnloadTexture(object.texture);
    }
}
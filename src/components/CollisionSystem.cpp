#include "CollisionSystem.h"

BoundingBox GetBoundingBox(Model model, Vector3 pos){
    BoundingBox bb = GetModelBoundingBox(model);
    // bb.min += pos / 2;
    // bb.max += pos / 2;
    bb.min = Vector3Add(bb.min, pos);
    bb.max = Vector3Add(bb.max, pos);
    return bb;
}

bool CheckCollision(BoundingBox bb1, BoundingBox bb2){
    bool collision = CheckCollisionBoxes(bb1, bb2);
    return collision;
}


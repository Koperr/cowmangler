#include "CollisionComponent.h"

BoundingBox GetBoundingBox(Model model, Vector3 pos){
    BoundingBox bb = GetModelBoundingBox(model);
    bb.min += pos / 2;
    bb.max += pos / 2;
    return bb;
}

bool CheckCollision(BoundingBox bb1, BoundingBox bb2){
    bool collision = CheckCollisionBoxes(bb1, bb2);
    return collision;
}


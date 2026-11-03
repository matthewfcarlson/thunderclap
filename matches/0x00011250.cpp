#include "gen/owners.h"
owners::Vec3_11250* owners::Vec3_11250::FUN_00011250(owners::Vec3_11250* out, owners::Vec3_11250* rhs) {
    float dz = z - rhs->z;
    float dy = y - rhs->y;
    float dx = x - rhs->x;
    out->x = dx;
    out->y = dy;
    out->z = dz;
    return out;
}
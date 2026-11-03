#include "gen/owners.h"
owners::Vec3_78750* owners::Vec3_78750::FUN_00078750(owners::Vec3_78750* out, owners::Vec3_78750* other) {
    float z = other->z + this->z;
    float y = other->y + this->y;
    float x = other->x + this->x;
    out->x = x;
    out->y = y;
    out->z = z;
    return out;
}
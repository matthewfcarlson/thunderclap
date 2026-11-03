#include "gen/owners.h"
void owners::Vec_83ba0::FUN_00083ba0(const owners::Vec_83ba0* a) {
    float yy = a->x * z - a->z * x;
    float zz = a->y * x - ((volatile const float*)a)[0] * y;
    float xx = a->z * y - a->y * z;
    x = xx;
    y = yy;
    z = zz;
}
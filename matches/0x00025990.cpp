#include "compat/ptr.h"
struct Vec3 {
    float x, y, z;
};
float __cdecl FUN_00025990(const Vec3* a, const Vec3* b) {
    hulk_freg x = a->x - b->x;
    hulk_freg y = a->y - b->y;
    hulk_freg z = a->z - b->z;
    hulk_freg r = x * x;
    r += z * z;
    r += y * y;
    return r;
}
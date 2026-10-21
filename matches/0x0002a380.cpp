#include "compat/ptr.h"
struct Vec {
    float x, y, z;
};
extern "C" double __cdecl sqrt(double);
hulk_freg __cdecl FUN_0002a380(const Vec* a, const Vec* b) {
    hulk_freg x = a->x - b->x;
    hulk_freg y = a->y - b->y;
    hulk_freg z = a->z - b->z;
    return (hulk_freg)sqrt(y * y + (x * x + z * z));
}
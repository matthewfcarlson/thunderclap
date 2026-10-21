#include "compat/ptr.h"
struct Vec_2fb860 {
    float x, y, z;
};
struct Obj_2fb860 {
    char pad[0x38];
    int mode;
    char pad2[12];
    float sx, sy, sz;
    Vec_2fb860 a, b, c;
    void FUN_002fb860(Vec_2fb860* out, int index);
};
void Obj_2fb860::FUN_002fb860(Vec_2fb860* out, int index) {
    hulk_freg sign = index > 3 ? -1.0f : 1.0f;
    hulk_freg x = sign * sx;
    hulk_freg y = sign * sy;
    hulk_freg z = sign * sz;
    if (index % 4 > 1)
        y = y * -1.0f;
    if (index % 2 == 1)
        z = z * -1.0f;
    if (!mode) {
        out->x = (z * c.x + y * b.x) + x * a.x;
        out->y = (z * c.y + y * b.y) + x * a.y;
        out->z = (z * c.z + y * b.z) + x * a.z;
    } else {
        out->x = x * a.x;
        out->y = y * b.y;
        out->z = z * c.z;
    }
}

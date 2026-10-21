#include "compat/ptr.h"
extern "C" double cos(double);
extern "C" double sin(double);
struct Vec_3059c0 {
    float x, y, z;
    float Len();
};
struct Q_3059c0 {
    float x, y, z, w;
};
bool FUN_003059c0(Vec_3059c0* a, Q_3059c0* b) {
    Vec_3059c0 v = *a;
    bool r = false;
    hulk_freg t = v.Len();
    if (t > 0.0001f) {
        t = t * 0.5f;
        b->w = (hulk_freg)cos(t);
        hulk_freg s = (hulk_freg)sin(t);
        b->x = v.x * s;
        b->y = v.y * s;
        b->z = v.z * s;
        r = true;
    }
    return r;
}
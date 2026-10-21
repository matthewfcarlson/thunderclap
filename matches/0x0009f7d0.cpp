#include "compat/ptr.h"
struct Vec3_9f7d0 {
    float x, y, z;
    bool IsSmall();
};
extern "C" double exp(double);

Vec3_9f7d0 Func(const Vec3_9f7d0* a, const Vec3_9f7d0* b, float t, float tau) {
    hulk_freg f = 1.0f;
    if (tau != 0.0f) {
        f = 1.0f - (hulk_freg)exp((double)(-(t / tau)));
    }
    Vec3_9f7d0 r;
    r.x = (b->x - a->x) * f + a->x;
    r.y = (b->y - a->y) * f + a->y;
    r.z = (b->z - a->z) * f + a->z;
    if (r.IsSmall()) {
        r.z = 0.0f;
        r.y = 0.0f;
        r.x = 0.0f;
    }
    return r;
}

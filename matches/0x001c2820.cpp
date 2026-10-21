#include "compat/ptr.h"
struct Plane {
    float x, y, z, w;
};
struct Volume {
    int count;
    Plane planes[1];
    unsigned char FUN_001c2820(const float* point);
};
unsigned char Volume::FUN_001c2820(const float* point) {
    for (int i = count - 1; i >= 0; --i) {
        const Plane& p = planes[i];
        hulk_freg dot = p.x * point[0] + p.z * point[2];
        dot += p.y * point[1];
        if (!(dot <= point[3] - p.w))
            return 0;
    }
    return 1;
}
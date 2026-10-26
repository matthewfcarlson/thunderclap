// STATUS: equivalent (tools/equiv.py level 3: 982 inputs, branch coverage 11/12; --wine 623 inputs)
// FUN_001c2c90 @ 0x001c2c90
#include "compat/ptr.h"
struct Vec3_1c2c90 {
    float x, y, z;
    void Scale(float s) {
        x = x * s;
        y = y * s;
        z = z * s;
    }
};

class PointSet_1c2c90 {
public:
    Vec3_1c2c90 *FUN_001c2c90(Vec3_1c2c90 *out);

    Vec3_1c2c90 points[32];
    unsigned int count;
};

Vec3_1c2c90 *PointSet_1c2c90::FUN_001c2c90(Vec3_1c2c90 *out)
{
    // The original unrolls by four. x stays in an x87 register (53-bit) across iterations and is stored only after the
    // second and third add; y is stored after the third and fourth; z after each group (see the rounding points below).
    hulk_freg sx = 0.0f;
    volatile float sy = 0.0f;   // volatile: a store/reload (the rounding point) under both compilers
    volatile float sz = 0.0f;
    unsigned int i = 0;
    if (count != 0) {
        if ((int)count >= 4) {
            unsigned int groups = ((count - 4) >> 2) + 1;
            do {
                const Vec3_1c2c90 *p = &points[i];
                hulk_freg x1 = sx + p[0].x;
                volatile float x2 = (float)(x1 + p[1].x);
                volatile float x3 = x2 + p[2].x;
                sx = x3 + p[3].x;
                hulk_freg y1 = sy + p[0].y;
                hulk_freg y2 = y1 + p[1].y;
                volatile float y3 = (float)(y2 + p[2].y);
                sy = y3 + p[3].y;
                volatile float z1 = sz + p[0].z;
                volatile float z3 = (float)((z1 + p[1].z) + p[2].z);
                sz = z3 + p[3].z;
                i += 4;
            } while (--groups);
        }
        for (; i < count; i++) {
            sx = sx + points[i].x;
            sy = sy + points[i].y;
            sz = sz + points[i].z;
        }
        // volatile: the original rounds the reciprocal to float before scaling
        volatile float inv = 1.0f / (float)count;
        out->x = sx * inv;
        out->y = inv * sy;
        out->z = inv * sz;
        return out;
    }
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    return out;
}

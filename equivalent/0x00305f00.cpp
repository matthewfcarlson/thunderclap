// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 6/6)
// FUN_00305f00 @ 0x00305f00
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Vec3_305f00 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_305f00 *other, float eps);
};

float FUN_00018a20(float x);

// Axis (cross product b x a) and angle between two vectors.
void FUN_00305f00(const Vec3_305f00 *a, const Vec3_305f00 *b, Vec3_305f00 *axis, float *angle)
{
    Vec3_305f00 zero;
    float dot;      // x87: dot goes through the frame across the call (rounded)

    hulk_freg v1 = a->x * b->z - a->z * b->x;
    hulk_freg v2 = a->y * b->x - a->x * b->y;
    hulk_freg v3 = a->z * b->y - a->y * b->z;
    axis->x = v3;
    axis->y = v1;
    axis->z = v2;

    dot = a->z * b->z + a->y * b->y + a->x * b->x;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    if (axis->FUN_0022d2b0(&zero, 0.0001f)) {
        if (dot < 0.0f)
            *angle = 3.14159274f;
        else
            *angle = 0.0f;
        axis->x = a->x;
        axis->y = a->y;
        axis->z = a->z;
        return;
    }

    double lenB = sqrt((double)(b->y * b->y + b->z * b->z + b->x * b->x));
    hulk_freg ay = a->y;
    hulk_freg az = a->z;
    hulk_freg ax = a->x;
    double lenA = sqrt((double)(ay * ay + az * az + ax * ax));
    double q = dot / (lenA * lenB);
    hulk_freg c = (float)q;
    if (q >= 1.0f)
        *angle = 0.0f;
    else
        *angle = FUN_00018a20(c);
}

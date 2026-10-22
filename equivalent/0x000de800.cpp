// STATUS: equivalent (tools/equiv.py level 3: 20059 inputs, branch coverage 17/20, incomplete)
// FUN_000de800 @ 0x000de800
#include "compat/ptr.h"
extern "C" double sqrt(double);
extern "C" double fabs(double);

struct Vec3_de800 {
    float x, y, z;
    float FUN_0022d110();
};

float __cdecl FUN_000189c0(float v);

hulk_freg FUN_000de800(float x, float z)
{
    if (fabs(x) <= 1e-5f && fabs(z) <= 1e-5f)
        return 0.0f;

    Vec3_de800 v;
    v.x = x;
    v.y = 0.0f;
    v.z = z;
    v.FUN_0022d110();

    hulk_freg a = v.z * 0.0f - v.y;
    hulk_freg b = v.x - v.z * 0.0f;
    hulk_freg c = v.y * 0.0f - v.x * 0.0f;
    hulk_freg m = sqrt(c * c + b * b + a * a);

    hulk_freg angle;
    if (fabs(m - 1.0f) <= 1e-5f)
        angle = 90.0f;
    else
        angle = FUN_000189c0(m) * 57.2957764f;

    if (x >= 0.0f) {
        if (z >= 0.0f)
            angle = angle + 270.0f;
        else if (z < 0.0f)
            angle = 90.0f - angle;
    } else if (x < 0.0f) {
        if (z < 0.0f)
            angle = angle + 90.0f;
        else if (z >= 0.0f)
            angle = 270.0f - angle;
    }
    if (angle == 360.0f)
        angle = 0.0f;
    return angle;
}

// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 10/10)
// FUN_00083080 @ 0x00083080
#include "compat/ptr.h"
struct Vec3_83080 {
    float x, y, z;
};

class Xform_83080 {
public:
    void FUN_0022c3b0(Vec3_83080 *in, Vec3_83080 *out);
    void FUN_0022cc90(Vec3_83080 *v);
};

void __cdecl FUN_00224d70(float angle, Vec3_83080 *axis);

class Aligner {
public:
    char pad0[0x1d];
    bool useXform;
    char pad1e[0x0e];
    Vec3_83080 dir;
    bool FUN_00083080(Xform_83080 *xf, Vec3_83080 *target, float angle);
};

bool Aligner::FUN_00083080(Xform_83080 *xf, Vec3_83080 *target, float angle)
{
    if (useXform) {
        Vec3_83080 up;
        Vec3_83080 rotated;
        up.x = 0.0f;
        up.y = 0.0f;
        up.z = 1.0f;
        xf->FUN_0022c3b0(&up, &rotated);
        hulk_freg d = rotated.y * target->y + rotated.x * target->x + rotated.z * target->z;
        if (d < -0.99f)
            return false;
        hulk_freg c = rotated.z * target->x - rotated.x * target->z;
        if (c > 0.0f)
            FUN_00224d70(-angle, &rotated);
        else
            FUN_00224d70(angle, &rotated);
        xf->FUN_0022cc90(&rotated);
        return true;
    }
    hulk_freg d = dir.y * target->y + dir.z * target->z + dir.x * target->x;
    if (d > 0.99f)
        return false;
    hulk_freg c = dir.z * target->x - dir.x * target->z;
    if (c > 0.0f)
        FUN_00224d70(-angle, &dir);
    else
        FUN_00224d70(angle, &dir);
    return true;
}

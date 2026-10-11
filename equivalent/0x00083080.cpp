// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_00083080 @ 0x00083080
struct Vec3 {
    float x, y, z;
};

class Xform {
public:
    void FUN_0022c3b0(Vec3 *in, Vec3 *out);
    void FUN_0022cc90(Vec3 *v);
};

void __cdecl FUN_00224d70(float angle, Vec3 *axis);

class Aligner {
public:
    char pad0[0x1d];
    bool useXform;
    char pad1e[0x0e];
    Vec3 dir;
    bool FUN_00083080(Xform *xf, Vec3 *target, float angle);
};

bool Aligner::FUN_00083080(Xform *xf, Vec3 *target, float angle)
{
    if (useXform) {
        Vec3 up;
        Vec3 rotated;
        up.x = 0.0f;
        up.y = 0.0f;
        up.z = 1.0f;
        xf->FUN_0022c3b0(&up, &rotated);
        float d = rotated.y * target->y + rotated.x * target->x + rotated.z * target->z;
        if (d < -0.99f)
            return false;
        float c = rotated.z * target->x - rotated.x * target->z;
        if (c > 0.0f)
            FUN_00224d70(-angle, &rotated);
        else
            FUN_00224d70(angle, &rotated);
        xf->FUN_0022cc90(&rotated);
        return true;
    }
    float d = dir.y * target->y + dir.z * target->z + dir.x * target->x;
    if (d > 0.99f)
        return false;
    float c = dir.z * target->x - dir.x * target->z;
    if (c > 0.0f)
        FUN_00224d70(-angle, &dir);
    else
        FUN_00224d70(angle, &dir);
    return true;
}

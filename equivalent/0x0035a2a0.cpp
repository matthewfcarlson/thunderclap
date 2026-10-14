// STATUS: equivalent (tools/equiv.py level 3: 137 inputs, branch coverage 10/10)
// FUN_0035a2a0 @ 0x0035a2a0
struct Vec3_35a2a0 {
    float x, y, z;
};

struct Hull_35a2a0 {
    char pad0[0x3c];
    void FUN_00357740(Vec3_35a2a0 *p, Vec3_35a2a0 axisX, Vec3_35a2a0 axisY, Vec3_35a2a0 axisZ, Vec3_35a2a0 *q);
};

bool __cdecl FUN_00359510(Vec3_35a2a0 *a1, Vec3_35a2a0 *a2, Vec3_35a2a0 *a3, Vec3_35a2a0 *a4, Vec3_35a2a0 *a5, Vec3_35a2a0 *a6, Vec3_35a2a0 *a7, Vec3_35a2a0 *a8, Vec3_35a2a0 *a9, int f0, int f1, int f2);
void __cdecl FUN_0035a190(Hull_35a2a0 *hull, Vec3_35a2a0 *a6, Vec3_35a2a0 *a7, Vec3_35a2a0 *a8, int *count, Vec3_35a2a0 *out);
float __cdecl FUN_00359860(Vec3_35a2a0 *a1, Vec3_35a2a0 *a2, Vec3_35a2a0 *a3, Vec3_35a2a0 *a4, Vec3_35a2a0 *a5, Vec3_35a2a0 *dir, Vec3_35a2a0 *point);

// Oriented-box overlap: centroid of the clipped contact points and penetration along the reversed direction.
bool FUN_0035a2a0(Vec3_35a2a0 *a1, Vec3_35a2a0 *a2, Vec3_35a2a0 *axisX, Vec3_35a2a0 *axisY, Vec3_35a2a0 *axisZ, Vec3_35a2a0 *a6, Vec3_35a2a0 *a7, Vec3_35a2a0 *a8,
                  Vec3_35a2a0 *dir, float *depth, Vec3_35a2a0 *centre, Vec3_35a2a0 *normal)
{
    struct Frame {
        Vec3_35a2a0 neg;
        int count;
        Hull_35a2a0 hull;
        Vec3_35a2a0 pts[12];
    } f;

    if (!FUN_00359510(a1, a2, axisX, axisY, axisZ, a6, a7, a8, dir, 1, 1, 1))
        return false;

    f.hull.FUN_00357740(a1, *axisX, *axisY, *axisZ, a2);
    FUN_0035a190(&f.hull, a6, a7, a8, &f.count, f.pts);
    if (f.count == 0)
        return false;

    centre->z = 0.0f;
    centre->y = 0.0f;
    centre->x = 0.0f;
    if (f.count > 0) {
        float sx = 0.0f;
        float sy = 0.0f;
        float sz = 0.0f;
        const Vec3_35a2a0 *p = f.pts;
        int n = f.count;
        do {
            sx += p->x;
            sy += p->y;
            sz += p->z;
            ++p;
            --n;
        } while (n != 0);
        centre->z = sz;
        centre->y = sy;
        centre->x = sx;
    }
    float inv = 1.0f / (float)f.count;
    centre->x = inv * centre->x;
    centre->y = inv * centre->y;
    centre->z = inv * centre->z;

    f.neg.x = dir->x * -1.0f;
    f.neg.y = dir->y * -1.0f;
    f.neg.z = dir->z * -1.0f;
    float d = FUN_00359860(a1, a2, axisX, axisY, axisZ, &f.neg, centre);
    *depth = d;
    if (!(d > 0.0f)) {
        *normal = *dir;
        return true;
    }
    return false;
}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_00359260 @ 0x00359260
extern "C" double __cdecl sqrt(double);

struct Vec3_359260 {
    float x, y, z;
};

static inline float fabsf_(float f)
{
    union { float f; unsigned int u; } x;
    x.f = f;
    x.u &= 0x7fffffff;
    return x.f;
}

bool FUN_003577c0(Vec3_359260* p, Vec3_359260* a, Vec3_359260* b, Vec3_359260* c, Vec3_359260* n);
void FUN_00357ea0(Vec3_359260* origin, Vec3_359260* a, Vec3_359260* b, Vec3_359260* c, Vec3_359260* closest, bool e0, bool e1, bool e2);

// Ray/plane distance plus triangle containment test; falls back to the closest edge point.
bool FUN_00359260(Vec3_359260* origin, float eps, Vec3_359260* a, Vec3_359260* b, Vec3_359260* c, Vec3_359260* normal,
                  float* dist, Vec3_359260* hit, Vec3_359260* outDir, bool e0, bool e1, bool e2)
{
    float d = (origin->z - b->z) * normal->z + (origin->x - b->x) * normal->x + (origin->y - b->y) * normal->y;
    *dist = d;
    if (fabsf_(d) > eps)
        return false;

    float mx = d * normal->x;
    volatile float my = d * normal->y;
    volatile float mz = d * normal->z;
    hit->x = origin->x - mx;
    hit->y = origin->y - my;
    hit->z = origin->z - mz;

    if (FUN_003577c0(hit, a, b, c, normal)) {
        *outDir = *normal;
        *dist = *dist - eps;
        return true;
    }

    if (!e0 && !e1 && !e2)
        return false;

    FUN_00357ea0(origin, a, b, c, hit, e0, e1, e2);

    outDir->x = origin->x - hit->x;
    outDir->y = origin->y - hit->y;
    outDir->z = origin->z - hit->z;
    float len2 = outDir->z * outDir->z + outDir->y * outDir->y + outDir->x * outDir->x;
    if (eps * eps < len2)
        return false;

    if (!(fabsf_(len2) <= 0.00001f)) {
        float len = (float)sqrt(len2);
        *dist = len;
        float inv = 1.0f / len;
        outDir->x = outDir->x * inv;
        outDir->y = outDir->y * inv;
        outDir->z = outDir->z * inv;
    } else {
        *dist = 0.0f;
        *outDir = *normal;
    }
    *dist = *dist - eps;
    return true;
}

// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 36/36)
// FUN_002f0230 @ 0x002f0230
struct V3 {
    float x, y, z;
};

extern const float DAT_003f5cf8;

bool __cdecl FUN_002f01c0(const V3 *origin, const V3 *extent);

union FBits {
    float f;
    unsigned int u;
};

static float absf(float v)
{
    FBits b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

float FUN_002f0230(const V3 *origin, const V3 *dir, const V3 *extent)
{
    float tx = 2.0f;
    float ty = 2.0f;
    float tz = DAT_003f5cf8;

    if (FUN_002f01c0(origin, extent))
        return 0.0f;

    if (origin->x * dir->x < 0.0f) {
        tx = absf(origin->x) - extent->x;
        bool hit = tx >= 0.0f && tx <= absf(dir->x);
        if (hit) {
            tx = tx / absf(dir->x);
            hit = !(absf(tx * dir->y + origin->y) >= extent->y) && !(absf(tx * dir->z + origin->z) >= extent->z);
        }
        if (!hit)
            tx = 2.0f;
    }
    if (origin->y * dir->y < 0.0f) {
        ty = absf(origin->y) - extent->y;
        bool hit = ty >= 0.0f && ty <= absf(dir->y);
        if (hit) {
            ty = ty / absf(dir->y);
            hit = !(absf(ty * dir->x + origin->x) >= extent->x) && !(absf(ty * dir->z + origin->z) >= extent->z);
        }
        if (!hit)
            ty = 2.0f;
    }
    if (origin->z * dir->z < 0.0f) {
        tz = absf(origin->z) - extent->z;
        bool hit = tz >= 0.0f && tz <= absf(dir->z);
        if (hit) {
            tz = tz / absf(dir->z);
            hit = !(absf(tz * dir->x + origin->x) >= extent->x) && !(absf(tz * dir->y + origin->y) >= extent->y);
        }
        if (!hit)
            tz = DAT_003f5cf8;
    }
    float r = tz;
    if (ty < r)
        r = ty;
    if (tx < r)
        r = tx;
    return r;
}

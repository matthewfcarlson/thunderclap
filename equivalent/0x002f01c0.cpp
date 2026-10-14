// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002f01c0 @ 0x002f01c0
struct Vec3_2f01c0 { float x, y, z; };

union FloatBits_2f01c0 {
    float f;
    unsigned int u;
};

// True when |a| <= limit on every axis (NaN fails).
int FUN_002f01c0(const Vec3_2f01c0* a, const Vec3_2f01c0* limit)
{
    FloatBits_2f01c0 t;
    t.f = a->x;
    t.u &= 0x7fffffff;
    if (!(t.f <= limit->x))
        return 0;
    t.f = a->y;
    t.u &= 0x7fffffff;
    if (!(t.f <= limit->y))
        return 0;
    t.f = a->z;
    t.u &= 0x7fffffff;
    if (!(t.f <= limit->z))
        return 0;
    return 1;
}

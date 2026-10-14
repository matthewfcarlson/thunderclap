// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001ad730 @ 0x001ad730
struct Vec3 { float x, y, z; };
struct Skeleton {
    void FUN_001b5760(int a);
    Vec3* FUN_001b56a0(int a, int axis);
};

union FloatBits {
    float f;
    unsigned u;
};

// True when the extent of the points along y is at most 0.7.
bool __cdecl FUN_001ad730(int a, Skeleton** skel)
{
    Skeleton* s = *skel;
    s->FUN_001b5760(a);
    float hi = -1000000000000.0f;
    float lo = 1000000000000.0f;
    for (int i = 0; i < 3; i++) {
        Vec3* p = s->FUN_001b56a0(a, i);
        if (hi < p->y)
            hi = p->y;
        if (!(lo < p->y))
            lo = p->y;
    }
    FloatBits d;
    d.f = hi - lo;
    d.u &= 0x7fffffff;
    return 0.7f >= d.f;
}

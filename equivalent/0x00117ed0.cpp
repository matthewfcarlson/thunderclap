// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 18/20, incomplete)
// hulkfight::ai::LocatorDistanceCondition::vfunc_6 @ 0x00117ed0
#include "decls/address.h"
extern "C" double sqrt(double);

struct Vec3_117ed0 {
    float x, y, z;
};

struct Frame_117ed0 {
    Vec3_117ed0 origin;
    Vec3_117ed0 target;
};

namespace fight {
class Params {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v3();
    virtual void v4();
};

class Locator {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(Vec3_117ed0 *out);
};

struct Finder_117ed0 {
    Locator *FUN_001fc8c0(int lo, int hi);
};

struct Anchor_117ed0 {
    void FUN_00059a50(Vec3_117ed0 *out);
};

struct Registry_117ed0 {
    char pad0[0x10];
    Anchor_117ed0 *anchor;
    char pad14[0x1d70 - 0x14];
    int handleLo;
    int handleHi;
};

struct Owner_117ed0 { char pad[4]; };

struct World {
    char pad0[0x28];
    Finder_117ed0 *finder;
};


Owner_117ed0 *__fastcall FUN_000592a0(void *x);
Registry_117ed0 *__fastcall FUN_00059a30(Owner_117ed0 *o);
bool __cdecl FUN_00018960(float a, float b, float eps);

struct LocatorDistanceCondition {
    char pad0[0xc];
    int mode;
    float threshold;
    bool FUN_00117ed0(int a1, fight::Params *params, int a3);
};

bool LocatorDistanceCondition::FUN_00117ed0(int a1, fight::Params *params, int a3)
{
    Frame_117ed0 f;

    if (!dynamic_cast<CFightParams *>(params))
        return false;

    Registry_117ed0 *reg = FUN_00059a30(FUN_000592a0(params));
    f.origin.x = 0.0f;
    f.origin.y = 0.0f;
    f.origin.z = 0.0f;
    reg->anchor->FUN_00059a50(&f.origin);

    int lo = reg->handleLo;
    int hi = reg->handleHi;
    if ((lo | hi) == 0)
        return false;

    Locator *loc = DAT_004dd700->finder->FUN_001fc8c0(lo, hi);
    if (!loc)
        return false;

    loc->v8(&f.target);
    float dx = f.target.x - f.origin.x;
    unsigned int m = (unsigned int)mode;
    float dz = f.target.z - f.origin.z;
    float dist = (float)sqrt(dz * dz + dx * dx);
    if (m > 5)
        return false;

    switch (m) {
    case 0:
        return dist < threshold;
    case 1:
        return dist <= threshold;
    case 2:
        return FUN_00018960(dist, threshold, 0.00001f);
    case 3:
        return !FUN_00018960(dist, threshold, 0.00001f);
    case 4:
        return dist >= threshold;
    default:
        return dist > threshold;
    }
}

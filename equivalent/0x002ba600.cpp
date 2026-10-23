// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 8/8)
// pure3d::BillboardCutOffQuadGroup::vfunc_11 @ 0x002ba600
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Vec2_2ba600 {
    float a, b;
};

struct Vec3_2ba600 {
    float x, y, z;
};

struct Probe_2ba600 {
    char pad00[0x30];
    Vec3_2ba600 pos;
};

union Slot_2ba600 {
    Probe_2ba600* p;
    float f;
    unsigned int u;
};

struct Frame_2ba600 {
    float outB0;
    float outA1;
    float outA0;
    float dx;
    float dy;
    float dz;
    Vec3_2ba600 normal;
    float spare[3];
};

void FUN_002b8840(float* out0, float* out1, int p98, const Vec2_2ba600* r0, const Vec2_2ba600* r1, Probe_2ba600* a, Vec3_2ba600* normal);
void FUN_002b8b30(float* out0, float* out1, int p9c, const Vec2_2ba600* r0, const Vec2_2ba600* r1, Probe_2ba600* b, Vec3_2ba600* normal);

namespace pure3d {

class BillboardCutOffQuadGroup {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual hulk_freg vfunc_11(Slot_2ba600 a, Slot_2ba600 b);

    char pad04[0x98 - 4];
    int field98;
    int field9c;
    int mode;
    Vec2_2ba600 rangeA4;
    Vec2_2ba600 rangeAC;
    Vec2_2ba600 rangeB4;
    Vec2_2ba600 rangeBC;
    float fadeStart;
    float fadeEnd;
};

hulk_freg BillboardCutOffQuadGroup::vfunc_11(Slot_2ba600 a, Slot_2ba600 b)
{
    Probe_2ba600* pa = a.p;
    Probe_2ba600* pb = b.p;
    Frame_2ba600 f;

    f.dx = pb->pos.x - pa->pos.x;
    f.dy = pb->pos.y - pa->pos.y;
    f.dz = pb->pos.z - pa->pos.z;
    double xy = f.dx * f.dx + f.dy * f.dy; // MSVC reorders three-term sums; dz is reloaded (rounded)
    a.f = (float)sqrt(xy + *(volatile float *)&f.dz * *(volatile float *)&f.dz);

    unsigned int bits = a.u;
    b.u = bits & 0x7fffffff;
    hulk_freg nx;
    hulk_freg ny;
    if (!(b.f <= 1e-5f)) {
        b.f = 1.0f / a.f;
        nx = (1.0f / a.f) * f.dx; // nx uses the unrounded quotient, ny and dz the stored (rounded) one
        ny = b.f * f.dy;
        f.dz = b.f * f.dz;
    } else {
        nx = 0.0f;
        ny = 0.0f;
        f.dz = 0.0f;
    }
    f.normal.x = -nx;
    f.normal.y = -ny;
    f.normal.z = -f.dz;

    f.outA0 = 1.0f;
    f.outA1 = 1.0f;
    FUN_002b8840(&f.outA0, &f.outA1, field98, &rangeA4, &rangeAC, pa, &f.normal);
    f.outB0 = 1.0f;
    b.f = 1.0f;
    FUN_002b8b30(&f.outB0, &b.f, field9c, &rangeB4, &rangeBC, pb, &f.normal);

    hulk_freg w = 1.0f;
    if (mode == 1) {
        if (a.f < fadeStart) {
            w = 1.0f;
        } else if (a.f < fadeEnd) {
            w = 1.0f - (a.f - fadeStart) / (fadeEnd - fadeStart);
        } else {
            w = 0.0f;
        }
    }
    // MSVC reassociates the product chain; spell the original's order
    double p1 = w * b.f;
    double p2 = p1 * f.outB0;
    double p3 = p2 * f.outA1;
    return p3 * f.outA0;
}

}

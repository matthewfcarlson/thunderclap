// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 7/8, incomplete)
// pure3d::BillboardCutOffQuadGroup::vfunc_11 @ 0x002ba600
extern "C" double sqrt(double);

struct Vec2 {
    float a, b;
};

struct Vec3 {
    float x, y, z;
};

struct Probe {
    char pad00[0x30];
    Vec3 pos;
};

union Slot {
    Probe* p;
    float f;
    unsigned int u;
};

struct Frame {
    float outB0;
    float outA1;
    float outA0;
    float dx;
    float dy;
    float dz;
    Vec3 normal;
    float spare[3];
};

void FUN_002b8840(float* out0, float* out1, int p98, const Vec2* r0, const Vec2* r1, Probe* a, Vec3* normal);
void FUN_002b8b30(float* out0, float* out1, int p9c, const Vec2* r0, const Vec2* r1, Probe* b, Vec3* normal);

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
    virtual float vfunc_11(Slot a, Slot b);

    char pad04[0x98 - 4];
    int field98;
    int field9c;
    int mode;
    Vec2 rangeA4;
    Vec2 rangeAC;
    Vec2 rangeB4;
    Vec2 rangeBC;
    float fadeStart;
    float fadeEnd;
};

float BillboardCutOffQuadGroup::vfunc_11(Slot a, Slot b)
{
    Probe* pa = a.p;
    Probe* pb = b.p;
    Frame f;

    f.dx = pb->pos.x - pa->pos.x;
    f.dy = pb->pos.y - pa->pos.y;
    f.dz = pb->pos.z - pa->pos.z;
    a.f = (float)sqrt(f.dx * f.dx + f.dy * f.dy + f.dz * f.dz);

    unsigned int bits = a.u;
    b.u = bits & 0x7fffffff;
    float nx;
    float ny;
    if (!(b.f <= 1e-5f)) {
        b.f = 1.0f / a.f;
        nx = b.f * f.dx;
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

    float w = 1.0f;
    if (mode == 1) {
        if (a.f < fadeStart) {
            w = 1.0f;
        } else if (a.f < fadeEnd) {
            w = 1.0f - (a.f - fadeStart) / (fadeEnd - fadeStart);
        } else {
            w = 0.0f;
        }
    }
    return w * b.f * f.outB0 * f.outA1 * f.outA0;
}

}

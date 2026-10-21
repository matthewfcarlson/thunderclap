// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 6/6)
// FUN_003024d0 @ 0x003024d0
#include "compat/ptr.h"
struct Vec3_3024d0 {
    float x, y, z;
};

union FloatBits_3024d0 {
    float f;
    unsigned int u;
};

static float Abs(float v)
{
    FloatBits_3024d0 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

class Other_3024d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_3024d0 *vfunc_4();
    char pad04[0x30];
    float margin;
};

class Box_3024d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_3024d0 *vfunc_4();
    char pad04[0x34];
    int axisAligned;
    char pad3c[0x48 - 0x3c];
    float extentX;
    float extentY;
    float extentZ;
    Vec3_3024d0 axisX;
    Vec3_3024d0 axisY;
    Vec3_3024d0 axisZ;
};

// Signed distance bound of a point-ish object against an oriented (or axis-aligned) box: max over axes.
hulk_freg __cdecl FUN_003024d0(Box_3024d0 *box, Other_3024d0 *other)
{
    Vec3_3024d0 *p = other->vfunc_4();
    Vec3_3024d0 *q = box->vfunc_4();
    Vec3_3024d0 d;
    d.x = q->x - p->x;
    d.y = q->y - p->y;
    d.z = q->z - p->z;

    double a; // register value in the original (b and c are frame copies)
    volatile float b;
    volatile float c;
    if (box->axisAligned == 0) {
        float dotX = d.z * box->axisX.z + d.y * box->axisX.y + d.x * box->axisX.x;
        a = Abs(dotX) - (box->extentX + other->margin);
        float dotY = d.z * box->axisY.z + d.y * box->axisY.y + d.x * box->axisY.x;
        b = Abs(dotY) - (box->extentY + other->margin);
        float dotZ = d.z * box->axisZ.z + d.y * box->axisZ.y + d.x * box->axisZ.x;
        c = Abs(dotZ) - (box->extentZ + other->margin);
    } else {
        a = Abs(d.x) - (box->extentX + other->margin);
        b = Abs(d.y) - (box->extentY + other->margin);
        c = Abs(d.z) - (box->extentZ + other->margin);
    }
    double best = a;
    if (best < b)
        best = b;
    if (best < c)
        best = c;
    return best;
}

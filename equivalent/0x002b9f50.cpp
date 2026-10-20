// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 22/28, incomplete)
// pure3d::BillboardQuadGroup::vfunc_10 @ 0x002b9f50
#include "compat/ptr.h"
struct Matrix {
    float m[16];
};

struct Sphere_2b9f50 {
    int w[4];
};

struct Vec3_2b9f50 {
    float x, y, z;
    void FUN_0022d210(Matrix* m);
    Sphere_2b9f50* FUN_000a8890(Sphere_2b9f50* out);
};

struct Quad_2b9f50 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Update();      // slot 5
    char pad04[0xc];
    Vec3_2b9f50 lo;                    // 0x10
    Vec3_2b9f50 hi;                    // 0x1c
};

// scratch block: in the original the callee's output buffer overlaps the last box corner
struct Frame_2b9f50 {
    Vec3_2b9f50 p;
    Vec3_2b9f50 q;
    Vec3_2b9f50 hi;
    Vec3_2b9f50 lo;
    int tail;
};

namespace pure3d {
class BillboardQuadGroup {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();

    char pad04[0x10];
    Vec3_2b9f50 min;                   // 0x14
    Vec3_2b9f50 max;                   // 0x20
    int sphere[4];              // 0x2c
    char pad3c[4];
    Matrix matrix;              // 0x40
    char pad80[0x8c - 0x80];
    Quad_2b9f50** begin;               // 0x8c
    Quad_2b9f50** end;                 // 0x90
};

void BillboardQuadGroup::vfunc_10()
{
    Frame_2b9f50 f;
    unsigned int i;
    hulk_uintptr n;

    max.x = 0.0f;
    max.y = 0.0f;
    max.z = 0.0f;
    min.x = 0.0f;
    min.y = 0.0f;
    min.z = 0.0f;
    sphere[0] = 0;
    sphere[1] = 0;
    sphere[2] = 0;
    sphere[3] = 0;

    n = end - begin;
    if (n == 0)
        return;
    for (i = 0; i < n; i++) {
        begin[i]->Update();
        Quad_2b9f50* q = begin[i];
        f.hi = q->hi;
        f.lo = q->lo;
        max.x = (max.x < f.hi.x) ? f.hi.x : max.x;
        max.y = (max.y < f.hi.y) ? f.hi.y : max.y;
        max.z = (max.z < f.hi.z) ? f.hi.z : max.z;
        min.x = (min.x < f.lo.x) ? min.x : f.lo.x;
        min.y = (min.y < f.lo.y) ? min.y : f.lo.y;
        min.z = (min.z < f.lo.z) ? min.z : f.lo.z;
    }

    f.p = max;
    f.q = min;
    f.p.FUN_0022d210(&matrix);
    f.q.FUN_0022d210(&matrix);
    max.x = (f.p.x < f.q.x) ? f.q.x : f.p.x;
    max.y = (f.p.y < f.q.y) ? f.q.y : f.p.y;
    max.z = (f.p.z < f.q.z) ? f.q.z : f.p.z;
    min.x = (f.p.x < f.q.x) ? f.p.x : f.q.x;
    min.y = (f.p.y < f.q.y) ? f.p.y : f.q.y;
    min.z = (f.p.z < f.q.z) ? f.p.z : f.q.z;
    Sphere_2b9f50* s = min.FUN_000a8890((Sphere_2b9f50*)&f.lo);
    sphere[0] = s->w[0];
    sphere[1] = s->w[1];
    sphere[2] = s->w[2];
    sphere[3] = s->w[3];
}
}

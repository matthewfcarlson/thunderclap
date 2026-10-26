// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 4/4; --wine 617 inputs)
// physics::PhysicsJoint1D::vfunc_12 @ 0x0030c110
extern "C" double sqrt(double);
#include "compat/ptr.h"

struct V3_30c110 {
    float x, y, z;
};

struct Part_30c110 {
    char pad0[0x10];
    float h0;
    float h1;
    float h2;
    void FUN_002fd730();
};

struct Mid_30c110 {
    char pad0[0x8c];
    Part_30c110 *part;
};

struct Gp {
    char pad0[0x1c];
    V3_30c110 vec;
};

struct Owner_30c110 {
    char pad0[0x10];
    Mid_30c110 *mid;
    char pad14[8];
    Gp *gp;
};

class PhysicsJoint1D {
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
    virtual void v11();
    virtual void vfunc_12(float a1, float a2, float a3, float a4, V3_30c110 *e, V3_30c110 *f, float a7);

    char pad4[0x14];
    Owner_30c110 *owner;
    char pad1c[0x80 - 0x1c];
    V3_30c110 bAxis;
    char pad8c[0xe4 - 0x8c];
    float k;
    char padE8[0xfc - 0xe8];
    V3_30c110 aAxis;
    char pad108[0x10c - 0x108];
    float accum;

    float FUN_0030b2c0(float x);
};

void PhysicsJoint1D::vfunc_12(float a1, float a2, float a3, float a4, V3_30c110 *e, V3_30c110 *f, float a7)
{
    float cx = aAxis.y * bAxis.z - aAxis.z * bAxis.y;
    float cy = aAxis.z * bAxis.x - aAxis.x * bAxis.z;
    hulk_freg czr = aAxis.x * bAxis.y - aAxis.y * bAxis.x;
    float cz = (float)czr;  // stored (`fst`), but the register copy is what the first square multiplies
    float len = (float)sqrt(czr * cz + cy * cy + cx * cx);
    Owner_30c110 *o = owner;
    float t5 = -((cz * e->z + cx * e->x + cy * e->y) * a1);
    float t6 = -((cz * f->z + cy * f->y + cx * f->x) * a2);
    V3_30c110 *g = &o->gp->vec;
    float t1 = (cz * g->z + cy * g->y + cx * g->x) * a3;
    if (a4 != 0.0f) {
        Part_30c110 *p = o->mid->part;
        p->FUN_002fd730();
        if (p->h0 * p->h0 + p->h1 * p->h1 + p->h2 * p->h2 > 0.00001f) {
            p = owner->mid->part;
            p->FUN_002fd730();
            t1 = ((e->x * p->h1 - e->y * p->h0) * cz + (e->z * p->h0 - e->x * p->h2) * cy +
                  (e->y * p->h2 - e->z * p->h1) * cx) * a4 + t1;
        }
    }
    float x = (t1 + t6 + t5) / len * k * a7;
    accum = accum + FUN_0030b2c0(x) * x;
}

// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 43/46, incomplete)
// CCollisionAction::vfunc_8 @ 0x0001a330
#include "decls/address.h"
struct V3_1a330 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat4_1a330 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(V3_1a330 *in, V3_1a330 *out);
};

struct Id64_1a330 {
    unsigned int lo, hi;
};

struct Obj6_1a330 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Mat4_1a330 *m, float dt);
};

struct Inner_1a330 {
    char pad0[0x10];
    char flag10;
};

struct Timing_1a330 {
    char pad0[0x11c];
    Inner_1a330 *f11c;
    char pad120[0x1d70 - 0x120];
    Id64_1a330 id1d70;
};

struct Frames_1a330 {
    char pad0[0x1c];
    Mat4_1a330 *f1c;
};

struct SkelData {
    char pad0[0x64];
    Frames_1a330 *f64;
};

struct Cfg_1a330 {
    char pad0[0x20];
    V3_1a330 v20;
    float f2c;
    int f30;
    int f34;
    char pad38[0x44 - 0x38];
    int f44;
    char pad48[0x70 - 0x48];
    Id64_1a330 id70;
};

struct Placed {
    V3_1a330 *FUN_001d6b40();
};

struct WorldSys_1a330 {
    Placed *FUN_001dee40(unsigned int lo, unsigned int hi);
};

struct World {
    char pad0[0xc];
    WorldSys_1a330 *f0c;
};

struct Clock_1a330 {
    Timing_1a330 *FUN_00059a30();
    SkelData *FUN_00059a40();
};

struct Target_1a330 {
    Clock_1a330 *FUN_000592a0();
};

class CCollisionAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual bool vfunc_8(float dt);
    char pad04[0x1c - 4];
    Target_1a330 *target;        // 0x1c
    Cfg_1a330 *cfg;              // 0x20
    int f24;
    V3_1a330 pos;                // 0x28
    int f34x;
    int f38x;
    Obj6_1a330 *f3c;

    void FUN_0001a050(V3_1a330 *a, V3_1a330 *b);
    char FUN_00013ed0();
};

struct Frame_1a330 {
    int tmp10;             // 0x10
    float lim;             // 0x14
    float len;             // 0x18
    V3_1a330 hit;                // 0x1c
    V3_1a330 dir;                // 0x28
    V3_1a330 step;               // 0x34
    V3_1a330 acc;                // 0x40
    Mat4_1a330 mat;              // 0x4c
};

bool CCollisionAction::vfunc_8(float dt)
{
    Frame_1a330 f;
    Clock_1a330 *clock = target->FUN_000592a0();
    Timing_1a330 *timing = clock->FUN_00059a30();
    SkelData *skel = clock->FUN_00059a40();
    Mat4_1a330 *xf = &skel->f64->f1c[f24];
    Cfg_1a330 *c = cfg;
    Id64_1a330 *id = &c->id70;
    if (id && (id->lo | id->hi)) {
        unsigned int lo = timing->id1d70.lo;
        unsigned int hi = timing->id1d70.hi;
        if (lo | hi) {
            Placed *p = DAT_004dd700->f0c->FUN_001dee40(lo, hi);
            if (p) {
                V3_1a330 *v = p->FUN_001d6b40();
                f.hit.x = v->x;
                f.hit.y = v->y;
                f.hit.z = v->z;
                V3_1a330 *q = &cfg->v20;
                f.acc.x = q->x;
                f.acc.y = q->y;
                f.acc.z = q->z;
                f.hit.x = f.acc.x + f.hit.x;
                f.hit.y = f.acc.y + f.hit.y;
                f.hit.z = f.acc.z + f.hit.z;
            }
        }
    } else {
        V3_1a330 *q = &c->v20;
        f.acc.x = q->x;
        f.acc.y = q->y;
        f.acc.z = q->z;
        xf->FUN_0022c2b0(&f.acc, &f.hit);
    }

    f.dir.x = f.hit.x - pos.x;
    f.dir.y = f.hit.y - pos.y;
    f.dir.z = f.hit.z - pos.z;
    f.len = f.dir.FUN_0022d110();
    c = cfg;
    f.lim = c->f2c * 2.0f;
    if (c->f44 != 1) {
        float lenv = f.len;
        float a = f.lim;
        if (lenv < a) {
            FUN_0001a050(&f.hit, &f.dir);
        } else {
            f.tmp10 = *(int *)&f.lim & 0x7fffffff;
            if (*(float *)&f.tmp10 <= 1e-5f) {
                FUN_0001a050(&f.hit, &f.dir);
            } else {
                double q = f.len / f.lim;
                int n = (int)q;
                if (q - n > 0.0f)
                    n++;
                if (n > 0x40)
                    n = 0x40;
                double sl = f.len / n;
                f.acc.x = pos.x;
                f.step.x = f.dir.x;
                f.acc.y = pos.y;
                f.step.y = f.dir.y;
                f.acc.z = pos.z;
                f.step.z = f.dir.z;
                f.step.x = f.step.x * sl;
                f.step.y = f.step.y * sl;
                f.step.z = f.step.z * sl;
                for (int i = 0; i < n; i++) {
                    f.acc.x = f.acc.x + f.step.x;
                    f.acc.y = f.acc.y + f.step.y;
                    f.acc.z = f.acc.z + f.step.z;
                    FUN_0001a050(&f.acc, &f.dir);
                    if (FUN_00013ed0())
                        break;
                }
            }
        }
    }

    if (f24 && f3c) {
        f.mat.FUN_0022b980();
        f.mat.m[12] = f.hit.x;
        f.mat.m[13] = f.hit.y;
        f.mat.m[14] = f.hit.z;
        f3c->v6(&f.mat, dt);
    }
    pos.x = f.hit.x;
    pos.y = f.hit.y;
    pos.z = f.hit.z;

    Timing_1a330 *t = target->FUN_000592a0()->FUN_00059a30();
    if (t && t->f11c && t->f11c->flag10)
        return true;
    c = cfg;
    return !(c->f30 > 0 && f34x >= c->f30 && c->f34 > 0 && f38x >= c->f34);
}

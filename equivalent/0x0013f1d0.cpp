// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 18/18)
// hulkfight::motion::WallExitAction::vfunc_3 @ 0x0013f1d0
#include "decls/address.h"
extern "C" double sqrt(double);
extern "C" void *__cdecl FUN_00263ea0(unsigned int size) throw();

union Bits_13f1d0 {
    float f;
    unsigned int u;
};

struct V3_13f1d0 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(V3_13f1d0 *other, float eps);
    void Scale(float s) { x = s * x; y = s * y; z = s * z; }
    void Add(const V3_13f1d0 &o) { x = o.x + x; y = o.y + y; z = o.z + z; }
};

struct Name_13f1d0 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(V3_13f1d0 *axis, float angle);
    void FUN_0022c3b0(V3_13f1d0 *in, V3_13f1d0 *out);
};

class JointDriver_13f1d0 {
public:
    virtual void AddRef();
    char pad4[4];
    Name_13f1d0 name;
    JointDriver_13f1d0 *FUN_002248f0(int a);
};

struct Tracker_13f1d0 {
    void FUN_00222890(JointDriver_13f1d0 *d, float a, float b, float c, float e, float f, float g);
};

struct Fighter_13f1d0 {
    struct Stats_13f1d0 *FUN_00059a30();
    void FUN_00059a50(V3_13f1d0 *out);
    Tracker_13f1d0 *FUN_00059a40();
};

struct Holder_13f1d0 {
    Fighter_13f1d0 *FUN_000592a0();
};

struct Node34 {
    char pad0[0x34];
    float f34;
};

struct Stats_13f1d0 {
    char pad0[0x11c];
    Node34 *f11c;               // 0x11c
    char pad120[0x1ad4 - 0x120];
    V3_13f1d0 va;                      // 0x1ad4
    V3_13f1d0 vb;                      // 0x1ae0
    V3_13f1d0 vc;                      // 0x1aec
    V3_13f1d0 vd;                      // 0x1af8
    char FUN_00035550(V3_13f1d0 *out);
    void FUN_000356c0(V3_13f1d0 *out);
};

struct Config_13f1d0 {
    char pad00[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    char pad28[4];
    Bits_13f1d0 f2c;
    Bits_13f1d0 f30;
    Bits_13f1d0 f34;
};

struct Sys8 {
    void FUN_00099d20(struct World *sys, Stats_13f1d0 *st, float a, unsigned int b, float c);
};

struct World {
    char pad0[8];
    Sys8 *f8;
};

namespace hulkfight {
namespace motion {

class WallExitAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_13f1d0 *cfg;                // 0x1c
    Holder_13f1d0 *holder;             // 0x20
    JointDriver_13f1d0 *driver;          // 0x24
    V3_13f1d0 v28;                     // 0x28
    V3_13f1d0 v34;                     // 0x34
    V3_13f1d0 v40;                     // 0x40
};

bool WallExitAction::vfunc_3(int a, int b)
{
    struct Frame {
        Bits_13f1d0 s10;
        Bits_13f1d0 s14;
        Bits_13f1d0 s18;
        V3_13f1d0 u;
        V3_13f1d0 t;
        V3_13f1d0 z;
        V3_13f1d0 w;
        Matrix m;
    } fr;

    Fighter_13f1d0 *fighter = holder->FUN_000592a0();
    Stats_13f1d0 *st = fighter->FUN_00059a30();
    v34 = st->vd;
    v28 = st->vc;
    fr.z.x = 0.0f;
    fr.z.y = 0.0f;
    fr.z.z = 0.0f;
    if (v34.FUN_0022d2b0(&fr.z, 0.00001f)) {
        v34 = st->vb;
        v28 = st->va;
        fr.z.x = 0.0f;
        fr.z.y = 0.0f;
        fr.z.z = 0.0f;
        if (v34.FUN_0022d2b0(&fr.z, 0.00001f)) {
            fr.t.x = 0.0f;
            fr.t.y = 0.0f;
            fr.t.z = -1.0f;
            st->FUN_00035550(&fr.t);
            v34 = fr.t;
            v34.x = -v34.x;
            v34.z = -v34.z;
            fr.s10.f = st->f11c->f34;
            fr.z.x = 0.0f;
            fr.z.y = 0.0f;
            fr.z.z = 0.0f;
            fighter->FUN_00059a50(&fr.z);
            v28 = fr.t;
            v28.Scale(fr.s10.f);
            v28.Add(fr.z);
        }
    }

    fr.u.x = 0.0f;
    fr.u.y = 0.0f;
    fr.u.z = 0.0f;
    st->FUN_000356c0(&fr.u);
    double dot = fr.u.z * v34.z + fr.u.y * v34.y + fr.u.x * v34.x;
    if (dot < 0.0) {
        double nd = -dot;
        fr.t = v34;
        fr.t.y = fr.t.y * nd;
        fr.t.z = fr.t.z * nd;
        fr.u.x = fr.u.x + fr.t.x * nd;
        fr.u.y = fr.t.y + fr.u.y;
        fr.u.z = fr.t.z + fr.u.z;
    }
    fr.s10.f = fr.u.FUN_0022d110();
    v34.y = 0.0f;
    v34.FUN_0022d110();
    fr.w.x = 1.0f * v34.z - 0.0f * v34.y;
    fr.w.y = 0.0f * v34.x - 0.0f * v34.z;
    fr.w.z = 0.0f * v34.y - 1.0f * v34.x;
    double c = fr.u.y;
    if (fr.u.y < 0.0f)
        c = 0.0f;
    fr.s14.f = (cfg->f24 - cfg->f20) * c + cfg->f20;
    fr.m.FUN_0022b980();
    fr.m.FUN_0022baf0(&fr.w, fr.s14.f);
    fr.m.FUN_0022c3b0(&fr.u, &v40);

    Config_13f1d0 *cf = cfg;
    if (fr.s10.f < cf->f14)
        fr.s10.f = cf->f14;
    if (cf->f18 > 0.0f && fr.s10.f > cf->f18)
        fr.s10.f = cf->f18;
    v40.x = fr.s10.f * v40.x;
    v40.y = fr.s10.f * v40.y;
    v40.z = fr.s10.f * v40.z;

    Tracker_13f1d0 *tr = fighter->FUN_00059a40();
    if (tr == 0)
        return false;
    fr.s18 = cfg->f2c;
    fr.s10 = cfg->f30;
    fr.s14 = cfg->f34;
    void *mem = FUN_00263ea0(0x70);
    JointDriver_13f1d0 *d;
    if (mem != 0)
        d = ((JointDriver_13f1d0 *)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    d->name.FUN_0027b040("wallExit");
    driver->AddRef();
    tr->FUN_00222890(driver, -1.0f, fr.s18.f, 1.0f, fr.s10.f, fr.s14.f, -1.0f);

    Bits_13f1d0 yb;
    yb.f = v40.y;
    double sq = v40.x * v40.x + v40.z * v40.z;
    DAT_004dd700->f8->FUN_00099d20(DAT_004dd700, st, sqrt(sq), yb.u, cfg->f1c);
    return true;
}

}
}

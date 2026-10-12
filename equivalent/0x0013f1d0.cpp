// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// hulkfight::motion::WallExitAction::vfunc_3 @ 0x0013f1d0
extern "C" double sqrt(double);
extern "C" void *__cdecl FUN_00263ea0(unsigned int size) throw();

union Bits {
    float f;
    unsigned int u;
};

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(V3 *other, float eps);
};

struct Name {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(V3 *axis, float angle);
    void FUN_0022c3b0(V3 *in, V3 *out);
};

class FlyDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name name;
    FlyDriver *FUN_002248f0(int a);
};

struct Tracker {
    void FUN_00222890(FlyDriver *d, float a, float b, float c, float e, float f, float g);
};

struct Fighter {
    struct Stats *FUN_00059a30();
    void FUN_00059a50(V3 *out);
    Tracker *FUN_00059a40();
};

struct Holder {
    Fighter *FUN_000592a0();
};

struct Node34 {
    char pad0[0x34];
    float f34;
};

struct Stats {
    char pad0[0x11c];
    Node34 *f11c;               // 0x11c
    char pad120[0x1ad4 - 0x120];
    V3 va;                      // 0x1ad4
    V3 vb;                      // 0x1ae0
    V3 vc;                      // 0x1aec
    V3 vd;                      // 0x1af8
    char FUN_00035550(V3 *out);
    void FUN_000356c0(V3 *out);
};

struct Config {
    char pad00[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    char pad28[4];
    Bits f2c;
    Bits f30;
    Bits f34;
};

struct Sys8 {
    void FUN_00099d20(struct Sys *sys, Stats *st, float a, unsigned int b, float c);
};

struct Sys {
    char pad0[8];
    Sys8 *f8;
};
extern Sys *DAT_004dd700;

namespace hulkfight {
namespace motion {

class WallExitAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config *cfg;                // 0x1c
    Holder *holder;             // 0x20
    FlyDriver *driver;          // 0x24
    V3 v28;                     // 0x28
    V3 v34;                     // 0x34
    V3 v40;                     // 0x40
};

bool WallExitAction::vfunc_3(int a, int b)
{
    struct Frame {
        Bits s10;
        Bits s14;
        Bits s18;
        V3 u;
        V3 t;
        V3 z;
        V3 w;
        Matrix m;
    } fr;

    Fighter *fighter = holder->FUN_000592a0();
    Stats *st = fighter->FUN_00059a30();
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
            v28.x = fr.s10.f * v28.x;
            v28.y = fr.s10.f * v28.y;
            v28.z = fr.s10.f * v28.z;
            v28.x = fr.z.x + v28.x;
            v28.y = fr.z.y + v28.y;
            v28.z = fr.z.z + v28.z;
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

    Config *cf = cfg;
    if (fr.s10.f < cf->f14)
        fr.s10.f = cf->f14;
    if (cf->f18 > 0.0f && fr.s10.f > cf->f18)
        fr.s10.f = cf->f18;
    v40.x = fr.s10.f * v40.x;
    v40.y = fr.s10.f * v40.y;
    v40.z = fr.s10.f * v40.z;

    Tracker *tr = fighter->FUN_00059a40();
    if (tr == 0)
        return false;
    fr.s18 = cfg->f2c;
    fr.s10 = cfg->f30;
    fr.s14 = cfg->f34;
    void *mem = FUN_00263ea0(0x70);
    FlyDriver *d;
    if (mem != 0)
        d = ((FlyDriver *)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    d->name.FUN_0027b040("wallExit");
    driver->AddRef();
    tr->FUN_00222890(driver, -1.0f, fr.s18.f, 1.0f, fr.s10.f, fr.s14.f, -1.0f);

    Bits yb;
    yb.f = v40.y;
    double sq = v40.x * v40.x + v40.z * v40.z;
    DAT_004dd700->f8->FUN_00099d20(DAT_004dd700, st, sqrt(sq), yb.u, cfg->f1c);
    return true;
}

}
}

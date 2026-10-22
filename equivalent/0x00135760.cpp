// STATUS: equivalent (tools/equiv.py level 3: 20015 inputs, branch coverage 32/32)
// hulkfight::motion::FlyingAttackAction::vfunc_5 @ 0x00135760
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"

extern "C" double cos(double);

struct V3_135760 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000111b0(const V3_135760 *a, const V3_135760 *b);
    float FUN_000111f0();
};

union Bits_135760 {
    float f;
    unsigned int u;
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(V3_135760 *axis, float angle);
    void FUN_0022c3b0(const V3_135760 *in, V3_135760 *out);
};

struct Xform_135760 {
    char data[0x54];
    void FUN_0022be40(V3_135760 *v);
    void FUN_00222180(V3_135760 *v);
    void FUN_00221d20(float v);
};

class FlyDriver_135760 {
public:
    virtual void AddRef();
    char pad4[0x14];
    Xform_135760 xform;                // 0x18
};

struct Stats_135760 {
    char pad0[0x1a88];
    float f1a88;
    char pad1a8c[0x2064 - 0x1a8c];
    V3_135760 v2064;
    float f2070;
    void FUN_000359c0(int n);
};

struct Fighter_135760 {
    Stats_135760 *FUN_00059a30();
    void FUN_00059a50(V3_135760 *out);
};

struct Holder_135760 {
    Fighter_135760 *FUN_000592a0();
};

struct Config_135760 {
    char pad0[0x14];
    V3_135760 vec14;
    int f20;
    float f24;
    float f28;
    Bits_135760 f2c;
    char flag30;
};

float __cdecl FUN_00224f10(V3_135760 *v);
void __cdecl FUN_00224d70(float angle, V3_135760 *v);
int __cdecl FUN_00098190(unsigned int dt, unsigned int acc, unsigned int mag, int a, void *ref, int b,
                         V3_135760 *vel, V3_135760 *dir, int c, int d, int e, int f);

class FlyingAttackAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x1c - 4];
    Config_135760 *cfg;                // 0x1c
    Holder_135760 *holder;             // 0x20
    FlyDriver_135760 *driver;          // 0x24
    void *ref;                  // 0x28
    float f2c;                  // 0x2c
    V3_135760 dir;                     // 0x30
    void FUN_00135700();
};

bool FlyingAttackAction::vfunc_5(int a, float dt)
{
    struct Frame {
        Bits_135760 mag;
        hulk_freg acc;
        hulk_freg d;
        V3_135760 t18;
        V3_135760 vel;
        V3_135760 w;
        V3_135760 w2;
        Matrix m;
    } fr;

    if (a != 0)
        return true;
    if (driver == 0)
        return false;

    Fighter_135760 *fighter = holder->FUN_000592a0();
    Stats_135760 *stats = fighter->FUN_00059a30();
    stats->FUN_000359c0(3);
    fr.vel.x = 0.0f;
    fr.vel.y = 0.0f;
    fr.vel.z = 0.0f;
    fighter->FUN_00059a50(&fr.vel);

    Config_135760 *c = cfg;
    void *r = ref;
    double accd = dt * c->f24 + f2c;
    fr.acc = accd;
    f2c = accd;
    fr.mag = c->f2c;

    if (r != 0) {
        Bits_135760 dtb;
        dtb.f = dt;
        Bits_135760 accb;
        accb.f = fr.acc;
        if (!FUN_00098190(dtb.u, accb.u, fr.mag.u, 0, r, 0, &fr.vel, &dir, 0, 0, 0, 1))
            FUN_00135700();
    } else {
        hulk_freg f2070 = stats->f2070;
        V3_135760 *vc = &c->vec14;
        fr.t18 = *vc;
        fr.w = *vc;
        V3_135760 *sel = (f2070 <= 0.0f) ? &dir : &stats->v2064;
        FUN_00224d70(FUN_00224f10(sel), &fr.t18);
        fr.t18.FUN_0022d110();
        if (fr.mag.f < 0.0f) {
            dir = fr.t18;
        } else {
            double m2 = fr.mag.f * dt;
            fr.acc = m2;
            double cv;
            if (m2 < 0.0 || fr.acc > 3.14159274f)
                cv = -1.0f;
            else
                cv = cos(fr.acc);
            double d = fr.t18.z * dir.z + fr.t18.y * dir.y + fr.t18.x * dir.x;
            fr.d = d;
            if (d >= cv - DAT_004dd940) {
                dir = fr.t18;
            } else if (!((DAT_004dd940 - 1.0f) >= fr.d)) {
                fr.w.FUN_000111b0(&fr.t18, &dir);
                if (fr.w.FUN_000111f0() > 0.0f) {
                    fr.m.FUN_0022b980();
                    fr.m.FUN_0022baf0(&fr.w, fr.acc);
                    fr.m.FUN_0022c3b0(&dir, &dir);
                }
            }
        }
    }

    double s = dt * f2c;
    fr.t18 = dir;
    double px = fr.t18.x * s;
    fr.t18.y = fr.t18.y * s;
    fr.t18.z = fr.t18.z * s;
    fr.w = fr.vel;
    fr.vel.x = px + fr.vel.x;
    fr.vel.y = fr.t18.y + fr.vel.y;
    fr.vel.z = fr.t18.z + fr.vel.z;

    double lim = stats->f1a88 + cfg->f28;
    if (fr.vel.y < lim) {
        fr.vel.y = lim;
        fr.t18.x = fr.vel.x - fr.w.x;
        fr.t18.y = fr.vel.y - fr.w.y;
        fr.t18.z = fr.vel.z - fr.w.z;
        fr.t18.FUN_0022d110();
        if (fr.mag.f < 0.0f) {
            dir = fr.t18;
        } else {
            double dd = fr.t18.z * dir.z + fr.t18.y * dir.y + fr.t18.x * dir.x;
            double ang = fr.mag.f * dt;
            fr.acc = ang;
            double cv = cos(ang);
            if (dd >= cv) {
                dir = fr.t18;
            } else if (!(dd <= -1.0f)) {
                fr.w2.FUN_000111b0(&fr.t18, &dir);
                fr.m.FUN_0022b980();
                fr.m.FUN_0022baf0(&fr.w2, fr.acc);
                fr.w = dir;
                fr.m.FUN_0022c3b0(&fr.w, &dir);
            }
        }
    }

    driver->xform.FUN_0022be40(&fr.vel);
    if (cfg->flag30)
        driver->xform.FUN_00222180(&dir);
    else
    {
        float tmp1 = FUN_00224f10(&dir);
        driver->xform.FUN_00221d20(tmp1);
    }
    return true;
}

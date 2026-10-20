// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 16/16)
// hulkfight::motion::HitThrowAction::vfunc_5 @ 0x00152210
#include "decls/address.h"
struct Vec3_152210 {
    float x, y, z;
    float FUN_0022d110();
};

struct Transform_152210 {
    void FUN_00221d20(float angle);
    void FUN_0022be40(Vec3_152210* pos);
};

struct Target_152210 {
    char pad00[0x18];
    Transform_152210 xform;
};

struct Config_152210 {
    char pad00[0x14];
    char flag14;
    char pad15[3];
    float f18;
    float f1c;
};

struct Fighter_152210 {
    char pad00[0x11c];
    struct Inner_152210* inner;
    char pad120[0xc];
    int f12c;
    void FUN_000359c0(int mode);
};

struct Inner_152210 {
    char pad00[0x2c];
    int f2c;
};

struct Anchor_152210 {
    Fighter_152210* FUN_00059a30();
    void FUN_00059a50(Vec3_152210* out);
};

struct Pool_152210 {
    void FUN_00029bb0(int a, int b, float c);
};

struct World {
    char pad0[0x20];
    Pool_152210* pool;
};

struct Probe_152210 {
    char pad00[0x8c];
    int f8c;
};

struct Holder_152210 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Probe_152210* vfunc_3();
};


Anchor_152210* __fastcall FUN_000592a0(Holder_152210* h);
Fighter_152210* __fastcall FUN_00059a30(Anchor_152210* a);
float FUN_00224f10(Vec3_152210* v);
int FUN_00098190(float dt, float speed, int probe, int zero0, int f28, int x, Vec3_152210* out, Vec3_152210* io, int z1, int z2, int z3, int one);

struct Frame_152210 {
    Vec3_152210 s;
    Vec3_152210 t;
    Vec3_152210 v;
};

class HitThrowAction {
public:
    char pad00[0x1c];
    Config_152210* cfg;
    Holder_152210* holder;
    Target_152210* target;
    int f28;
    float f2c;
    float f30;
    Vec3_152210 vel;
    void FUN_001521b0();
    bool vfunc_5(int skip, float dt);
};

bool HitThrowAction::vfunc_5(int skip, float dt)
{
    Frame_152210 fr;

    if (skip)
        return true;
    if (target == 0)
        return false;
    Probe_152210* probe = holder->vfunc_3();
    if (probe == 0)
        return false;

    Anchor_152210* anchor = FUN_000592a0(holder);
    Fighter_152210* fighter = FUN_00059a30(anchor);
    fr.v.x = 0.0f;
    fr.v.y = 0.0f;
    fr.v.z = 0.0f;
    anchor->FUN_00059a50(&fr.v);
    fighter->FUN_000359c0(3);

    f2c = f2c - dt * f30;
    if (f28) {
        skip = fighter->inner->f2c;
        if (FUN_00098190(dt, f30, probe->f8c, 0, f28, skip, &fr.v, &vel, 0, 0, 0, 1))
            DAT_004dd700->pool->FUN_00029bb0(fighter->f12c, f28, f2c);
        else
            FUN_001521b0();
    }

    fr.s.x = vel.x * f30;
    fr.s.y = vel.y * f30;
    fr.s.z = vel.z * f30;
    if (f28 == 0) {
        fr.s.x = fr.s.x + dt * 0.0f;
        vel.x = fr.s.x;
        fr.s.y = fr.s.y + (-cfg->f1c) * dt;
        vel.y = fr.s.y;
        fr.s.z = fr.s.z + dt * 0.0f;
        vel.z = fr.s.z;
        f30 = vel.FUN_0022d110();
    }

    fr.t.x = fr.s.x * dt;
    fr.t.y = fr.s.y * dt;
    fr.t.z = fr.s.z * dt;
    fr.t.x = fr.t.x + fr.v.x;
    fr.t.y = fr.t.y + fr.v.y;
    fr.t.z = fr.t.z + fr.v.z;
    target->xform.FUN_0022be40(&fr.t);

    if (cfg->flag14) {
        float ang = FUN_00224f10(&vel);
        target->xform.FUN_00221d20(ang + cfg->f18);
    }
    return f2c > 0.0f;
}

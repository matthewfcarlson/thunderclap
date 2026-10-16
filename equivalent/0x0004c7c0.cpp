// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 9/10, incomplete)
// CSmartPropAngleCondition::vfunc_7 @ 0x0004c7c0
#include "decls/data/game/global.h"

extern "C" double fabs(double);

struct Vec3_4c7c0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat3 {
    void FUN_0022c3b0(float* in, Vec3_4c7c0* out);
};

struct Sub_4c7c0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual Mat3* v15();
    Vec3_4c7c0* FUN_001d6b40();
};

struct Entity {
    int f00;
    int f04;
    Sub_4c7c0* sub;
    int kind;
};

struct Holder_4c7c0 {
    Entity* FUN_001d72e0();
};

struct Fighter_4c7c0 {
    bool FUN_00059a50(Vec3_4c7c0* out);
};

struct Stats_4c7c0 {
    char pad00[0x3a4];
    Entity* defaultEntity;
    Holder_4c7c0* FUN_00035ef0(int index);
};

Fighter_4c7c0* __fastcall FUN_000592a0(void* owner);
Stats_4c7c0* __fastcall FUN_00059a30(Fighter_4c7c0* f);
float FUN_00224ea0(float x, float z);
float FUN_00224fc0(float a, float b);

class CSmartPropAngleCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(void* owner);
    int pad04[2];
    float offset;
    float range;
};

bool CSmartPropAngleCondition::vfunc_7(void* owner)
{
    Fighter_4c7c0* fighter = FUN_000592a0(owner);
    Stats_4c7c0* stats = FUN_00059a30(fighter);
    Entity* e = 0;
    if (stats->FUN_00035ef0(0)) {
        e = stats->FUN_00035ef0(0)->FUN_001d72e0();
    }
    if (!e) {
        e = stats->defaultEntity;
        if (!e)
            return false;
    }
    if (e->kind != 5)
        return false;
    Sub_4c7c0* sub = e->sub;
    struct Frame { Vec3_4c7c0 d; Vec3_4c7c0 v; Vec3_4c7c0 q; Vec3_4c7c0 w; } f;
    f.v.x = 0.0f;
    f.v.y = 0.0f;
    f.v.z = 0.0f;
    fighter->FUN_00059a50(&f.v);
    Vec3_4c7c0* p = sub->FUN_001d6b40();
    f.q = *p;
    f.d.x = f.v.x - f.q.x;
    f.d.y = f.v.y - f.q.y;
    f.d.z = f.v.z - f.q.z;
    f.d.FUN_0022d110();
    float a1 = FUN_00224ea0(f.d.x, f.d.z);
    sub->v15()->FUN_0022c3b0(DAT_0048fa24, &f.w);
    float a2 = FUN_00224ea0(f.w.x, f.w.z) + offset;
    float r = FUN_00224fc0(a1, a2);
    return range * 0.5f > (float)fabs(r);
}

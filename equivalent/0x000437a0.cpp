// STATUS: equivalent (tools/equiv.py level 3: 3042 inputs, branch coverage 64/65, incomplete)
// FUN_000437a0 @ 0x000437a0
#include "decls/data/game/global.h"
#include "gen/global.h"

extern "C" int atexit(void (*)());
extern "C" int __cdecl FUN_00266da0(int mode);
void* __cdecl FUN_0008d690(unsigned int size);
void FUN_00363b90();

struct Vec3_437a0 {
    float x, y, z;
};

struct Key_437a0 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
    void FUN_0027b040(const char* name);
};


struct CFightParamsCollision_nv_437a0 {
    CFightParamsCollision* FUN_000598e0(int first, void* params);
};

struct Target2 {
    char pad00[0x1d20];
    float f1d20;
};

struct Target_437a0 {
    char pad00[8];
    Target2* f08;
    int f0c;
};

struct Params_437a0 {
    char pad00[0x24];
    char b24;
    char pad25[3];
    Vec3_437a0 vec28;
    char pad34[0x44 - 0x34];
    char b44;
    char pad45[3];
    int f48;
    Target_437a0* f4c;
    char pad50[4];
    int f54;
    char pad58[0x80 - 0x58];
    int f80;
    char pad84[0x90 - 0x84];
    char b90;
    unsigned char b91;
};

struct Actor_437a0 {
    void FUN_00231ad0(Vec3_437a0* where, CFightParamsCollision* ev, int t);
    char FUN_00231a40(Vec3_437a0* where, CFightParamsCollision* ev);
    char FUN_001d6ec0(int a, Target_437a0* t, int c);
};

class Holder110 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Actor_437a0* v8(CFightParamsCollision* ev, int z);
};

struct Obj11c_437a0 {
    char pad00[0x110];
    Holder110* f110;
    char pad114[0x1a4 - 0x114];
    int f1a4;
    unsigned __int64 FUN_000443c0();
};

struct Sub2_437a0 {
    float FUN_002220d0();
};

struct Anchor2 {
    char pad00[0x10];
    Sub2_437a0 sub;
};

struct Owner_437a0 {
    int first;
    Anchor2* FUN_00059a40();
};

struct Sub_437a0 {
    void FUN_00232240();
};

struct Entry_437a0 {
    Actor_437a0* a;
    char pad[76];
};

extern "C" float __cdecl FUN_00224f10(Vec3_437a0* v);
extern "C" float __cdecl FUN_00224fc0(float a, float b);

class Unit_437a0 {
public:
    char pad00[0x10];
    Owner_437a0* f10;
    char pad14[0xb4 - 0x14];
    Sub_437a0 subB4;
    char padB5[0xdc - 0xb5];
    Vec3_437a0 fdc;
    char pade8[0x11c - 0xe8];
    Obj11c_437a0* f11c;
    char pad120[0x318 - 0x120];
    int f318;
    int f31c;
    float f320;
    char pad324[0x3a8 - 0x324];
    Entry_437a0 entries[8];
    float f628;
    char pad62c[0x1d28 - 0x62c];
    char b1d28;
    int FUN_00035fe0();
    char FUN_00043350(float dt, Target_437a0* t, int a, int b, int c, int d);
    Actor_437a0* FUN_000392e0(CFightParamsCollision* ev);
    void FUN_00035930(int v);
    int FUN_00036e40(Key_437a0* k);
    void FUN_00037000();
    char FUN_000437a0(float dt, Params_437a0* p, Vec3_437a0* where, Actor_437a0* actor, char flag5);
};

union FloatBits_437a0 {
    float f;
    unsigned int u;
};

char Unit_437a0::FUN_000437a0(float dt, Params_437a0* p, Vec3_437a0* where, Actor_437a0* actor, char flag5)
{
    if (f11c == 0)
        return 0;
    int saved = FUN_00266da0(0xd);
    int limit = p->f54;
    char counted = p->b24;
    int extra = 0;
    if (f11c != 0)
        extra = f11c->f1a4;
    if (f31c + f318 + extra > limit)
        counted = 0;
    char behind = 0;
    int idx = FUN_00035fe0();
    if (idx >= 0) {
        float yawBase = FUN_00224f10(&p->vec28) + 3.1415927f;
        Anchor2* anchor = f10->FUN_00059a40();
        float ang;
        if (anchor == 0)
            ang = 0.0f;
        else
            ang = anchor->sub.FUN_002220d0();
        FloatBits_437a0 r;
        r.f = FUN_00224fc0(yawBase, ang);
        r.u &= 0x7fffffff;
        if (f628 * 0.5f > r.f)
            behind = 1;
    }
    if (b1d28 && !p->b90)
        dt = 0.0f;
    if (f11c != 0) {
        if (f11c->FUN_000443c0() == ((unsigned __int64)DAT_004dc084 << 32 | DAT_004dc080) && p->b90)
            dt = 0.0f;
    }
    char ok;
    if (behind) {
        Actor_437a0* target = 0;
        if (idx >= 0 && idx < 8)
            target = entries[idx].a;
        ok = target->FUN_001d6ec0((int)dt, p->f4c, 0);
    } else {
        ok = FUN_00043350(dt, p->f4c, p->f48, p->f80, 0, p->b91);
    }
    p->b44 = !ok;
    if (!counted) {
        float factor = 1.0f;
        Target_437a0* t = p->f4c;
        if (t != 0 && t->f0c == 1 && t->f08 != 0)
            factor = t->f08->f1d20;
        f320 = factor * dt + f320;
    }
    CFightParamsCollision* ev = (CFightParamsCollision*)FUN_0008d690(0xb0);
    if (ev != 0)
        ev = ((CFightParamsCollision_nv_437a0*)(ev))->FUN_000598e0(f10->first, p);
    else
        ev = 0;
    ev->vfunc_0();
    if (!flag5) {
        Actor_437a0* act = actor;
        if (act == 0)
            act = FUN_000392e0(ev);
        if (act != 0) {
            Vec3_437a0* w = where;
            if (w == 0)
                w = &fdc;
            act->FUN_00231ad0(w, ev, -(int)dt);
            if (act->FUN_00231a40(w, ev) && ok) {
                FUN_00035930(6);
                if ((DAT_004dc318 & 1) == 0) {
                    DAT_004dc318 |= 1;
                    (*(Key_437a0*)&DAT_004dc310).FUN_0027af00();
                    atexit(FUN_00363b90);
                }
                (*(Key_437a0*)&DAT_004dc310).FUN_0027b040("no_ai_reset");
                int r = FUN_00036e40(((Key_437a0*)&DAT_004dc310));
                Sub_437a0* sub = &subB4;
                if (sub != 0 && r == 0) {
                    FUN_00037000();
                    sub->FUN_00232240();
                }
            }
        }
    } else {
        Holder110* h = f11c->f110;
        if (h != 0) {
            Actor_437a0* act = h->v8(ev, 0);
            if (act != 0) {
                Vec3_437a0* w = where;
                if (w == 0)
                    w = &fdc;
                act->FUN_00231ad0(w, ev, -(int)dt);
            }
        }
    }
    ev->vfunc_1();
    FUN_00266da0(saved);
    return ok;
}

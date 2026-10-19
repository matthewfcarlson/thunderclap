// STATUS: equivalent (tools/equiv.py level 3: 13006 inputs, branch coverage 66/76, incomplete)
// FUN_00043350 @ 0x00043350
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Unit_43350;
struct Target_43350;

union Arg2_43350 {
    Target_43350 *t;
    char result;
};

union Arg6 {
    char d;
    int neg;
};

struct Obj11c_43350 {
    char pad0[0x174];
    float f174;
    char pad178[0x188 - 0x178];
    float f188;
    float f18c;
    char pad190[0x1b0 - 0x190];
    int f1b0;
    char pad1b4[0x310 - 0x1b4];
    float f310;
    unsigned __int64 FUN_000443c0();
};

struct Timer {
    float FUN_00086080();
};

struct Next_43350 {
    void FUN_00067870(Unit_43350 *u);
};
Next_43350 *__cdecl FUN_000678d0();

struct Check_43350 {
    char FUN_00092940(int v);
};

struct Holder54_43350 {
    Check_43350 *FUN_00086340();
    struct W { void FUN_000d6e00(int v); };
    W *FUN_000862b0();
};

struct Hook_43350 {
    void FUN_001cd5b0(float v);
};

struct Listener_43350 {
    void FUN_000fe4d0(void *target, int flag);
};

struct World {
    char pad0[0x20];
    Unit_43350 *player;               // 0x20
    char pad24[0x2c - 0x24];
    Hook_43350 *hook;                 // 0x2c
    char pad30[0x54 - 0x30];
    Holder54_43350 *holder;           // 0x54
    Timer *timer;               // 0x58
};

struct Target_43350 {
    char pad0[8];
    Unit_43350 *unit;                 // 0x08
    int kind;                   // 0x0c
};

struct Link128 {
    char pad0[0x11c];
    Obj11c_43350 *obj;
};

struct Out_43350 {
    void FUN_001c4ac0(int *tmp, float f);
};

struct Unit_43350 {
    char pad0[0x10];
    Unit_43350 *link10;               // 0x10
    char pad14[0x11c - 0x14];
    Obj11c_43350 *obj;                // 0x11c
    char pad120[4];
    Unit_43350 *link124;              // 0x124
    Link128 *link128;           // 0x128
    void *f12c;                 // 0x12c
    char pad130[0x1b0c - 0x130];
    float f1b0c;
    char pad1b10[0x1b28 - 0x1b10];
    int f1b28;
    float f1b2c;
    float f1b30;
    char pad1b34[0x1ca0 - 0x1b34];
    Listener_43350 *listener;         // 0x1ca0
    char pad1ca4[0x1cef - 0x1ca4];
    unsigned char b1cef;
    char pad1cf0[0x1d20 - 0x1cf0];
    float f1d20;
    char pad1d24[0x1e4c - 0x1d24];
    int f1e4c;
    char pad1e50[0x20b0 - 0x1e50];
    int f20b0;
    char pad20b4[0x2138 - 0x20b4];
    char b2138;
    char pad2139[3];
    float f213c;
    char pad2140[0x22e8 - 0x2140];
    char b22e8;
    char pad22e9[3];
    void FUN_000403f0();
    void FUN_000385a0(Target_43350 *t, int v);
    char FUN_0003b1c0(float v, char flag);
    void FUN_00025720(int v);
    Out_43350 *FUN_00036a80(int a);
    char FUN_00043350(float dt, Arg2_43350 p2, int a, float one, char c, Arg6 p6);
};

struct Scale_43350 { float FUN_00045670(); };

struct Frame_43350 {
    Unit_43350 *player;               // R-8
    World *mgr;                   // R-4
};


char Unit_43350::FUN_00043350(float dt, Arg2_43350 p2, int a, float one, char c, Arg6 p6)
{
    Frame_43350 f;
    f.mgr = DAT_004dd700;
    f.player = f.mgr->player;
    Timer *timer = f.mgr->timer;
    obj->FUN_000443c0();
    if ((*(float*)&DAT_004dc308) == 0.0f || timer->FUN_00086080() - 0.8f > (*(float*)&DAT_004dc308)) {
        (*(float*)&DAT_004dc308) = timer->FUN_00086080();
        FUN_000678d0()->FUN_00067870(this);
    }
    if (DAT_004dc304 == 0.0f || timer->FUN_00086080() - 0.8f > DAT_004dc304)
        FUN_000403f0();
    if (obj == 0)
        return 0;

    Target_43350 *t = p2.t;
    Unit_43350 *ptarget = 0;
    if (t != 0 && t->kind == 1) {
        ptarget = t->unit;
        if (ptarget != 0 && !c && !b2138) {
            if ((float)b1cef != 0.0f) {
                if (ptarget->obj->f1b0 == obj->f1b0)
                    dt = 0;
            }
        }
        if (f.player->link124 == ptarget) {
            if (one < f213c)
                dt = 0;
            Check_43350 *chk = DAT_004dd700->holder->FUN_00086340();
            if (chk->FUN_00092940(0x14))
                dt = dt + dt;
        }
        if (ptarget != 0)
            dt = dt * ptarget->f1d20;
    }
    FUN_000385a0(t, 0);
    double v;
    World *mgr = f.mgr;
    if (f.player->link124 == this) {
        Check_43350 *chk = mgr->holder->FUN_00086340();
        if (chk->FUN_00092940(0x2e4))
            v = 0.0f;
        else
            v = dt;
    } else {
        v = dt;
    }
    Obj11c_43350 *o = obj;
    if (f1b28 == 0) {
        dt = (float)(v * o->f310);
    } else {
        float sel;
        if (!(o->f18c >= f1b2c))
            sel = o->f174;
        else
            sel = o->f188;
        dt = (float)(sel * o->f310 * v);
    }
    dt = ((Scale_43350*)o)->FUN_00045670() * dt;
    char ok = FUN_0003b1c0(f1b0c - dt, (char)c);
    p2.result = 0;
    if (ok && dt > 0.0f && f20b0 == 0) {
        p2.result = 1;
        if (ptarget != 0 && a != 0 && mgr->player != 0 && mgr->player->link124 == ptarget && mgr->hook != 0)
            mgr->hook->FUN_001cd5b0(dt);
        f1e4c = 0;
        f1b30 = dt + f1b30;
        if (f1b0c <= 0.0f && p6.d)
            b22e8 = 1;
    }
    if (this == mgr->player->link124) {
        Holder54_43350 *h = DAT_004dd700->holder;
        h->FUN_000862b0()->FUN_000d6e00(4);
    }
    Unit_43350 *pl = f.player;
    if (pl->link124 != this) {
        if (listener != 0)
            listener->FUN_000fe4d0(pl->link124->f12c, 1);
    }
    if (p2.result == 0) {
        pl->FUN_00025720(a);
        return p2.result;
    }
    void *tgt;
    if (link124 != 0) {
        tgt = link124->link10;
    } else if (link128 != 0) {
        tgt = link128->obj;
    } else {
        return p2.result;
    }
    if (tgt != 0 && dt > 0.0f) {
        p6.neg = -1;
        FUN_00036a80(1)->FUN_001c4ac0(&p6.neg, 0.3f);
    }
    return p2.result;
}

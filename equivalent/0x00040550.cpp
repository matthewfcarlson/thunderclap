// STATUS: equivalent (tools/equiv.py level 3: 3061 inputs, branch coverage 57/60, incomplete)
// FUN_00040550 @ 0x00040550
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
#include "decls/address.h"
#include "decls/data/game/hulkfight.h"
struct V3_40550 {
    float x, y, z;
    bool FUN_0022d2b0(V3_40550 *other, float eps);
};

struct Key {
    unsigned int lo;
    unsigned int hi;
    Key(const Key &src) throw();
    Key() {}
    Key *FUN_0027b0e0(const char *name) throw();
    void FUN_0027af50() throw();
};

struct Event_40550 {
    char data[0x28];
    void FUN_001cadf0(Key k) throw();
};

struct Sink_40550 {
    void FUN_001cbc20(Event_40550 *e) throw();
};

struct Gate_40550 {
    char FUN_001ccff0();
};

struct Hud_40550 {
    void FUN_001ebd00(const char *a, const char *b);
};

class Fighter_40550;

struct Hero_40550 {
    char pad0[0x124];
    Fighter_40550 *f124;
};

struct World {
    char pad0[0x20];
    Hero_40550 *hero;                      // 0x20
    char pad24[8];
    Gate_40550 *gate;                      // 0x2c
    Sink_40550 *sink;                      // 0x30
    Hud_40550 *hud;                        // 0x34
};

struct Mgr_40550 {
    V3_40550 *FUN_001c39d0();
    V3_40550 *FUN_001c39c0();
};
Mgr_40550 *__cdecl FUN_001c3d90();

struct Obj_40550 {
    char pad0[0x114];
    Obj_40550 *f114;
};

struct Link_40550 {
    char pad0[8];
    Obj_40550 *f08;
    int kind;                        // 0xc
};

static float TwoPi()
{
    return 6.2831855f;
}

class Fighter_40550 {
public:
    char pad0[0x328];
    Obj_40550 *f328;
    char b32c;
    char b32d;
    char pad32e[0x1fa0 - 0x32e];
    int mode;                        // 0x1fa0
    char pad1fa4[0x202c - 0x1fa4];
    int f202c;
    char pad2030[4];
    unsigned int f2034;
    unsigned int f2038;
    char pad203c[0x2080 - 0x203c];
    V3_40550 v2080;
    char pad208c[0x20a8 - 0x208c];
    int f20a8;
    Link_40550 *FUN_000396a0(unsigned int lo, unsigned int hi, int z);
    void FUN_0003ffa0(Link_40550 *l, int z);
    void FUN_000350c0(V3_40550 *out);
    void FUN_00035dc0(V3_40550 *out);
    void FUN_000400e0(V3_40550 *a, V3_40550 *b, float tau, float range, int z);
    void FUN_00040550(float dt) throw();
};

void Fighter_40550::FUN_00040550(float dt) throw()
{
    if (f20a8 < 0 || f20a8 >= 4)
        return;
    if (b32c != 0 && f328 == 0) {
        b32c = 0;
        b32d = 0;
    }
    int m = mode;
    if ((*(char*)&DAT_004dc290) != 0) {
        if (m == 1)
            b32c = (b32c == 0);
    } else if (m == 1 || (m == 2 && f202c == 1)) {
        b32c = 1;
    } else if (m == 3 || m == 0) {
        if (b32c != 0 && m == 3)
            DAT_004dd700->hud->FUN_001ebd00("targetting", "lost");
        b32c = 0;
    }
    b32d = b32c;
    if (b32c == 0)
        return;

    static float tau = TwoPi();

    if (f202c == 1) {
        Obj_40550 *old = f328;
        Link_40550 *l = FUN_000396a0(f2034, f2038, 0);
        if (l == 0)
            return;
        FUN_0003ffa0(l, 0);
        if (DAT_004dd700->gate->FUN_001ccff0()) {
            Sink_40550 *s = DAT_004dd700->sink;
            Key k;
            Event_40550 ev;
            k.FUN_0027b0e0("hulk_target_switched");
            ev.FUN_001cadf0(k);
            s->FUN_001cbc20(&ev);
            k.FUN_0027af50();
        }
        if (old != 0 && l->kind == 5) {
            Obj_40550 *o = l->f08;
            if (o != 0 && o->f114 == old) {
                Sink_40550 *s = DAT_004dd700->sink;
                Key k;
                Event_40550 ev;
                k.FUN_0027b0e0("SH_sub_targeting");
                ev.FUN_001cadf0(k);
                s->FUN_001cbc20(&ev);
                k.FUN_0027af50();
            }
        }
        DAT_004dd700->hud->FUN_001ebd00("targetting", "switched");
        return;
    }

    if (f328 != 0 && m != 1)
        return;

    V3_40550 a;
    V3_40550 b;
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    if (DAT_004dd700->hero->f124 == this) {
        bool direct = false;
        // the original re-tests f202c here (never true on this path); a volatile read keeps the test
        if (*(volatile int *)&f202c == 1) {
            b.x = 0.0f;
            b.y = 0.0f;
            b.z = 0.0f;
            if (!v2080.FUN_0022d2b0(&b, 1e-5f)) {
                FUN_000350c0(&a);
                b = v2080;
                direct = true;
            }
        }
        if (!direct) {
            Mgr_40550 *mgr = FUN_001c3d90();
            a = *mgr->FUN_001c39d0();
            b = *mgr->FUN_001c39c0();
        }
    } else {
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 0.0f;
        FUN_00035dc0(&b);
        a.x = 0.0f;
        a.y = 0.0f;
        a.z = 0.0f;
        FUN_000350c0(&a);
    }
    FUN_000400e0(&a, &b, tau, 500.0f, 0);

    if (f328 == 0) {
        b32c = 0;
        b32d = 0;
        DAT_004dd700->hud->FUN_001ebd00("targetting", "lost");
        return;
    }
    if (DAT_004dd700->gate->FUN_001ccff0()) {
        Sink_40550 *s = DAT_004dd700->sink;
        Key k;
        Event_40550 ev;
        k.FUN_0027b0e0("hulk_target_acquired");
        ev.FUN_001cadf0(k);
        s->FUN_001cbc20(&ev);
        k.FUN_0027af50();
    }
    DAT_004dd700->hud->FUN_001ebd00("targetting", "acquired");
}

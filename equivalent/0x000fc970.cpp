// STATUS: equivalent (tools/equiv.py level 3: 115 inputs, branch coverage 34/40, incomplete)
// CChaseAgent::vfunc_3 @ 0x000fc970
struct Binding;

struct Unit {
    char pad0[8];
    Binding *binding;
    char pad0c[0x12 - 0xc];
    char flag12;
    char pad13;
    float f14;
    char pad18[0x45 - 0x18];
    char flag45;
    char pad46[0x70 - 0x46];
    char flag70;
    char flag71;
    bool FUN_000fc900();
    float FUN_000fc890();
    float FUN_000fc830();
};

struct Stats {
    char pad0[0x3a0];
    float limit;
};

struct Weapon {
    char pad0[0x11c];
    Stats *stats;
    int FUN_00035ef0(int a);
};

struct Mode {
    char pad0[0x140];
    int kind;
};

struct Binding {
    char pad0[8];
    Mode *mode;
    int type;
};

class Brain {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Weapon *v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
    char pad[0x58 - 4];
    Unit unit;
};

class CChaseAgent {
public:
    char pad0[8];
    float timer;
    char pad0c[0x58 - 0xc];
    Brain *brain;
    char pad5c[0x6c - 0x5c];
    char engaged;
    char pad6d[3];
    float f70;
    float FUN_000fc4e0(Unit *u, int a);
    float FUN_000fc970(Unit *u, int a);
};

float CChaseAgent::FUN_000fc970(Unit *arg, int a)
{
    FUN_000fc4e0(arg, a);
    Binding *bind = brain->unit.binding;
    Unit *u = &brain->unit;
    timer = 0.0f;
    if (!bind)
        return 0.0f;

    Weapon *w = brain->v6();
    if (!w)
        return timer;
    if (brain->v9() < 2)
        return timer;

    int kind = 0;
    if (bind->type == 1)
        kind = bind->mode->kind;
    bool is3 = (kind == 3);
    bool is2 = (kind == 2);
    bool ready = false;
    if (w->FUN_00035ef0(0)) {
        if (w->stats->limit >= 4.0f)
            ready = true;
    }

    bool reset = false;
    if (!is3 && !is2) {
        if (u->FUN_000fc900() && (!ready || !u->flag45))
            reset = true;
        if (!reset && ready) {
            if (u->FUN_000fc890() > 1.5f)
                reset = true;
        }
        if (!reset && u->flag70) {
            if (u->FUN_000fc830() > 2.5f)
                reset = true;
        }
    }
    if (reset) {
        timer = 50.0f;
        engaged = 0;
        return timer;
    }

    if (!u->flag12 && u->f14 > 2.5f && f70 > 0.0f) {
        engaged = 1;
        timer = 50.0f;
    }
    return timer;
}

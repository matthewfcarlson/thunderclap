// STATUS: equivalent (tools/equiv.py level 3: 20063 inputs, branch coverage 40/40)
// CChaseAgent::vfunc_3 @ 0x000fc970
#include "gen/global.h"

struct Binding_fc970;

struct Unit_fc970 {
    char pad0[8];
    Binding_fc970 *binding;
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

struct Stats_fc970 {
    char pad0[0x3a0];
    float limit;
};

struct Weapon_fc970 {
    char pad0[0x11c];
    Stats_fc970 *stats;
    int FUN_00035ef0(int a);
};

struct Mode_fc970 {
    char pad0[0x140];
    int kind;
};

struct Binding_fc970 {
    char pad0[8];
    Mode_fc970 *mode;
    int type;
};

class Brain_fc970 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Weapon_fc970 *v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
    char pad[0x58 - 4];
    Unit_fc970 unit;
};

struct CChaseAgent_nv_fc970 {
    float FUN_000fc4e0(Unit_fc970 *u, int a);
};

float CChaseAgent::vfunc_3(int __p0, int a) { Unit_fc970 * arg = (Unit_fc970 *)__p0;

    ((CChaseAgent_nv_fc970*)this)->FUN_000fc4e0(arg, a);
    Binding_fc970 *bind = (*(Brain_fc970 * *)&this->f_58)->unit.binding;
    Unit_fc970 *u = &(*(Brain_fc970 * *)&this->f_58)->unit;
    (*(float *)&this->f_08) = 0.0f;
    if (!bind)
        return 0.0f;

    Weapon_fc970 *w = (*(Brain_fc970 * *)&this->f_58)->v6();
    if (!w)
        return (*(float *)&this->f_08);
    if ((*(Brain_fc970 * *)&this->f_58)->v9() < 2)
        return (*(float *)&this->f_08);

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
        (*(float *)&this->f_08) = 50.0f;
        this->f_6c = 0;
        return (*(float *)&this->f_08);
    }

    if (!u->flag12 && u->f14 > 2.5f && (*(float *)&this->f_70) > 0.0f) {
        this->f_6c = 1;
        (*(float *)&this->f_08) = 50.0f;
    }
    return (*(float *)&this->f_08);
}

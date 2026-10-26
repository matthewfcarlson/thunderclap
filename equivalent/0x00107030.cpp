// STATUS: equivalent (tools/equiv.py level 3: 3039 inputs, branch coverage 13/13)
// CRangedAgent::vfunc_3 @ 0x00107030
// CRangedAgent::vfunc_3 @ 0x00107030
#include "compat/ptr.h"
#include "gen/global.h"

struct Stats_107030 {
    char pad0[0x3a0];
    float limit;
};

struct Weapon_107030 {
    char pad0[0x11c];
    Stats_107030 *stats;
};

struct Unit_107030 {
    char pad0[8];
    void *binding;
    char pad0c[0x45 - 0xc];
    char flag45;
    char flag46;
};

class Brain_107030 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Weapon_107030 *v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
    char pad[0x58 - 4];
    Unit_107030 unit;
};

struct CRangedAgent_nv_107030 {
    float FUN_000fc4e0(int a, int b);
};

hulk_freg CRangedAgent::vfunc_3(hulk_intptr a, int b) {
    ((CRangedAgent_nv_107030*)this)->FUN_000fc4e0(a, b);
    Weapon_107030 *weapon = (*(Brain_107030 * *)&this->f_58)->v6();
    Unit_107030 *unit = &(*(Brain_107030 * *)&this->f_58)->unit;
    (*(float *)&this->f_08) = 0.0f;
    if (unit == 0 || unit->binding == 0)
        return 0.0f;

    if (!unit->flag46) {
        if ((*(Brain_107030 * *)&this->f_58)->v9() < 3 || !unit->flag45)
            return (*(float *)&this->f_08);
    }
    if (weapon->stats->limit >= 4.0f) {
        if (unit->flag46) {
            (*(float *)&this->f_08) = 60.0f;
            return (*(float *)&this->f_08);
        }
        (*(float *)&this->f_08) = 40.0f;
    }
    return (*(float *)&this->f_08);
}

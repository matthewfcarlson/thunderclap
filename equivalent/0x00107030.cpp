// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 13/14, incomplete)
// CRangedAgent::vfunc_3 @ 0x00107030
// CRangedAgent::vfunc_3 @ 0x00107030
struct Stats {
    char pad0[0x3a0];
    float limit;
};

struct Weapon {
    char pad0[0x11c];
    Stats *stats;
};

struct Unit {
    char pad0[8];
    void *binding;
    char pad0c[0x45 - 0xc];
    char flag45;
    char flag46;
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

class CRangedAgent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual float vfunc_3(int a, int b);
    char pad4[4];
    float value;
    char pad0c[0x58 - 0xc];
    Brain *brain;

    float FUN_000fc4e0(int a, int b);
};

float CRangedAgent::vfunc_3(int a, int b)
{
    FUN_000fc4e0(a, b);
    Weapon *weapon = brain->v6();
    Unit *unit = &brain->unit;
    value = 0.0f;
    if (unit == 0 || unit->binding == 0)
        return 0.0f;

    if (!unit->flag46) {
        if (brain->v9() < 3 || !unit->flag45)
            return value;
    }
    if (weapon->stats->limit >= 4.0f) {
        if (unit->flag46) {
            value = 60.0f;
            return value;
        }
        value = 40.0f;
    }
    return value;
}

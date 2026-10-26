// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 31/32, incomplete)
// FEThingsBase::vfunc_36 @ 0x000f07b0
#include "compat/ptr.h"
#include "gen/global.h"

class Param_f07b0 {
public:
    float FUN_000fad30();
    unsigned FUN_000faeb0();
    bool FUN_000f9e90();
};

class Args_f07b0 {
public:
    virtual void v0();
    virtual unsigned GetKey();
};

struct Target_f07b0 {
    char pad0[0x141];
    char flag141;
    char flag142;
    char pad143;
    char flag144;
    char pad145[0x14c - 0x145];
    unsigned color;
};

struct FEThingsBase_nv_f07b0 {
    void FUN_000eff20(Param_f07b0 *p, int b, Target_f07b0 *t, int mode);
};

bool FEThingsBase::vfunc_36(hulk_intptr __p0, int b, hulk_intptr __p2, hulk_intptr __p3) { Param_f07b0 * p = (Param_f07b0 *)__p0; Target_f07b0 * t = (Target_f07b0 *)__p2; Args_f07b0 * a = (Args_f07b0 *)__p3;

    switch (a->GetKey()) {
    case 0x800e8237:
        ((FEThingsBase_nv_f07b0*)this)->FUN_000eff20(p, b, t, 0);
        return true;
    case 0x04605ef2:
        ((FEThingsBase_nv_f07b0*)this)->FUN_000eff20(p, b, t, 1);
        return true;
    case 0xfe1d4671:
        ((FEThingsBase_nv_f07b0*)this)->FUN_000eff20(p, b, t, 2);
        return true;
    case 0x67b8aefc:
        ((FEThingsBase_nv_f07b0*)this)->FUN_000eff20(p, b, t, 3);
        return true;
    case 0xeb227e7b:
        ((FEThingsBase_nv_f07b0*)this)->FUN_000eff20(p, b, t, 4);
        return true;
    case 0xfb26aca4:
        t->flag144 = p->FUN_000faeb0() != 0xa3c653f9;
        return true;
    case 0x700e422a:
        t->flag141 = p->FUN_000faeb0() != 0x457e63d9;
        return true;
    case 0x79bbec03:
        t->flag142 = p->FUN_000faeb0() != 0xa3c653f9;
        return true;
    case 0x5d7d2382: {
        int c1 = (int)p->FUN_000fad30();
        int c2 = (int)p->FUN_000fad30();
        int c3 = (int)p->FUN_000fad30();
        int alpha = 0xff;
        if (p->FUN_000f9e90())
            alpha = (int)p->FUN_000fad30();
        t->color = (((alpha << 8 | c1) << 8 | c2) << 8) | c3;
        return true;
    }
    }
    return false;
}

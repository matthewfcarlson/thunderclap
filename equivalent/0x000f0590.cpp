// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 22/22)
// FEThingsBase::vfunc_34 @ 0x000f0590
#include "compat/ptr.h"
#include "gen/global.h"

class Param_f0590 {
public:
    float FUN_000fad30();
    __int64 FUN_000faeb0();
    bool FUN_000f9e90();
};

class Args_f0590 {
public:
    virtual void v0();
    virtual unsigned GetKey();
};

struct FEThingsBase_nv_f0590 {
    void FUN_000e0360(float x, float y, float z);
    int FUN_000e7ec0(__int64 id, Param_f0590 *p);
    int FUN_000e7f10(__int64 id, Param_f0590 *p);
    void FUN_000e0300(float f, int a, int b);
    void FUN_000e03c0(float x, float y, int a, int b, int c);
    void FUN_000e7d90(Param_f0590 *p, int c);
    void FUN_000e7c30(Param_f0590 *p, int c);
    void FUN_000e7cd0(Param_f0590 *p, int c);
    void FUN_000e7b90(Param_f0590 *p, int c);
};

bool FEThingsBase::vfunc_34(hulk_intptr __p0, hulk_intptr __p1, int c) { Param_f0590 * p = (Param_f0590 *)__p0; Args_f0590 * a = (Args_f0590 *)__p1;

    switch (a->GetKey()) {
    case 0x9cf1366a: {
        float x = p->FUN_000fad30();
        float y = p->FUN_000fad30();
        float z = p->FUN_000fad30();
        ((FEThingsBase_nv_f0590*)this)->FUN_000e0360(x, y, z);
        return true;
    }
    case 0x81467d1e: {
        float f = p->FUN_000fad30();
        int ra = ((FEThingsBase_nv_f0590*)this)->FUN_000e7ec0(p->FUN_000faeb0(), p);
        int rb = 2;
        if (p->FUN_000f9e90())
            rb = ((FEThingsBase_nv_f0590*)this)->FUN_000e7f10(p->FUN_000faeb0(), p);
        ((FEThingsBase_nv_f0590*)this)->FUN_000e0300(f, ra, rb);
        return true;
    }
    case 0xdc18a191: {
        float x = p->FUN_000fad30();
        float y = p->FUN_000fad30();
        int c1 = (int)p->FUN_000fad30();
        int c2 = (int)p->FUN_000fad30();
        int c3 = (int)p->FUN_000fad30();
        ((FEThingsBase_nv_f0590*)this)->FUN_000e03c0(x, y, c1, c2, c3);
        return true;
    }
    case 0x0d2b530a: {
        int c1 = (int)p->FUN_000fad30();
        int c2 = (int)p->FUN_000fad30();
        int c3 = (int)p->FUN_000fad30();
        (*(unsigned int *)&this->f_1850) = (((0xffffff00u | c1) << 8 | c2) << 8) | c3;
        return true;
    }
    case 0x257960fb:
        ((FEThingsBase_nv_f0590*)this)->FUN_000e7d90(p, c);
        return true;
    case 0x3d3d4c3b:
        ((FEThingsBase_nv_f0590*)this)->FUN_000e7c30(p, c);
        return true;
    case 0x3e24edbf:
        ((FEThingsBase_nv_f0590*)this)->FUN_000e7cd0(p, c);
        return true;
    case 0x5772e4d0:
        ((FEThingsBase_nv_f0590*)this)->FUN_000e7b90(p, c);
        return true;
    }
    return false;
}

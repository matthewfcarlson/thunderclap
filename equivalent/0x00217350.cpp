// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 14/14)
// singlestep: one step of the collector's state machine (propagate, sweep strings, sweep, finalize); the budget left.
#include "decls/data/lua.h"

// equiv-conv: FUN_00216ac0 eax stack
extern "C" int __cdecl FUN_00216ac0(int lim, LuaVMGlobal* g);
// equiv-conv: FUN_00217050 eax
extern "C" void __cdecl FUN_00217050(LuaVMState* L);
// equiv-conv: FUN_00216e10 stack stack ebx
extern "C" int __cdecl FUN_00216e10(int all, int lim, LuaVMState* L);
extern "C" LuaVMGCObject** __cdecl FUN_002171c0(LuaVMState* L, LuaVMGCObject** p, int all, int* lim, int* count);
// equiv-conv: FUN_00216e70 ebx
extern "C" void __cdecl FUN_00216e70(LuaVMState* L);
// equiv-conv: FUN_00216ed0 esi
extern "C" void __cdecl FUN_00216ed0(LuaVMState* L);
// equiv-conv: FUN_00216f90 edi
extern "C" void __cdecl FUN_00216f90(LuaVMState* L);
// equiv-conv: FUN_00217350 eax stack
extern "C" int __cdecl FUN_00217350(LuaVMState* L, int lim) {
    LuaVMGlobal* g = L->l_G;
    switch (g->gcstate) {
    case 0:
        if (g->gray)
            return FUN_00216ac0(lim, g);
        FUN_00217050(L);
        return 0;
    case 1: {
        int result = FUN_00216e10(1, lim, L);
        if (g->sweepstrgc >= g->strt.size) {
            g->sweepstrgc = 0;
            g->gcstate = 2;
        }
        return result;
    }
    case 2: {
        LuaVMGCObject** p = FUN_002171c0(L, g->sweepgc, 1, &lim, 0);
        g->sweepgc = p;
        if (*p == 0) {
            FUN_00216e70(L);
            g->sweepgc = &g->rootgc;
            g->gcstate = 3;
        }
        return lim;
    }
    case 3:
        if (g->tmudata) {
            FUN_00216ed0(L);
            return lim - 80;
        }
        FUN_00216f90(L);
        return 0;
    default:
        return lim;
    }
}

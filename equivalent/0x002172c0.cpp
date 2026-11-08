// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 2/2)
// luaC_sweepall: sweep everything twice (the second time with the other white), keeping the main thread.
#include "decls/data/lua.h"

// equiv-conv: FUN_00216e10 stack stack ebx
extern "C" int __cdecl FUN_00216e10(int all, int lim, LuaVMState* L);
extern "C" LuaVMGCObject** __cdecl FUN_002171c0(LuaVMState* L, LuaVMGCObject** p, int all, int* lim, int* count);
extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o);

extern "C" void __cdecl FUN_002172c0(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    int lim = 0x7fffffff;
    FUN_00216e10(0, 0x7fffffff, L);
    FUN_002171c0(L, &g->rootgc, 0, &lim, 0);
    LuaVMGCObject* mainthread = (LuaVMGCObject*)g->mainthread;
    if (mainthread->marked & 3)
        FUN_002164b0(g, mainthread);
    g->currentwhite ^= 3;
    g->sweepgc = &g->rootgc;
    g->sweepstrgc = 0;
    FUN_00216e10(0, 0x7fffffff, L);
    FUN_002171c0(L, &g->rootgc, 0, &lim, 0);
}

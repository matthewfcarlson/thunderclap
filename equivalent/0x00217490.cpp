// STATUS: equivalent (tools/equiv.py level 3: 8 inputs, branch coverage 11/12, incomplete)
// luaC_fullgc: finish the current cycle, run a whole one, set the threshold and call the finalizers.
#include "decls/data/lua.h"

// equiv-conv: FUN_00217350 eax stack
extern "C" int __cdecl FUN_00217350(LuaVMState* L, int lim);
// equiv-conv: FUN_00216f90 edi
extern "C" void __cdecl FUN_00216f90(LuaVMState* L);
// equiv-conv: FUN_00216ed0 esi
extern "C" void __cdecl FUN_00216ed0(LuaVMState* L);

extern "C" void __cdecl FUN_00217490(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    while (g->gcstate != 3)
        FUN_00217350(L, 0x7fffffff);
    FUN_00216f90(L);
    while (g->gcstate != 3)
        FUN_00217350(L, 0x7fffffff);
    g->GCthreshold = g->totalbytes + 0x140;
    while (L->l_G->tmudata != 0)
        FUN_00216ed0(L);
}

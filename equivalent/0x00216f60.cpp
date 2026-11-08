// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 4/4)
// luaC_callGCTM: run the pending finalizers.
#include "decls/data/lua.h"

// equiv-conv: FUN_00216ed0 esi
extern "C" void __cdecl FUN_00216ed0(LuaVMState* L);

extern "C" void __cdecl FUN_00216f60(LuaVMState* L) {
    while (L->l_G->tmudata != 0)
        FUN_00216ed0(L);
}

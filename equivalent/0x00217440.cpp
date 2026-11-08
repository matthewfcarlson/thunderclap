// STATUS: equivalent (tools/equiv.py level 3: 2592 inputs, branch coverage 6/6)
// luaC_step: run collector steps for the bytes allocated past the threshold; set the next threshold.
#include "decls/data/lua.h"

// equiv-conv: FUN_00217350 eax stack
extern "C" int __cdecl FUN_00217350(LuaVMState* L, int lim);

extern "C" void __cdecl FUN_00217440(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    int lim = (int)(g->totalbytes - g->GCthreshold) * 8 + 0xa00;
    do {
        lim = FUN_00217350(L, lim);
        if (g->gcstate == 3 && g->tmudata == 0)
            break;
    } while (lim > 0);
    g->GCthreshold = g->totalbytes - (lim / 8) + 0x140;
}

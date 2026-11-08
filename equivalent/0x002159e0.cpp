// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 10/10)
// luaD_call: call func with its arguments above it (C-stack depth checked), then the GC step.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_002152b0(LuaVMState* L, int errcode);
extern "C" LuaVMTObject* __cdecl FUN_00215790(LuaVMState* L, LuaVMTObject* func);
extern "C" LuaVMTObject* __cdecl FUN_00218350(LuaVMState* L, int nexeccalls);
extern "C" void __cdecl FUN_00215970(LuaVMState* L, int wanted, LuaVMTObject* firstResult);
extern "C" void __cdecl FUN_00217440(LuaVMState* L);

extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nResults) {
    if (++L->nCcalls >= 200) {
        if (L->nCcalls == 200)
            FUN_00214a90(L, "C stack overflow");
        else if (L->nCcalls >= 225)
            FUN_002152b0(L, 5);
    }
    LuaVMTObject* first = FUN_00215790(L, func);
    if (first == 0)
        first = FUN_00218350(L, 1);
    FUN_00215970(L, nResults, first);
    L->nCcalls--;
    if (L->l_G->totalbytes >= L->l_G->GCthreshold)
        FUN_00217440(L);
}

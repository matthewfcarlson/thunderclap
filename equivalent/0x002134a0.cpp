// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 6/6)
// lua_pushcclosure: push a C closure of fn with the n top values as its upvalues (a GC step first when due).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" LuaVMClosure* __cdecl FUN_00219520(LuaVMState* L, int nelems);

extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n) {
    if (L->l_G->totalbytes >= L->l_G->GCthreshold)
        FUN_00217440(L);
    LuaVMClosure* cl = FUN_00219520(L, n);
    cl->c.f = fn;
    L->top -= n;
    while (n--)
        cl->c.upvalue[n] = L->top[n];
    L->top->value.gc = (LuaVMGCObject*)cl;
    L->top->tt = LUAVM_TFUNCTION;
    L->top++;
}

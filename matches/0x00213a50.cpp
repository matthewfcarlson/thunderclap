// cl-flags: /O2 /GR /GX
// f_Ccall: the protected body of lua_cpcall: push a C closure of the CCallS's function and its light userdata, call.
#include "decls/data/lua.h"

extern "C" LuaVMClosure* __cdecl FUN_00219520(LuaVMState* L, int nelems);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);

extern "C" void __cdecl FUN_00213a50(LuaVMState* L, void* ud) {
    LuaVMCCallS* c = (LuaVMCCallS*)ud;
    LuaVMClosure* cl = FUN_00219520(L, 0);
    cl->c.f = c->func;
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)cl;
    o->tt = LUAVM_TFUNCTION;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    o = L->top;
    o->value.p = c->ud;
    o->tt = LUAVM_TLIGHTUSERDATA;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    FUN_002159e0(L, L->top - 2, 0);
}

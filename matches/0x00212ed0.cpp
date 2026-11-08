// lua_pushvalue: push a copy of the value at idx.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    *L->top = *o;
    L->top++;
}

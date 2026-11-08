// lua_isstring: the value at idx is a string or a number.
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx) {
    int i = *(volatile int*)&idx;  // idx loaded first (ecx), as the original
    LuaVMTObject* o = FUN_00212bb0(i, L);
    if (o == LUAVM_NILOBJECT)
        return 0;
    return o->tt == LUAVM_TSTRING || o->tt == LUAVM_TNUMBER;
}

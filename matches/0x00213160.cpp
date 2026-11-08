// lua_toboolean: the value at idx is neither nil nor false.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" int __cdecl FUN_00213160(LuaVMState* L, int idx) {
    int i = *(volatile int*)&idx;  // idx loaded first (ecx), as the original
    LuaVMTObject* o = FUN_00212bb0(i, L);
    return o->tt != LUAVM_TNIL && (o->tt != LUAVM_TBOOLEAN || o->value.b != 0);
}

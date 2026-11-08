// lua_iscfunction: the value at idx is a C closure.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" int __cdecl FUN_00212f40(LuaVMState* L, int idx) {
    int i = *(volatile int*)&idx;  // idx loaded first (ecx), as the original
    LuaVMTObject* o = FUN_00212bb0(i, L);
    if (o->tt == LUAVM_TFUNCTION && ((LuaVMClosure*)o->value.gc)->c.isC)
        return 1;
    return 0;
}

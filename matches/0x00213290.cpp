// lua_tothread: the thread at idx, or NULL.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState* L, int idx) {
    int i = *(volatile int*)&idx;  // idx loaded first (ecx), as the original
    LuaVMTObject* o = FUN_00212bb0(i, L);
    if (o->tt != LUAVM_TTHREAD)
        return 0;
    return (LuaVMState*)o->value.gc;
}

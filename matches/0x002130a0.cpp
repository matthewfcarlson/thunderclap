// lua_lessthan: the value at index1 is less than the one at index2 (0 when either is absent).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" int __cdecl FUN_00217cf0(LuaVMState* L, const LuaVMTObject* l, const LuaVMTObject* r);

extern "C" int __cdecl FUN_002130a0(LuaVMState* L, int index1, int index2) {
    LuaVMTObject* o1 = FUN_00212bb0(index1, L);
    LuaVMTObject* o2 = FUN_00212bb0(index2, L);
    if (o1 != LUAVM_NILOBJECT && o2 != LUAVM_NILOBJECT)
        return FUN_00217cf0(L, o1, o2);
    return 0;
}

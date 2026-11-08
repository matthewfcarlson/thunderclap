// lua_equal: the values at index1 and index2 are equal (primitive equality; 0 when either is absent).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" int __cdecl FUN_00215fa0(const LuaVMTObject* t1, const LuaVMTObject* t2);

extern "C" int __cdecl FUN_00213010(LuaVMState* L, int index1, int index2) {
    LuaVMTObject* o1 = FUN_00212bb0(index1, L);
    LuaVMTObject* o2 = FUN_00212bb0(index2, L);
    if (o1 != LUAVM_NILOBJECT && o2 != LUAVM_NILOBJECT)
        return FUN_00215fa0(o1, o2);
    return 0;
}

// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 2/2)
// lua_type: the type tag of the value at idx (LUA_TNONE -1 when absent).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o == LUAVM_NILOBJECT)
        return -1;
    return o->tt;
}

// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// lua_touserdata: the block of the full userdata or the light userdata at idx; NULL otherwise.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" void* __cdecl FUN_00213260(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt == LUAVM_TLIGHTUSERDATA)
        return o->value.p;
    if (o->tt == LUAVM_TUSERDATA)
        return (LuaVMUdata*)o->value.gc + 1;
    return 0;
}

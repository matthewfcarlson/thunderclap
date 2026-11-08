// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// lua_isuserdata: the value at idx is a full or light userdata.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" int __cdecl FUN_00212fe0(LuaVMState* L, int idx) {
    int t = FUN_00212bb0(idx, L)->tt;
    return t == LUAVM_TUSERDATA || t == LUAVM_TLIGHTUSERDATA;
}

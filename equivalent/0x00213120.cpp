// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 4/4)
// lua_tointeger: the number at idx truncated to an integer (converted from a string when it can be); 0 otherwise.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" const LuaVMTObject* __cdecl FUN_00217600(const LuaVMTObject* obj, LuaVMTObject* n);

extern "C" int __cdecl FUN_00213120(LuaVMState* L, int idx) {
    LuaVMTObject n;
    const LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt == LUAVM_TNUMBER || (o = FUN_00217600(o, &n)) != 0)
        return (int)(__int64)o->value.n;
    return 0;
}

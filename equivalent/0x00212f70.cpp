// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 4/4)
// lua_isnumber: the value at idx is a number or converts to one.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" const LuaVMTObject* __cdecl FUN_00217600(const LuaVMTObject* obj, LuaVMTObject* n);

extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx) {
    LuaVMTObject n;
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt != LUAVM_TNUMBER && FUN_00217600(o, &n) == 0)
        return 0;
    return 1;
}

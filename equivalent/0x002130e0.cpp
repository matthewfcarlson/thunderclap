// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 4/4)
// lua_tonumber: the number at idx (converted from a string when it can be); 0 otherwise.
#include "decls/data/lua.h"
#include "decls/data/game/global.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" const LuaVMTObject* __cdecl FUN_00217600(const LuaVMTObject* obj, LuaVMTObject* n);

extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx) {
    LuaVMTObject n;
    const LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt != LUAVM_TNUMBER) {
        o = FUN_00217600(o, &n);
        if (!o)
            return DAT_003f32e0;
    }
    return o->value.n;
}

// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 0/0)
// lua_pushinteger.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n) {
    LuaVMTObject* o = L->top;
    o->tt = LUAVM_TNUMBER;
    o->value.n = (float)n;
    L->top++;
}

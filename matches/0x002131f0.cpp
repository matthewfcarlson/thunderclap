// lua_strlen: the length of the string at idx (a number is converted in place); 0 otherwise.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" int __cdecl FUN_00217640(LuaVMState* L, LuaVMTObject* obj);

extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt == LUAVM_TSTRING)
        return ((LuaVMString*)o->value.gc)->len;
    if (FUN_00217640(L, o))
        return ((LuaVMString*)o->value.gc)->len;
    return 0;
}

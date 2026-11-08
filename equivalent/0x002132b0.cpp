// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 13/13)
// lua_topointer: the address of the table, function, thread or userdata at idx; NULL otherwise.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" const void* __cdecl FUN_002132b0(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    switch (o->tt) {
    case LUAVM_TLIGHTUSERDATA:
    case LUAVM_TUSERDATA:
        o = FUN_00212bb0(idx, L);  // lua_touserdata inlined
        if (o->tt == LUAVM_TLIGHTUSERDATA)
            return o->value.p;
        if (o->tt == LUAVM_TUSERDATA)
            return (LuaVMUdata*)o->value.gc + 1;
        break;
    case LUAVM_TTABLE:
    case LUAVM_TFUNCTION:
    case LUAVM_TTHREAD:
        return o->value.gc;
    }
    return 0;
}

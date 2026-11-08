// luaT_gettmbyobj: the event's metamethod of a table or userdata's metatable, or luaO_nilobject.
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);

extern "C" const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event) {
    LuaVMTable* mt;
    switch (o->tt) {
    case LUAVM_TTABLE:
        mt = ((LuaVMTable*)o->value.gc)->metatable;
        break;
    case LUAVM_TUSERDATA:
        mt = ((LuaVMUdata*)o->value.gc)->metatable;
        break;
    default:
        return LUAVM_NILOBJECT;
    }
    if (mt != 0)
        return FUN_00219e50(mt, L->l_G->tmname[event]);
    return LUAVM_NILOBJECT;
}

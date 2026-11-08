// lua_getmetatable: push the metatable of the table or userdata at objindex; 0 when it has none.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" int __cdecl FUN_002136d0(LuaVMState* L, int objindex) {
    LuaVMTObject* obj = FUN_00212bb0(objindex, L);
    LuaVMTable* mt;
    switch (obj->tt) {
    case LUAVM_TTABLE:
        mt = ((LuaVMTable*)obj->value.gc)->metatable;
        break;
    case LUAVM_TUSERDATA:
        mt = ((LuaVMUdata*)obj->value.gc)->metatable;
        break;
    default:
        return 0;
    }
    if (mt == 0)
        return 0;
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)mt;
    o->tt = LUAVM_TTABLE;
    L->top++;
    return 1;
}

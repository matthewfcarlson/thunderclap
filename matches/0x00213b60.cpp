// lua_dump: dump the Lua function on top through writer; 0 when it is not one.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021ad80(LuaVMState* L, LuaVMProto* f, LuaVMWriter w, void* data, int strip);

extern "C" int __cdecl FUN_00213b60(LuaVMState* L, LuaVMWriter writer, void* data) {
    LuaVMTObject* o = L->top - 1;
    if (o->tt == LUAVM_TFUNCTION) {
        LuaVMClosure* cl = (LuaVMClosure*)o->value.gc;
        if (cl->c.isC == 0)
            return FUN_0021ad80(L, cl->l.p, writer, data, 0);
    }
    return 0;
}

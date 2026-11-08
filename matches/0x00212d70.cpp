// lua_gettop: the number of values in the current frame.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00212d70(LuaVMState* L) {
    return (int)(L->top - L->base);
}

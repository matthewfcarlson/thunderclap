// getS: luaL_loadbuffer's reader (a LuaVMReader; ud is the LuaVMLoadS): the whole buffer once.
#include "decls/data/lua.h"
extern "C" const char* __cdecl FUN_00339a40(LuaVMState* L, void* ud, unsigned int* out) {
    LuaVMLoadS* p = (LuaVMLoadS*)ud;
    unsigned int b = p->size;
    if (!b)
        return 0;
    *out = b;
    p->size = 0;
    return p->s;
}

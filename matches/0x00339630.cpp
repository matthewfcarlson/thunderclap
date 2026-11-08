// luaL_buffinit
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00339630(LuaVMState* L, LuaVMLBuffer* buffer) {
    buffer->L = L;
    buffer->p = buffer->buffer;
    buffer->lvl = 0;
}

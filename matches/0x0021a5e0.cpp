// luaZ_init: a stream over a reader.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_0021a5e0(LuaVMState* L, LuaVMZio* z, LuaVMReader reader, void* data) {
    z->L = L;
    z->reader = reader;
    z->data = data;
    z->n = 0;
    z->p = 0;
}

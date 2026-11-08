// luaS_freeall: free the string table's hash array.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

extern "C" void __cdecl FUN_002192c0(LuaVMState* L) {
    FUN_0021add0(L, L->l_G->strt.hash, L->l_G->strt.size * (unsigned int)sizeof(LuaVMString*), 0);
}

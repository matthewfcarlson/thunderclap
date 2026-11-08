// luaM_realloc: (re)allocate through the state's allocator and count the bytes.
#include "decls/data/lua.h"

void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
LuaVMState* __cdecl FUN_002152b0(LuaVMState* L, int errcode);

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize) {
    LuaVMGlobal* g = L->l_G;
    if (nsize >= 0xfffffffd)
        FUN_00214a90(L, "memory allocation error: block too big");
    void* r = g->frealloc(g->ud, block, osize, nsize);
    if (r == 0 && nsize > 0)
        FUN_002152b0(L, 4);
    g->totalbytes += nsize - osize;
    return r;
}

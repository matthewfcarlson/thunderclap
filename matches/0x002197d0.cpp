// luaF_freeclosure: free a C or Lua closure by its size.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

extern "C" void __cdecl FUN_002197d0(LuaVMState* L, LuaVMClosure* c) {
    FUN_0021add0(L, c,
                 c->c.isC ? (unsigned int)LUAVM_SIZECCLOSURE(c->c.nupvalues)
                          : (unsigned int)LUAVM_SIZELCLOSURE(c->l.nupvalues),
                 0);
}

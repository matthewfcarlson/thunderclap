// luaD_reallocCI: resize the CallInfo array and move ci / end_ci with it.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

extern "C" void __cdecl FUN_00215410(LuaVMState* L, int newsize) {
    unsigned short c = (unsigned short)newsize;
    LuaVMCallInfo* oldci = L->base_ci;
    LuaVMCallInfo* n = (LuaVMCallInfo*)FUN_0021add0(L, oldci, (unsigned int)L->size_ci * (unsigned int)sizeof(LuaVMCallInfo),
                                                    (unsigned int)newsize * (unsigned int)sizeof(LuaVMCallInfo));
    L->size_ci = c;
    L->base_ci = n;
    L->ci = n + (L->ci - oldci);
    L->end_ci = n + c;
}

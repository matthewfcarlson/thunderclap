// luaM_growaux: double a vector (4 at least, limit at most; an error near the limit).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

extern "C" void* __cdecl FUN_0021ae40(LuaVMState* L, void* block, int* size, int size_elems, int limit,
                                      const char* errormsg) {
    int newsize = limit;
    if (*size >= limit / 2) {
        if (*size >= limit - 4)
            FUN_00214a90(L, errormsg);
    } else {
        newsize = *size * 2;
        if (newsize < 4)
            newsize = 4;
    }
    void* newblock = FUN_0021add0(L, block, *size * size_elems, newsize * size_elems);
    *size = newsize;
    return newblock;
}

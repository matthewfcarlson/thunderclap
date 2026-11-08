// l_alloc: luaL_newstate's allocator (a LuaVMAlloc): free on a zero size, else realloc.
#include "decls/data/lua.h"
extern "C" void FUN_003479bc(void*);                  // free
extern "C" void* FUN_00347d7a(void*, unsigned int);   // realloc
extern "C" void* __cdecl FUN_00339a90(void* ud, void* p, unsigned int osize, unsigned int nsize) {
    if (!nsize) {
        FUN_003479bc(p);
        return 0;
    }
    return FUN_00347d7a(p, nsize);
}

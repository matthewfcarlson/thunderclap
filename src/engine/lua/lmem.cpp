// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0021add0..0x0021aeb0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f3dfd5e8 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3dfd5e8 {} using namespace fn_f3dfd5e8;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f3dfd5e8 {
void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
LuaVMState* __cdecl FUN_002152b0(LuaVMState* L, int errcode);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);


// 0x0021add0 FUN_0021add0 (97 B): matches/0x0021add0.cpp
// sym: _FUN_0021add0
// luaM_realloc: (re)allocate through the state's allocator and count the bytes.
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


// 0x0021ae40 FUN_0021ae40 (100 B): matches/0x0021ae40.cpp
// sym: _FUN_0021ae40
// luaM_growaux: double a vector (4 at least, limit at most; an error near the limit).
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

} // namespace fn_f3dfd5e8

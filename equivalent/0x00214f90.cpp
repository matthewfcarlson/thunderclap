// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 0/0)
// close_state: close the upvalues, free every object, the string table and the buffer, the main thread's stacks
// and the state block itself.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00219660(LuaVMState* L, LuaVMStkId level);
extern "C" void __cdecl FUN_002172c0(LuaVMState* L);
extern "C" void __cdecl FUN_002192c0(LuaVMState* L);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

// equiv-conv: FUN_00214f90 esi
extern "C" void __cdecl FUN_00214f90(LuaVMState* L) {
    HULK_SIZE32(LuaVMLG, 0x108);
    LuaVMGlobal* g = L->l_G;
    FUN_00219660(L, L->stack);
    FUN_002172c0(L);
    FUN_002192c0(L);
    g->buff.buffer = (char*)FUN_0021add0(L, g->buff.buffer, g->buff.buffsize, 0);
    g->buff.buffsize = 0;
    FUN_0021add0(L, L->base_ci, (unsigned int)L->size_ci * (unsigned int)sizeof(LuaVMCallInfo), 0);
    FUN_0021add0(L, L->stack, (unsigned int)L->stacksize * (unsigned int)sizeof(LuaVMTObject), 0);
    g->frealloc(g->ud, L, sizeof(LuaVMLG), 0);
}

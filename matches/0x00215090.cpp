// luaE_freethread: close L1's upvalues, then free its CallInfo array, its stack and the thread.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00219660(LuaVMState* L, LuaVMStkId level);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

extern "C" void __cdecl FUN_00215090(LuaVMState* L, LuaVMState* L1) {
    HULK_SIZE32(LuaVMState, 0x58);
    FUN_00219660(L1, L1->stack);
    FUN_0021add0(L, L1->base_ci, (unsigned int)L1->size_ci * (unsigned int)sizeof(LuaVMCallInfo), 0);
    FUN_0021add0(L, L1->stack, (unsigned int)L1->stacksize * (unsigned int)sizeof(LuaVMTObject), 0);
    FUN_0021add0(L, L1, sizeof(LuaVMState), 0);
}

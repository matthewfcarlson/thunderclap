// STATUS: equivalent (tools/equiv.py level 3: 2982 inputs, branch coverage 0/0)
// stack_init: allocate the value stack (BASIC_STACK_SIZE 40 + EXTRA_STACK 5) and the CallInfo array of thread L1.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

// equiv-conv: FUN_00214dd0 edi esi
extern "C" void __cdecl FUN_00214dd0(LuaVMState* L, LuaVMState* L1) {
    LuaVMTObject* stack = (LuaVMTObject*)FUN_0021add0(L, 0, 0, 45 * (unsigned int)sizeof(LuaVMTObject));
    L1->stack = stack;
    L1->top = stack;
    L1->stacksize = 45;
    L1->stack_last = stack + 45 - 6;
    LuaVMCallInfo* ci = (LuaVMCallInfo*)FUN_0021add0(L, 0, 0, 8 * (unsigned int)sizeof(LuaVMCallInfo));
    L1->ci = ci;
    L1->base_ci = ci;
    L1->top->tt = LUAVM_TNIL;  // the function entry of the first CallInfo
    L1->top++;
    L1->ci->base = L1->top;
    L1->base = L1->ci->base;
    L1->ci->top = L1->top + 20;  // LUA_MINSTACK
    L1->end_ci = L1->base_ci + 8;
    L1->size_ci = 8;
}

// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// luaD_reallocstack: resize the stack to newsize slots (EXTRA_STACK 5 above stack_last), then correctstack.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
// equiv-conv: FUN_00215350 eax edx
extern "C" void __cdecl FUN_00215350(LuaVMState* L, LuaVMTObject* oldstack);

extern "C" void __cdecl FUN_002153d0(LuaVMState* L, int newsize) {
    LuaVMTObject* oldstack = L->stack;
    LuaVMTObject* stack = (LuaVMTObject*)FUN_0021add0(L, oldstack, L->stacksize * (unsigned int)sizeof(LuaVMTObject),
                                                       newsize * (unsigned int)sizeof(LuaVMTObject));
    L->stack_last = stack + newsize - 6;
    L->stack = stack;
    L->stacksize = newsize;
    FUN_00215350(L, oldstack);
}

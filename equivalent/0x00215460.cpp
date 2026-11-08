// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 2/2)
// luaD_growstack: grow the stack by at least n slots, then fix the pointers into it (correctstack).
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
// equiv-conv: FUN_00215350 eax edx
extern "C" void __cdecl FUN_00215350(LuaVMState* L, LuaVMTObject* oldstack);

extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n) {
    int newsize;
    if (n <= L->stacksize)
        newsize = 2 * L->stacksize;
    else
        newsize = L->stacksize + n + 5;
    LuaVMTObject* oldstack = L->stack;
    L->stack = (LuaVMTObject*)FUN_0021add0(L, oldstack, L->stacksize * (unsigned int)sizeof(LuaVMTObject),
                                           newsize * (unsigned int)sizeof(LuaVMTObject));
    L->stacksize = newsize;
    L->stack_last = L->stack + newsize - 6;  // EXTRA_STACK 5
    FUN_00215350(L, oldstack);
}

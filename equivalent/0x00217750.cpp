// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 0/0)
// callTM's pushes: the metamethod f and its operands p1, p2 at the top of the stack (the caller moves top).
#include "decls/data/lua.h"

// equiv-conv: FUN_00217750 ecx stack eax edx
extern "C" void __cdecl FUN_00217750(LuaVMState* L, const LuaVMTObject* f, const LuaVMTObject* p1,
                                     const LuaVMTObject* p2) {
    L->top[0] = *f;
    L->top[1] = *p1;
    L->top[2] = *p2;
}

// STATUS: equivalent (tools/equiv.py level 3: 102 inputs, branch coverage 8/8)
// correctstack: after the stack moved from oldstack, move top, the open upvalues and every CallInfo with it.
// equiv-conv: FUN_00215350 eax edx
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00215350(LuaVMState* L, LuaVMTObject* oldstack) {
    L->top = L->stack + (L->top - oldstack);
    for (LuaVMGCObject* up = L->openupval; up != 0; up = up->next)
        ((LuaVMUpVal*)up)->v = L->stack + (((LuaVMUpVal*)up)->v - oldstack);
    for (LuaVMCallInfo* ci = L->base_ci; ci <= L->ci; ci++) {
        ci->top = L->stack + (ci->top - oldstack);
        ci->base = L->stack + (ci->base - oldstack);
    }
    L->base = L->ci->base;
}

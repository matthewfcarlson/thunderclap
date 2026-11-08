// luaA_pushobject: push a copy of o (setobj2s + incr_top).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);

extern "C" void __cdecl FUN_00212c10(LuaVMState* L, const LuaVMTObject* o) {
    LuaVMTObject* t = L->top;
    t->tt = o->tt;
    t->value = o->value;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
}

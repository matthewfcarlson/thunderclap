// STATUS: equivalent (tools/equiv.py level 3: 3064 inputs, branch coverage 10/10)
// lua_getinfo: fill ar for the activation it names, or for the function on top when what starts with '>'.
extern "C" char* __cdecl strchr(const char*, int);
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
// equiv-conv: FUN_00214ac0 eax esi edi stack stack
extern "C" int __cdecl FUN_00214ac0(const char* what, LuaVMDebug* ar, LuaVMCallInfo* ci, LuaVMState* L, const LuaVMTObject* f);
// equiv-conv: FUN_002141d0 esi stack
extern "C" void __cdecl FUN_002141d0(LuaVMDebug* ar, LuaVMState* L);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);

extern "C" int __cdecl FUN_00214bd0(LuaVMState* L, const char* what, LuaVMDebug* ar)
{
    int status = 1;
    if (*what == '>') {
        LuaVMTObject* f = L->top - 1;
        if (f->tt != LUAVM_TFUNCTION)
            FUN_00214a90(L, "value for `lua_getinfo' is not a function");
        status = FUN_00214ac0(what + 1, ar, 0, L, f);
        L->top -= 1;
    } else if (ar->i_ci != 0) {
        LuaVMCallInfo* ci = L->base_ci + ar->i_ci;
        status = FUN_00214ac0(what, ar, ci, L, ci->base - 1);
    } else {
        FUN_002141d0(ar, L);
    }
    if (strchr(what, 'f')) {
        if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
            FUN_00215460(L, 1);
        L->top += 1;
    }
    return status;
}

// STATUS: equivalent (tools/equiv.py level 3: 3104 inputs, branch coverage 12/14, incomplete)
// lua_setlocal: pop the top value into local n of the activation ar names; its name or NULL.
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00219820(const LuaVMProto* f, int local_number, int pc);

extern "C" const char* __cdecl FUN_002140c0(LuaVMState* L, LuaVMDebug* ar, int n) {
    LuaVMCallInfo* ci = L->base_ci + ar->i_ci;
    LuaVMTObject* fn = ci->base - 1;
    LuaVMProto* p = 0;
    if (fn->tt == LUAVM_TFUNCTION && ((LuaVMClosure*)fn->value.gc)->c.isC == 0)
        p = ((LuaVMClosure*)fn->value.gc)->l.p;
    L->top--;
    if (p == 0)
        return 0;
    int pc = -1;
    fn = ci->base - 1;
    if (fn->tt == LUAVM_TFUNCTION && ((LuaVMClosure*)fn->value.gc)->c.isC == 0)
        pc = (int)(ci->savedpc - ((LuaVMClosure*)fn->value.gc)->l.p->code) - 1;
    const char* name = FUN_00219820(p, n, pc);
    if (name == 0 || name[0] == '(')
        return 0;
    ci->base[n - 1] = *L->top;
    return name;
}

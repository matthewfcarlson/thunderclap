// lua_getlocal: push local n of the activation ar names; its name or NULL.
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00219820(const LuaVMProto* f, int local_number, int pc);
extern "C" void __cdecl FUN_00212c10(LuaVMState* L, const LuaVMTObject* o);

extern "C" const char* __cdecl FUN_00214050(LuaVMState* L, LuaVMDebug* ar, int n) {
    const char* name = 0;
    LuaVMCallInfo* ci = &L->base_ci[ar->i_ci];
    if (ci->base[-1].tt == LUAVM_TFUNCTION) {
        LuaVMClosure* cl = (LuaVMClosure*)ci->base[-1].value.gc;
        if (cl->c.isC == 0) {
            LuaVMProto* p = cl->l.p;
            if (p) {
                int pc = (int)(ci->savedpc - p->code) - 1;
                name = FUN_00219820(p, n, pc);
                if (name)
                    FUN_00212c10(L, ci->base + (n - 1));
            }
        }
    }
    return name;
}

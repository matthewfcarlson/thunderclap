// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 13/14, incomplete)
// lua_getstack: find the activation level levels up (tail calls count) and store its CallInfo index in ar.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar) {
    LuaVMCallInfo* ci = L->ci;
    if (level > 0) {
        do {
            if (ci <= L->base_ci) {
                if (level > 0)
                    return 0;
                break;
            }
            level--;
            if (((LuaVMClosure*)ci->base[-1].value.gc)->c.isC == 0)
                level -= ci->tailcalls;
            ci--;
        } while (level > 0);
    }
    if (ci == L->base_ci)
        return 0;
    if (level < 0) {
        ar->i_ci = 0;
        return 1;
    }
    ar->i_ci = (int)(ci - L->base_ci);
    return 1;
}

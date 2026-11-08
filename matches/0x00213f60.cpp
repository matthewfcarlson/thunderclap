// lua_sethook: install func for the events in mask (no hook when either is 0), count for the count hook.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00213f60(LuaVMState* L, LuaVMHook func, int mask, int count) {
    if (func == 0 || mask == 0) {
        mask = 0;
        func = 0;
    }
    L->hook = func;
    L->basehookcount = count;
    L->hookcount = count;
    L->hookmask = (unsigned char)mask;
    return 1;
}

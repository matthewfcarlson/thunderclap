#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212fe0(LuaVMState* L, int idx);
extern "C" void* __cdecl FUN_00213260(LuaVMState* L, int idx);
typedef int(__cdecl* Fn_1d0d30)(LuaVMState*, void*);
int __cdecl FUN_001d0d30(LuaVMState* L) {
    if (!FUN_00212fe0(L, -10002))
        return 0;
    Fn_1d0d30 f = (Fn_1d0d30)FUN_00213260(L, -10002);
    if (!FUN_00212fe0(L, -10003))
        return 0;
    return f(L, FUN_00213260(L, -10003));
}

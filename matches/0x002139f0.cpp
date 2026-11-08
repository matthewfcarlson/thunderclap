// lua_pcall: call the function below nargs arguments in protected mode; errfunc names the error handler (0: none).
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" void __cdecl FUN_002139d0(LuaVMState* L, void* ud);
extern "C" int __cdecl FUN_00215de0(LuaVMState* L, void(__cdecl* f)(LuaVMState*, void*), void* u, int oldtop, int ef);

extern "C" int __cdecl FUN_002139f0(LuaVMState* L, int nargs, int nresults, int errfunc) {
    int func;
    if (errfunc == 0)
        func = 0;
    else
        func = (int)((char*)FUN_00212bb0(errfunc, L) - (char*)L->stack);
    LuaVMCallS c;
    c.func = L->top - (nargs + 1);
    c.nresults = nresults;
    return FUN_00215de0(L, FUN_002139d0, &c, (int)((char*)c.func - (char*)L->stack), func);
}

// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// lua_call: call the function below the nargs top values.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);

extern "C" void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults) {
    FUN_002159e0(L, L->top - (nargs + 1), nresults);
}

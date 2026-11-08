#include "decls/data/lua.h"
typedef int(__cdecl* Fn_1d0cf0)(LuaVMState*);
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void* __cdecl FUN_00213260(LuaVMState*, int);
extern "C" void __cdecl FUN_00212de0(LuaVMState*, int);
int __cdecl FUN_001d0cf0(LuaVMState* param) {
    int i = FUN_00212d70(param);
    if (i < 1)
        return 0;
    Fn_1d0cf0 pc = (Fn_1d0cf0)FUN_00213260(param, -1);
    FUN_00212de0(param, -1);
    return pc(param);
}

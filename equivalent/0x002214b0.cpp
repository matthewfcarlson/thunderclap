// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
// luaK_goiftrue: jump when the expression is false (added to its false list); the true list falls through.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs);
// equiv-conv: FUN_00220ab0 ecx eax
extern "C" void __cdecl FUN_00220ab0(LuaVMFuncState* fs, LuaVMExpDesc* e);
// equiv-conv: FUN_00221430 eax edi ebx
extern "C" int __cdecl FUN_00221430(LuaVMFuncState* fs, LuaVMExpDesc* e, int cond);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);

extern "C" void __cdecl FUN_002214b0(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    FUN_00220d90(fs, e);
    int value;
    switch (e->k) {
    case 2:
    case 4:
        value = -1;
        break;
    case 3:
        value = FUN_00220cd0(fs);
        break;
    case 9:
        FUN_00220ab0(fs, e);
        value = e->info;
        break;
    default:
        value = FUN_00221430(fs, e, 0);
        break;
    }
    FUN_002207c0(fs, &e->f, value);
}

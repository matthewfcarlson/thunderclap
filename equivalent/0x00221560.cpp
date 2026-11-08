// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 6/6)
// luaK_goiffalse: jump when the expression is true (added to its true list).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs);
// equiv-conv: FUN_00221430 eax edi ebx
extern "C" int __cdecl FUN_00221430(LuaVMFuncState* fs, LuaVMExpDesc* e, int cond);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);

extern "C" void __cdecl FUN_00221560(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    FUN_00220d90(fs, e);
    int value;
    switch (e->k) {
    case 1:
    case 3:
        value = -1;
        break;
    case 2:
        value = FUN_00220cd0(fs);
        break;
    case 9:
        value = e->info;
        break;
    default:
        value = FUN_00221430(fs, e, 1);
        break;
    }
    FUN_002207c0(fs, &e->t, value);
}

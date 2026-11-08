// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 6/6)
// luaK_infix: prepare the first operand of a binary operator (and / or / concat / RK operand).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00221200(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00221560(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_002214b0(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);

extern "C" void __cdecl FUN_002217c0(LuaVMFuncState* fs, int op, LuaVMExpDesc* v) {
    switch (op) {
    case 5:
        FUN_00221110(fs, v);
        break;
    case 12:
        FUN_002214b0(fs, v);
        fs->lasttarget = fs->pc;
        FUN_002207c0(fs, &fs->jpc, v->t);
        v->t = -1;
        break;
    case 13:
        FUN_00221560(fs, v);
        fs->lasttarget = fs->pc;
        FUN_002207c0(fs, &fs->jpc, v->f);
        v->f = -1;
        break;
    default:
        FUN_00221200(fs, v);
        break;
    }
}

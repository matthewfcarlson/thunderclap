// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 2/2)
// cond: a condition (nil as false); jumps when true go here, returns the false list.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit);
extern "C" void __cdecl FUN_002214b0(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list);
// equiv-conv: FUN_0021e2b0 esi
extern "C" int FUN_0021e2b0(LuaVMLexState* ls) {
    LuaVMExpDesc v;
    FUN_0021ded0(ls, &v, 0);
    if (v.k == 1) // VNIL
        v.k = 3;  // VFALSE
    FUN_002214b0(ls->fs, &v);
    FUN_00220d70(ls->fs, v.t);
    return v.f;
}

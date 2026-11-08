// luaK_exp2val: an expression with jumps goes to a register, others are only discharged.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);

extern "C" void __cdecl FUN_002211e0(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    if (e->t != e->f)
        FUN_00221190(fs, e);
    else
        FUN_00220d90(fs, e);
}

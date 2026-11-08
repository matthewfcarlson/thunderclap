// luaK_indexed: t[k] (VINDEXED, the key as an RK operand).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00221200(LuaVMFuncState* fs, LuaVMExpDesc* e);

extern "C" void __cdecl FUN_002216e0(LuaVMFuncState* fs, LuaVMExpDesc* t, LuaVMExpDesc* k) {
    t->aux = FUN_00221200(fs, k);
    t->k = 8;
}

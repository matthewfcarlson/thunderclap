// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 6/6)
// luaK_exp2anyreg: put the expression into some register; returns it.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);
// equiv-conv: FUN_00220fe0 eax stack stack
extern "C" int __cdecl FUN_00220fe0(LuaVMFuncState* fs, LuaVMExpDesc* e, int reg);

extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    FUN_00220d90(fs, e);
    if (e->k == 11) {
        if (e->t == e->f)
            return e->info;
        if (e->info >= fs->nactvar) {
            FUN_00220fe0(fs, e, e->info);
            return e->info;
        }
    }
    FUN_00221110(fs, e);
    return e->info;
}

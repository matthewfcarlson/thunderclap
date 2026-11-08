// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 10/10)
// luaK_exp2RK: a register or a constant index (+ 250) for the expression.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
// equiv-conv: FUN_00220a10 eax
extern "C" int __cdecl FUN_00220a10(LuaVMFuncState* fs);

extern "C" int __cdecl FUN_00221200(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    if (e->t == e->f)
        FUN_00220d90(fs, e);
    else
        FUN_00221190(fs, e);
    switch (e->k) {
    case 1:
        if (fs->nk + 250 <= 511) {
            e->info = FUN_00220a10(fs);
            e->k = 4;
            return e->info + 250;
        }
        break;
    case 4:
        if (e->info + 250 <= 511)
            return e->info + 250;
        break;
    }
    return FUN_00221190(fs, e);
}

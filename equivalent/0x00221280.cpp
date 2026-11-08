// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 18/18)
// luaK_storevar: store expression ex into variable var (local, upvalue, global, indexed).
#include "decls/data/lua.h"

// equiv-conv: FUN_00220fe0 eax stack stack
extern "C" int __cdecl FUN_00220fe0(LuaVMFuncState* fs, LuaVMExpDesc* e, int reg);
extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00221200(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b, unsigned int c);

extern "C" void __cdecl FUN_00221280(LuaVMFuncState* fs, LuaVMExpDesc* var, LuaVMExpDesc* ex) {
    unsigned int result;
    switch (var->k) {
    case 5:
        if (ex->k == 11 && ex->info >= fs->nactvar && ex->info < 250)
            --fs->freereg;
        FUN_00220fe0(fs, ex, var->info);
        return;
    case 6:
        result = (unsigned int)FUN_00221190(fs, ex);
        FUN_00220bd0(fs, 8, (int)result, (unsigned int)var->info, 0);
        break;
    case 7:
        result = (unsigned int)FUN_00221190(fs, ex);
        FUN_00220b20(fs, ((result << 18) | (unsigned int)var->info) << 6 | 7, fs->ls->lastline);
        break;
    case 8:
        result = (unsigned int)FUN_00221200(fs, ex);
        FUN_00220bd0(fs, 9, var->info, (unsigned int)var->aux, result);
        break;
    }
    if (ex->k == 11 && ex->info >= fs->nactvar && ex->info < 250)
        --fs->freereg;
}

// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 14/14)
// luaK_prefix: unary minus (a numeric constant folds) or not.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_002209e0(LuaVMFuncState* fs, float r);
extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
// equiv-conv: FUN_00221610 esi edi
extern "C" int __cdecl FUN_00221610(LuaVMExpDesc* e, LuaVMFuncState* fs);

extern "C" void __cdecl FUN_00221700(LuaVMFuncState* fs, int op, LuaVMExpDesc* e) {
    if (op) {
        FUN_00221610(e, fs);
        return;
    }
    if (e->t != e->f)
        FUN_00221190(fs, e);
    else
        FUN_00220d90(fs, e);
    if (e->k == 4) {
        LuaVMTObject* constant = &fs->f->k[e->info];
        if (constant->tt == LUAVM_TNUMBER) {
            e->info = FUN_002209e0(fs, -constant->value.n);
            return;
        }
    }
    FUN_00221190(fs, e);
    if (e->k == 11 && e->info >= fs->nactvar && e->info < 250)
        --fs->freereg;
    e->info = FUN_00220b20(fs, (LuaVMInstruction)(((unsigned int)e->info << 15) | 17), fs->ls->lastline);
    e->k = 10;
}

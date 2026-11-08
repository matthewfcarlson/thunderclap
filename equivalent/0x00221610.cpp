// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 12/13, incomplete)
// codenot: the logical negation of the expression (constants fold, jumps invert, values get OP_NOT); swaps t / f.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
// equiv-conv: FUN_00220ab0 ecx eax
extern "C" void __cdecl FUN_00220ab0(LuaVMFuncState* fs, LuaVMExpDesc* e);
// equiv-conv: FUN_00220f80 eax stack
extern "C" void __cdecl FUN_00220f80(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b, unsigned int c);

// equiv-conv: FUN_00221610 esi edi
extern "C" int __cdecl FUN_00221610(LuaVMExpDesc* e, LuaVMFuncState* fs) {
    FUN_00220d90(fs, e);
    switch (e->k) {
    case 1:
    case 3:
        e->k = 2;
        break;
    case 2:
    case 4:
        e->k = 3;
        break;
    case 9:
        FUN_00220ab0(fs, e);
        break;
    case 10:
    case 11:
        FUN_00220f80(fs, e);
        if (e->k == 11 && e->info >= fs->nactvar && e->info < 250)
            --fs->freereg;
        e->info = FUN_00220bd0(fs, 18, 0, (unsigned int)e->info, 0);
        e->k = 10;
        break;
    }
    int r = e->f;
    e->f = e->t;
    e->t = r;
    return r;
}

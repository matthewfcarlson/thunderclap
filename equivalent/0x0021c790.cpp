// STATUS: equivalent (tools/equiv.py level 3: 3114 inputs, branch coverage 21/22, incomplete)
// singlevaraux: resolve the name n as a local of fs (marking its block as having an upvalue unless base), an
// upvalue of an enclosing function, or a global (its name constant when base).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_002209b0(LuaVMFuncState* fs, LuaVMString* s);
// equiv-conv: FUN_0021c5f0 edi stack stack
extern "C" int FUN_0021c5f0(LuaVMFuncState* fs, LuaVMString* name, LuaVMExpDesc* v);
extern "C" void __cdecl FUN_0021c790(LuaVMFuncState* fs, LuaVMString* n, LuaVMExpDesc* var, int base) {
    if (!fs) {
        var->t = -1;
        var->f = -1;
        var->k = 7;      // VGLOBAL
        var->info = 255; // NO_REG
        return;
    }
    int i = (int)fs->nactvar - 1;
    for (; i >= 0; --i) {
        if (fs->f->locvars[fs->actvar[i]].varname == n)
            break;
    }
    if (i >= 0) {
        var->t = -1;
        var->f = -1;
        var->k = 5; // VLOCAL
        var->info = i;
        if (!base) {
            LuaVMBlockCnt* bl = fs->bl;
            while (bl) {
                if ((int)bl->nactvar <= i) {
                    bl->upval = 1;
                    break;
                }
                bl = bl->previous;
            }
        }
        return;
    }
    FUN_0021c790(fs->prev, n, var, 0);
    if (var->k == 7) {
        if (base)
            var->info = FUN_002209b0(fs, n);
    } else {
        int index = FUN_0021c5f0(fs, n, var);
        var->k = 6; // VUPVAL
        var->info = index;
    }
}

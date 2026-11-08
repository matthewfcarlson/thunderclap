// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 12/12)
// check_conflict: when an earlier target of the assignment indexes with the local v, use a copy of v instead.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
extern "C" void __cdecl FUN_00220850(LuaVMFuncState* fs, int n);
// equiv-conv: FUN_0021e110 ecx eax edi
extern "C" void FUN_0021e110(LuaVMLexState* ls, LuaVMLHSAssign* lh, LuaVMExpDesc* v) {
    LuaVMFuncState* fs = ls->fs;
    int extra = fs->freereg;
    bool conflict = false;
    for (; lh; lh = lh->prev) {
        if (lh->v.k == 8) { // VINDEXED
            if (lh->v.info == v->info) {
                conflict = true;
                lh->v.info = extra;
            }
            if (lh->v.aux == v->info) {
                conflict = true;
                lh->v.aux = extra;
            }
        }
    }
    if (conflict) {
        FUN_00220bd0(fs, 0, fs->freereg, (unsigned int)v->info, 0); // OP_MOVE
        FUN_00220850(fs, 1);
    }
}

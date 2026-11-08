// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 12/12)
// jumponcond: emit a TEST on the expression and a jump; folds a preceding NOT, otherwise discharges it first.
#include "decls/data/lua.h"

// equiv-conv: FUN_00220d10 eax esi stack stack stack
extern "C" unsigned int __cdecl FUN_00220d10(unsigned int a, LuaVMFuncState* fs, unsigned int op, unsigned int b,
                                             unsigned int c);
// equiv-conv: FUN_00220f80 eax stack
extern "C" void __cdecl FUN_00220f80(LuaVMFuncState* fs, LuaVMExpDesc* e);

// equiv-conv: FUN_00221430 eax edi ebx
extern "C" int __cdecl FUN_00221430(LuaVMFuncState* fs, LuaVMExpDesc* e, int cond) {
    if (e->k == 10) {
        LuaVMInstruction i = fs->f->code[e->info];
        if ((i & 0x3f) == 0x12) {
            fs->pc--;
            return (int)FUN_00220d10(0xff, fs, 0x18, (i >> 15) & 0x1ff, (unsigned int)(cond == 0));
        }
    }
    FUN_00220f80(fs, e);
    if (e->k == 11) {
        if (e->info >= fs->nactvar && e->info < 0xfa)
            fs->freereg--;
    }
    return (int)FUN_00220d10(0xff, fs, 0x18, (unsigned int)e->info, (unsigned int)cond);
}

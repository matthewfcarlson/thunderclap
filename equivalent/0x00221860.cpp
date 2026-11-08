// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// codebinop: an arithmetic instruction (B = rkb, C = rkc), or a comparison and its jump (operands swapped for > / >=).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
// equiv-conv: FUN_00220d10 eax esi stack stack stack
extern "C" unsigned int __cdecl FUN_00220d10(unsigned int a, LuaVMFuncState* fs, unsigned int op, unsigned int b,
                                             unsigned int c);

// equiv-conv: FUN_00221860 eax ecx edx edi stack
extern "C" void __cdecl FUN_00221860(int rkc, int rkb, int op, LuaVMExpDesc* res, LuaVMFuncState* fs) {
    if (op <= 4) {
        res->info = FUN_00220b20(fs, (LuaVMInstruction)((((rkb << 9) | rkc) << 6) | (op + 12)), fs->ls->lastline);
        res->k = 10;
        return;
    }
    int cond = 1;
    if (op >= 10) {
        int tmp = rkb;
        rkb = rkc;
        rkc = tmp;
    } else if (op == 6) {
        cond = 0;
    }
    // the comparison opcodes of the operators ne, eq, lt, le, gt, ge (6..11)
    res->info = (int)FUN_00220d10((unsigned int)cond, fs, DAT_0042720c[op - 6],
                                  (unsigned int)rkb, (unsigned int)rkc);
    res->k = 9;
}

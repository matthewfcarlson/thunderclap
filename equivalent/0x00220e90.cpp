// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 12/12)
// discharge2reg: put the expression's value into register reg (VNONRELOC).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00220c40(LuaVMFuncState* fs, int from, int n);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b, unsigned int c);
extern "C" int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc);

// equiv-conv: FUN_00220e90 ebx esi edi
extern "C" void __cdecl FUN_00220e90(LuaVMExpDesc* e, unsigned int reg, LuaVMFuncState* fs) {
    FUN_00220d90(fs, e);
    switch ((unsigned int)e->k) {
    case 1:
        FUN_00220c40(fs, (int)reg, 1);
        break;
    case 2:
    case 3:
        FUN_00220bd0(fs, 2, (int)reg, (unsigned int)((unsigned int)e->k == 2), 0);
        break;
    case 4:
        FUN_00220c10(fs, 1, (int)reg, (unsigned int)e->info);
        break;
    case 10: {
        LuaVMInstruction& word = fs->f->code[e->info];
        word = (word & 0x00ffffffu) | (reg << 24);
        break;
    }
    case 11:
        if (reg != (unsigned int)e->info)
            FUN_00220bd0(fs, 0, (int)reg, (unsigned int)e->info, 0);
        break;
    default:
        return;
    }
    e->info = (int)reg;
    e->k = 11;
}

// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 10/10)
// luaK_exp2reg: put the expression (with its true / false jump lists) into register reg.
#include "decls/data/lua.h"

// equiv-conv: FUN_00220e90 ebx esi edi
extern "C" void __cdecl FUN_00220e90(LuaVMExpDesc* e, unsigned int reg, LuaVMFuncState* fs);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);
// equiv-conv: FUN_002205a0 ecx eax stack
extern "C" int __cdecl FUN_002205a0(int list, LuaVMFuncState* fs, int cond);
extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs);
extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
extern "C" void __cdecl FUN_00220650(int list, LuaVMFuncState* fs, int ttarget, int treg, int ftarget, int freg,
                                     int dtarget);

// equiv-conv: FUN_00220fe0 eax stack stack
extern "C" int __cdecl FUN_00220fe0(LuaVMFuncState* fs, LuaVMExpDesc* e, int reg) {
    FUN_00220e90(e, (unsigned int)reg, fs);
    if (e->k == 9)
        FUN_002207c0(fs, &e->t, e->info);
    if (e->t != e->f) {
        int f = e->f;
        int a = -1, b = -1;
        if (FUN_002205a0(e->t, fs, 1) || FUN_002205a0(f, fs, 0)) {
            int link = -1;
            if (e->k != 9)
                link = FUN_00220cd0(fs);
            fs->lasttarget = fs->pc;
            a = FUN_00220b20(fs, (LuaVMInstruction)((reg << 24) | 0x42), fs->ls->lastline);
            fs->lasttarget = fs->pc;
            b = FUN_00220b20(fs, (LuaVMInstruction)((reg << 24) | 0x8002), fs->ls->lastline);
            fs->lasttarget = fs->pc;
            FUN_002207c0(fs, &fs->jpc, link);
        }
        int position = fs->pc;
        fs->lasttarget = position;
        FUN_00220650(e->f, fs, a, 255, position, reg, a);
        FUN_00220650(e->t, fs, position, reg, b, 255, b);
    }
    e->t = -1;
    e->f = -1;
    e->info = reg;
    e->k = 11;
    return -1;
}

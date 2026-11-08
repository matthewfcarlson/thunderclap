// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 10/10)
#include "decls/data/lua.h"

// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c);
// equiv-conv: FUN_0021c570 eax edx
extern "C" void FUN_0021c570(LuaVMLexState* ls, int nvars);
// equiv-conv: FUN_0021e080 eax
extern "C" void FUN_0021e080(LuaVMLexState* ls);
// equiv-conv: FUN_0021c5b0 eax edx
extern "C" void FUN_0021c5b0(LuaVMLexState* ls, int tolevel);
extern "C" int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
extern "C" void __cdecl FUN_00220850(LuaVMFuncState* fs, int n);
extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list);
extern "C" void __cdecl FUN_00220b00(LuaVMFuncState* fs, int line);
extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs);
extern "C" void __cdecl FUN_00221ae0(LuaVMFuncState* fs, int list, int target);

// forbody: a for loop body: activate the control variables, FORPREP / FORLOOP (numeric) or TFORLOOP; ls
// arrives in eax, the rest on the stack.
// equiv-conv: FUN_0021e700 eax stack stack stack stack
extern "C" void FUN_0021e700(LuaVMLexState* ls, int base, int line, int nvars, int isnum) {
    LuaVMBlockCnt bl;
    int prep;
    int i;
    int endfor;
    LuaVMFuncState* fs = ls->fs;
    LuaVMBlockCnt* b;

    fs->nactvar = (unsigned char)(fs->nactvar + 3);
    for (i = 3; i != 0; i--)
        fs->f->locvars[fs->actvar[fs->nactvar - i]].startpc = fs->pc;

    FUN_0021c2e0(ls, 0x103);

    prep = FUN_00220c10(fs, (unsigned int)(isnum ? 0x1d : 0x1f), base, 0x1fffe);
    bl.breaklist = -1;
    bl.isbreakable = 0;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;

    FUN_0021c570(ls, nvars);
    FUN_00220850(fs, nvars);
    FUN_0021e080(ls);

    b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0);
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
    FUN_00220d70(fs, prep);

    if (isnum)
        endfor = FUN_00220c10(fs, 0x1c, base, 0x1fffe);
    else
        endfor = FUN_00220bd0(fs, 0x1e, base, 0, (unsigned int)nvars);
    FUN_00220b00(fs, line);
    if (!isnum)
        endfor = FUN_00220cd0(fs);
    FUN_00221ae0(fs, endfor, prep + 1);
}

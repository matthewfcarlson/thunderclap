// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 12/12)
#include "decls/data/lua.h"

extern "C" LuaVMString* __cdecl FUN_0021b080(LuaVMLexState* ls, const char* str, unsigned int l);
extern "C" int __cdecl FUN_0021c490(LuaVMLexState* ls, LuaVMString* varname);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit);
extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_002209e0(LuaVMFuncState* fs, float r);
extern "C" int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc);
extern "C" void __cdecl FUN_00220850(LuaVMFuncState* fs, int n);
// equiv-conv: FUN_0021c240 esi ecx edx
extern "C" void FUN_0021c240(LuaVMFuncState* fs, const char* what, int limit);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c);
// equiv-conv: FUN_0021e700 eax stack stack stack stack
extern "C" void FUN_0021e700(LuaVMLexState* ls, int base, int line, int nvars, int isnum);

// fornum: for v = e1, e2 [, e3] do body: the control locals (index, limit, step, v) and their values; ls
// arrives in edi, the rest on the stack.
// equiv-conv: FUN_0021e860 edi stack stack
extern "C" void FUN_0021e860(LuaVMLexState* ls, LuaVMString* varname, int line) {
    struct {
        int base;
        LuaVMExpDesc e;
    } fr;
    LuaVMFuncState* fs0 = ls->fs;
    LuaVMFuncState* fs;
    fr.base = fs0->freereg;

    LuaVMString* name = FUN_0021b080(ls, "(for index)", 11);
    fs = ls->fs;
    if (fs->nactvar + 1 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 0] = (unsigned short)FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for limit)", 11);
    fs = ls->fs;
    if (fs->nactvar + 2 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 1] = (unsigned short)FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for step)", 10);
    fs = ls->fs;
    if (fs->nactvar + 3 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 2] = (unsigned short)FUN_0021c490(ls, name);

    fs = ls->fs;
    if (fs->nactvar + 4 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 3] = (unsigned short)FUN_0021c490(ls, varname);

    FUN_0021c2e0(ls, '=');
    FUN_0021ded0(ls, &fr.e, 0);
    FUN_00221110(ls->fs, &fr.e);
    FUN_0021c2e0(ls, ',');
    FUN_0021ded0(ls, &fr.e, 0);
    FUN_00221110(ls->fs, &fr.e);

    if (ls->t.token == ',') {
        ls->lastline = ls->linenumber;
        if (ls->lookahead.token != 0x11f) {
            ls->t.token = ls->lookahead.token;
            ls->t.seminfo = ls->lookahead.seminfo;
            ls->lookahead.token = 0x11f;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        FUN_0021ded0(ls, &fr.e, 0);
        FUN_00221110(ls->fs, &fr.e);
    } else {
        int k = FUN_002209e0(fs0, 1.0f);
        FUN_00220c10(fs0, 1, fs0->freereg, (unsigned int)k);
        FUN_00220850(fs0, 1);
    }
    FUN_0021e700(ls, fr.base, line, 1, 1);
}

// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 17/20, incomplete)
#include "decls/data/lua.h"

extern "C" LuaVMString* __cdecl FUN_0021b080(LuaVMLexState* ls, const char* str, unsigned int l);
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
extern "C" int __cdecl FUN_0021c490(LuaVMLexState* ls, LuaVMString* varname);
extern "C" void __cdecl FUN_00220810(LuaVMFuncState* fs, int n);
// equiv-conv: FUN_0021c240 esi ecx edx
extern "C" void FUN_0021c240(LuaVMFuncState* fs, const char* what, int limit);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c);
// equiv-conv: FUN_0021d5c0 esi edi
extern "C" int FUN_0021d5c0(LuaVMLexState* ls, LuaVMExpDesc* v);
// equiv-conv: FUN_0021c8b0 eax ecx edx stack
extern "C" void FUN_0021c8b0(LuaVMLexState* ls, LuaVMExpDesc* e, int nexps, int nvars);
// equiv-conv: FUN_0021e700 eax stack stack stack stack
extern "C" void FUN_0021e700(LuaVMLexState* ls, int base, int line, int nvars, int isnum);

static inline void Next(LuaVMLexState* ls) {
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
}

// forlist: for v1, ... in explist do body: the control locals (generator, state, control, the names); ls
// arrives in ebx, indexname on the stack.
// equiv-conv: FUN_0021ea60 ebx stack
extern "C" void FUN_0021ea60(LuaVMLexState* ls, LuaVMString* indexname) {
    LuaVMExpDesc e;
    LuaVMFuncState* fs0 = ls->fs;
    LuaVMFuncState* fs;
    int base = fs0->freereg;

    LuaVMString* name = FUN_0021b080(ls, "(for generator)", 15);
    fs = ls->fs;
    if (fs->nactvar + 1 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 0] = (unsigned short)FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for state)", 11);
    fs = ls->fs;
    if (fs->nactvar + 2 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 1] = (unsigned short)FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for control)", 13);
    fs = ls->fs;
    if (fs->nactvar + 3 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 2] = (unsigned short)FUN_0021c490(ls, name);

    fs = ls->fs;
    if (fs->nactvar + 4 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 3] = (unsigned short)FUN_0021c490(ls, indexname);

    int nvars = 4;
    while (ls->t.token == 0x2c) {
        Next(ls);
        if (ls->t.token != 0x116)
            FUN_0021b060(ls, "<name> expected");
        LuaVMString* nm = ls->t.seminfo.ts;
        Next(ls);
        fs = ls->fs;
        if (fs->nactvar + nvars + 1 > 200) {
            int line = fs->f->lineDefined;
            const char* msg;
            if (line != 0)
                msg = FUN_00216320(fs->L, "function at line %d has more than %d %s", line, 200,
                                   "local variables");
            else
                msg = FUN_00216320(fs->L, "main function has more than %d %s", 200, "local variables");
            FUN_0021afd0(fs->ls, msg, 0);
        }
        fs->actvar[fs->nactvar + nvars] = (unsigned short)FUN_0021c490(ls, nm);
        nvars++;
    }

    FUN_0021c2e0(ls, 0x10b);
    int line = ls->linenumber;
    int nexps = FUN_0021d5c0(ls, &e);
    FUN_0021c8b0(ls, &e, nexps, 3);
    FUN_00220810(fs0, 3);
    FUN_0021e700(ls, base, line, nvars - 3, 0);
}

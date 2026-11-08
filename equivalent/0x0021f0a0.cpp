// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/16, incomplete)
// localstat: local name {, name} [= explist1].
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
extern "C" int __cdecl FUN_0021c490(LuaVMLexState* ls, LuaVMString* varname);
// equiv-conv: FUN_0021d5c0 esi edi
extern "C" int FUN_0021d5c0(LuaVMLexState* ls, LuaVMExpDesc* v);
// equiv-conv: FUN_0021c8b0 eax ecx edx stack
extern "C" void FUN_0021c8b0(LuaVMLexState* ls, LuaVMExpDesc* e, int nexps, int nvars);
// equiv-conv: FUN_0021c570 eax edx
extern "C" void FUN_0021c570(LuaVMLexState* ls, int nvars);

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

// equiv-conv: FUN_0021f0a0 eax
extern "C" void FUN_0021f0a0(LuaVMLexState* ls) {
    int nvars = 0;
    LuaVMExpDesc e;
    for (;;) {
        if (ls->t.token != 0x116)
            FUN_0021b060(ls, "<name> expected");
        LuaVMString* name = ls->t.seminfo.ts;
        Next(ls);
        LuaVMFuncState* fs = ls->fs;
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
        fs->actvar[fs->nactvar + nvars] = (unsigned short)FUN_0021c490(ls, name);
        nvars++;
        if (ls->t.token != 0x2c)
            break;
        Next(ls);
    }
    int nexps;
    if (ls->t.token == 0x3d) {
        Next(ls);
        nexps = FUN_0021d5c0(ls, &e);
    } else {
        e.k = 0;
        nexps = 0;
    }
    FUN_0021c8b0(ls, &e, nexps, nvars);
    FUN_0021c570(ls, nvars);
}

// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 22/28, incomplete)
// parlist: the parameter list (names, `...' as the vararg `arg'); numparams, is_vararg, the registers.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" LuaVMString* __cdecl FUN_0021b080(LuaVMLexState* ls, const char* str, unsigned int l);
extern "C" int __cdecl FUN_0021c490(LuaVMLexState* ls, LuaVMString* varname);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
extern "C" void __cdecl FUN_00220850(LuaVMFuncState* fs, int n);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c);
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

static inline void CheckLocalLimit(LuaVMFuncState* fs, int count) {
    if (fs->nactvar + count > LUAVM_MAXVARS) {
        int line = fs->f->lineDefined;
        const char* msg;
        if (line != 0)
            msg =
                FUN_00216320(fs->L, "function at line %d has more than %d %s", line, 200, "local variables");
        else
            msg = FUN_00216320(fs->L, "main function has more than %d %s", 200, "local variables");
        FUN_0021afd0(fs->ls, msg, 0);
    }
}

// ls arrives in eax.
// equiv-conv: FUN_0021d210 eax
extern "C" void FUN_0021d210(LuaVMLexState* ls) {
    LuaVMFuncState* fs0 = ls->fs;
    LuaVMFuncState* fs;
    LuaVMProto* f = fs0->f;
    int nparams = 0;

    f->is_vararg = 0;
    if (ls->t.token != ')') {
        for (;;) {
            if (ls->t.token == 0x116) {
                LuaVMString* name = ls->t.seminfo.ts;
                Next(ls);
                fs = ls->fs;
                CheckLocalLimit(fs, nparams + 1);
                fs->actvar[fs->nactvar + nparams] = (unsigned short)FUN_0021c490(ls, name);
                nparams++;
                if (ls->t.token == '=') {
                    Next(ls);
                    FUN_0021c2e0(ls, 0x118);
                    f->is_vararg = 1;
                    break;
                }
            } else if (ls->t.token == 0x118) {
                Next(ls);
                LuaVMString* name = FUN_0021b080(ls, "arg", 3);
                LuaVMFuncState* cur = ls->fs;
                CheckLocalLimit(cur, nparams + 1);
                cur->actvar[cur->nactvar + nparams] = (unsigned short)FUN_0021c490(ls, name);
                nparams++;
                f->is_vararg = 1;
                break;
            } else {
                FUN_0021b060(ls, "<name> or `...' expected");
            }

            if (f->is_vararg)
                break;
            if (ls->t.token != ',')
                break;
            Next(ls);
        }
    }

    FUN_0021c570(ls, nparams);
    f->numparams = (unsigned char)(fs0->nactvar - f->is_vararg);
    FUN_00220850(fs0, fs0->nactvar);
}

// STATUS: equivalent (tools/equiv.py level 3: 2742 inputs, branch coverage 24/28, incomplete)
// constructor: a table constructor { ... } (NEWTABLE sized by the items read; list items flushed by SETLIST).
#include "decls/data/lua.h"

extern "C" {
int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b, unsigned int c);
int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc);
void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);
int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit);
int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
unsigned int __cdecl FUN_00215f50(unsigned int x);
int __cdecl FUN_00215f70(unsigned int x);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(LuaVMLexState* ls, int c);
// equiv-conv: FUN_0021c340 eax esi edi stack
void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who);
// equiv-conv: FUN_0021cec0 esi edi
void FUN_0021cec0(LuaVMConsControl* cc, LuaVMFuncState* fs);
int __cdecl FUN_0021cd90(LuaVMLexState* ls, LuaVMConsControl* cc);
}

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

// Lua 5.0 constructor(ls, t): ls arrives in ecx, t in eax.
// equiv-conv: FUN_0021cf70 ecx eax
extern "C" void FUN_0021cf70(LuaVMLexState* ls, LuaVMExpDesc* t) {
    LuaVMFuncState* fs = ls->fs;
    int line = ls->linenumber;
    int pc = FUN_00220bd0(fs, 0xa, 0, 0, 0);
    LuaVMConsControl cc;

    t->t = -1;
    t->f = -1;
    t->k = 0xa;
    t->info = pc;
    LuaVMFuncState* fs1 = ls->fs;
    cc.tostore = 0;
    cc.na = 0;
    cc.nh = 0;
    cc.t = t;
    cc.v.t = -1;
    cc.v.f = -1;
    cc.v.k = 0;
    cc.v.info = 0;
    FUN_00221110(fs1, t);
    FUN_0021c2e0(ls, 0x7b);

    for (;;) {
        if (ls->t.token == 0x3b)
            Next(ls);
        if (ls->t.token == 0x7d)
            break;

        if (cc.v.k != 0) {
            FUN_00221110(fs, &cc.v);
            cc.v.k = 0;
            if (cc.tostore == 0x20) {
                FUN_00220c10(fs, 0x20, cc.t->info, (unsigned int)(cc.na - 1));
                cc.tostore = 0;
                fs->freereg = cc.t->info + 1;
            }
        }

        bool rec = false;
        if (ls->t.token == '[') {
            rec = true;
        } else if (ls->t.token == 0x116) {
            ls->lookahead.token = FUN_0021bbc0(ls, &ls->lookahead.seminfo);
            rec = (ls->lookahead.token == '=');
        }
        if (rec) {
            FUN_0021cd90(ls, &cc);
        } else {
            FUN_0021ded0(ls, &cc.v, 0);
            if (cc.na > 0x3ffff) {
                LuaVMFuncState* f2 = ls->fs;
                const char* msg;
                int ld = f2->f->lineDefined;
                if (ld != 0)
                    msg = FUN_00216320(f2->L, "function at line %d has more than %d %s", ld, 0x3ffff,
                                       "items in a constructor");
                else
                    msg = FUN_00216320(f2->L, "main function has more than %d %s", 0x3ffff,
                                       "items in a constructor");
                FUN_0021afd0(f2->ls, msg, 0);
            }
            cc.na++;
            cc.tostore++;
        }

        if (ls->t.token == ',') {
            Next(ls);
        } else if (ls->t.token == ';') {
            Next(ls);
        } else {
            break;
        }
    }

    FUN_0021c340(line, ls, 0x7d, 0x7b);
    FUN_0021cec0((&cc), fs);
    LuaVMInstruction* ip = &fs->f->code[pc];
    int fb = ((int)FUN_00215f50(cc.na));
    unsigned int i = *ip;
    *ip = (i & ~0xff8000u) | (((unsigned int)fb << 15) & 0xff8000u);
    ip = &fs->f->code[pc];
    int lg = FUN_00215f70(cc.nh);
    i = *ip;
    *ip = (i & ~0x7fc0u) | (((unsigned int)(lg + 1) << 6) & 0x7fc0u);
}

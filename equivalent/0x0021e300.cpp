// STATUS: equivalent (tools/equiv.py level 3: 3035 inputs, branch coverage 23/26, incomplete)
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs);
extern "C" int __cdecl FUN_00220530(LuaVMFuncState* fs);
extern "C" int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit);
extern "C" void __cdecl FUN_00221560(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" const char* __cdecl FUN_0021af00(LuaVMLexState* ls, int token);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
// equiv-conv: FUN_0021e080 eax
extern "C" void FUN_0021e080(LuaVMLexState* ls);
extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list);
extern "C" void __cdecl FUN_00221ae0(LuaVMFuncState* fs, int list, int target);
extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who);

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

// whilestat: while cond do block end (the condition is coded after the block, its code copied there).
extern "C" void __cdecl FUN_0021e300(LuaVMLexState* ls, int line) {
    LuaVMInstruction codeexp[105];
    LuaVMBlockCnt bl;
    LuaVMExpDesc v;
    int whileinit;
    int expinit;
    int lineexp;
    int sizeexp;
    int blockinit;
    int i;
    LuaVMFuncState* fs = ls->fs;

    Next(ls);
    whileinit = FUN_00220cd0(fs);
    expinit = FUN_00220530(fs);
    FUN_0021ded0(ls, &v, 0);
    if (v.k == 4)
        v.k = 2;
    lineexp = ls->linenumber;
    FUN_00221560(fs, &v);
    FUN_002207c0(fs, &v.f, fs->jpc);
    sizeexp = fs->pc - expinit;
    fs->jpc = -1;
    if (sizeexp > 100)
        FUN_0021b060(ls, "`while' condition too complex");
    for (i = 0; i < sizeexp; i++)
        codeexp[i] = fs->f->code[expinit + i];
    fs->pc = expinit;

    bl.breaklist = -1;
    bl.isbreakable = 1;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;

    if (ls->t.token == 0x103) {
        Next(ls);
    } else {
        FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected", FUN_0021af00(ls, 0x103)));
    }

    blockinit = FUN_00220530(fs);
    FUN_0021e080(ls);
    FUN_00220d70(fs, whileinit);
    if (v.t != -1)
        v.t += fs->pc - expinit;
    if (v.f != -1)
        v.f += fs->pc - expinit;
    for (i = 0; i < sizeexp; i++)
        FUN_00220b20(fs, codeexp[i], lineexp);
    FUN_0021c340(line, ls, 0x106, 0x115);

    LuaVMBlockCnt* b = fs->bl;
    fs->bl = b->previous;
    LuaVMFuncState* fs2 = fs->ls->fs;
    int level = b->nactvar;
    while (fs2->nactvar > level) {
        fs2->nactvar--;
        fs2->f->locvars[fs2->actvar[fs2->nactvar]].endpc = fs2->pc;
    }
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0);
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
    FUN_00221ae0(fs, v.t, blockinit);
    FUN_00220d70(fs, v.f);
}

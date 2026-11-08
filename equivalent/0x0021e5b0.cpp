// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 6/6)
// repeatstat: repeat block until cond (a loop block; the false list jumps back to the start).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00220530(LuaVMFuncState* fs);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
// equiv-conv: FUN_0021e080 eax
extern "C" void FUN_0021e080(LuaVMLexState* ls);
// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who);
extern "C" int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit);
extern "C" void __cdecl FUN_002214b0(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list);
extern "C" void __cdecl FUN_00221ae0(LuaVMFuncState* fs, int list, int target);
// equiv-conv: FUN_0021c5b0 eax edx
extern "C" void FUN_0021c5b0(LuaVMLexState* ls, int tolevel);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
// equiv-conv: FUN_0021e5b0 eax stack
extern "C" void FUN_0021e5b0(LuaVMLexState* ls, int line) {
    LuaVMFuncState* fs = ls->fs;
    int repeat_init = FUN_00220530(fs);
    LuaVMBlockCnt bl;
    bl.breaklist = -1;
    bl.isbreakable = 1;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    FUN_0021e080(ls);
    FUN_0021c340(line, ls, 0x114, 0x110); // TK_UNTIL, TK_REPEAT
    LuaVMExpDesc v;
    FUN_0021ded0(ls, &v, 0);
    if (v.k == 1) // VNIL
        v.k = 3;  // VFALSE
    FUN_002214b0(ls->fs, &v);
    FUN_00220d70(ls->fs, v.t);
    FUN_00221ae0(fs, v.f, repeat_init);
    LuaVMBlockCnt* b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0); // OP_CLOSE
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
}

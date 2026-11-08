// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// forstat: for name = ... (fornum) or for name {, name} in ... (forlist) ... end, in a loop block.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
// equiv-conv: FUN_0021c3d0 esi
extern "C" LuaVMString* FUN_0021c3d0(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
// equiv-conv: FUN_0021e860 edi stack stack
extern "C" void FUN_0021e860(LuaVMLexState* ls, LuaVMString* varname, int line);
// equiv-conv: FUN_0021ea60 ebx stack
extern "C" void FUN_0021ea60(LuaVMLexState* ls, LuaVMString* indexname);
// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who);
// equiv-conv: FUN_0021c5b0 eax edx
extern "C" void FUN_0021c5b0(LuaVMLexState* ls, int tolevel);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list);
// equiv-conv: FUN_0021ecd0 eax stack
extern "C" void FUN_0021ecd0(LuaVMLexState* ls, int line) {
    LuaVMFuncState* fs = ls->fs;
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
    LuaVMString* varname = FUN_0021c3d0(ls);
    if (ls->t.token == 0x3d)
        FUN_0021e860(ls, varname, line);
    else if (ls->t.token == 0x2c || ls->t.token == 0x10b) // ',' or TK_IN
        FUN_0021ea60(ls, varname);
    else
        FUN_0021b060(ls, "`=' or `in' expected");
    FUN_0021c340(line, ls, 0x106, 0x108); // TK_END, TK_FOR
    LuaVMBlockCnt* b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0); // OP_CLOSE
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
}

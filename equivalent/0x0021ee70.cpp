// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 8/8)
// ifstat: if cond then block {elseif cond then block} [else block] end.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021ede0 eax
extern "C" int FUN_0021ede0(LuaVMLexState* ls);
extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);
extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list);
// equiv-conv: FUN_0021e080 eax
extern "C" void FUN_0021e080(LuaVMLexState* ls);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who);
// equiv-conv: FUN_0021ee70 eax stack
extern "C" void FUN_0021ee70(LuaVMLexState* ls, int line) {
    LuaVMFuncState* fs = ls->fs;
    int escapelist = -1;
    int flist = FUN_0021ede0(ls);
    while (ls->t.token == 0x105) { // TK_ELSEIF
        int j = FUN_00220cd0(fs);
        FUN_002207c0(fs, &escapelist, j);
        FUN_00220d70(fs, flist);
        flist = FUN_0021ede0(ls);
    }
    if (ls->t.token == 0x104) { // TK_ELSE
        int j = FUN_00220cd0(fs);
        FUN_002207c0(fs, &escapelist, j);
        FUN_00220d70(fs, flist);
        int token = ls->lookahead.token;
        ls->lastline = ls->linenumber;
        if (token != 0x11f) {
            LuaVMSemInfo seminfo = ls->lookahead.seminfo;
            ls->lookahead.token = 0x11f;
            ls->t.token = token;
            ls->t.seminfo = seminfo;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        FUN_0021e080(ls);
    } else {
        FUN_002207c0(fs, &escapelist, flist);
    }
    FUN_00220d70(fs, escapelist);
    FUN_0021c340(line, ls, 0x106, 0x10a); // TK_END, TK_IF
}

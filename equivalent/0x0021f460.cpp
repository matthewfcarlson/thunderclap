// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 10/10)
// breakstat: break (closes the upvalues of the blocks left, jumps to the enclosing loop's break list).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo); // llex
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);      // luaX_syntaxerror
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);                       // luaK_codeABC
extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs);                   // luaK_jump
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2); // luaK_concat

// equiv-conv: FUN_0021f460 edi
extern "C" void FUN_0021f460(LuaVMLexState* ls) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMBlockCnt* bl = fs->bl;
    int upval = 0;

    // luaX_next(ls)
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t = ls->lookahead;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }

    while (bl != 0 && !bl->isbreakable) {
        upval |= bl->upval;
        bl = bl->previous;
    }
    if (bl == 0)
        FUN_0021b060(ls, "no loop to break");
    if (upval)
        FUN_00220bd0(fs, 0x22, bl->nactvar, 0, 0); // OP_CLOSE
    FUN_002207c0(fs, &bl->breaklist, FUN_00220cd0(fs));
}

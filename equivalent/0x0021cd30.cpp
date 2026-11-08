// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// yindex: [ exp ] (the key as a value).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit);
extern "C" void __cdecl FUN_002211e0(LuaVMFuncState* fs, LuaVMExpDesc* e);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c);
// equiv-conv: FUN_0021cd30 eax edi
extern "C" void FUN_0021cd30(LuaVMLexState* ls, LuaVMExpDesc* v) {
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token == 0x11f) {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    } else {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    }
    FUN_0021ded0(ls, v, 0);
    FUN_002211e0(ls->fs, v);
    FUN_0021c2e0(ls, 0x5d);
}

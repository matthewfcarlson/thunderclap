// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// funcstat: function funcname body (stored to the name).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo); // llex
// equiv-conv: FUN_0021f220 ecx eax
extern "C" int FUN_0021f220(LuaVMLexState* ls, LuaVMExpDesc* v);
// equiv-conv: FUN_0021d4b0 ebx stack stack stack
extern "C" void __cdecl FUN_0021d4b0(LuaVMLexState* ls, LuaVMExpDesc* e, int needself, int line);
extern "C" void __cdecl FUN_00221280(LuaVMFuncState* fs, LuaVMExpDesc* var, LuaVMExpDesc* ex);
extern "C" void __cdecl FUN_00220b00(LuaVMFuncState* fs, int line);

// equiv-conv: FUN_0021f280 eax esi
extern "C" void FUN_0021f280(LuaVMLexState* ls, int line) {
    struct {
        LuaVMExpDesc b;
        LuaVMExpDesc v;
    } f;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 287) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 287;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    int needself = FUN_0021f220(ls, &f.v);
    FUN_0021d4b0(ls, &f.b, needself, line);
    FUN_00221280(ls->fs, &f.v, &f.b);
    FUN_00220b00(ls->fs, line);
}

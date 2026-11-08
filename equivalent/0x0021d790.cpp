// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 6/6)
// prefixexp: a name or a parenthesized expression.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo); // llex
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);      // luaX_syntaxerror
extern "C" int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit); // subexpr
// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who); // check_match
// equiv-conv: FUN_0021c3d0 esi
extern "C" LuaVMString* FUN_0021c3d0(LuaVMLexState* ls); // str_checkname
extern "C" void __cdecl FUN_0021c790(LuaVMFuncState* fs, LuaVMString* n, LuaVMExpDesc* var,
                                     int base);                            // singlevar
extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e); // luaK_dischargevars

// equiv-conv: FUN_0021d790 eax ebx
extern "C" void FUN_0021d790(LuaVMLexState* ls, LuaVMExpDesc* v) {
    switch (ls->t.token) {
    case '(': {
        int line = ls->linenumber;
        // luaX_next(ls)
        ls->lastline = line;
        if (ls->lookahead.token != 0x11f) {
            ls->t = ls->lookahead;
            ls->lookahead.token = 0x11f;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        FUN_0021ded0(ls, v, 0);
        FUN_0021c340(line, ls, ')', '(');
        FUN_00220d90(ls->fs, v);
        return;
    }
    case 0x116:
        FUN_0021c790(ls->fs, FUN_0021c3d0(ls), v, 1);
        return;
    default:
        FUN_0021b060(ls, "unexpected symbol");
        return;
    }
}

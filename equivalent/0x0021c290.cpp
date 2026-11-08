// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// testnext: when the current token is c, advance and return 1; else 0.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
// equiv-conv: FUN_0021c290 esi ecx
extern "C" int FUN_0021c290(LuaVMLexState* ls, int c) {
    if (ls->t.token != c)
        return 0;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        int token = ls->lookahead.token;
        ls->lookahead.token = 0x11f;
        ls->t.token = token;
        ls->t.seminfo = ls->lookahead.seminfo;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    return 1;
}

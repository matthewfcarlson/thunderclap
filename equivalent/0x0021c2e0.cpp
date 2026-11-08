// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// checknext: expect token c ("`c' expected" otherwise), then advance.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" const char* __cdecl FUN_0021af00(LuaVMLexState* ls, int token);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c) {
    if (ls->t.token != c) {
        const char* name = FUN_0021af00(ls, c);
        const char* msg = FUN_00216320(ls->L, "`%s' expected", name);
        FUN_0021b060(ls, msg);
        return;
    }
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
}

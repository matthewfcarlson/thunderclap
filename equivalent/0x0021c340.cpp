// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 6/6)
// check_match: expect token what, else report an error (mentioning who and its line when it is another line).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);    // llex
extern "C" const char* __cdecl FUN_0021af00(LuaVMLexState* ls, int token);        // luaX_token2str
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...); // luaO_pushfstring
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);         // luaX_syntaxerror

// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who) {
    if (ls->t.token == what) {
        ls->lastline = ls->linenumber;
        if (ls->lookahead.token != 287) {
            ls->t.token = ls->lookahead.token;
            ls->t.seminfo = ls->lookahead.seminfo;
            ls->lookahead.token = 287;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        return;
    }
    if (where == ls->linenumber) {
        FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected", FUN_0021af00(ls, what)));
    } else {
        FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected (to close `%s' at line %d)",
                                      FUN_0021af00(ls, what), FUN_0021af00(ls, who), where));
    }
}

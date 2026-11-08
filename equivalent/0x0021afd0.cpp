// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 2/2)
// luaX_lexerror: "source:line: msg" (with "near `token'" when a token is given), then throw a syntax error.
// cl-flags: /GS
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00216340(char* out, const char* source, int bufflen);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_002152b0(LuaVMState* L, int errcode);
// equiv-conv: FUN_0021af60 eax edi
extern "C" const char* FUN_0021af60(int token, LuaVMLexState* ls);

extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token) {
    char buff[0x50];
    FUN_00216340(buff, LUAVM_GETSTR(ls->source), 0x50);
    const char* s = FUN_00216320(ls->L, "%s:%d: %s", buff, ls->linenumber, msg);
    if (token)
        FUN_00216320(ls->L, "%s near `%s'", s, FUN_0021af60(token, ls));
    FUN_002152b0(ls->L, 3);
}

// luaX_syntaxerror: a lexer error near the current token.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg) {
    FUN_0021afd0(ls, msg, ls->t.token);
}

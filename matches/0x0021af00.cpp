// luaX_token2str: a single-character token as "%c" (or "char(%d)" when it is a control character), a reserved
// word or other token by the token2string table.
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
// data: token2string = DAT_00426bf0 (const char* [], indexed by token - 257)

extern "C" int __cdecl iscntrl(int);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" const char* __cdecl FUN_0021af00(LuaVMLexState* ls, int token) {
    const char* r;
    if (token < 0x101) {
        if (iscntrl(token))
            r = FUN_00216320(ls->L, "char(%d)", token);
        else
            r = FUN_00216320(ls->L, "%c", token);
    } else {
        r = (const char*)DAT_00426bf0[token - 0x101];
    }
    return r;
}

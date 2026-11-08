// luaX_init: create the reserved words' strings, fix them and number them (TString.reserved).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
// data: token2string = DAT_00426bf0 (const char* [21])

extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" void __cdecl FUN_0021aeb0(LuaVMState* L) {
    int i = 0;
    do {
        const char* p = (const char*)DAT_00426bf0[i];
        const char* e = p + 1;
        char c;
        do {
            c = *p;
            p++;
        } while (c != 0);
        LuaVMString* ts = FUN_00219430(L, (const char*)DAT_00426bf0[i], (unsigned int)(p - e));
        ts->marked |= 0x20;
        ts->reserved = (unsigned char)(i + 1);
        i++;
    } while (i < 21);
}

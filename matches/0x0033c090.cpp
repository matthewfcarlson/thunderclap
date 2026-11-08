// string.byte
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int narg, int def);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);

extern "C" int __cdecl FUN_0033c090(LuaVMState* L) {
    unsigned int l;
    const unsigned char* s = (const unsigned char*)FUN_00339df0(L, 1, &l);
    unsigned int oldLength = l;
    int result = FUN_00339fe0(L, 2, 1);
    unsigned int pos = (unsigned int)result;
    if (result < 0)
        pos += oldLength + 1;
    if ((int)pos > 0 && pos <= l) {
        FUN_00213360(L, s[pos - 1]);
        return 1;
    }
    return 0;
}

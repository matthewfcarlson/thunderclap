// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 18/18)
// FUN_0033d7a0 @ 0x0033d7a0
// luaB_tonumber
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int narg, int def);
extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx);
extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" unsigned int __cdecl FUN_00345d81(const char*, char**, int);
extern "C" int __cdecl _isspace(int);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);

extern "C" int __cdecl FUN_0033d7a0(LuaVMState* L) {
    int base = FUN_00339fe0(L, 2, 10);
    if (base == 10) {
        FUN_00339dc0(L, 1);
        if (FUN_00212f70(L, 1)) {
            FUN_00213340(L, FUN_002130e0(L, 1));
            return 1;
        }
    } else {
        const char* s1 = FUN_00339df0(L, 1, 0);
        if (base < 2 || base > 36)
            FUN_00339c30(L, 2, "base out of range");
        char* s2;
        unsigned int n = FUN_00345d81(s1, &s2, base);
        if (s2 != s1) {
            while (_isspace((unsigned char)*s2)) ++s2;
            if (*s2 == 0) {
                FUN_00213340(L, (float)n);
                return 1;
            }
        }
    }
    FUN_00213320(L);
    return 1;
}

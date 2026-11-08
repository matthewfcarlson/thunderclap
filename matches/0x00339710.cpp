// luaL_unref
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_00213640(LuaVMState*, int, int);
extern "C" void __cdecl FUN_00213870(LuaVMState*, int, int);
extern "C" void __cdecl FUN_00213360(LuaVMState*, int);
extern "C" void __cdecl FUN_00339710(LuaVMState* L, int index, int n) {
    if (n >= 0) {
        if (index <= 0 && index > -10000)
            index = index + 1 + FUN_00212d70(L);
        FUN_00213640(L, index, 1);
        FUN_00213870(L, index, n);
        FUN_00213360(L, n);
        FUN_00213870(L, index, 1);
    }
}

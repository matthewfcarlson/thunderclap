// foreach
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00339d70(LuaVMState*, int, int);
extern "C" void __cdecl FUN_00213320(LuaVMState*);
extern "C" int __cdecl FUN_00213c50(LuaVMState*, int);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*, int);
extern "C" void __cdecl FUN_002139a0(LuaVMState*, int, int);
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" int __cdecl FUN_0033ad60(LuaVMState* p) {
    FUN_00339d70(p, 1, 5);
    FUN_00339d70(p, 2, 6);
    FUN_00213320(p);
    int i = FUN_00213c50(p, 1);
    while (i) {
        FUN_00212ed0(p, 2);
        FUN_00212ed0(p, -3);
        FUN_00212ed0(p, -3);
        FUN_002139a0(p, 2, 1);
        i = FUN_00212f00(p, -1);
        if (i)
            return 1;
        FUN_00212d80(p, -3);
        i = FUN_00213c50(p, 1);
    }
    return 0;
}

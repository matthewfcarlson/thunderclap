// luaB_tinsert
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_00339d70(LuaVMState*, int, int);
extern "C" int __cdecl FUN_003392c0(LuaVMState*, int);
extern "C" int __cdecl FUN_00339f70(LuaVMState*, int);
extern "C" void __cdecl FUN_00339270(LuaVMState*, int, int);
extern "C" void __cdecl FUN_00213640(LuaVMState*, int, int);
extern "C" void __cdecl FUN_00213870(LuaVMState*, int, int);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*, int);
extern "C" int __cdecl FUN_0033ae50(LuaVMState* p) {
    int b = FUN_00212d70(p);
    FUN_00339d70(p, 1, 5);
    int s = FUN_003392c0(p, 1) + 1;
    int e;
    if (b == 2)
        e = s;
    else {
        e = FUN_00339f70(p, 2);
        if (e > s)
            s = e;
        b = 3;
    }
    FUN_00339270(p, 1, s);
    --s;
    while (s >= e) {
        FUN_00213640(p, 1, s);
        FUN_00213870(p, 1, s + 1);
        --s;
    }
    FUN_00212ed0(p, b);
    FUN_00213870(p, 1, e);
    return 0;
}

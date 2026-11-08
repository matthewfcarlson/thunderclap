#include "decls/data/lua.h"
extern "C" void __cdecl FUN_002135a0(LuaVMState*, int, const char*);
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" int __cdecl FUN_00213160(LuaVMState*, int);
unsigned char __stdcall FUN_001d1080(const char* p1, LuaVMState* p2) {
    if (p1 == 0)
        return 0;
    FUN_002135a0(p2, (int)0xffffd8ef, p1);
    int r = FUN_00212f00(p2, -1);
    if (r != 1) {
        FUN_00212d80(p2, -2);
        return 0;
    }
    int q = FUN_00213160(p2, -1);
    FUN_00212d80(p2, -2);
    return q != 0;
}

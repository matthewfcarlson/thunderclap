#include "decls/data/lua.h"
typedef unsigned int uint;
struct Obj_1d1cb0 {
    char pad[8];
    LuaVMState* m;
};
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_00213380(LuaVMState*, const char*, unsigned int);
extern "C" void __cdecl FUN_00213600(LuaVMState*, int);
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);

bool __fastcall Target(Obj_1d1cb0* self) {
    int x = FUN_00212d70(self->m);
    FUN_00213380(self->m, "context", 7);
    FUN_00213600(self->m, 0xffffd8ef);
    int r = FUN_00212f00(self->m, -1);
    if (r != 5) {
        FUN_00212d80(self->m, x);
        return false;
    }
    return true;
}

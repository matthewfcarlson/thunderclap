#include "decls/data/script.h"
typedef unsigned int uint;
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_00213380(LuaVMState*, const char*, unsigned int);
extern "C" void __cdecl FUN_00213600(LuaVMState*, int);
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);

bool __fastcall Target(ScriptHandlerView* self) {
    int x = FUN_00212d70(self->f.L);
    FUN_00213380(self->f.L, "context", 7);
    FUN_00213600(self->f.L, 0xffffd8ef);
    int r = FUN_00212f00(self->f.L, -1);
    if (r != 5) {
        FUN_00212d80(self->f.L, x);
        return false;
    }
    return true;
}

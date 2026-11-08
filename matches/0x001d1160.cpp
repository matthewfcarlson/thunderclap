#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
struct Obj_1d1160 {
    char pad[8];
    LuaVMState* value;
};
void __fastcall target(Obj_1d1160* self, int arg, int extra) {
    FUN_00212d80(self->value, 0);
}

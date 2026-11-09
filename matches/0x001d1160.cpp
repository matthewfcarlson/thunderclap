#include "decls/data/script.h"
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
void __fastcall target(ScriptHandlerView* self, int arg, int extra) {
    FUN_00212d80(self->f.L, 0);
}

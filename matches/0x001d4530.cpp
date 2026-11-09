#include "gen/global.h"
#include "gen/owners.h"
#include "decls/data/script.h"
struct R_1d4530 {
    void FUN_00092410();
};
struct ScriptHandler_nv_1d4530 {
    int FUN_001d3c90(LuaVMState** state);
    void FUN_001d3bc0();
};
struct H {
};
struct T_1d4530 {
    char pad[12];
    R_1d4530* r;
};
struct End_1d4530 {
    void FUN_001dbd50();
};
extern H* g1_1d4530;
extern T_1d4530* g2_1d4530;
// ScriptHandler (include/decls/data/script.h): (re)creates the Lua state once, then registers the functions.
void __fastcall target(ScriptHandlerView* self) {
    if (!self->f.ownsState) {
        self->f.ownsState = 1;
        ((ScriptHandler_nv_1d4530*)(self))->FUN_001d3c90(&self->f.L);
        ((ScriptHandler_nv_1d4530*)(self))->FUN_001d3bc0();
        ((R_1d4530 *)((owners::A_86340 *)g1_1d4530)->FUN_00086340())->FUN_00092410();
        ((End_1d4530*)g2_1d4530->r)->FUN_001dbd50();
    }
}

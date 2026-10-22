// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 4/4)
// FUN_0026e9e0 @ 0x0026e9e0
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "gen/core.h"

struct Obj_26e9e0 { virtual void FUN_0026e9e0_slot0(); };
extern "C" void* __cdecl FUN_00266e00(int, hulk_intptr);
struct ConsoleClient_26e9e0 {
    void* FUN_0026e2a0(int, int);
};
void __cdecl target(Obj_26e9e0** result, int value, int other) {
    if ((*(Obj_26e9e0**)&DAT_005283b0)) {
        (*(Obj_26e9e0**)&DAT_005283b0)->FUN_0026e9e0_slot0();
        *result = (*(Obj_26e9e0**)&DAT_005283b0);
        return;
    }
    DAT_004cdbb0 = value;
    core::ConsoleClient* created = (core::ConsoleClient*)FUN_00266e00(value, 0x1d8);
    if (created) (*(Obj_26e9e0**)&DAT_005283b0) = (Obj_26e9e0*)((ConsoleClient_26e9e0*)(created))->FUN_0026e2a0(value, other);
    else (*(Obj_26e9e0**)&DAT_005283b0) = 0;
    *result = (*(Obj_26e9e0**)&DAT_005283b0);
}
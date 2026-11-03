#include "decls/data/engine/physics.h"
// data: gThing_2f2e20 = DAT_00554c30

#include "compat/ptr.h"
#include "gen/owners.h"
struct Obj_2f2e20 {
    hulk_intptr Init();
};
extern "C" void* __cdecl FUN_0008d690(int);
extern "C" void __cdecl FUN_002f2e20() {
    if (!(*(Obj_2f2e20**)&DAT_00554c30)) {
        Obj_2f2e20* p = (Obj_2f2e20*)FUN_0008d690(0x808);
        if (p) {
            (*(Obj_2f2e20**)&DAT_00554c30) = (Obj_2f2e20*)p->Init();
            return;
        }
        (*(Obj_2f2e20**)&DAT_00554c30) = 0;
        return;
    }
    ((owners::Obj_2f2cb0 *)((*(Obj_2f2e20**)&DAT_00554c30)))->FUN_002f2cb0();
}
#include "decls/data/engine/physics.h"
// data: gThing_2f2e20 = DAT_00554c30

#include "compat/ptr.h"
struct Obj_2f2e20 {
    hulk_intptr Init();
    void Existing();
};
extern void* __cdecl Alloc(int);
void __cdecl FUN_002f2e20() {
    if (!(*(Obj_2f2e20**)&DAT_00554c30)) {
        Obj_2f2e20* p = (Obj_2f2e20*)Alloc(0x808);
        if (p) {
            (*(Obj_2f2e20**)&DAT_00554c30) = (Obj_2f2e20*)p->Init();
            return;
        }
        (*(Obj_2f2e20**)&DAT_00554c30) = 0;
        return;
    }
    (*(Obj_2f2e20**)&DAT_00554c30)->Existing();
}
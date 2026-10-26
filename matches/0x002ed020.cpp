#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "gen/physics.h"
struct Environment_nv_2ed020 {
    physics::Environment* Init();
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
void __cdecl Target() {
    physics::Environment* p = (*(physics::Environment**)&DAT_00554c10);
    if (p == 0) {
        p = (physics::Environment*)Alloc(0x38);
        if (p != 0)
            p = ((Environment_nv_2ed020*)(((physics::Environment*)(p))))->Init();
        else
            p = 0;
        (*(physics::Environment**)&DAT_00554c10) = p;
        p->vfunc_0();
    }
}
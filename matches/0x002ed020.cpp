#include "gen/physics.h"
struct Environment_nv_2ed020 {
    physics::Environment* Init();
};
extern "C" void* __cdecl Alloc(unsigned int);
extern physics::Environment* gObj_2ed020;
void __cdecl Target() {
    physics::Environment* p = gObj_2ed020;
    if (p == 0) {
        p = (physics::Environment*)Alloc(0x38);
        if (p != 0)
            p = ((Environment_nv_2ed020*)(p))->Init();
        else
            p = 0;
        gObj_2ed020 = p;
        p->vfunc_0();
    }
}
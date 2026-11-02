// Same code shape as 0x00077a90 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
hulk_uintptr __fastcall construct_camera(void*);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::ClimbLocomotion4Track>::vfunc_5() {
    void* p = FUN_0008d690(0xa0);
    if (p)
        return (void*)(construct_camera(p));
    return (void*)(0);
}

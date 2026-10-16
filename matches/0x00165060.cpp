// Same code shape as 0x00077a90 (propagated; names are from that function)
#include "gen/fight.h"

void* __cdecl alloc_block(unsigned int);
unsigned int __fastcall construct_camera(void*);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::ClimbLocomotion4Track>::vfunc_5() {
    void* p = alloc_block(0xa0);
    if (p)
        return (void*)(construct_camera(p));
    return (void*)(0);
}

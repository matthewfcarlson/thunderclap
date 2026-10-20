// Same code shape as 0x0006f3d0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_17ef80;
struct CGrabTrack_17ef80 {
    hulk_uintptr init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::JointRelativeTrack>::vfunc_5() {
    CGrabTrack_17ef80* p = (CGrabTrack_17ef80*)operator_new(0x50);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}

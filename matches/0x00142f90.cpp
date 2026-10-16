// Same code shape as 0x00076ec0 (propagated; names are from that function)
#include "gen/fight.h"

struct Jump {
    int construct();
};
extern "C" void* __cdecl alloc_54(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::WallJumpTrack>::vfunc_5() {
    Jump* p = (Jump*)alloc_54(0x54);
    if (p)
        return (void*)(p->construct());
    return (void*)(0);
}

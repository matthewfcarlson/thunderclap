#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_139860;
struct Init_139860 {
    hulk_uintptr run();
};
extern void* alloc(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FallTrack>::vfunc_5() {
    void* p = alloc(0x4c);
    if (p)
        return (void*)(((Init_139860*)p)->run());
    return (void*)(0);
}

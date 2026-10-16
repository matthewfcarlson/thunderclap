// Same code shape as 0x0006f220 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_17f1c0;
extern void* __cdecl Alloc(unsigned int);
struct InitObj_17f1c0 {
    u32_17f1c0 Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::JointPivotTrackerTrack>::vfunc_5() {
    void* p = Alloc(0x60);
    if (p)
        return (void*)(((InitObj_17f1c0*)p)->Init());
    return (void*)(0);
}

// Same code shape as 0x00070420 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int uint;
extern void* __cdecl Allocate(unsigned int);
struct Track_15a7d0 {
    void* Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitReactionTrack>::vfunc_5() {
    void* p = Allocate(0x48);
    if (p)
        return (void*)(((Track_15a7d0*)p)->Init());
    return (void*)(0);
}

// Same code shape as 0x00070420 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int uint;
extern void* __cdecl Allocate(unsigned int);
struct Track_13e5f0 {
    void* Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AnimationLinkedTrack>::vfunc_5() {
    void* p = Allocate(0x48);
    if (p)
        return (void*)(((Track_13e5f0*)p)->Init());
    return (void*)(0);
}

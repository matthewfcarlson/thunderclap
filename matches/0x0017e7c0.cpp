// Same code shape as 0x00070420 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int uint;
extern void* __cdecl Allocate(unsigned int);
struct Track_17e7c0 {
    void* Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::SurfTrack>::vfunc_5() {
    void* p = Allocate(0x48);
    if (p)
        return (void*)(((Track_17e7c0*)p)->Init());
    return (void*)(0);
}

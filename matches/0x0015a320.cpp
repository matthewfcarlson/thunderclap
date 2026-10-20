// Same code shape as 0x0006fac0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

class Track_15a320 {
  public:
    hulk_intptr method();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GroundSlideTrack>::vfunc_5() {
    Track_15a320* p = (Track_15a320*)operator_new(0x38);
    if (p)
        return (void*)(p->method());
    return (void*)(0);
}

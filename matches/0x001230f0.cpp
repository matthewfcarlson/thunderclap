// Same code shape as 0x0006fac0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

class Track_1230f0 {
  public:
    hulk_intptr method();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::StrafeCircleTrack>::vfunc_5() {
    Track_1230f0* p = (Track_1230f0*)operator_new(0x38);
    if (p)
        return (void*)(p->method());
    return (void*)(0);
}

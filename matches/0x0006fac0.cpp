#include "compat/ptr.h"
#include "gen/fight.h"

class Track_6fac0 {
  public:
    hulk_intptr method();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CHeliDeathSpiralTrack>::vfunc_5() {
    Track_6fac0* p = (Track_6fac0*)operator_new(0x38);
    if (p)
        return (void*)(p->method());
    return (void*)(0);
}

#include "compat/ptr.h"
#include "gen/fight.h"

class Track_6fac0 {
  public:
    hulk_intptr method();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CHeliDeathSpiralTrack>::vfunc_5() {
    Track_6fac0* p = (Track_6fac0*)FUN_0008d690(0x38);
    if (p)
        return (void*)(p->method());
    return (void*)(0);
}

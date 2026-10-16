// Same code shape as 0x0006fac0 (propagated; names are from that function)
#include "gen/fight.h"

class Track_139710 {
  public:
    int method();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AirToGroundTargetTrack>::vfunc_5() {
    Track_139710* p = (Track_139710*)operator_new(0x38);
    if (p)
        return (void*)(p->method());
    return (void*)(0);
}

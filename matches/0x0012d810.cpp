// Same code shape as 0x0006fac0 (propagated; names are from that function)
#include "gen/fight.h"

class Track_12d810 {
  public:
    int method();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::ThreatBallTrack>::vfunc_5() {
    Track_12d810* p = (Track_12d810*)operator_new(0x38);
    if (p)
        return (void*)(p->method());
    return (void*)(0);
}

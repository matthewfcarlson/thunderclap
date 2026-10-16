// Same code shape as 0x0006fac0 (propagated; names are from that function)
#include "gen/fight.h"

class Track_122e50 {
  public:
    int method();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::PathFormationTrack>::vfunc_5() {
    Track_122e50* p = (Track_122e50*)operator_new(0x38);
    if (p)
        return (void*)(p->method());
    return (void*)(0);
}

// Same code shape as 0x0006f460 (propagated; names are from that function)
#include "gen/fight.h"

void* __cdecl FUN_0008d690(unsigned int);
class Dummy_1652a0 {
  public:
    int FUN_0005aa00();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::LocomotionSprintTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x68);
    if (p)
        return (void*)(((Dummy_1652a0*)p)->FUN_0005aa00());
    return (void*)(0);
}

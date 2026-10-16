#include "gen/fight.h"

class LocomotionStrafe4Track_1650f0 {
  public:
    int Init();
};
extern "C" void* __cdecl Alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::LocomotionStrafe4Track>::vfunc_5() {
    LocomotionStrafe4Track_1650f0* p = (LocomotionStrafe4Track_1650f0*)Alloc(0xa8);
    if (p)
        return (void*)(p->Init());
    return (void*)(0);
}

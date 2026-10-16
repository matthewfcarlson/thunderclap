#include "gen/fight.h"

typedef unsigned int u32_705d0;
extern "C" void* __cdecl alloc(unsigned int);
class CWeaponCollisionTrack_705d0 {
  public:
    u32_705d0 Init();
};

template <> void* fight::TrackFactoryTemplate<CWeaponCollisionTrack>::vfunc_5() {
    CWeaponCollisionTrack_705d0* p = (CWeaponCollisionTrack_705d0*)alloc(0x100);
    if (p)
        return (void*)(p->Init());
    return (void*)(0);
}

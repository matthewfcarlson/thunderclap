#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_705d0;
extern "C" void* __cdecl alloc(hulk_uintptr);
class CWeaponCollisionTrack_705d0 {
  public:
    hulk_uintptr Init();
};

template <> void* fight::TrackFactoryTemplate<CWeaponCollisionTrack>::vfunc_5() {
    CWeaponCollisionTrack_705d0* p = (CWeaponCollisionTrack_705d0*)alloc(0x100);
    if (p)
        return (void*)(p->Init());
    return (void*)(0);
}

#include "compat/ptr.h"
#include "gen/fight.h"

void* __cdecl operator_new(unsigned int);
struct Init_191c30 {
    hulk_intptr initialize();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TankLocomotionTrack>::vfunc_5() {
    Init_191c30* p = (Init_191c30*)operator_new(0x74);
    if (p)
        return (void*)(p->initialize());
    return (void*)(0);
}

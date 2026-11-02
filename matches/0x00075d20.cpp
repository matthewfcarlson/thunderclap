#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_75d20;
struct CAutoTargetTrack_75d20 {
    hulk_uintptr initialize();
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<CAutoTargetTrack>::vfunc_5() {
    CAutoTargetTrack_75d20* p = (CAutoTargetTrack_75d20*)FUN_0008d690(0x3c);
    if (p)
        return (void*)(p->initialize());
    return (void*)(0);
}

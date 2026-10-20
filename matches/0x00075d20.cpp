#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_75d20;
struct CAutoTargetTrack_75d20 {
    hulk_uintptr initialize();
};
extern void* __cdecl alloc(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<CAutoTargetTrack>::vfunc_5() {
    CAutoTargetTrack_75d20* p = (CAutoTargetTrack_75d20*)alloc(0x3c);
    if (p)
        return (void*)(p->initialize());
    return (void*)(0);
}

// Same code shape as 0x00075d20 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_122dc0;
struct CAutoTargetTrack_122dc0 {
    hulk_uintptr initialize();
};
extern void* __cdecl alloc(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::RoutTrack>::vfunc_5() {
    CAutoTargetTrack_122dc0* p = (CAutoTargetTrack_122dc0*)alloc(0x3c);
    if (p)
        return (void*)(p->initialize());
    return (void*)(0);
}

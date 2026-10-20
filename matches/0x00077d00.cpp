#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_77d00;
void* __cdecl FUN_0008d690(hulk_uintptr);
struct CKeyPoseTrack_77d00 {
    hulk_uintptr init();
};

template <> void* fight::TrackFactoryTemplate<CKeyPoseTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x78);
    if (p)
        return (void*)(((CKeyPoseTrack_77d00*)p)->init());
    return (void*)(0);
}

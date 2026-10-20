#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_77b50;
extern "C" void* __cdecl alloc(hulk_uintptr);
extern u32_77b50 track_vftable;
struct CGrappleKeyPoseTrack_77b50 {
    hulk_uintptr vf;
    void init();
};

template <> void* fight::TrackFactoryTemplate<CGrappleKeyPoseTrack>::vfunc_5() {
    CGrappleKeyPoseTrack_77b50* p = (CGrappleKeyPoseTrack_77b50*)alloc(0x78);
    if (p) {
        p->init();
        p->vf = (hulk_uintptr)&track_vftable;
        return (void*)(p);
    }
    return (void*)(0);
}

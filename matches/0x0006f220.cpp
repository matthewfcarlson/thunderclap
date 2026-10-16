#include "gen/fight.h"

typedef unsigned int u32_6f220;
extern void* __cdecl Alloc(unsigned int);
struct InitObj_6f220 {
    u32_6f220 Init();
};

template <> void* fight::TrackFactoryTemplate<CEffectTrack>::vfunc_5() {
    void* p = Alloc(0x60);
    if (p)
        return (void*)(((InitObj_6f220*)p)->Init());
    return (void*)(0);
}

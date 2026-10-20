#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003fd108[];
void* __cdecl FUN_0008d690(unsigned int);
struct Track_6f7c0 {
    virtual void f0();
    char pad[0xcc];
};
struct Init_6f7c0 {
    void init();
};

template <> void* fight::TrackFactoryTemplate<CGrappleMotionTrailTrack>::vfunc_5() {
    Track_6f7c0* p = (Track_6f7c0*)FUN_0008d690(0xd0);
    if (p) {
        ((Init_6f7c0*)p)->init();
        *(void**)p = (void*)((hulk_intptr)DAT_003fd108);
        return (void*)(p);
    }
    return (void*)(0);
}

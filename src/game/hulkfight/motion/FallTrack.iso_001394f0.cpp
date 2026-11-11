// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001394f0 fight::TrackFactoryTemplate<hulkfight::motion::GrappleHoverTrack>::vfunc_5 (66 B): matches/0x001394f0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VGrappleHoverTrack@motion@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

extern "C" char DAT_00411be8[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class FallTrack_1394f0 {
  public:
    hulk_intptr vptr;
    int pad;
    int m2;
    int m3;
    float m4;
    int m5;
    void Init_00236d40();
};
class GrappleHoverTrack_1394f0 : public FallTrack_1394f0 {};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleHoverTrack>::vfunc_5() {
    GrappleHoverTrack_1394f0* p = (GrappleHoverTrack_1394f0*)Alloc(0x18);
    if (p) {
        p->Init_00236d40();
        p->vptr = ((hulk_intptr)DAT_00411be8);
        p->m3 = 0;
        p->m4 = -1.0f;
        p->m5 = 0;
        p->m2 = 1;
        return (void*)(p);
    }
    return (void*)((GrappleHoverTrack_1394f0*)0);
}


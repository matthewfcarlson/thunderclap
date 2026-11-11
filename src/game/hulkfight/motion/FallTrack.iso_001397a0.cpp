// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001397a0 fight::TrackFactoryTemplate<hulkfight::motion::HoverTrack>::vfunc_5 (66 B): matches/0x001397a0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHoverTrack@motion@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

extern "C" char DAT_00411ca8[];
class HoverTrack_1397a0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[4];
    int one;
    int a;
    int b;
    int c;
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
void __fastcall Init_00236d40(HoverTrack_1397a0*);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HoverTrack>::vfunc_5() {
    HoverTrack_1397a0* p = (HoverTrack_1397a0*)Alloc(0x18);
    if (p) {
        Init_00236d40(p);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00411ca8);
        p->a = 0;
        p->b = (int)0xbf800000;
        p->c = 0;
        p->one = 1;
        return (void*)(p);
    }
    return (void*)(0);
}


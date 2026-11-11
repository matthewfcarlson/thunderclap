// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012b190..0x0012d920 (kind game, layer game, confidence high), dominant class hulkfight::ai::ThreatDistanceCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0012d8a0 fight::TrackFactoryTemplate<hulkfight::ai::ThreatDodgeTrack>::vfunc_5 (71 B): matches/0x0012d8a0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VThreatDodgeTrack@ai@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

extern "C" char DAT_00410c84[];
class ThreatDodgeTrack_12d8a0 {
  public:
    int a[2];
    int b;
    int c;
    int d;
    char e[4];
    int f;
};
extern void* __cdecl Alloc_0008d690(int);
struct Base {
    Base();
};
struct Tail {
    Tail();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::ThreatDodgeTrack>::vfunc_5() {
    ThreatDodgeTrack_12d8a0* p = (ThreatDodgeTrack_12d8a0*)Alloc_0008d690(0x28);
    if (p) {
        Base* b = (Base*)p;
        b->Base::Base();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00410c84);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0xbf800000;
        *(int*)((char*)p + 0x14) = 0x3f800000;
        *((char*)p + 0x18) = 1;
        Tail* t = (Tail*)((char*)p + 0x20);
        t->Tail::Tail();
        return (void*)(p);
    }
    return (void*)(0);
}


// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00159ea0..0x00159f60 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitOrientToPushbackTrack
#include "tree_prelude.h"


// 0x00159ee0 fight::TrackFactoryTemplate<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_5 (69 B): matches/0x00159ee0.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VHitOrientToPushbackTrack@motion@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

void* operator new(size_t);
struct Base_159ee0 {
    virtual void g();
    Base_159ee0();
};
struct Track_159ee0 : Base_159ee0 {
    virtual void f();
    int x4, x8, xC;
    float x10;
    int x14, x18, x1C, x20;
    Track_159ee0();
};
Track_159ee0::Track_159ee0() {
    xC = 0;
    x14 = 0;
    x1C = 0;
    x20 = 0;
    x10 = -1.0f;
    x18 = -5;
}

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_5() {
    Track_159ee0* p = (Track_159ee0*)::operator new(0x24);
    if (p) {
        p->Track_159ee0::Track_159ee0();
        return (void*)(p);
    }
    return (void*)(0);
}


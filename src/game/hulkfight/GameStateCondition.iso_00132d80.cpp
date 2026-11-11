// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
#include "tree_prelude.h"


// 0x00132d80 fight::TrackFactoryTemplate<hulkfight::DebugPrintTrack>::vfunc_5 (73 B): matches/0x00132d80.cpp [isolated: helper definitions (3 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VDebugPrintTrack@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

extern void* __cdecl Allocate_0008d690(unsigned int);
HULK_NATIVE_INLINE void* operator new(size_t, void* p) {
    return p;
}

class Track_132d80 {
  public:
    Track_132d80();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

class DebugPrintTrack_132d80 : public Track_132d80 {
  public:
    DebugPrintTrack_132d80();
    virtual void f5();
    int unused;
    int x;
    int a;
    int b;
    int c;
    int d;
};

DebugPrintTrack_132d80::DebugPrintTrack_132d80() {
    a = 0;
    b = 0xbf800000;
    c = 0;
    d = 0;
    x = 1;
}

class TrackFactory_132d80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* f5();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::DebugPrintTrack>::vfunc_5() {
    DebugPrintTrack_132d80* p = (DebugPrintTrack_132d80*)Allocate_0008d690(0x1c);
    if (p) {
        new (p) DebugPrintTrack_132d80();
        return (void*)(p);
    }
    return (void*)(0);
}


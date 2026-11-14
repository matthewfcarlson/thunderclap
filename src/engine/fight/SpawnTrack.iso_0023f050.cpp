// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023ea20..0x0023f0d0 (kind game, layer engine, confidence high), dominant class fight::SpawnTrack
#include "tree_prelude.h"


// 0x0023f050 fight::TrackFactoryTemplate<fight::SpawnTrack>::vfunc_5 (75 B): matches/0x0023f050.cpp [isolated: merged class would differ: SpawnTrack_23f050: field x: Field(+0x14 PartA x) vs Field(+0x14 PartA x); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VSpawnTrack@fight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

/* size_t: tree_prelude.h */
void* __cdecl operator new(size_t);
class PartA {
  public:
    char p[12];
    PartA();
};
class PartB {
  public:
    char p[4];
    PartB();
};
class Base {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int a;
    int b;
    Base();
};
class SpawnTrack_23f050 : public Base {
  public:
    int c;
    float d;
    PartA x;
    PartB y;
    SpawnTrack_23f050() : c(0), d(-1.0f) { b = 1; }
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

template <> void* fight::TrackFactoryTemplate<fight::SpawnTrack>::vfunc_5() {
    return (void*)(new SpawnTrack_23f050);
}


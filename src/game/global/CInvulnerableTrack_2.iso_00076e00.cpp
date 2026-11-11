// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00076dc0..0x00076e80 (kind game, layer game, confidence high), dominant class CInvulnerableTrack
#include "tree_prelude.h"


// 0x00076e00 fight::TrackFactoryTemplate<CInvulnerableTrack>::vfunc_5 (66 B): matches/0x00076e00.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCInvulnerableTrack@@@fight@@UAEPAXXZ
#include "gen/fight.h"

/* size_t: tree_prelude.h */
void* operator new(size_t);
class CTrack_76e00 {
  public:
    CTrack_76e00() throw();
    virtual void f0();
    virtual bool f1_00234270(void*);
    virtual bool f2_002342b0(int);
    virtual bool f3_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool f4_00234350(int, int);
    virtual void* f5_0006bad0(char);
    int x;
    int flag;
};
class CInvulnerableTrack_76e00 : public CTrack_76e00 {
  public:
    CInvulnerableTrack_76e00() throw();
    virtual void f0();
    int a;
    float b;
    int c;
};
CInvulnerableTrack_76e00::CInvulnerableTrack_76e00() throw() {
    a = 0;
    b = -1.0f;
    c = 0;
    flag = 1;
}

template <> void* fight::TrackFactoryTemplate<CInvulnerableTrack>::vfunc_5() {
    return (void*)(new CInvulnerableTrack_76e00);
}


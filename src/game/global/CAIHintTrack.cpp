// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006aee0..0x0006afc0 (kind game, layer game, confidence high), dominant class CAIHintTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fda83b0b {
#define TREE_TU_END }
namespace fn_fda83b0b {} using namespace fn_fda83b0b;
namespace fn_fda83b0b { extern "C" char DAT_003f98d0[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fda83b0b {
extern int* hulk_at_004dd008;
class CCondition_6af00 {
  public:
    virtual int vfunc_0(int);
};
struct Param_6af60 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6af60 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern void* hulk_at_003fc184[];
struct Sub_6af70 {
    void Fin_0027af50();
};
class CTrack_6af70 {
  public:
    void* vptr;
    ~CTrack_6af70();
};
class CAIHintTrack_6af70 : public CTrack_6af70 {
  public:
    char pad[0x18 - 4];
    Sub_6af70 sub;
    ~CAIHintTrack_6af70();
};
class R_6af90 {
  public:
    int invoke_00020bc0(CAIHintTrack*, hulk_intptr);
};
extern "C" R_6af90* FUN_0008d690(int);


// 0x0006aee0 FUN_0006aee0 (19 B): matches/0x0006aee0.cpp
// sym: ?FUN_0006aee0@fn_fda83b0b@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006aee0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dd008), ((char*)&DAT_004dd00c));
}

} // namespace fn_fda83b0b

// 0x0006af00 CAIHintTrack::vfunc_0 (16 B): matches/0x0006af00.cpp
// sym: ?vfunc_0@CAIHintTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CAIHintTrack::vfunc_0(int index) {
    int* p = hulk_at_004dd008;
    return p[index];
}


// 0x0006af10 FUN_0006af10 (47 B): matches/0x0006af10.cpp [wrapped: conflict: CAIHintTrack]
// sym: ??0CAIHintTrack@fn_0006af10@@QAE@XZ
namespace fn_0006af10 {
class CTrack_6af10 {
  public:
    CTrack_6af10();
    virtual hulk_intptr FnA_0006af00(int);
    virtual bool FnB_00234270(void*);
};

class Elem_6af10 {
  public:
    void Init_0027af00();
    char pad[16];
};

class CAIHintTrack : public CTrack_6af10 {
  public:
    char pad0[4];
    int mCount;   // offset 0x8
    int mZero;    // offset 0xc
    float mScale; // offset 0x10
    char pad1[4]; // offset 0x14
    Elem_6af10 mElem;   // offset 0x18
    CAIHintTrack();
};

CAIHintTrack::CAIHintTrack() {
    mZero = 0;
    mScale = -1.0f;
    mElem.Init_0027af00();
    mCount = 1;
}
} // namespace fn_0006af10


// 0x0006af40 CAIHintTrack::vfunc_13 (13 B): matches/0x0006af40.cpp
// sym: ?vfunc_13@CAIHintTrack@@UAEXPAX@Z
// Same code shape as 0x0005e010 (propagated; names are from that function)
void CAIHintTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = -1;
}


// 0x0006af50 CAIHintTrack::vfunc_6 (4 B): matches/0x0006af50.cpp
// sym: ?vfunc_6@CAIHintTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CAIHintTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0006af60 CAIHintTrack::vfunc_7 (7 B): matches/0x0006af60.cpp
// sym: ?vfunc_7@CAIHintTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CAIHintTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

namespace fn_fda83b0b {

// 0x0006af70 FUN_0006af70 (31 B): matches/0x0006af70.cpp
// sym: ??1CAIHintTrack_6af70@fn_fda83b0b@@QAE@XZ
CAIHintTrack_6af70::~CAIHintTrack_6af70() {
    vptr = hulk_at_003fc184;
    sub.Fin_0027af50();
    vptr = (void**)DAT_003f98d0;
}

} // namespace fn_fda83b0b

// 0x0006af90 CAIHintTrack::vfunc_12 (40 B): matches/0x0006af90.cpp
// sym: ?vfunc_12@CAIHintTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CAIHintTrack::vfunc_12(hulk_intptr param) {
    R_6af90* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_00020bc0(this, param);
    return 0;
}


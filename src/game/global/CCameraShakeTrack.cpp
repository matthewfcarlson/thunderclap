// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006a2a0..0x0006a370 (kind game, layer game, confidence high), dominant class CCameraShakeTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f62dad14 {
#define TREE_TU_END }
namespace fn_f62dad14 {} using namespace fn_f62dad14;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f62dad14 {
extern void* hulk_at_004dcfa0;
class R_6a340 {
  public:
    int invoke_0001f800(CCameraShakeTrack*, hulk_intptr);
};
extern "C" R_6a340* FUN_0008d690(int);


// 0x0006a2a0 FUN_0006a2a0 (19 B): matches/0x0006a2a0.cpp
// sym: ?FUN_0006a2a0@fn_f62dad14@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006a2a0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcfa0), ((char*)&DAT_004dcfa4));
}

} // namespace fn_f62dad14

// 0x0006a2c0 CCameraShakeTrack::vfunc_0 (16 B): matches/0x0006a2c0.cpp
// sym: ?vfunc_0@CCameraShakeTrack@@UAEHH@Z
hulk_intptr CCameraShakeTrack::vfunc_0(int index) {
    void** p = (void**)hulk_at_004dcfa0;
    return (hulk_intptr)p[index];
}


// 0x0006a2d0 FUN_0006a2d0 (39 B): matches/0x0006a2d0.cpp [wrapped: conflict: CCameraShakeTrack]
// sym: ??0CCameraShakeTrack@fn_0006a2d0@@QAE@XZ
namespace fn_0006a2d0 {
class CTrack_6a2d0 {
  public:
    CTrack_6a2d0();
    virtual void Fn();
};

class CCameraShakeTrack : public ::CCameraShakeTrack {
  public:
    CCameraShakeTrack();
};

CCameraShakeTrack::CCameraShakeTrack() {
    timeBegin = 0;
    timeEnd = 0;
    amplitude = 0;
    frequency = 0;
    f_08 = 1;
}
} // namespace fn_0006a2d0


// 0x0006a300 CCameraShakeTrack::vfunc_13 (13 B): matches/0x0006a300.cpp
// sym: ?vfunc_13@CCameraShakeTrack@@UAEXPAX@Z
// Same code shape as 0x0005aa70 (propagated; names are from that function)
void CCameraShakeTrack::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = 0xffff7f00;
}


// 0x0006a310 CCameraShakeTrack::vfunc_6 (4 B): matches/0x0006a310.cpp
// sym: ?vfunc_6@CCameraShakeTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CCameraShakeTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0006a320 CCameraShakeTrack::vfunc_7 (7 B): matches/0x0006a320.cpp
// sym: ?vfunc_7@CCameraShakeTrack@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg CCameraShakeTrack::vfunc_7() {
    return DAT_003f32e0;
}


// 0x0006a340 CCameraShakeTrack::vfunc_12 (40 B): matches/0x0006a340.cpp
// sym: ?vfunc_12@CCameraShakeTrack@@UAEHH@Z
// Same code shape as 0x0005aad0 (propagated; names are from that function)
hulk_intptr CCameraShakeTrack::vfunc_12(hulk_intptr param) {
    R_6a340* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke_0001f800(this, param);
    return 0;
}


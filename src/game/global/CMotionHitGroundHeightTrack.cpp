// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006b070..0x0006b140 (kind game, layer game, confidence high), dominant class CMotionHitGroundHeightTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fb1b52d7 {
#define TREE_TU_END }
namespace fn_fb1b52d7 {} using namespace fn_fb1b52d7;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb1b52d7 {
extern int* hulk_at_004dd018;
struct Param_6b0f0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6b0f0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" void* __cdecl FUN_0008d690(int);
struct Worker_6b110 {
    int go_00020cd0(unsigned int, unsigned int);
};


// 0x0006b070 FUN_0006b070 (19 B): matches/0x0006b070.cpp
// sym: ?FUN_0006b070@fn_fb1b52d7@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006b070() {
    FUN_00234810(((char*)&DAT_004dd018), ((char*)&DAT_004dd01c));
}

} // namespace fn_fb1b52d7

// 0x0006b090 CMotionHitGroundHeightTrack::vfunc_0 (16 B): matches/0x0006b090.cpp
// sym: ?vfunc_0@CMotionHitGroundHeightTrack@@UAEHH@Z
hulk_intptr CMotionHitGroundHeightTrack::vfunc_0(int index) {
    return hulk_at_004dd018[index];
}


// 0x0006b0a0 FUN_0006b0a0 (46 B): matches/0x0006b0a0.cpp [wrapped: conflict: CMotionHitGroundHeightTrack]
// sym: ??0CMotionHitGroundHeightTrack@fn_0006b0a0@@QAE@XZ
namespace fn_0006b0a0 {
class CTrack_6b0a0 {
  public:
    CTrack_6b0a0();
    virtual hulk_intptr Fnv_0006b090(int);
    int baseField;
};
class CMotionHitGroundHeightTrack : public CTrack_6b0a0 {
  public:
    CMotionHitGroundHeightTrack();
    int state;
    int a;
    float b;
    float c;
};
CMotionHitGroundHeightTrack::CMotionHitGroundHeightTrack() : CTrack_6b0a0() {
    a = 0;
    b = -1.0f;
    c = 1.0f;
    state = 1;
}
} // namespace fn_0006b0a0


// 0x0006b0d0 CMotionHitGroundHeightTrack::vfunc_13 (13 B): matches/0x0006b0d0.cpp
// sym: ?vfunc_13@CMotionHitGroundHeightTrack@@UAEXPAX@Z
void CMotionHitGroundHeightTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff00ff7f;
}


// 0x0006b0e0 CMotionHitGroundHeightTrack::vfunc_6 (4 B): matches/0x0006b0e0.cpp
// sym: ?vfunc_6@CMotionHitGroundHeightTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CMotionHitGroundHeightTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0006b0f0 CMotionHitGroundHeightTrack::vfunc_7 (7 B): matches/0x0006b0f0.cpp
// sym: ?vfunc_7@CMotionHitGroundHeightTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CMotionHitGroundHeightTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}


// 0x0006b110 CMotionHitGroundHeightTrack::vfunc_12 (43 B): matches/0x0006b110.cpp
// sym: ?vfunc_12@CMotionHitGroundHeightTrack@@UAEHH@Z
// Same code shape as 0x0006a010 (propagated; names are from that function)
hulk_intptr CMotionHitGroundHeightTrack::vfunc_12(hulk_intptr __p0) { unsigned int param = (unsigned int)__p0;

    void* p = FUN_0008d690(0x24);
    if (p)
        return ((Worker_6b110*)p)->go_00020cd0(param, this->height);
    return 0;
}


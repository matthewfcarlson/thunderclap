// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00022690..0x00022770 (kind game, layer game, confidence medium), dominant class CMotionHitGroundHeightAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2bde127 {
#define TREE_TU_END }
namespace fn_f2bde127 {} using namespace fn_f2bde127;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2bde127 {
extern void* hulk_at_003f3390[];
class Ref_22690 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22690 {
  public:
    void* vptr;
};
class CAIHintAction_22690 : public CAction_22690 {
  public:
    char pad[0x1c - 4];
    Ref_22690* m;
    CAIHintAction_22690* f2(unsigned char flags);
};
extern void* hulk_at_003f3d30[];
class Ref_226d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_226d0 {
  public:
    void* vptr;
};
class CSnapToWallAction_226d0 : public CAction_226d0 {
  public:
    char pad[0x18];
    Ref_226d0* m2;
    char pad2[0x4];
    Ref_226d0* m1;
    CSnapToWallAction_226d0* f2(unsigned char flags);
};
extern void* g_vftable_22730[];
class Ref_22730 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22730 {
  public:
    void* vptr;
};
class CMotionHitGroundHeightAction_22730 : public CAction_22730 {
  public:
    char pad[0x1c - 4];
    Ref_22730* m;
    CMotionHitGroundHeightAction_22730* f2(unsigned char flags);
};


// 0x00022690 CAIHintAction::vfunc_2 (57 B): matches/0x00022690.cpp
// sym: ?f2@CAIHintAction_22690@fn_f2bde127@@QAEPAV12@E@Z
CAIHintAction_22690* CAIHintAction_22690::f2(unsigned char flags) {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22690 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x000226d0 CSnapToWallAction::vfunc_2 (82 B): matches/0x000226d0.cpp
// sym: ?f2@CSnapToWallAction_226d0@fn_f2bde127@@QAEPAV12@E@Z
CSnapToWallAction_226d0* CSnapToWallAction_226d0::f2(unsigned char flags) {
    vptr = hulk_at_003f3d30;
    _ReadWriteBarrier();
    if (m1) {
        m1->Release();
        m1 = 0;
    }
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m2) {
        m2->Release();
        m2 = 0;
    }
    ((fight::Action *)(CAction_226d0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00022730 CMotionHitGroundHeightAction::vfunc_2 (57 B): matches/0x00022730.cpp
// sym: ?f2@CMotionHitGroundHeightAction_22730@fn_f2bde127@@QAEPAV12@E@Z
CMotionHitGroundHeightAction_22730* CMotionHitGroundHeightAction_22730::f2(unsigned char flags) {
    vptr = g_vftable_22730;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22730 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f2bde127

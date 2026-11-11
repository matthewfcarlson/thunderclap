// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00022560..0x000225a0 (kind game, layer game, confidence medium), dominant class CStageAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8a156a2 {
#define TREE_TU_END }
namespace fn_f8a156a2 {} using namespace fn_f8a156a2;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8a156a2 {
extern void* hulk_at_003f3390[];
class Ref_22560 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22560 {
  public:
    void* vptr;
};
class CStageAction_22560 : public CAction_22560 {
  public:
    char pad[0x1c - 4];
    Ref_22560* m;
    CStageAction_22560* f2(unsigned char flags);
};


// 0x00022560 CStageAction::vfunc_2 (57 B): matches/0x00022560.cpp
// sym: ?f2@CStageAction_22560@fn_f8a156a2@@QAEPAV12@E@Z
CStageAction_22560* CStageAction_22560::f2(unsigned char flags) {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22560 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f8a156a2

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00022650..0x00022690 (kind game, layer game, confidence medium), dominant class CDeathAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f97416fb {
#define TREE_TU_END }
namespace fn_f97416fb {} using namespace fn_f97416fb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f97416fb {
extern void* hulk_at_003f3390[];
class Ref_22650 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22650 {
  public:
    void* vptr;
};
class CDeathAction_22650 : public CAction_22650 {
  public:
    char pad[0x1c - 4];
    Ref_22650* m;
    CDeathAction_22650* f2(unsigned char flags);
};


// 0x00022650 CDeathAction::vfunc_2 (57 B): matches/0x00022650.cpp
// sym: ?f2@CDeathAction_22650@fn_f97416fb@@QAEPAV12@E@Z
CDeathAction_22650* CDeathAction_22650::f2(unsigned char flags) {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22650 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f97416fb

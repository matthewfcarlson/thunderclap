// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000228f0..0x00022960 (kind game, layer game, confidence medium), dominant class CClearHitRecordsAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0590878 {
#define TREE_TU_END }
namespace fn_f0590878 {} using namespace fn_f0590878;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0590878 {
extern void* g_vftable_228f0[];
class Ref_228f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_228f0 {
  public:
    void* vptr;
};
class CClearHitRecordsAction_228f0 : public CAction_228f0 {
  public:
    char pad[0x1c - 4];
    Ref_228f0* m;
    CClearHitRecordsAction_228f0* f2(unsigned char flags);
};


// 0x000228f0 CClearHitRecordsAction::vfunc_2 (57 B): matches/0x000228f0.cpp
// sym: ?f2@CClearHitRecordsAction_228f0@fn_f0590878@@QAEPAV12@E@Z
CClearHitRecordsAction_228f0* CClearHitRecordsAction_228f0::f2(unsigned char flags) {
    vptr = g_vftable_228f0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_228f0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f0590878

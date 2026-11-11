// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00022160..0x000221a0 (kind game, layer game, confidence medium), dominant class CIntangibleToActorsAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fc721419 {
#define TREE_TU_END }
namespace fn_fc721419 {} using namespace fn_fc721419;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc721419 {
extern void* hulk_at_003f3390[];
class Ref_22160 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22160 {
  public:
    void* vptr;
};
class CIntangibleToActorsAction_22160 : public CAction_22160 {
  public:
    char pad[0x1c - 4];
    Ref_22160* m;
    CIntangibleToActorsAction_22160* f2(unsigned char flags);
};


// 0x00022160 CIntangibleToActorsAction::vfunc_2 (57 B): matches/0x00022160.cpp
// sym: ?f2@CIntangibleToActorsAction_22160@fn_fc721419@@QAEPAV12@E@Z
CIntangibleToActorsAction_22160* CIntangibleToActorsAction_22160::f2(unsigned char flags) {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22160 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fc721419

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00021f60..0x00021fa0 (kind game, layer game, confidence medium), dominant class CSmartPropDetachAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fe8d468f {
#define TREE_TU_END }
namespace fn_fe8d468f {} using namespace fn_fe8d468f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe8d468f {
extern void* g_vftable_21f60[];
class Ref_21f60 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21f60 {
  public:
    void* vptr;
};
class CSmartPropDetachAction_21f60 : public CAction_21f60 {
  public:
    char pad[0x1c - 4];
    Ref_21f60* m;
    CSmartPropDetachAction_21f60* f2(unsigned char flags);
};


// 0x00021f60 CSmartPropDetachAction::vfunc_2 (57 B): matches/0x00021f60.cpp
// sym: ?f2@CSmartPropDetachAction_21f60@fn_fe8d468f@@QAEPAV12@E@Z
CSmartPropDetachAction_21f60* CSmartPropDetachAction_21f60::f2(unsigned char flags) {
    vptr = g_vftable_21f60;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21f60 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fe8d468f

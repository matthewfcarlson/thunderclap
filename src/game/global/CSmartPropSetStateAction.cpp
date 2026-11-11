// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00021f20..0x00021f60 (kind game, layer game, confidence medium), dominant class CSmartPropSetStateAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0d13c42 {
#define TREE_TU_END }
namespace fn_f0d13c42 {} using namespace fn_f0d13c42;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0d13c42 {
extern void* g_vftable_21f20[];
class Ref_21f20 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21f20 {
  public:
    void* vptr;
};
class CSmartPropSetStateAction_21f20 : public CAction_21f20 {
  public:
    char pad[24];
    Ref_21f20* m;
    CSmartPropSetStateAction_21f20* f2(unsigned char flags);
};


// 0x00021f20 CSmartPropSetStateAction::vfunc_2 (57 B): matches/0x00021f20.cpp
// sym: ?f2@CSmartPropSetStateAction_21f20@fn_f0d13c42@@QAEPAV12@E@Z
CSmartPropSetStateAction_21f20* CSmartPropSetStateAction_21f20::f2(unsigned char flags) {
    vptr = g_vftable_21f20;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21f20 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f0d13c42

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000220e0..0x00022160 (kind game, layer game, confidence medium), dominant class CIntangibleAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f464926c {
#define TREE_TU_END }
namespace fn_f464926c {} using namespace fn_f464926c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f464926c {
extern void* hulk_at_003f3390[];
class Ref_220e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_220e0 {
  public:
    void* vptr;
};
class CInvincibleAction_220e0 : public CAction_220e0 {
  public:
    char pad[0x1c - 4];
    Ref_220e0* m;
    CInvincibleAction_220e0* f2(unsigned char flags);
};
extern void* g_vftable_22120[];
class Ref_22120 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22120 {
  public:
    void* vptr;
};
class CIntangibleAction_22120 : public CAction_22120 {
  public:
    char pad[0x1c - 4];
    Ref_22120* m;
    CIntangibleAction_22120* f2(unsigned char flags);
};


// 0x000220e0 CInvincibleAction::vfunc_2 (57 B): matches/0x000220e0.cpp
// sym: ?f2@CInvincibleAction_220e0@fn_f464926c@@QAEPAV12@E@Z
CInvincibleAction_220e0* CInvincibleAction_220e0::f2(unsigned char flags) {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_220e0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00022120 CIntangibleAction::vfunc_2 (57 B): matches/0x00022120.cpp
// sym: ?f2@CIntangibleAction_22120@fn_f464926c@@QAEPAV12@E@Z
CIntangibleAction_22120* CIntangibleAction_22120::f2(unsigned char flags) {
    vptr = g_vftable_22120;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22120 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f464926c

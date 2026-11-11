// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000216a0..0x00021780 (kind game, layer game, confidence medium), dominant class CClimbingAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f420a0ef {
#define TREE_TU_END }
namespace fn_f420a0ef {} using namespace fn_f420a0ef;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f420a0ef {
extern void* g_vftable_216a0[];
class Ref_216a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_216a0 {
  public:
    void* vptr;
};
class CAction_216a0 : public Action_216a0 {
  public:
    char pad[24];
    Ref_216a0* m;
    CAction_216a0* f2(unsigned char flags);
};
extern void* gA_216e0[];
class Ref_216e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_216e0 {
  public:
    void* vptr;
};
class CJointAction_216e0 : public CAction_216e0 {
  public:
    char pad_1c[0x18];
    Ref_216e0* m1c;
    char pad_24[0x4];
    Ref_216e0* m24;
    CJointAction_216e0* f2(unsigned char flags);
};
class Child_21740 {
  public:
    virtual void A();
    virtual void B();
};
class CClimbingAction {
  public:
    void* volatile vptr;
    char pad[0x18];
    Child_21740* member;
    void Run();
    CClimbingAction* Target(char);
};
extern void __cdecl thunk_FUN_00267090(CClimbingAction*);


// 0x000216a0 CAction::vfunc_2 (57 B): matches/0x000216a0.cpp
// sym: ?f2@CAction_216a0@fn_f420a0ef@@QAEPAV12@E@Z
CAction_216a0* CAction_216a0::f2(unsigned char flags) {
    vptr = g_vftable_216a0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_216a0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x000216e0 CJointAction::vfunc_2 (82 B): matches/0x000216e0.cpp
// sym: ?f2@CJointAction_216e0@fn_f420a0ef@@QAEPAV12@E@Z
CJointAction_216e0* CJointAction_216e0::f2(unsigned char flags) {
    vptr = gD;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = gA_216e0;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_216e0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021740 CClimbingAction::vfunc_2 (57 B): matches/0x00021740.cpp
// sym: ?Target@CClimbingAction@fn_f420a0ef@@QAEPAV12@D@Z
CClimbingAction* CClimbingAction::Target(char flag) {
    vptr = (void*)((hulk_intptr)DAT_003f3390);
    _ReadWriteBarrier();
    Child_21740* p = member;
    if (p) {
        p->B();
        member = 0;
    }
    Run();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f420a0ef

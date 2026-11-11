// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00021fa0..0x00022020 (kind game, layer game, confidence medium), dominant class CSmartPropThrowingAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f05d8adb {
#define TREE_TU_END }
namespace fn_f05d8adb {} using namespace fn_f05d8adb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f05d8adb {
extern void* hulk_at_003f3390[];
class Ref_21fa0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21fa0 {
  public:
    void* vptr;
};
class CSmartPropThrowAction_21fa0 : public CAction_21fa0 {
  public:
    char pad[0x1c - 4];
    Ref_21fa0* m;
    CSmartPropThrowAction_21fa0* f2(unsigned char flags);
};
class Ref_21fe0 {
  public:
    virtual void F();
    virtual void Release();
};
class CSmartPropThrowingAction {
  public:
    volatile hulk_intptr vptr;
    char pad[0x18];
    Ref_21fe0* member;
    CSmartPropThrowingAction* V2(int);
};
class CSmartPropThrowingAction_21fe0 {
  public:
    void Go_002326a0();
};
extern void thunk_FUN_00267090(CSmartPropThrowingAction*);


// 0x00021fa0 CSmartPropThrowAction::vfunc_2 (57 B): matches/0x00021fa0.cpp
// sym: ?f2@CSmartPropThrowAction_21fa0@fn_f05d8adb@@QAEPAV12@E@Z
CSmartPropThrowAction_21fa0* CSmartPropThrowAction_21fa0::f2(unsigned char flags) {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21fa0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021fe0 CSmartPropThrowingAction::vfunc_2 (57 B): matches/0x00021fe0.cpp
// sym: ?V2@CSmartPropThrowingAction@fn_f05d8adb@@QAEPAV12@H@Z
CSmartPropThrowingAction* CSmartPropThrowingAction::V2(int flag) {
    vptr = ((hulk_intptr)DAT_003f3390);
    _ReadWriteBarrier();
    if (member) {
        member->Release();
        member = 0;
    }
    ((CSmartPropThrowingAction_21fe0*)this)->Go_002326a0();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f05d8adb

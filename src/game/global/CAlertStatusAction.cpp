// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000225a0..0x00022650 (kind game, layer game, confidence medium), dominant class CAlertStatusAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_faa66039 {
#define TREE_TU_END }
namespace fn_faa66039 {} using namespace fn_faa66039;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_faa66039 {
class Obj_225c0 {
  public:
    virtual void a();
    virtual void b();
};
class CHapticEventAction_225c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual CHapticEventAction_225c0* f2(unsigned char flags);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    char pad[0x18];
    Obj_225c0* mObj;
    int mHandle;
};
extern void thunk(CHapticEventAction_225c0*);
extern void* g_vftable_22610[];
class Ref_22610 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22610 {
  public:
    void* vptr;
};
class CAlertStatusAction_22610 : public CAction_22610 {
  public:
    char pad[24];
    Ref_22610* m;
    CAlertStatusAction_22610* f2(unsigned char flags);
};

} // namespace fn_faa66039

// 0x000225a0 CHeadTrackerAction::vfunc_2 (30 B): matches/0x000225a0.cpp
// sym: ??_GCHeadTrackerAction@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CHeadTrackerAction::~CHeadTrackerAction() {}

namespace fn_faa66039 {

// 0x000225c0 CHapticEventAction::vfunc_2 (77 B): matches/0x000225c0.cpp
// sym: ?f2@CHapticEventAction_225c0@fn_faa66039@@UAEPAV12@E@Z
CHapticEventAction_225c0* CHapticEventAction_225c0::f2(unsigned char flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_003f3c90);
    _ReadWriteBarrier();
    if (mHandle)
        mHandle = 0;
    *(void**)this = (void*)((hulk_intptr)DAT_003f3390);
    _ReadWriteBarrier();
    if (mObj) {
        mObj->b();
        mObj = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flags & 1)
        thunk(this);
    return this;
}


// 0x00022610 CAlertStatusAction::vfunc_2 (57 B): matches/0x00022610.cpp
// sym: ?f2@CAlertStatusAction_22610@fn_faa66039@@QAEPAV12@E@Z
CAlertStatusAction_22610* CAlertStatusAction_22610::f2(unsigned char flags) {
    vptr = g_vftable_22610;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22610 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_faa66039

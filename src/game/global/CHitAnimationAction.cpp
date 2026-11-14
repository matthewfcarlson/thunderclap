// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00021780..0x00021940 (kind game, layer game, confidence medium), dominant class CHitAnimationAction
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fb6e77e3 {
#define TREE_TU_END }
namespace fn_fb6e77e3 {} using namespace fn_fb6e77e3;
namespace fn_fb6e77e3 { extern "C" char DAT_003f3408[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
namespace fn_fb6e77e3 { extern "C" char DAT_003f3438[], DAT_003f3390[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb6e77e3 {
extern void* hulk_at_003f3390[];
class Ref_21780 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21780 {
  public:
    void* vptr;
};
class CJumpAction_21780 : public CAction_21780 {
  public:
    char pad[0x1c - 4];
    Ref_21780* m1c;
    char pad2[4];
    Ref_21780* m24;
    CJumpAction_21780* f2(unsigned char flags);
};
class Ref_217e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_217e0 {
  public:
    void* vptr;
};
class CDropAction_217e0 : public CAction_217e0 {
  public:
    char pad[0x1c - 4];
    Ref_217e0* m1c;
    char pad2[4];
    Ref_217e0* m24;
    CDropAction_217e0* f2(unsigned char flags);
};
extern void* g_vftable_21860[];
class Ref_21860 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21860 {
  public:
    void* vptr;
};
class COpportunityBallAction_21860 : public CAction_21860 {
  public:
    char pad[0x1c - 4];
    Ref_21860* m;
    COpportunityBallAction_21860* f2(unsigned char flags);
};
extern void* hulk_at_003f34f0[];
class Ref_218c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_218c0 {
  public:
    void* vptr;
};
class CProceduralDurationAnimationAction_218c0 : public CAction_218c0 {
  public:
    char pad[0x18];
    Ref_218c0* m2;
    char pad2[0x4];
    Ref_218c0* m1;
    CProceduralDurationAnimationAction_218c0* f2(unsigned char flags);
};


// 0x00021780 CJumpAction::vfunc_2 (82 B): matches/0x00021780.cpp
// sym: ?f2@CJumpAction_21780@fn_fb6e77e3@@QAEPAV12@E@Z
CJumpAction_21780* CJumpAction_21780::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3408);
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_21780 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x000217e0 CDropAction::vfunc_2 (82 B): matches/0x000217e0.cpp
// sym: ?f2@CDropAction_217e0@fn_fb6e77e3@@QAEPAV12@E@Z
CDropAction_217e0* CDropAction_217e0::f2(unsigned char flags) {
    vptr = (void**)DAT_003f3438;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = (void**)DAT_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_217e0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fb6e77e3

// 0x00021840 CCollisionAction::vfunc_2 (30 B): matches/0x00021840.cpp
// sym: ??_GCCollisionAction@@UAEPAXI@Z
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CCollisionAction::~CCollisionAction() {}

namespace fn_fb6e77e3 {

// 0x00021860 COpportunityBallAction::vfunc_2 (57 B): matches/0x00021860.cpp
// sym: ?f2@COpportunityBallAction_21860@fn_fb6e77e3@@QAEPAV12@E@Z
COpportunityBallAction_21860* COpportunityBallAction_21860::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21860 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fb6e77e3

// 0x000218a0 CWeaponCollisionAction::vfunc_2 (30 B): matches/0x000218a0.cpp
// sym: ??_GCWeaponCollisionAction@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CWeaponCollisionAction::~CWeaponCollisionAction() {}

namespace fn_fb6e77e3 {

// 0x000218c0 CProceduralDurationAnimationAction::vfunc_2 (82 B): matches/0x000218c0.cpp
// sym: ?f2@CProceduralDurationAnimationAction_218c0@fn_fb6e77e3@@QAEPAV12@E@Z
CProceduralDurationAnimationAction_218c0* CProceduralDurationAnimationAction_218c0::f2(unsigned char flags) {
    vptr = hulk_at_003f34f0;
    _ReadWriteBarrier();
    if (m1) {
        m1->Release();
        m1 = 0;
    }
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m2) {
        m2->Release();
        m2 = 0;
    }
    ((fight::Action *)(CAction_218c0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fb6e77e3

// 0x00021920 CHitAnimationAction::vfunc_2 (30 B): matches/0x00021920.cpp
// sym: ??_GCHitAnimationAction@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CHitAnimationAction::~CHitAnimationAction() {}


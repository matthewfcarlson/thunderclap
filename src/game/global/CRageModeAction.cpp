// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00022340..0x00022560 (kind game, layer game, confidence medium), dominant class CRageModeAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f327212d {
#define TREE_TU_END }
namespace fn_f327212d {} using namespace fn_f327212d;
namespace fn_f327212d { extern "C" char DAT_003f3390[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f327212d {
extern void* hulk_at_003f3b24[];
class Ref_22340 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22340 {
  public:
    void* vptr;
};
class CJumpAttackAction_22340 : public CAction_22340 {
  public:
    char pad[0x18];
    Ref_22340* m2;
    char pad2[0x4];
    Ref_22340* m1;
    CJumpAttackAction_22340* f2(unsigned char flags);
};
extern int hulk_at_003f3b4c, hulk_at_003f3390;
class Ref_223a0 {
  public:
    virtual void f0();
    virtual void Release();
};
class CAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};
class COrientAction : public CAction {
  public:
    virtual void a0();
    virtual void a1();
    virtual COrientAction* vfunc_2(unsigned int);
    char pad[0x18];
    Ref_223a0* mSecond;
    char pad2[4];
    Ref_223a0* mFirst;
    void helper_002326a0();
};
void __cdecl thunk_FUN_00267090(COrientAction*);
extern void* gA_22400[];
class Ref_22400 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22400 {
  public:
    void* vptr;
};
class COrientTargetAction_22400 : public CAction_22400 {
  public:
    char pad_1c[0x18];
    Ref_22400* m1c;
    char pad_28[0x8];
    Ref_22400* m28;
    COrientTargetAction_22400* f2(unsigned char flags);
};
extern void* g_vftable_22460[];
class Ref_22460 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22460 {
  public:
    void* vptr;
};
class CDriftAction_22460 : public CAction_22460 {
  public:
    char pad[0x18];
    Ref_22460* m;
    CDriftAction_22460* f2(unsigned char flags);
};
class Ref_224a0 {
  public:
    virtual void f0();
    virtual void Release();
};
class CUninterruptibleAction {
  public:
    volatile hulk_intptr vptr;
    char pad[0x18];
    volatile Ref_224a0* mRef;
    CUninterruptibleAction* f2(unsigned char flags);
    void Cleanup_002326a0();
};
extern void __cdecl thunk_FUN_00267090(CUninterruptibleAction*);
extern void* g_vftable_224e0[];
class Ref_224e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_224e0 {
  public:
    void* vptr;
};
class CInvulnerableAction_224e0 : public CAction_224e0 {
  public:
    char pad[0x1c - 4];
    Ref_224e0* m;
    CInvulnerableAction_224e0* f2(unsigned char flags);
};
extern void* g_vftable_22520[];
class Ref_22520 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22520 {
  public:
    void* vptr;
};
class CRageModeAction_22520 : public CAction_22520 {
  public:
    char pad[0x18];
    Ref_22520* m;
    CRageModeAction_22520* f2(unsigned char flags);
};


// 0x00022340 CJumpAttackAction::vfunc_2 (82 B): matches/0x00022340.cpp
// sym: ?f2@CJumpAttackAction_22340@fn_f327212d@@QAEPAV12@E@Z
CJumpAttackAction_22340* CJumpAttackAction_22340::f2(unsigned char flags) {
    vptr = hulk_at_003f3b24;
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
    ((fight::Action *)(CAction_22340 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x000223a0 COrientAction::vfunc_2 (82 B): matches/0x000223a0.cpp
// sym: ?vfunc_2@COrientAction@fn_f327212d@@UAEPAV12@I@Z
COrientAction* COrientAction::vfunc_2(unsigned int flags) {
    *(void**)this = &hulk_at_003f3b4c;
    _ReadWriteBarrier();
    Ref_223a0* q = mFirst;
    if (q) {
        q->Release();
        mFirst = 0;
    }
    *(void**)this = &hulk_at_003f3390;
    _ReadWriteBarrier();
    q = mSecond;
    if (q) {
        q->Release();
        mSecond = 0;
    }
    helper_002326a0();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00022400 COrientTargetAction::vfunc_2 (82 B): matches/0x00022400.cpp
// sym: ?f2@COrientTargetAction_22400@fn_f327212d@@QAEPAV12@E@Z
COrientTargetAction_22400* COrientTargetAction_22400::f2(unsigned char flags) {
    vptr = gD;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    vptr = gA_22400;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_22400 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00022460 CDriftAction::vfunc_2 (57 B): matches/0x00022460.cpp
// sym: ?f2@CDriftAction_22460@fn_f327212d@@QAEPAV12@E@Z
CDriftAction_22460* CDriftAction_22460::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22460 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x000224a0 CUninterruptibleAction::vfunc_2 (57 B): matches/0x000224a0.cpp
// sym: ?f2@CUninterruptibleAction@fn_f327212d@@QAEPAV12@E@Z
CUninterruptibleAction* CUninterruptibleAction::f2(unsigned char flags) {
    vptr = ((hulk_intptr)DAT_003f3390);
    _ReadWriteBarrier();
    if (mRef) {
        ((Ref_224a0*)mRef)->Release();
        mRef = 0;
    }
    Cleanup_002326a0();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000224e0 CInvulnerableAction::vfunc_2 (57 B): matches/0x000224e0.cpp
// sym: ?f2@CInvulnerableAction_224e0@fn_f327212d@@QAEPAV12@E@Z
CInvulnerableAction_224e0* CInvulnerableAction_224e0::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_224e0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00022520 CRageModeAction::vfunc_2 (57 B): matches/0x00022520.cpp
// sym: ?f2@CRageModeAction_22520@fn_f327212d@@QAEPAV12@E@Z
CRageModeAction_22520* CRageModeAction_22520::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22520 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f327212d

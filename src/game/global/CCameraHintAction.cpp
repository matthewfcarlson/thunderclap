// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000221a0..0x00022340 (kind game, layer game, confidence medium), dominant class CCameraHintAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ffe756aa {
#define TREE_TU_END }
namespace fn_ffe756aa {} using namespace fn_ffe756aa;
namespace fn_ffe756aa { extern "C" char DAT_003f3390[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ffe756aa {
class Ref_221a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CMotionTrailAction {
  public:
    virtual void V0();
    virtual void V1();
    virtual CMotionTrailAction* vfunc_2(int);
    char pad[0x18];
    Ref_221a0* mRef;
};
extern void* hulk_at_003f3390;
class CCameraHintAction_221a0 {
  public:
    void Destroy_002326a0();
};
void __cdecl thunk_0008d330(CMotionTrailAction*);
extern void* hulk_at_003f3a5c[];
class Ref_221e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_221e0 {
  public:
    void* vptr;
};
class CEffectAction_221e0 : public CAction_221e0 {
  public:
    char pad[0x18];
    Ref_221e0* m1c;
    char pad2[4];
    Ref_221e0* m24;
    CEffectAction_221e0* f2(unsigned char flags);
};
extern void* g_vftable_22240[];
class Ref_22240 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22240 {
  public:
    void* vptr;
};
class CEffectStopAction_22240 : public CAction_22240 {
  public:
    char pad[0x1c - 4];
    Ref_22240* m1c;
    CEffectStopAction_22240* f2(unsigned char flags);
};
extern void* g_vftable_22280[];
class Ref_22280 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22280 {
  public:
    void* vptr;
};
class CCameraShakeAction_22280 : public CAction_22280 {
  public:
    char pad[24];
    Ref_22280* m;
    CCameraShakeAction_22280* f2(unsigned char flags);
};
extern void* g_vftable_222c0[];
class Ref_222c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_222c0 {
  public:
    void* vptr;
};
class CCameraDramaticAction_222c0 : public CAction_222c0 {
  public:
    char pad[0x1c - 4];
    Ref_222c0* m;
    CCameraDramaticAction_222c0* f2(unsigned char flags);
};
extern void* g_vftable_22300[];
class Ref_22300 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22300 {
  public:
    void* vptr;
};
class CCameraHintAction_22300 : public CAction_22300 {
  public:
    char pad[0x1c - 4];
    Ref_22300* m;
    CCameraHintAction_22300* f2(unsigned char flags);
};


// 0x000221a0 CMotionTrailAction::vfunc_2 (57 B): matches/0x000221a0.cpp
// sym: ?vfunc_2@CMotionTrailAction@fn_ffe756aa@@UAEPAV12@H@Z
CMotionTrailAction* CMotionTrailAction::vfunc_2(int flags) {
    *(void**)this = &hulk_at_003f3390;
    _ReadWriteBarrier();
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    ((CCameraHintAction_221a0*)this)->Destroy_002326a0();
    if (flags & 1)
        thunk_0008d330(this);
    return this;
}


// 0x000221e0 CEffectAction::vfunc_2 (82 B): matches/0x000221e0.cpp
// sym: ?f2@CEffectAction_221e0@fn_ffe756aa@@QAEPAV12@E@Z
CEffectAction_221e0* CEffectAction_221e0::f2(unsigned char flags) {
    vptr = hulk_at_003f3a5c;
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
    ((fight::Action *)(CAction_221e0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00022240 CEffectStopAction::vfunc_2 (57 B): matches/0x00022240.cpp
// sym: ?f2@CEffectStopAction_22240@fn_ffe756aa@@QAEPAV12@E@Z
CEffectStopAction_22240* CEffectStopAction_22240::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_22240 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00022280 CCameraShakeAction::vfunc_2 (57 B): matches/0x00022280.cpp
// sym: ?f2@CCameraShakeAction_22280@fn_ffe756aa@@QAEPAV12@E@Z
CCameraShakeAction_22280* CCameraShakeAction_22280::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22280 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x000222c0 CCameraDramaticAction::vfunc_2 (57 B): matches/0x000222c0.cpp
// sym: ?f2@CCameraDramaticAction_222c0@fn_ffe756aa@@QAEPAV12@E@Z
CCameraDramaticAction_222c0* CCameraDramaticAction_222c0::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_222c0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00022300 CCameraHintAction::vfunc_2 (57 B): matches/0x00022300.cpp
// sym: ?f2@CCameraHintAction_22300@fn_ffe756aa@@QAEPAV12@E@Z
CCameraHintAction_22300* CCameraHintAction_22300::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22300 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_ffe756aa

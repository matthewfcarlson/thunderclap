// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001eff0..0x0001fab0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fcc81091 {
#define TREE_TU_END }
namespace fn_fcc81091 {} using namespace fn_fcc81091;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fcc81091 {
class Base_1eff0 {
  public:
    virtual void Fn();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    virtual void G();
    char pad[0x18];
    Base_1eff0* mRef;
    int mValue;
    int mOther;
};
class CSmartPropSpawnAction : public CAction {
  public:
    CSmartPropSpawnAction(int, Base_1eff0*);
    virtual void A();
};
extern int hulk_at_003f3390;
extern int hulk_at_003f386c;
class RefObj_1f040 {
  public:
    virtual void v0();
    virtual void Release();
};
struct Tidier {
    void Tidy_002326a0();
};
class CSmartPropUpdateAttachmentAction {
  public:
    char pad[0x1c];
    RefObj_1f040* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_1f040* volatile mB; // 0x24
    void Shutdown();
};
extern void* g_vftable_1f1c0[];
class Ref_1f1c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f1c0 {
  public:
    void* vptr;
};
class CAction_1f1c0 : public Action_1f1c0 {
  public:
    char pad[24];
    Ref_1f1c0* m;
    ~CAction_1f1c0();
};
extern void* g_vftable_1f230[];
class Ref_1f230 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1f230 {
  public:
    void* vptr;
};
class Action : public Base_1f230 {
  public:
    char pad1c[0x18];
    Ref_1f230* m1c;
    ~Action();
};
extern void* g_vftable_1f2b0[];
class Ref_1f2b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f2b0 {
  public:
    void* vptr;
};
class CAction_1f2b0 : public Action_1f2b0 {
  public:
    char pad1c[0x18];
    Ref_1f2b0* m1c;
    ~CAction_1f2b0();
};
extern void* g_vftable_1f330[];
class Ref_1f330 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f330 {
  public:
    void* vptr;
};
class CAction_1f330 : public Action_1f330 {
  public:
    char pad[24];
    Ref_1f330* m;
    ~CAction_1f330();
};
extern void* g_vftable_1f3b0[];
class Ref_1f3b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f3b0 {
  public:
    void* vptr;
};
class CAction_1f3b0 : public Action_1f3b0 {
  public:
    char pad[0x18];
    Ref_1f3b0* m1c;
    ~CAction_1f3b0();
};
extern void* g_vftable_1f430[];
class Ref_1f430 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f430 {
  public:
    void* vptr;
};
class CAction_1f430 : public Action_1f430 {
  public:
    char pad1c[0x18];
    Ref_1f430* m1c;
    ~CAction_1f430();
};
extern void* g_vftable_1f4b0[];
class Ref_1f4b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f4b0 {
  public:
    void* vptr;
};
class CAction_1f4b0 : public Action_1f4b0 {
  public:
    char pad[24];
    Ref_1f4b0* m;
    ~CAction_1f4b0();
};
extern void* g_vftable_1f530[];
class Ref_1f530 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f530 {
  public:
    void* vptr;
};
class CAction_1f530 : public Action_1f530 {
  public:
    char pad[0x18];
    Ref_1f530* m1c;
    ~CAction_1f530();
};
extern void* g_vftable_1f5a0[];
class Ref_1f5a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f5a0 {
  public:
    void* vptr;
};
class CAction_1f5a0 : public Action_1f5a0 {
  public:
    char pad[24];
    Ref_1f5a0* m;
    ~CAction_1f5a0();
};
extern void* g_vftable_1f610[];
class Ref_1f610 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f610 {
  public:
    void* vptr;
};
class CAction_1f610 : public Action_1f610 {
  public:
    char pad1c[0x18];
    Ref_1f610* m1c;
    ~CAction_1f610();
};
extern void* g_vftable_1f690[];
class Ref_1f690 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f690 {
  public:
    void* vptr;
};
class CAction_1f690 : public Action_1f690 {
  public:
    char pad[24];
    Ref_1f690* m;
    ~CAction_1f690();
};
extern "C" char DAT_003f3a5c[];
struct RefObj_1f6c0 {
    virtual void addRef();
    virtual void release();
};
struct CEffectAction {
    hulk_intptr vptr;
    char pad04[0x18];
    RefObj_1f6c0 *f1c;
    int f20;
    RefObj_1f6c0 *f24;
    int f28;
    void FUN_00232660();
    CEffectAction *FUN_0001f6c0(int a, RefObj_1f6c0 *b, RefObj_1f6c0 *c);
};
extern void* g_vftable_1f7d0[];
class Ref_1f7d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f7d0 {
  public:
    void* vptr;
};
class CAction_1f7d0 : public Action_1f7d0 {
  public:
    char pad[24];
    Ref_1f7d0* m;
    ~CAction_1f7d0();
};
extern void* g_vftable_1f850[];
class Ref_1f850 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f850 {
  public:
    void* vptr;
};
class CAction_1f850 : public Action_1f850 {
  public:
    char pad[24];
    Ref_1f850* m;
    ~CAction_1f850();
};
extern void* g_vftable_1f8d0[];
class Ref_1f8d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f8d0 {
  public:
    void* vptr;
};
class CAction_1f8d0 : public Action_1f8d0 {
  public:
    char pad1c[0x18];
    Ref_1f8d0* m1c;
    ~CAction_1f8d0();
};
extern void* g_vftable_1f950[];
class Ref_1f950 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1f950 {
  public:
    void* vptr;
};
class CAction_1f950 : public Action_1f950 {
  public:
    char pad1c[0x18];
    Ref_1f950* m1c;
    ~CAction_1f950();
};


// 0x0001eff0 FUN_0001eff0 (78 B): matches/0x0001eff0.cpp
// sym: ??0CSmartPropSpawnAction@fn_fcc81091@@QAE@HPAVBase_1eff0@1@@Z
CSmartPropSpawnAction::CSmartPropSpawnAction(int value, Base_1eff0* ref) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f3390;
    mRef = 0;
    if (ref)
        ref->Fn();
    if (mRef)
        mRef->Release();
    mRef = ref;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f386c;
    mOther = 0;
}


// 0x0001f040 FUN_0001f040 (61 B): matches/0x0001f040.cpp
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_fcc81091@@QAEXXZ
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)vftableD;
    RefObj_1f040* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_1f040* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f170 FUN_0001f170 (71 B): matches/0x0001f170.cpp [wrapped: merged class would differ: CAction: size 40 vs 36]
// sym: ??0CSmartPropSetStateAction_1f170@fn_0001f170@@QAE@HPAVIRef_1f170@1@@Z
namespace fn_0001f170 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1f170 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1f170 {
  public:
    virtual void VFunc();
    Action_1f170();
};

class CAction : public Action_1f170 {
  public:
    char m_pad[0x18];
    IRef_1f170* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1f170* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CSmartPropSetStateAction_1f170 : public CAction {
  public:
    virtual void ProcessDrift();
    CSmartPropSetStateAction_1f170(int a, IRef_1f170* p);
};

CSmartPropSetStateAction_1f170::CSmartPropSetStateAction_1f170(int a, IRef_1f170* p) : CAction(a, p) {}
} // namespace fn_0001f170

namespace fn_fcc81091 {

// 0x0001f1c0 FUN_0001f1c0 (36 B): matches/0x0001f1c0.cpp
// sym: ??1CAction_1f1c0@fn_fcc81091@@QAE@XZ
CAction_1f1c0::~CAction_1f1c0() {
    vptr = g_vftable_1f1c0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1f1c0 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f1f0 FUN_0001f1f0 (64 B): matches/0x0001f1f0.cpp [wrapped: merged class would differ: CSmartPropDetachAction_1f1f0: virtual V0 missing]
// sym: ??0CSmartPropDetachAction_1f1f0@fn_0001f1f0@@QAE@PAVActor_1f1f0@1@@Z
namespace fn_0001f1f0 {
// Same code shape as 0x0001f5d0 (propagated; names are from that function)
class Actor_1f1f0 {
  public:
    virtual void V0();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void V0();
    char pad[0x18];
    Actor_1f1f0* mActor;
};
class CSmartPropDetachAction_1f1f0 : public CAction {
  public:
    CSmartPropDetachAction_1f1f0(Actor_1f1f0*);
    virtual void V1();
};
extern int vtAction;
extern int hulk_at_003f38cc;
CSmartPropDetachAction_1f1f0::CSmartPropDetachAction_1f1f0(Actor_1f1f0* a) {
    *(hulk_intptr*)this = (hulk_intptr)&vtAction;
    mActor = 0;
    if (a)
        a->V0();
    if (mActor)
        mActor->Release();
    mActor = a;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f38cc;
}
} // namespace fn_0001f1f0

namespace fn_fcc81091 {

// 0x0001f230 FUN_0001f230 (36 B): matches/0x0001f230.cpp
// sym: ??1Action@fn_fcc81091@@QAE@XZ
Action::~Action() {
    vptr = g_vftable_1f230;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Base_1f230 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f260 FUN_0001f260 (71 B): matches/0x0001f260.cpp [wrapped: merged class would differ: CAction: size 40 vs 36]
// sym: ??0CSmartPropThrowAction_1f260@fn_0001f260@@QAE@HPAVIRef_1f260@1@@Z
namespace fn_0001f260 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1f260 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1f260 {
  public:
    virtual void VFunc();
    Action_1f260();
};

class CAction : public Action_1f260 {
  public:
    char m_pad[0x18];
    IRef_1f260* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1f260* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CSmartPropThrowAction_1f260 : public CAction {
  public:
    virtual void ProcessDrift();
    CSmartPropThrowAction_1f260(int a, IRef_1f260* p);
};

CSmartPropThrowAction_1f260::CSmartPropThrowAction_1f260(int a, IRef_1f260* p) : CAction(a, p) {}
} // namespace fn_0001f260

namespace fn_fcc81091 {

// 0x0001f2b0 FUN_0001f2b0 (36 B): matches/0x0001f2b0.cpp
// sym: ??1CAction_1f2b0@fn_fcc81091@@QAE@XZ
CAction_1f2b0::~CAction_1f2b0() {
    vptr = g_vftable_1f2b0;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1f2b0 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f2e0 FUN_0001f2e0 (71 B): matches/0x0001f2e0.cpp [wrapped: merged class would differ: CAction: size 40 vs 36]
// sym: ??0CSmartPropThrowingAction_1f2e0@fn_0001f2e0@@QAE@HPAVIRef_1f2e0@1@@Z
namespace fn_0001f2e0 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1f2e0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1f2e0 {
  public:
    virtual void VFunc();
    Action_1f2e0();
};

class CAction : public Action_1f2e0 {
  public:
    char m_pad[0x18];
    IRef_1f2e0* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1f2e0* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CSmartPropThrowingAction_1f2e0 : public CAction {
  public:
    virtual void ProcessDrift();
    CSmartPropThrowingAction_1f2e0(int a, IRef_1f2e0* p);
};

CSmartPropThrowingAction_1f2e0::CSmartPropThrowingAction_1f2e0(int a, IRef_1f2e0* p) : CAction(a, p) {}
} // namespace fn_0001f2e0

namespace fn_fcc81091 {

// 0x0001f330 FUN_0001f330 (36 B): matches/0x0001f330.cpp
// sym: ??1CAction_1f330@fn_fcc81091@@QAE@XZ
CAction_1f330::~CAction_1f330() {
    vptr = g_vftable_1f330;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1f330 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f360 FUN_0001f360 (71 B): matches/0x0001f360.cpp [wrapped: merged class would differ: CAction: size 40 vs 36]
// sym: ??0CSmartPropDropAction_1f360@fn_0001f360@@QAE@HPAVIRef_1f360@1@@Z
namespace fn_0001f360 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1f360 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1f360 {
  public:
    virtual void VFunc();
    Action_1f360();
};

class CAction : public Action_1f360 {
  public:
    char m_pad[0x18];
    IRef_1f360* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1f360* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CSmartPropDropAction_1f360 : public CAction {
  public:
    virtual void ProcessDrift();
    CSmartPropDropAction_1f360(hulk_intptr a, IRef_1f360* p);
};

CSmartPropDropAction_1f360::CSmartPropDropAction_1f360(hulk_intptr a, IRef_1f360* p) : CAction(a, p) {}
} // namespace fn_0001f360

namespace fn_fcc81091 {

// 0x0001f3b0 FUN_0001f3b0 (36 B): matches/0x0001f3b0.cpp
// sym: ??1CAction_1f3b0@fn_fcc81091@@QAE@XZ
CAction_1f3b0::~CAction_1f3b0() {
    vptr = g_vftable_1f3b0;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1f3b0 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f3e0 FUN_0001f3e0 (78 B): matches/0x0001f3e0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CSmartPropEventAction@fn_0001f3e0@@QAE@PAVRef@1@HH@Z
namespace fn_0001f3e0 {
class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Root {
  public:
    Root();
    virtual void Run();
    char pad[24];
};
class CSmartPropEventAction_1f3e0 : public Root {
  public:
    CSmartPropEventAction_1f3e0(Ref* r, int b);
    virtual void Run();
    Ref* ref;
    int x;
};
class CSmartPropEventAction : public CSmartPropEventAction_1f3e0 {
  public:
    CSmartPropEventAction(Ref* r, int a, int b);
    virtual void Run();
    int y;
};
CSmartPropEventAction_1f3e0::CSmartPropEventAction_1f3e0(Ref* r, int b) {
    ref = 0;
    if (r)
        r->Add();
    if (ref)
        ref->Release();
    ref = r;
    x = b;
}
CSmartPropEventAction::CSmartPropEventAction(Ref* r, int a, int b) : CSmartPropEventAction_1f3e0(r, b) {
    y = a;
}
} // namespace fn_0001f3e0

namespace fn_fcc81091 {

// 0x0001f430 FUN_0001f430 (36 B): matches/0x0001f430.cpp
// sym: ??1CAction_1f430@fn_fcc81091@@QAE@XZ
CAction_1f430::~CAction_1f430() {
    vptr = g_vftable_1f430;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1f430 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f460 FUN_0001f460 (71 B): matches/0x0001f460.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CSmartPropRemoveInstanceAction_1f460@fn_0001f460@@QAE@PAUObj_1f460@1@H@Z
namespace fn_0001f460 {
// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_1f460 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int hulk_at_003f3994;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_1f460* mObj;
    int mValue;
};
class CSmartPropRemoveInstanceAction_1f460 : public CAction {
  public:
    CSmartPropRemoveInstanceAction_1f460(Obj_1f460*, int);
    virtual void V0();
};
CSmartPropRemoveInstanceAction_1f460::CSmartPropRemoveInstanceAction_1f460(Obj_1f460* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f3994;
}
void CSmartPropRemoveInstanceAction_1f460::V0() {}
} // namespace fn_0001f460

namespace fn_fcc81091 {

// 0x0001f4b0 FUN_0001f4b0 (36 B): matches/0x0001f4b0.cpp
// sym: ??1CAction_1f4b0@fn_fcc81091@@QAE@XZ
CAction_1f4b0::~CAction_1f4b0() {
    vptr = g_vftable_1f4b0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1f4b0 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f4e0 FUN_0001f4e0 (71 B): matches/0x0001f4e0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CInvincibleAction_1f4e0@fn_0001f4e0@@QAE@PAUObj_1f4e0@1@H@Z
namespace fn_0001f4e0 {
// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_1f4e0 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int hulk_at_003f39bc;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_1f4e0* mObj;
    int mValue;
};
class CInvincibleAction_1f4e0 : public CAction {
  public:
    CInvincibleAction_1f4e0(Obj_1f4e0*, int);
    virtual void V0();
};
CInvincibleAction_1f4e0::CInvincibleAction_1f4e0(Obj_1f4e0* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f39bc;
}
void CInvincibleAction_1f4e0::V0() {}
} // namespace fn_0001f4e0

namespace fn_fcc81091 {

// 0x0001f530 FUN_0001f530 (36 B): matches/0x0001f530.cpp
// sym: ??1CAction_1f530@fn_fcc81091@@QAE@XZ
CAction_1f530::~CAction_1f530() {
    vptr = g_vftable_1f530;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1f530 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f560 FUN_0001f560 (64 B): matches/0x0001f560.cpp [wrapped: conflict: CAction]
// sym: ??0CIntangibleAction_1f560@fn_0001f560@@QAE@PAVActor_1f560@1@@Z
namespace fn_0001f560 {
// Same code shape as 0x0001f5d0 (propagated; names are from that function)
class Actor_1f560 {
  public:
    virtual void V0();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void V0();
    char pad[0x18];
    Actor_1f560* mActor;
};
class CIntangibleAction_1f560 : public CAction {
  public:
    CIntangibleAction_1f560(Actor_1f560*);
    virtual void V1();
};
extern int vtAction;
extern int hulk_at_003f39e4;
CIntangibleAction_1f560::CIntangibleAction_1f560(Actor_1f560* a) {
    *(hulk_intptr*)this = (hulk_intptr)&vtAction;
    mActor = 0;
    if (a)
        a->V0();
    if (mActor)
        mActor->Release();
    mActor = a;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f39e4;
}
} // namespace fn_0001f560

namespace fn_fcc81091 {

// 0x0001f5a0 FUN_0001f5a0 (36 B): matches/0x0001f5a0.cpp
// sym: ??1CAction_1f5a0@fn_fcc81091@@QAE@XZ
CAction_1f5a0::~CAction_1f5a0() {
    vptr = g_vftable_1f5a0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1f5a0 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f5d0 FUN_0001f5d0 (64 B): matches/0x0001f5d0.cpp [wrapped: conflict: CAction]
// sym: ??0CIntangibleToActorsAction@fn_0001f5d0@@QAE@PAVActor_1f5d0@1@@Z
namespace fn_0001f5d0 {
class Actor_1f5d0 {
  public:
    virtual void V0();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void V0();
    char pad[0x18];
    Actor_1f5d0* mActor;
};
class CIntangibleToActorsAction : public CAction {
  public:
    CIntangibleToActorsAction(Actor_1f5d0*);
    virtual void V1();
};
extern int vtAction;
extern int hulk_at_003f3a0c;
CIntangibleToActorsAction::CIntangibleToActorsAction(Actor_1f5d0* a) {
    *(hulk_intptr*)this = (hulk_intptr)&vtAction;
    mActor = 0;
    if (a)
        a->V0();
    if (mActor)
        mActor->Release();
    mActor = a;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f3a0c;
}
} // namespace fn_0001f5d0

namespace fn_fcc81091 {

// 0x0001f610 FUN_0001f610 (36 B): matches/0x0001f610.cpp
// sym: ??1CAction_1f610@fn_fcc81091@@QAE@XZ
CAction_1f610::~CAction_1f610() {
    vptr = g_vftable_1f610;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1f610 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f640 FUN_0001f640 (78 B): matches/0x0001f640.cpp [wrapped: merged class would differ: CMotionTrailAction: field m1c: Field(+0x40 Ref_1f640 * m1c) vs Field(+0x1c Ref_1f640 * m1c)]
// sym: ??0CMotionTrailAction@fn_0001f640@@QAE@HPAVRef_1f640@1@@Z
namespace fn_0001f640 {
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3a34[];
class Ref_1f640 {
  public:
    virtual void F();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void F();
    virtual void R();
};
class CMotionTrailAction : public CAction {
  public:
    virtual void F();
    virtual void R();
    char pad08[0x18];
    Ref_1f640* m1c;
    int m20;
    int m24;
    CMotionTrailAction(int, Ref_1f640*);
};
CMotionTrailAction::CMotionTrailAction(int b, Ref_1f640* a) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f3390);
    int* q = (int*)&m1c;
    *q = 0;
    if (a)
        a->F();
    if (m1c)
        m1c->Release();
    m1c = a;
    m20 = b;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f3a34);
    m24 = 0;
}
} // namespace fn_0001f640

namespace fn_fcc81091 {

// 0x0001f690 FUN_0001f690 (36 B): matches/0x0001f690.cpp
// sym: ??1CAction_1f690@fn_fcc81091@@QAE@XZ
CAction_1f690::~CAction_1f690() {
    vptr = g_vftable_1f690;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1f690 *)this)->FUN_002326a0();
}


// 0x0001f6c0 FUN_0001f6c0 (114 B): matches/0x0001f6c0.cpp
// sym: ?FUN_0001f6c0@CEffectAction@fn_fcc81091@@QAEPAU12@HPAURefObj_1f6c0@2@0@Z
// FUN_0001f6c0 @ 0x0001f6c0
CEffectAction *CEffectAction::FUN_0001f6c0(int a, RefObj_1f6c0 *b, RefObj_1f6c0 *c)
{
    FUN_00232660();
    vptr = (hulk_intptr)DAT_003f3390;
    f1c = 0;
    if (b)
        b->addRef();
    if (f1c)
        f1c->release();
    f1c = b;
    vptr = (hulk_intptr)DAT_003f3a5c;
    f24 = 0;
    f28 = 0;
    f20 = a;
    if (c)
        c->addRef();
    if (f24)
        f24->release();
    f24 = c;
    return this;
}

} // namespace fn_fcc81091

// 0x0001f740 FUN_0001f740 (61 B): matches/0x0001f740.cpp [wrapped: conflict: CSmartPropUpdateAttachmentAction]
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_0001f740@@QAEXXZ
namespace fn_0001f740 {
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char hulk_at_003f3a5c[];
extern char vftableA[];

class RefObj_1f740 {
  public:
    virtual void v0();
    virtual void Release();
};

struct Tidier {
    void Tidy_002326a0();
};

class CSmartPropUpdateAttachmentAction {
  public:
    char pad[0x1c];
    RefObj_1f740* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_1f740* volatile mB; // 0x24
    void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)hulk_at_003f3a5c;
    RefObj_1f740* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_1f740* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}
} // namespace fn_0001f740


// 0x0001f780 FUN_0001f780 (71 B): matches/0x0001f780.cpp [wrapped: merged class would differ: CAction: size 40 vs 36]
// sym: ??0CEffectStopAction_1f780@fn_0001f780@@QAE@HPAVIRef_1f780@1@@Z
namespace fn_0001f780 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1f780 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1f780 {
  public:
    virtual void VFunc();
    Action_1f780();
};

class CAction : public Action_1f780 {
  public:
    char m_pad[0x18];
    IRef_1f780* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1f780* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CEffectStopAction_1f780 : public CAction {
  public:
    virtual void ProcessDrift();
    CEffectStopAction_1f780(int a, IRef_1f780* p);
};

CEffectStopAction_1f780::CEffectStopAction_1f780(int a, IRef_1f780* p) : CAction(a, p) {}
} // namespace fn_0001f780

namespace fn_fcc81091 {

// 0x0001f7d0 FUN_0001f7d0 (36 B): matches/0x0001f7d0.cpp
// sym: ??1CAction_1f7d0@fn_fcc81091@@QAE@XZ
CAction_1f7d0::~CAction_1f7d0() {
    vptr = g_vftable_1f7d0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1f7d0 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f800 FUN_0001f800 (71 B): matches/0x0001f800.cpp [wrapped: merged class would differ: CAction: size 40 vs 36]
// sym: ??0CCameraShakeAction_1f800@fn_0001f800@@QAE@HPAVIRef_1f800@1@@Z
namespace fn_0001f800 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1f800 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1f800 {
  public:
    virtual void VFunc();
    Action_1f800();
};

class CAction : public Action_1f800 {
  public:
    char m_pad[0x18];
    IRef_1f800* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1f800* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CCameraShakeAction_1f800 : public CAction {
  public:
    virtual void ProcessDrift();
    CCameraShakeAction_1f800(int a, IRef_1f800* p);
};

CCameraShakeAction_1f800::CCameraShakeAction_1f800(int a, IRef_1f800* p) : CAction(a, p) {}
} // namespace fn_0001f800

namespace fn_fcc81091 {

// 0x0001f850 FUN_0001f850 (36 B): matches/0x0001f850.cpp
// sym: ??1CAction_1f850@fn_fcc81091@@QAE@XZ
CAction_1f850::~CAction_1f850() {
    vptr = g_vftable_1f850;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1f850 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f880 FUN_0001f880 (78 B): matches/0x0001f880.cpp [wrapped: conflict: CAction]
// sym: ??0CCameraDramaticAction@fn_0001f880@@QAE@HPAURef_1f880@1@@Z
namespace fn_0001f880 {
struct Ref_1f880 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_1f880 {
    Action_1f880() throw();
    virtual void V0();
    char pad04[0x18];
};
struct CAction : Action_1f880 {
    Ref_1f880* m1c;
    int m20;
    CAction(Ref_1f880* r, int a) {
        Ref_1f880** q = &m1c;
        *q = 0;
        if (r)
            r->AddRef();
        if (m1c)
            m1c->Release();
        m1c = r;
        m20 = a;
    }
    virtual void V0();
};
struct CCameraDramaticAction : CAction {
    int m24;
    CCameraDramaticAction(int a, Ref_1f880* r);
    virtual void V0();
};
CCameraDramaticAction::CCameraDramaticAction(int a, Ref_1f880* r) : CAction(r, a) {
    m24 = 0;
}
} // namespace fn_0001f880

namespace fn_fcc81091 {

// 0x0001f8d0 FUN_0001f8d0 (36 B): matches/0x0001f8d0.cpp
// sym: ??1CAction_1f8d0@fn_fcc81091@@QAE@XZ
CAction_1f8d0::~CAction_1f8d0() {
    vptr = g_vftable_1f8d0;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1f8d0 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f900 FUN_0001f900 (71 B): matches/0x0001f900.cpp [wrapped: merged class would differ: CAction: size 40 vs 36]
// sym: ??0CCameraHintAction_1f900@fn_0001f900@@QAE@HPAVIRef_1f900@1@@Z
namespace fn_0001f900 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1f900 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1f900 {
  public:
    virtual void VFunc();
    Action_1f900();
};

class CAction : public Action_1f900 {
  public:
    char m_pad[0x18];
    IRef_1f900* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1f900* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CCameraHintAction_1f900 : public CAction {
  public:
    virtual void ProcessDrift();
    CCameraHintAction_1f900(int a, IRef_1f900* p);
};

CCameraHintAction_1f900::CCameraHintAction_1f900(int a, IRef_1f900* p) : CAction(a, p) {}
} // namespace fn_0001f900

namespace fn_fcc81091 {

// 0x0001f950 FUN_0001f950 (36 B): matches/0x0001f950.cpp
// sym: ??1CAction_1f950@fn_fcc81091@@QAE@XZ
CAction_1f950::~CAction_1f950() {
    vptr = g_vftable_1f950;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1f950 *)this)->FUN_002326a0();
}

} // namespace fn_fcc81091

// 0x0001f980 FUN_0001f980 (83 B): equivalent/0x0001f980.cpp [wrapped: conflict: CAction]
// sym: ?FUN_0001f980@CJumpAttackAction@fn_0001f980@@QAEPAU12@PAXPAURef@2@@Z
inline void* operator new(size_t, void* place) { return place; }
namespace fn_0001f980 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0001f980 @ 0x0001f980

struct Ref { virtual void FUN_00000000(); virtual void FUN_00000001(); };
struct CAction {
    virtual void slot0();
    char pad[0x18];
    Ref* reference;
    void* data;
    void FUN_00232660();
};
struct CJumpAttackAction : CAction {
    void* field24;
    void* field28;
    void* field2c;
    void* field30;
    CJumpAttackAction* FUN_0001f980(void* value, Ref* ref);
};
CJumpAttackAction* CJumpAttackAction::FUN_0001f980(void* value, Ref* ref) {
    FUN_00232660();
    new ((CAction*)this) CAction;
    reference = 0;
    if (ref) ref->FUN_00000000();
    if (reference) reference->FUN_00000001();
    reference = ref;
    field24 = 0;
    new (this) CJumpAttackAction;
    field28 = 0;
    field2c = 0;
    field30 = 0;
    data = value;
    return this;
}
} // namespace fn_0001f980


// 0x0001f9e0 FUN_0001f9e0 (61 B): matches/0x0001f9e0.cpp [wrapped: conflict: CSmartPropUpdateAttachmentAction]
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_0001f9e0@@QAEXXZ
namespace fn_0001f9e0 {
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char hulk_at_003f3b24[];
extern char vftableA[];

class RefObj_1f9e0 {
  public:
    virtual void v0();
    virtual void Release();
};

struct Tidier {
    void Tidy_002326a0();
};

class CSmartPropUpdateAttachmentAction {
  public:
    char pad[0x1c];
    RefObj_1f9e0* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_1f9e0* volatile mB; // 0x24
    void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)hulk_at_003f3b24;
    RefObj_1f9e0* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_1f9e0* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}
} // namespace fn_0001f9e0


// 0x0001fa20 FUN_0001fa20 (78 B): matches/0x0001fa20.cpp [wrapped: conflict: CAction]
// sym: ??0COrientAction@fn_0001fa20@@QAE@HPAVRef@1@@Z
namespace fn_0001fa20 {
class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1fa20 {
  public:
    Action_1fa20();
    virtual void v0();
};
class CAction : public Action_1fa20 {
  public:
    CAction(Ref* r);
    virtual void v0();
    char pad[0x18];
    Ref* ref;
    int value;
};
class COrientAction : public CAction {
  public:
    COrientAction(int n, Ref* r);
    virtual void v0();
    int extra;
};
inline CAction::CAction(Ref* r) : Action_1fa20() {
    ref = 0;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
}
COrientAction::COrientAction(int n, Ref* r) : CAction(r) {
    value = n;
    extra = 0;
}
} // namespace fn_0001fa20


// 0x0001fa70 FUN_0001fa70 (61 B): matches/0x0001fa70.cpp [wrapped: conflict: CSmartPropUpdateAttachmentAction]
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_0001fa70@@QAEXXZ
namespace fn_0001fa70 {
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char hulk_at_003f3b4c[];
extern char vftableA[];

class RefObj_1fa70 {
  public:
    virtual void v0();
    virtual void Release();
};

struct Tidier {
    void Tidy_002326a0();
};

class CSmartPropUpdateAttachmentAction {
  public:
    char pad[0x1c];
    RefObj_1fa70* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_1fa70* volatile mB; // 0x24
    void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)hulk_at_003f3b4c;
    RefObj_1fa70* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_1fa70* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}
} // namespace fn_0001fa70


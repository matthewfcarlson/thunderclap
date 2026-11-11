// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00020a40..0x00020de0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fe1a35b1 {
#define TREE_TU_END }
namespace fn_fe1a35b1 {} using namespace fn_fe1a35b1;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe1a35b1 {
class Param {
  public:
    virtual void Add();
    virtual void Drop();
};
struct ThisCall_00232660 {
    void BaseInit_00232660();
};
class CHapticEventAction_20a40 {
  public:
    void* v;
    char pad[0x18];
    Param* p;
    volatile int value;
    CHapticEventAction_20a40* ctor(int value, Param* p);
};
extern void* hulk_at_003f3390[];
class Ref_20b20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20b20 {
  public:
    void* vptr;
};
class CAction_20b20 : public Action_20b20 {
  public:
    char pad[24];
    Ref_20b20* m;
    ~CAction_20b20();
};
extern "C" char DAT_003f3ce0[];
class Arg_20b50 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    hulk_intptr vf;
    char pad[0x18];
    Arg_20b50* mArg;
};
class CDeathAction : public CAction {
  public:
    CDeathAction(Arg_20b50*);
};
extern void* g_vftable_20b90[];
class Ref_20b90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20b90 {
  public:
    void* vptr;
};
class CAction_20b90 : public Action_20b90 {
  public:
    char pad[24];
    Ref_20b90* m;
    ~CAction_20b90();
};
extern void* g_vftable_20c10[];
class Ref_20c10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20c10 {
  public:
    void* vptr;
};
class CAction_20c10 : public Action_20c10 {
  public:
    char pad[24];
    Ref_20c10* m;
    ~CAction_20c10();
};
class RefObj_20c90 {
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
    RefObj_20c90* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_20c90* volatile mB; // 0x24
    void Shutdown();
};
extern void* g_vftable_20d20[];
class Ref_20d20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20d20 {
  public:
    void* vptr;
};
class CAction_20d20 : public Action_20d20 {
  public:
    char pad[24];
    Ref_20d20* m;
    ~CAction_20d20();
};


// 0x00020a40 FUN_00020a40 (78 B): matches/0x00020a40.cpp
// sym: ?ctor@CHapticEventAction_20a40@fn_fe1a35b1@@QAEPAV12@HPAVParam@2@@Z
CHapticEventAction_20a40* CHapticEventAction_20a40::ctor(int value, Param* p) {
    ((ThisCall_00232660*)(this))->BaseInit_00232660();
    v = (void*)((hulk_intptr)DAT_003f3390);
    this->p = 0;
    if (p)
        p->Add();
    if (this->p)
        this->p->Drop();
    *(Param* volatile*)&this->p = p;
    *(void* volatile*)&v = (void*)((hulk_intptr)DAT_003f3c90);
    this->value = 0;
    this->value = value;
    return this;
}

} // namespace fn_fe1a35b1

// 0x00020a90 FUN_00020a90 (56 B): matches/0x00020a90.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ?Dtor@CHapticEventAction_20a90@fn_00020a90@@QAEXXZ
namespace fn_00020a90 {
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3c90[];
extern "C" void _ReadWriteBarrier();
struct Ref_20a90 {
    virtual void f0();
    virtual void Release();
};
struct CHapticEventAction_20a90;
void __fastcall BaseDtor_002326a0(CHapticEventAction_20a90* p);
struct CHapticEventAction_20a90 {
    virtual void a0();
    virtual void a1();
    char pad[0x18];
    Ref_20a90* mRef;
    int mUnknown;
    void Dtor();
};
void CHapticEventAction_20a90::a0() {}
void CHapticEventAction_20a90::a1() {}
void CHapticEventAction_20a90::Dtor() {
    *(void**)this = (void*)((hulk_intptr)DAT_003f3c90);
    _ReadWriteBarrier();
    if (mUnknown)
        mUnknown = 0;
    *(void**)this = (void*)((hulk_intptr)DAT_003f3390);
    _ReadWriteBarrier();
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    BaseDtor_002326a0(this);
}
} // namespace fn_00020a90


// 0x00020ad0 FUN_00020ad0 (71 B): matches/0x00020ad0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CAlertStatusAction_20ad0@fn_00020ad0@@QAE@PAUObj_20ad0@1@H@Z
namespace fn_00020ad0 {
// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_20ad0 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int hulk_at_003f3cb8;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_20ad0* mObj;
    int mValue;
};
class CAlertStatusAction_20ad0 : public CAction {
  public:
    CAlertStatusAction_20ad0(Obj_20ad0*, int);
    virtual void V0();
};
CAlertStatusAction_20ad0::CAlertStatusAction_20ad0(Obj_20ad0* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f3cb8;
}
void CAlertStatusAction_20ad0::V0() {}
} // namespace fn_00020ad0

namespace fn_fe1a35b1 {

// 0x00020b20 FUN_00020b20 (36 B): matches/0x00020b20.cpp
// sym: ??1CAction_20b20@fn_fe1a35b1@@QAE@XZ
CAction_20b20::~CAction_20b20() {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_20b20 *)this)->FUN_002326a0();
}


// 0x00020b50 FUN_00020b50 (64 B): matches/0x00020b50.cpp
// sym: ??0CDeathAction@fn_fe1a35b1@@QAE@PAVArg_20b50@1@@Z
CDeathAction::CDeathAction(Arg_20b50* a) {
    vf = ((hulk_intptr)DAT_003f3390);
    mArg = 0;
    if (a)
        a->AddRef();
    if (mArg)
        mArg->Release();
    mArg = a;
    vf = ((hulk_intptr)DAT_003f3ce0);
}


// 0x00020b90 FUN_00020b90 (36 B): matches/0x00020b90.cpp
// sym: ??1CAction_20b90@fn_fe1a35b1@@QAE@XZ
CAction_20b90::~CAction_20b90() {
    vptr = g_vftable_20b90;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_20b90 *)this)->FUN_002326a0();
}

} // namespace fn_fe1a35b1

// 0x00020bc0 FUN_00020bc0 (71 B): matches/0x00020bc0.cpp [wrapped: conflict: CAction]
// sym: ??0CAIHintAction_20bc0@fn_00020bc0@@QAE@HPAVIRef_20bc0@1@@Z
namespace fn_00020bc0 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_20bc0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_20bc0 {
  public:
    virtual void VFunc_00018b30();
    Action_20bc0();
};

class CAction : public Action_20bc0 {
  public:
    char m_pad[0x18];
    IRef_20bc0* m_pRef;
    int m_param;
    virtual void Process_00018b40();
    CAction(int a, IRef_20bc0* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CAIHintAction_20bc0 : public CAction {
  public:
    virtual void ProcessDrift();
    CAIHintAction_20bc0(int a, IRef_20bc0* p);
};

CAIHintAction_20bc0::CAIHintAction_20bc0(int a, IRef_20bc0* p) : CAction(a, p) {}
} // namespace fn_00020bc0

namespace fn_fe1a35b1 {

// 0x00020c10 FUN_00020c10 (36 B): matches/0x00020c10.cpp
// sym: ??1CAction_20c10@fn_fe1a35b1@@QAE@XZ
CAction_20c10::~CAction_20c10() {
    vptr = g_vftable_20c10;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_20c10 *)this)->FUN_002326a0();
}

} // namespace fn_fe1a35b1

// 0x00020c40 FUN_00020c40 (78 B): matches/0x00020c40.cpp [wrapped: conflict: CAction]
// sym: ??0CSnapToWallAction@fn_00020c40@@QAE@HPAVRef_20c40@1@@Z
namespace fn_00020c40 {
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3d30[];
class Ref_20c40 {
  public:
    virtual void F();
    virtual void G();
};
class CAction {
  public:
    CAction();
    virtual void F();
    virtual void G();
    char pad[0x1c - 4];
    Ref_20c40* mRef;
    int mValue;
    int mOther;
};
class CSnapToWallAction : public CAction {
  public:
    CSnapToWallAction(int, Ref_20c40*);
    virtual void F();
    virtual void G();
};
CSnapToWallAction::CSnapToWallAction(int v, Ref_20c40* r) {
    int* p = (int*)this;
    *(hulk_intptr*)p = ((hulk_intptr)DAT_003f3390);
    mRef = 0;
    if (r)
        r->F();
    if (mRef)
        mRef->G();
    mRef = r;
    mValue = v;
    p[0] = ((hulk_intptr)DAT_003f3d30);
    mOther = 0;
}
} // namespace fn_00020c40

namespace fn_fe1a35b1 {

// 0x00020c90 FUN_00020c90 (61 B): matches/0x00020c90.cpp
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_fe1a35b1@@QAEXXZ
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)vftableD;
    RefObj_20c90* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_20c90* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}

} // namespace fn_fe1a35b1

// 0x00020cd0 FUN_00020cd0 (71 B): matches/0x00020cd0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CMotionHitGroundHeightAction_20cd0@fn_00020cd0@@QAE@PAUObj_20cd0@1@H@Z
namespace fn_00020cd0 {
// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_20cd0 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int hulk_at_003f3d58;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_20cd0* mObj;
    int mValue;
};
class CMotionHitGroundHeightAction_20cd0 : public CAction {
  public:
    CMotionHitGroundHeightAction_20cd0(Obj_20cd0*, int);
    virtual void V0();
};
CMotionHitGroundHeightAction_20cd0::CMotionHitGroundHeightAction_20cd0(Obj_20cd0* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f3d58;
}
void CMotionHitGroundHeightAction_20cd0::V0() {}
} // namespace fn_00020cd0

namespace fn_fe1a35b1 {

// 0x00020d20 FUN_00020d20 (36 B): matches/0x00020d20.cpp
// sym: ??1CAction_20d20@fn_fe1a35b1@@QAE@XZ
CAction_20d20::~CAction_20d20() {
    vptr = g_vftable_20d20;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_20d20 *)this)->FUN_002326a0();
}

} // namespace fn_fe1a35b1

// 0x00020d50 FUN_00020d50 (78 B): matches/0x00020d50.cpp [wrapped: conflict: CAction]
// sym: ??0CWallSlideAction@fn_00020d50@@QAE@HPAVOther_20d50@1@@Z
namespace fn_00020d50 {
class Other_20d50 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_20d50 {
  public:
    Action_20d50();
    virtual void FnX_00018b30();
    char pad[0x18];
};
class CAction : public Action_20d50 {
  public:
    virtual void A();
    Other_20d50* m1c;
    int m20;
    CAction(int a, Other_20d50* o) : m1c(0) {
        if (o)
            o->AddRef();
        if (m1c)
            m1c->Release();
        m1c = o;
        m20 = a;
    }
};
class CWallSlideAction : public CAction {
  public:
    virtual void A();
    int m24;
    CWallSlideAction(int, Other_20d50*);
};
CWallSlideAction::CWallSlideAction(int a, Other_20d50* o) : CAction(a, o) {
    m24 = 0;
}
} // namespace fn_00020d50


// 0x00020da0 FUN_00020da0 (61 B): matches/0x00020da0.cpp [wrapped: conflict: CSmartPropUpdateAttachmentAction]
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_00020da0@@QAEXXZ
namespace fn_00020da0 {
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char hulk_at_003f3d80[];
extern char vftableA[];

class RefObj_20da0 {
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
    RefObj_20da0* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_20da0* volatile mB; // 0x24
    void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)hulk_at_003f3d80;
    RefObj_20da0* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_20da0* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}
} // namespace fn_00020da0


// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001cf40..0x0001d570 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6040229 {
#define TREE_TU_END }
namespace fn_f6040229 {} using namespace fn_f6040229;
namespace fn_f6040229 { extern "C" char DAT_003f34f0[], DAT_003f3390[], DAT_003f359c[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6040229 {
class RefObj_1cf90 {
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
    RefObj_1cf90* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_1cf90* volatile mB; // 0x24
    void Shutdown();
};
class Ref_1cfd0 {
  public:
    virtual void A();
    virtual void B();
};
extern int hulk_at_003f3390;
extern int HitVtable;
class CHitAnimationAction_1cfd0 : public Ctor_00232660 {
  public:
    int* vptr;
    char pad[0x18];
    Ref_1cfd0* mRef;
    int mValue;
    int mZero;
    CHitAnimationAction_1cfd0(int a, Ref_1cfd0* b);
};
class Ref_1d020 {
  public:
    virtual void A();
    virtual void B();
};
class CPushBackAnimationAction_1d020 : public Ctor_00232660 {
  public:
    int* vptr;
    char pad[0x18];
    Ref_1d020* mRef;
    int mValue;
    int mZero;
    CPushBackAnimationAction_1d020(int a, Ref_1d020* b);
};
class Ref_1d100 {
  public:
    virtual void A();
    virtual void B();
};
extern int actionVftable;
extern int hulk_at_003f359c;
class Action {
  public:
    Action();
    virtual void A();
    virtual void B();
    char pad[0x18];
    Ref_1d100* mRef;
    int mValue;
    int m9;
    int m10;
    int m11;
};
class CKeyPoseAction_1d100 : public Action {
  public:
    CKeyPoseAction_1d100(hulk_intptr, Ref_1d100*);
    virtual void A();
};
extern void* g_vftable_1d1e0[];
class Ref_1d1e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1d1e0 {
  public:
    void* vptr;
};
class CAction_1d1e0 : public Action_1d1e0 {
  public:
    char pad[24];
    Ref_1d1e0* m;
    ~CAction_1d1e0();
};
extern void* g_vftable_1d260[];
class Ref_1d260 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1d260 {
  public:
    void* vptr;
};
class CAction_1d260 : public Action_1d260 {
  public:
    char pad[24];
    Ref_1d260* m;
    ~CAction_1d260();
};
extern void* g_vftable_1d370[];
class Ref_1d370 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1d370 {
  public:
    void* vptr;
};
class CAction_1d370 : public Action_1d370 {
  public:
    char pad[24];
    Ref_1d370* m;
    ~CAction_1d370();
};
extern void* g_vftable_1d3f0[];
class Ref_1d3f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1d3f0 {
  public:
    void* vptr;
};
class CAction_1d3f0 : public Action_1d3f0 {
  public:
    char pad[0x18];
    Ref_1d3f0* m1c;
    ~CAction_1d3f0();
};
class Arg_1d420 {
  public:
    virtual void F0();
    virtual void F1();
};
class CSweepAction : public Ctor_00232660 {
  public:
    CSweepAction(int value, Arg_1d420* arg);
    char pad[0x1c];
    Arg_1d420* mThing;
    int mValue;
    int mA;
    int mB;
};
extern void* gA_1d520[];
class Ref_1d520 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_1d520 {
  public:
    void* vptr;
};
class CAutoTargetAction_1d520 : public CAction_1d520 {
  public:
    char pad_1c[0x18];
    Ref_1d520* m1c;
    char pad_24[0x4];
    Ref_1d520* m24;
    Ref_1d520* m28;
    ~CAutoTargetAction_1d520();
};

} // namespace fn_f6040229

// 0x0001cf40 FUN_0001cf40 (78 B): matches/0x0001cf40.cpp [wrapped: merged class would differ: CProceduralDurationAnimationAction: field m1c missing]
// sym: ??0CProceduralDurationAnimationAction@fn_0001cf40@@QAE@HPAURef_1cf40@1@@Z
namespace fn_0001cf40 {
struct Ref_1cf40 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_1cf40 {
    Action_1cf40();
    virtual void V0();
    char pad04[0x18];
};
struct CAction : Action_1cf40 {
    Ref_1cf40* m1c;
    int m20;
    CAction(Ref_1cf40* r, int a) {
        Ref_1cf40** q = &m1c;
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
struct CProceduralDurationAnimationAction : CAction {
    int m24;
    CProceduralDurationAnimationAction(int a, Ref_1cf40* r);
    virtual void V0();
};
CProceduralDurationAnimationAction::CProceduralDurationAnimationAction(int a, Ref_1cf40* r) : CAction(r, a) {
    m24 = 0;
}
} // namespace fn_0001cf40

namespace fn_f6040229 {

// 0x0001cf90 FUN_0001cf90 (61 B): matches/0x0001cf90.cpp
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_f6040229@@QAEXXZ
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)((char*)DAT_003f34f0);
    RefObj_1cf90* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)((char*)DAT_003f3390);
    RefObj_1cf90* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}


// 0x0001cfd0 FUN_0001cfd0 (78 B): matches/0x0001cfd0.cpp
// sym: ??0CHitAnimationAction_1cfd0@fn_f6040229@@QAE@HPAVRef_1cfd0@1@@Z
CHitAnimationAction_1cfd0::CHitAnimationAction_1cfd0(int a, Ref_1cfd0* b) : Ctor_00232660() {
    vptr = &hulk_at_003f3390;
    mRef = 0;
    if (b)
        b->A();
    if (mRef)
        mRef->B();
    mRef = b;
    mValue = a;
    mZero = 0;
    vptr = &HitVtable;
}


// 0x0001d020 FUN_0001d020 (78 B): matches/0x0001d020.cpp
// sym: ??0CPushBackAnimationAction_1d020@fn_f6040229@@QAE@HPAVRef_1d020@1@@Z
// Same code shape as 0x0001cfd0 (propagated; names are from that function)
CPushBackAnimationAction_1d020::CPushBackAnimationAction_1d020(int a, Ref_1d020* b) : Ctor_00232660() {
    vptr = &hulk_at_003f3390;
    mRef = 0;
    if (b)
        b->A();
    if (mRef)
        mRef->B();
    mRef = b;
    mValue = a;
    mZero = 0;
    vptr = &HitVtable;
}

} // namespace fn_f6040229

// 0x0001d070 FUN_0001d070 (78 B): matches/0x0001d070.cpp [wrapped: conflict: CAction]
// sym: ??0CStunAnimationAction@fn_0001d070@@QAE@HPAVObj@1@@Z
namespace fn_0001d070 {
class Obj {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_1d070 {
  public:
    virtual void v();
    char pad[24];
    Obj* object;
    int val;
    Action_1d070();
};
class CAction : public Action_1d070 {
  public:
    virtual void v();
    CAction(Obj* obj, int n) : Action_1d070() {
        object = 0;
        if (obj)
            obj->Add();
        if (object)
            object->Release();
        object = obj;
        val = n;
    }
};
class CStunAnimationAction : public CAction {
  public:
    virtual void v();
    int extra;
    CStunAnimationAction(int n, Obj* obj);
};
CStunAnimationAction::CStunAnimationAction(int n, Obj* obj) : CAction(obj, n) {
    extra = 0;
}
} // namespace fn_0001d070


// 0x0001d0c0 FUN_0001d0c0 (61 B): matches/0x0001d0c0.cpp [wrapped: conflict: CSmartPropUpdateAttachmentAction]
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_0001d0c0@@QAEXXZ
namespace fn_0001d0c0 {
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char hulk_at_003f3574[];
extern char vftableA[];

class RefObj_1d0c0 {
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
    RefObj_1d0c0* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_1d0c0* volatile mB; // 0x24
    void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)hulk_at_003f3574;
    RefObj_1d0c0* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)((char*)DAT_003f3390);
    RefObj_1d0c0* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}
} // namespace fn_0001d0c0

namespace fn_f6040229 {

// 0x0001d100 FUN_0001d100 (80 B): matches/0x0001d100.cpp
// sym: ??0CKeyPoseAction_1d100@fn_f6040229@@QAE@HPAVRef_1d100@1@@Z
CKeyPoseAction_1d100::CKeyPoseAction_1d100(hulk_intptr value, Ref_1d100* ref) : Action() {
    *(hulk_intptr*)this = (hulk_intptr)&actionVftable;
    mRef = 0;
    if (ref)
        ref->A();
    if (mRef)
        mRef->B();
    mRef = ref;
    mValue = value;
    m9 = 0;
    m10 = 0;
    m11 = 0;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f359c;
}

} // namespace fn_f6040229

// 0x0001d150 FUN_0001d150 (61 B): matches/0x0001d150.cpp [wrapped: conflict: CSmartPropUpdateAttachmentAction]
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_0001d150@@QAEXXZ
namespace fn_0001d150 {
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char vftableD[];
extern char vftableA[];

class RefObj_1d150 {
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
    RefObj_1d150* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_1d150* volatile mB; // 0x24
    void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)((char*)DAT_003f359c);
    RefObj_1d150* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)((char*)DAT_003f3390);
    RefObj_1d150* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}
} // namespace fn_0001d150


// 0x0001d190 FUN_0001d190 (71 B): matches/0x0001d190.cpp [wrapped: conflict: CAction]
// sym: ??0CSoundAction_1d190@fn_0001d190@@QAE@HPAVIRef_1d190@1@@Z
namespace fn_0001d190 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1d190 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1d190 {
  public:
    virtual void VFunc_00018b30();
    Action_1d190();
};

class CAction : public Action_1d190 {
  public:
    char m_pad[0x18];
    IRef_1d190* m_pRef;
    int m_param;
    virtual void Process_00018b40();
    CAction(int a, IRef_1d190* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CSoundAction_1d190 : public CAction {
  public:
    virtual void* ProcessDrift_00021a20(char);
    CSoundAction_1d190(hulk_intptr a, IRef_1d190* p);
};

CSoundAction_1d190::CSoundAction_1d190(hulk_intptr a, IRef_1d190* p) : CAction(a, p) {}
} // namespace fn_0001d190

namespace fn_f6040229 {

// 0x0001d1e0 FUN_0001d1e0 (36 B): matches/0x0001d1e0.cpp
// sym: ??1CAction_1d1e0@fn_f6040229@@QAE@XZ
CAction_1d1e0::~CAction_1d1e0() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1d1e0 *)this)->FUN_002326a0();
}

} // namespace fn_f6040229

// 0x0001d210 FUN_0001d210 (71 B): matches/0x0001d210.cpp [wrapped: conflict: CAction]
// sym: ??0CComboMessageAction_1d210@fn_0001d210@@QAE@HPAVIRef_1d210@1@@Z
namespace fn_0001d210 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1d210 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1d210 {
  public:
    virtual void VFunc_00018b30();
    Action_1d210();
};

class CAction : public Action_1d210 {
  public:
    char m_pad[0x18];
    IRef_1d210* m_pRef;
    int m_param;
    virtual void Process_00018b40();
    CAction(int a, IRef_1d210* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CComboMessageAction_1d210 : public CAction {
  public:
    virtual void* ProcessDrift_00021a60(char);
    CComboMessageAction_1d210(int a, IRef_1d210* p);
};

CComboMessageAction_1d210::CComboMessageAction_1d210(int a, IRef_1d210* p) : CAction(a, p) {}
} // namespace fn_0001d210

namespace fn_f6040229 {

// 0x0001d260 FUN_0001d260 (36 B): matches/0x0001d260.cpp
// sym: ??1CAction_1d260@fn_f6040229@@QAE@XZ
CAction_1d260::~CAction_1d260() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1d260 *)this)->FUN_002326a0();
}

} // namespace fn_f6040229

// 0x0001d290 FUN_0001d290 (78 B): matches/0x0001d290.cpp [wrapped: merged class would differ: CMoveAction: field m1c missing]
// sym: ??0CMoveAction@fn_0001d290@@QAE@HPAURef_1d290@1@@Z
namespace fn_0001d290 {
struct Ref_1d290 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_1d290 {
    Action_1d290();
    virtual void V0();
    char pad04[0x18];
};
struct CAction : Action_1d290 {
    Ref_1d290* m1c;
    int m20;
    CAction(Ref_1d290* r, int a) {
        Ref_1d290** q = &m1c;
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
struct CMoveAction : CAction {
    int m24;
    CMoveAction(int a, Ref_1d290* r);
    virtual void V0();
};
CMoveAction::CMoveAction(int a, Ref_1d290* r) : CAction(r, a) {
    m24 = 0;
}
} // namespace fn_0001d290


// 0x0001d2e0 FUN_0001d2e0 (61 B): matches/0x0001d2e0.cpp [wrapped: conflict: CSmartPropUpdateAttachmentAction]
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_0001d2e0@@QAEXXZ
namespace fn_0001d2e0 {
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char hulk_at_003f3614[];
extern char vftableA[];

class RefObj_1d2e0 {
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
    RefObj_1d2e0* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_1d2e0* volatile mB; // 0x24
    void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)hulk_at_003f3614;
    RefObj_1d2e0* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)((char*)DAT_003f3390);
    RefObj_1d2e0* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}
} // namespace fn_0001d2e0


// 0x0001d320 FUN_0001d320 (71 B): matches/0x0001d320.cpp [wrapped: conflict: CAction]
// sym: ??0CMoveAddAction_1d320@fn_0001d320@@QAE@HPAVIRef_1d320@1@@Z
namespace fn_0001d320 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1d320 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1d320 {
  public:
    virtual void VFunc_00018b30();
    Action_1d320();
};

class CAction : public Action_1d320 {
  public:
    char m_pad[0x18];
    IRef_1d320* m_pRef;
    int m_param;
    virtual void Process_00018b40();
    CAction(int a, IRef_1d320* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CMoveAddAction_1d320 : public CAction {
  public:
    virtual void* ProcessDrift_00021b00(char);
    CMoveAddAction_1d320(int a, IRef_1d320* p);
};

CMoveAddAction_1d320::CMoveAddAction_1d320(int a, IRef_1d320* p) : CAction(a, p) {}
} // namespace fn_0001d320

namespace fn_f6040229 {

// 0x0001d370 FUN_0001d370 (36 B): matches/0x0001d370.cpp
// sym: ??1CAction_1d370@fn_f6040229@@QAE@XZ
CAction_1d370::~CAction_1d370() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1d370 *)this)->FUN_002326a0();
}

} // namespace fn_f6040229

// 0x0001d3a0 FUN_0001d3a0 (71 B): matches/0x0001d3a0.cpp [wrapped: conflict: CAction]
// sym: ??0CMoveAddYAction_1d3a0@fn_0001d3a0@@QAE@HPAVIRef_1d3a0@1@@Z
namespace fn_0001d3a0 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1d3a0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1d3a0 {
  public:
    virtual void VFunc_00018b30();
    Action_1d3a0();
};

class CAction : public Action_1d3a0 {
  public:
    char m_pad[0x18];
    IRef_1d3a0* m_pRef;
    int m_param;
    virtual void Process_00018b40();
    CAction(int a, IRef_1d3a0* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CMoveAddYAction_1d3a0 : public CAction {
  public:
    virtual void* ProcessDrift_00021b40(char);
    CMoveAddYAction_1d3a0(int a, IRef_1d3a0* p);
};

CMoveAddYAction_1d3a0::CMoveAddYAction_1d3a0(int a, IRef_1d3a0* p) : CAction(a, p) {}
} // namespace fn_0001d3a0

namespace fn_f6040229 {

// 0x0001d3f0 FUN_0001d3f0 (36 B): matches/0x0001d3f0.cpp
// sym: ??1CAction_1d3f0@fn_f6040229@@QAE@XZ
CAction_1d3f0::~CAction_1d3f0() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1d3f0 *)this)->FUN_002326a0();
}


// 0x0001d420 FUN_0001d420 (85 B): matches/0x0001d420.cpp
// sym: ??0CSweepAction@fn_f6040229@@QAE@HPAVArg_1d420@1@@Z
CSweepAction::CSweepAction(int value, Arg_1d420* arg) : Ctor_00232660() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableAction;
    mThing = 0;
    if (arg)
        arg->F0();
    if (mThing)
        mThing->F1();
    mThing = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&vtableSweep;
    mA = 0;
    mB = 0;
}

} // namespace fn_f6040229

// 0x0001d480 FUN_0001d480 (61 B): matches/0x0001d480.cpp [wrapped: conflict: CSmartPropUpdateAttachmentAction]
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_0001d480@@QAEXXZ
namespace fn_0001d480 {
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char hulk_at_003f368c[];
extern char vftableA[];

class RefObj_1d480 {
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
    RefObj_1d480* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_1d480* volatile mB; // 0x24
    void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)hulk_at_003f368c;
    RefObj_1d480* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)((char*)DAT_003f3390);
    RefObj_1d480* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}
} // namespace fn_0001d480


// 0x0001d4c0 FUN_0001d4c0 (93 B): matches/0x0001d4c0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CAutoTargetAction@fn_0001d4c0@@QAE@PAVHelper_1d4c0@1@PAVObj_1d4c0@1@@Z
namespace fn_0001d4c0 {
class Obj_1d4c0 {
  public:
    virtual void F();
    virtual void G();
};
class Helper_1d4c0 {
  public:
    float Get_00069d30();
};
class Base_1d4c0 {
  public:
    Base_1d4c0();
    virtual void FnZ_00018b30();
};
class CAutoTargetAction_1d4c0 : public Base_1d4c0 {
  public:
    CAutoTargetAction_1d4c0(Obj_1d4c0* o);
    virtual void FnA_00018b40();
    virtual void B();
    char pad[0x18];
    Obj_1d4c0* ref;
};
CAutoTargetAction_1d4c0::CAutoTargetAction_1d4c0(Obj_1d4c0* o) : Base_1d4c0() {
    ref = 0;
    if (o)
        o->F();
    if (ref)
        ref->G();
    ref = o;
}
class CAutoTargetAction : public CAutoTargetAction_1d4c0 {
  public:
    CAutoTargetAction(Helper_1d4c0* h, Obj_1d4c0* o);
    virtual bool FnC_00013940(hulk_intptr, hulk_intptr);
    virtual void FnD_00015270();
    Helper_1d4c0* x;
    int y;
    int z;
    float f;
};
CAutoTargetAction::CAutoTargetAction(Helper_1d4c0* h, Obj_1d4c0* o) : CAutoTargetAction_1d4c0(o) {
    y = 0;
    z = 0;
    x = h;
    f = h->Get_00069d30();
}
} // namespace fn_0001d4c0

namespace fn_f6040229 {

// 0x0001d520 FUN_0001d520 (80 B): matches/0x0001d520.cpp
// sym: ??1CAutoTargetAction_1d520@fn_f6040229@@QAE@XZ
CAutoTargetAction_1d520::~CAutoTargetAction_1d520() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = gA_1d520;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_1d520 *)this)->FUN_002326a0();
}

} // namespace fn_f6040229

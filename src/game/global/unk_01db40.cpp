// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001db40..0x0001df20 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1243cbb {
#define TREE_TU_END }
namespace fn_f1243cbb {} using namespace fn_f1243cbb;
namespace fn_f1243cbb { extern "C" char DAT_003f3390[], DAT_003f3754[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f1243cbb {
extern void* hulk_at_003f3390[];
class Ref_1db90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1db90 {
  public:
    void* vptr;
};
class CAction_1db90 : public Action_1db90 {
  public:
    char pad1c[0x18];
    Ref_1db90* m1c;
    ~CAction_1db90();
};
extern void* g_vftable_1dc10[];
class Ref_1dc10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1dc10 {
  public:
    void* vptr;
};
class CAction_1dc10 : public Action_1dc10 {
  public:
    char pad[24];
    Ref_1dc10* m;
    ~CAction_1dc10();
};
class Action_1dc40 {
  public:
    Action_1dc40();
    virtual void f();
    char pad[0x18];
};
class Ref {
  public:
    virtual void add();
    virtual void release();
};
class CAction : public Action_1dc40 {
  public:
    Ref* ref;
    int value;
    CAction(int v, Ref* r) : Action_1dc40() {
        ref = 0;
        if (r)
            r->add();
        if (ref)
            ref->release();
        ref = r;
        value = v;
    }
    virtual void f();
};
class CGrappleLocoStrafe4Action : public CAction {
  public:
    int extra;
    CGrappleLocoStrafe4Action(hulk_intptr v, Ref* r);
    virtual void f();
};
class RefObj_1dc90 {
  public:
    virtual void v0();
    virtual void Release();
};
struct Tidier {
};
class CGrappleLocoStrafe4Action_1dc90 {
  public:
    char pad[0x1c];
    RefObj_1dc90* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_1dc90* volatile mB; // 0x24
    void Shutdown();
};
extern void* g_vftable_1dd20[];
class Ref_1dd20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1dd20 {
  public:
    void* vptr;
};
class CAction_1dd20 : public Action_1dd20 {
  public:
    char pad1c[0x18];
    Ref_1dd20* m1c;
    ~CAction_1dd20();
};
extern void* g_vftable_1dda0[];
class Ref_1dda0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1dda0 {
  public:
    void* vptr;
};
class CAction_1dda0 : public Action_1dda0 {
  public:
    char pad1c[0x18];
    Ref_1dda0* m1c;
    ~CAction_1dda0();
};
extern void* g_vftable_1de20[];
class Ref_1de20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1de20 {
  public:
    void* vptr;
};
class CAction_1de20 : public Action_1de20 {
  public:
    char pad[0x18];
    Ref_1de20* m1c;
    ~CAction_1de20();
};
extern "C" char DAT_003f37f4[];
class Ref_1de50 {
  public:
    virtual void A();
    virtual void B();
};
class CGrabAction : public Ctor_00232660 {
  public:
    int* vptr;
    char pad04[0x18];
    Ref_1de50* first;
    int m20;
    int m24;
    int m28;
    char pad2c[12];
    char m38;
    char pad39[3];
    Ref_1de50* second;
    CGrabAction(Ref_1de50*, hulk_intptr, Ref_1de50*, int);
};

} // namespace fn_f1243cbb

// 0x0001db40 FUN_0001db40 (71 B): matches/0x0001db40.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CDrainHealthAction@fn_0001db40@@QAE@PAUObj_1db40@1@H@Z
namespace fn_0001db40 {
struct Obj_1db40 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int hulk_at_003f3704;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_1db40* mObj;
    int mValue;
};
class CDrainHealthAction : public CAction {
  public:
    CDrainHealthAction(Obj_1db40*, int);
    virtual void V0();
};
CDrainHealthAction::CDrainHealthAction(Obj_1db40* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f3704;
}
void CDrainHealthAction::V0() {}
} // namespace fn_0001db40

namespace fn_f1243cbb {

// 0x0001db90 FUN_0001db90 (36 B): matches/0x0001db90.cpp
// sym: ??1CAction_1db90@fn_f1243cbb@@QAE@XZ
CAction_1db90::~CAction_1db90() {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1db90 *)this)->FUN_002326a0();
}

} // namespace fn_f1243cbb

// 0x0001dbc0 FUN_0001dbc0 (71 B): matches/0x0001dbc0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CComboTimerAction_1dbc0@fn_0001dbc0@@QAE@PAUObj_1dbc0@1@H@Z
namespace fn_0001dbc0 {
// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_1dbc0 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int hulk_at_003f372c;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_1dbc0* mObj;
    int mValue;
};
class CComboTimerAction_1dbc0 : public CAction {
  public:
    CComboTimerAction_1dbc0(Obj_1dbc0*, int);
    virtual void V0();
};
CComboTimerAction_1dbc0::CComboTimerAction_1dbc0(Obj_1dbc0* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f372c;
}
void CComboTimerAction_1dbc0::V0() {}
} // namespace fn_0001dbc0

namespace fn_f1243cbb {

// 0x0001dc10 FUN_0001dc10 (36 B): matches/0x0001dc10.cpp
// sym: ??1CAction_1dc10@fn_f1243cbb@@QAE@XZ
CAction_1dc10::~CAction_1dc10() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1dc10 *)this)->FUN_002326a0();
}


// 0x0001dc40 FUN_0001dc40 (78 B): matches/0x0001dc40.cpp
// sym: ??0CGrappleLocoStrafe4Action@fn_f1243cbb@@QAE@HPAVRef@1@@Z
CGrappleLocoStrafe4Action::CGrappleLocoStrafe4Action(hulk_intptr v, Ref* r) : CAction(v, r) {
    extra = 0;
}


// 0x0001dc90 FUN_0001dc90 (61 B): matches/0x0001dc90.cpp
// sym: ?Shutdown@CGrappleLocoStrafe4Action_1dc90@fn_f1243cbb@@QAEXXZ
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
void CGrappleLocoStrafe4Action_1dc90::Shutdown() {
    *(void* volatile*)this = (void*)((char*)DAT_003f3754);
    RefObj_1dc90* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)((char*)DAT_003f3390);
    RefObj_1dc90* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((fight::Action *)(((Tidier*)this)))->FUN_002326a0();
}

} // namespace fn_f1243cbb

// 0x0001dcd0 FUN_0001dcd0 (71 B): matches/0x0001dcd0.cpp [wrapped: conflict: CAction]
// sym: ??0CGrappleAttachAction_1dcd0@fn_0001dcd0@@QAE@HPAVIRef_1dcd0@1@@Z
namespace fn_0001dcd0 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1dcd0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1dcd0 {
  public:
    virtual void VFunc_00018b30();
    Action_1dcd0();
};

class CAction : public Action_1dcd0 {
  public:
    char m_pad[0x18];
    IRef_1dcd0* m_pRef;
    int m_param;
    virtual void Process_00018b40();
    CAction(int a, IRef_1dcd0* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CGrappleAttachAction_1dcd0 : public CAction {
  public:
    virtual void* ProcessDrift_00021d20(char);
    CGrappleAttachAction_1dcd0(int a, IRef_1dcd0* p);
};

CGrappleAttachAction_1dcd0::CGrappleAttachAction_1dcd0(int a, IRef_1dcd0* p) : CAction(a, p) {}
} // namespace fn_0001dcd0

namespace fn_f1243cbb {

// 0x0001dd20 FUN_0001dd20 (36 B): matches/0x0001dd20.cpp
// sym: ??1CAction_1dd20@fn_f1243cbb@@QAE@XZ
CAction_1dd20::~CAction_1dd20() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1dd20 *)this)->FUN_002326a0();
}

} // namespace fn_f1243cbb

// 0x0001dd50 FUN_0001dd50 (71 B): matches/0x0001dd50.cpp [wrapped: conflict: CAction]
// sym: ??0CGrappleSwapAction_1dd50@fn_0001dd50@@QAE@HPAVIRef_1dd50@1@@Z
namespace fn_0001dd50 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1dd50 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1dd50 {
  public:
    virtual void VFunc_00018b30();
    Action_1dd50();
};

class CAction : public Action_1dd50 {
  public:
    char m_pad[0x18];
    IRef_1dd50* m_pRef;
    int m_param;
    virtual void Process_00018b40();
    CAction(int a, IRef_1dd50* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CGrappleSwapAction_1dd50 : public CAction {
  public:
    virtual void* ProcessDrift_00021d60(char);
    CGrappleSwapAction_1dd50(int a, IRef_1dd50* p);
};

CGrappleSwapAction_1dd50::CGrappleSwapAction_1dd50(int a, IRef_1dd50* p) : CAction(a, p) {}
} // namespace fn_0001dd50

namespace fn_f1243cbb {

// 0x0001dda0 FUN_0001dda0 (36 B): matches/0x0001dda0.cpp
// sym: ??1CAction_1dda0@fn_f1243cbb@@QAE@XZ
CAction_1dda0::~CAction_1dda0() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1dda0 *)this)->FUN_002326a0();
}

} // namespace fn_f1243cbb

// 0x0001ddd0 FUN_0001ddd0 (71 B): matches/0x0001ddd0.cpp [wrapped: conflict: CAction]
// sym: ??0CGrappleDetachAction_1ddd0@fn_0001ddd0@@QAE@HPAVIRef_1ddd0@1@@Z
namespace fn_0001ddd0 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1ddd0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1ddd0 {
  public:
    virtual void VFunc_00018b30();
    Action_1ddd0();
};

class CAction : public Action_1ddd0 {
  public:
    char m_pad[0x18];
    IRef_1ddd0* m_pRef;
    int m_param;
    virtual void Process_00018b40();
    CAction(int a, IRef_1ddd0* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CGrappleDetachAction_1ddd0 : public CAction {
  public:
    virtual void* ProcessDrift_00021da0(char);
    CGrappleDetachAction_1ddd0(int a, IRef_1ddd0* p);
};

CGrappleDetachAction_1ddd0::CGrappleDetachAction_1ddd0(int a, IRef_1ddd0* p) : CAction(a, p) {}
} // namespace fn_0001ddd0

namespace fn_f1243cbb {

// 0x0001de20 FUN_0001de20 (36 B): matches/0x0001de20.cpp
// sym: ??1CAction_1de20@fn_f1243cbb@@QAE@XZ
CAction_1de20::~CAction_1de20() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_1de20 *)this)->FUN_002326a0();
}


// 0x0001de50 FUN_0001de50 (116 B): matches/0x0001de50.cpp
// sym: ??0CGrabAction@fn_f1243cbb@@QAE@PAVRef_1de50@1@H0H@Z
CGrabAction::CGrabAction(Ref_1de50* a, hulk_intptr b, Ref_1de50* c, int d) : Ctor_00232660() {
    vptr = (int*)((hulk_intptr)DAT_003f3390);
    first = 0;
    if (c)
        c->A();
    if (first)
        first->B();
    first = c;
    vptr = (int*)((hulk_intptr)DAT_003f37f4);
    m24 = d;
    m28 = 0;
    m38 = 0;
    second = 0;
    m20 = b;
    if (a)
        a->A();
    if (second)
        second->B();
    second = a;
}

} // namespace fn_f1243cbb

// 0x0001ded0 FUN_0001ded0 (80 B): matches/0x0001ded0.cpp [wrapped: conflict: CAction; CGrabAction]
// sym: ?Cleanup@CGrabAction@fn_0001ded0@@QAEXXZ
namespace fn_0001ded0 {
extern "C" void _ReadWriteBarrier();
class Ref_1ded0 {
  public:
    virtual void A();
    virtual void Release();
};
extern char hulk_at_003f37f4[];
extern char actionvt[];
class CAction {
  public:
    char* vptr;
    char pad[0x18];
    Ref_1ded0* m1;
    void BaseTail_002326a0();
};
class CGrabAction : public CAction {
  public:
    char pad2[8];
    Ref_1ded0* m2;
    char pad3[16];
    Ref_1ded0* m3;
    void Cleanup();
};
void CGrabAction::Cleanup() {
    vptr = hulk_at_003f37f4;
    _ReadWriteBarrier();
    if (m2) {
        m2->Release();
        m2 = 0;
    }
    if (m3) {
        m3->Release();
        m3 = 0;
    }
    vptr = actionvt;
    _ReadWriteBarrier();
    if (m1) {
        m1->Release();
        m1 = 0;
    }
    BaseTail_002326a0();
}
} // namespace fn_0001ded0


// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000185f0..0x00018d40 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f7aff818 {
#define TREE_TU_END }
namespace fn_f7aff818 {} using namespace fn_f7aff818;
namespace fn_f7aff818 { extern "C" char DAT_003f3390[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f7aff818 {
class CAction_185f0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
};
struct Inner_185f0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void set(int, int);
};
struct Obj_185f0 {
    char pad[0x128];
    Inner_185f0* p;
};
struct Actor_185f0 {
    Obj_185f0* get_000592a0();
};
struct Obj2_185f0 {
    Obj_185f0* get_00059a30();
};
struct State_185f0 {
    char pad[0x10];
    int value;
};
struct ObjA_18620 {
};
struct ObjB_18620 {
    void* Next_00059a30();
};
struct ObjC_18620 {
    int Run_00035cd0();
};
class Arr_18650 {
  public:
    int* Get(int index);
    int* m;
};
class Obj {
  public:
    virtual void Add();
    virtual void release();
    void Release() { release(); }
    void b() { release(); }
};
class Obj_187a0 {
  public:
    virtual void A();
    virtual void B();
};
class A_187d0 {
  public:
    virtual void f();
    virtual void g();
};
class Obj_18810 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_18840 {
  public:
    virtual void A();
    virtual void B();
};
struct Holder {
    Obj* p;
};
class Obj_188e0 {
  public:
    virtual void A();
    virtual void B();
};
class IRefCount_18b30 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
extern void* hulk_at_003f3390[];
class Ref_18b60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_18b60 {
  public:
    void* vptr;
};
class CAction_18b60 : public Action_18b60 {
  public:
    char pad[0x1c - 4];
    Ref_18b60* m1c;
    ~CAction_18b60();
};
extern void* g_vftable_18c70[];
class Ref_18c70 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_18c70 {
  public:
    void* vptr;
};
class CAction_18c70 : public Action_18c70 {
  public:
    char pad[24];
    Ref_18c70* m;
    ~CAction_18c70();
};

} // namespace fn_f7aff818

// 0x000185f0 CPropActorSetStateAction::vfunc_7 (48 B): matches/0x000185f0.cpp
// sym: ?vfunc_7@CPropActorSetStateAction@@UAE_NH@Z
bool CPropActorSetStateAction::vfunc_7(int ) {
    Obj_185f0* o = (*(Actor_185f0 * *)&this->f_1c)->get_000592a0();
    o = ((Obj2_185f0*)o)->get_00059a30();
    if (o->p)
        o->p->set((*(struct State_185f0 * *)&this->f_20)->value, 1);
    return false;
}


// 0x00018620 CClearHitRecordsAction::vfunc_6 (31 B): matches/0x00018620.cpp
// sym: ?vfunc_6@CClearHitRecordsAction@@UAE_NH@Z
bool CClearHitRecordsAction::vfunc_6(int x) {
    ObjA_18620* a = (*(ObjA_18620 * *)&this->f_1c);
    void* r = ((void *)((owners::Object_592a0 *)a)->FUN_000592a0());
    void* b = ((ObjB_18620*)r)->Next_00059a30();
    if (b)
        ((ObjC_18620*)b)->Run_00035cd0();
    return false;
}

namespace fn_f7aff818 {

// 0x00018650 FUN_00018650 (12 B): matches/0x00018650.cpp
// sym: ?Get@Arr_18650@fn_f7aff818@@QAEPAHH@Z
int* Arr_18650::Get(int index) {
    return m + index;
}


// 0x000186b0 FUN_000186b0 (58 B): matches/0x000186b0.cpp
// sym: _FUN_000186b0
extern "C" float FUN_000186b0(float* a, float* b, float* c) {
    if (*a >= *b && *a <= *c)
        return *a;
    if (*a > *c)
        return *c;
    return *b;
}


// 0x000186f0 FUN_000186f0 (25 B): matches/0x000186f0.cpp
// sym: _FUN_000186f0
extern "C" float __cdecl FUN_000186f0(float* a, float* b) {
    if (*a < *b)
        return *a;
    return *b;
}


// 0x00018710 FUN_00018710 (25 B): matches/0x00018710.cpp
// sym: _FUN_00018710
extern "C" float FUN_00018710(float* a, float* b) {
    return *a < *b ? *b : *a;
}


// 0x00018730 FUN_00018730 (36 B): matches/0x00018730.cpp
// sym: ?f@fn_f7aff818@@YAXPAPAVObj@1@PAV21@@Z
void f(Obj** slot, Obj* value) {
    if (value)
        value->Add();
    if (*slot)
        (*slot)->Release();
    *slot = value;
}


// 0x00018780 FUN_00018780 (24 B): matches/0x00018780.cpp
// sym: ?FUN_00018780@fn_f7aff818@@YAXPAPAVObj@1@@Z
void FUN_00018780(Obj** p) {
    Obj* q = *p;
    if (q) {
        q->b();
        *p = 0;
    }
}


// 0x000187a0 FUN_000187a0 (36 B): matches/0x000187a0.cpp
// sym: ?Set@fn_f7aff818@@YAXPAPAVObj_187a0@1@PAV21@@Z
void Set(Obj_187a0** p, Obj_187a0* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}


// 0x000187d0 FUN_000187d0 (24 B): matches/0x000187d0.cpp
// sym: ?FUN_000187d0@fn_f7aff818@@YAXPAPAVA_187d0@1@@Z
void FUN_000187d0(A_187d0** p) {
    if (*p) {
        (*p)->g();
        *p = 0;
    }
}


// 0x00018810 FUN_00018810 (36 B): matches/0x00018810.cpp
// sym: ?Set@fn_f7aff818@@YAXPAPAVObj_187a0@1@PAV21@@Z
// Same code shape as 0x000187a0 (propagated; names are from that function)
void Set(Obj_18810** p, Obj_18810* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}


// 0x00018840 FUN_00018840 (36 B): matches/0x00018840.cpp
// sym: ?Set@fn_f7aff818@@YAXPAPAVObj_187a0@1@PAV21@@Z
// Same code shape as 0x000187a0 (propagated; names are from that function)
void Set(Obj_18840** p, Obj_18840* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}


// 0x00018890 FUN_00018890 (24 B): matches/0x00018890.cpp
// sym: ?FUN_00018890@fn_f7aff818@@YAXPAUHolder@1@@Z
void __cdecl FUN_00018890(Holder* h) {
    if (h->p) {
        h->p->release();
        h->p = 0;
    }
}


// 0x000188e0 FUN_000188e0 (36 B): matches/0x000188e0.cpp
// sym: ?Set@fn_f7aff818@@YAXPAPAVObj_187a0@1@PAV21@@Z
// Same code shape as 0x000187a0 (propagated; names are from that function)
void Set(Obj_188e0** p, Obj_188e0* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}


// 0x00018960 FUN_00018960 (44 B): matches/0x00018960.cpp
// sym: _FUN_00018960
extern "C" int FUN_00018960(float a, float b, float c) {
    union U {
        float f;
        unsigned int u;
    } x;
    x.f = a - b;
    x.u &= 0x7fffffff;
    return x.f <= c;
}


// 0x00018990 FUN_00018990 (33 B): matches/0x00018990.cpp
// sym: ?FUN_00018990@fn_f7aff818@@YIMPAM@Z
hulk_freg __fastcall FUN_00018990(float* p) {
    return sqrt((double)(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]));
}


// 0x000189c0 FUN_000189c0 (83 B): equivalent/0x000189c0.cpp
// sym: ?FUN_000189c0@fn_f7aff818@@YAMM@Z @c3b65b7c3ea4 @wfa67871c53ed
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 6/6; Wine build 3003 inputs, 6/6)
// FUN_000189c0 @ 0x000189c0
// Clamping asin: the argument is limited to [-1, 1] (NaN becomes -1) before the CRT's __CIasin.
// equiv-map: __CIasin = 0x003442bc
hulk_freg __cdecl FUN_000189c0(float x)
{
    if (!(x >= -1.0f && x <= 1.0f))
        x = (x > 1.0f) ? 1.0f : -1.0f;
    double r = asin(x);
    return r;      // x87: the original returns the CRT result unrounded in st0 (as 0x00018a20)
}


// 0x00018a20 FUN_00018a20 (83 B): equivalent/0x00018a20.cpp
// sym: ?FUN_00018a20@fn_f7aff818@@YAMM@Z @5bf24cdf8282 @wcbfc3d2fe84c
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 6/6)
// FUN_00018a20 @ 0x00018a20
// Clamping acos: the argument is limited to [-1, 1] (NaN becomes -1) before the CRT's __CIacos.
// equiv-map: __CIacos = 0x003441f0
hulk_freg __cdecl FUN_00018a20(float x)
{
    if (!(x >= -1.0f && x <= 1.0f))
        x = (x > 1.0f) ? 1.0f : -1.0f;
    double r = acos(x);
    return r;      // x87: the original returns the CRT result unrounded in st0
}

} // namespace fn_f7aff818

// 0x00018af0 FUN_00018af0 (58 B): matches/0x00018af0.cpp [wrapped: conflict: CAction]
// sym: ??0CAction@fn_00018af0@@QAE@PAVRef_18af0@1@@Z
namespace fn_00018af0 {
class Ref_18af0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_18af0 {
  public:
    virtual void FnV_00018b30();
    Action_18af0();
};
class CAction : public Action_18af0 {
  public:
    virtual void V2_00018b40();
    char pad[0x18];
    Ref_18af0* mRef;
    CAction(Ref_18af0*);
};
CAction::CAction(Ref_18af0* arg) : Action_18af0() {
    mRef = 0;
    if (arg)
        arg->AddRef();
    if (mRef)
        mRef->Release();
    mRef = arg;
}
} // namespace fn_00018af0


// 0x00018b30 pure3d::NonCopyable::vfunc_0 (4 B): matches/0x00018b30.cpp
// sym: ?vfunc_0@NonCopyable@pure3d@@UAEXXZ
void pure3d::NonCopyable::vfunc_0() {
    ++this->f_04;
}


// 0x00018b40 pure3d::NonCopyable::vfunc_1 (20 B): matches/0x00018b40.cpp [wrapped: conflict: core::IRefCount; pure3d::NonCopyable]
// sym: ?Release@IRefCount@core@fn_00018b40@@UAEXXZ
namespace fn_00018b40 {
namespace core {
class IRefCount {
  public:
    virtual void vfunc_0();
    virtual void Release();
    virtual ~IRefCount();
    int mRefCount;
};

void IRefCount::Release() {
    if (--mRefCount < 1)
        delete this;
}
} // namespace core

namespace pure3d {
class NonCopyable : public core::IRefCount {};
} // namespace pure3d
} // namespace fn_00018b40

namespace fn_f7aff818 {

// 0x00018b60 FUN_00018b60 (36 B): matches/0x00018b60.cpp
// sym: ??1CAction_18b60@fn_f7aff818@@QAE@XZ
CAction_18b60::~CAction_18b60() {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(Action_18b60 *)this)->FUN_002326a0();
}

} // namespace fn_f7aff818

// 0x00018b90 FUN_00018b90 (78 B): matches/0x00018b90.cpp [wrapped: conflict: CJointAction]
// sym: ?Init@CJointAction@fn_00018b90@@QAEPAV12@HPAVRef_18b90@2@@Z
namespace fn_00018b90 {
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f33b8[];
class Ref_18b90 {
  public:
    virtual void AddRef();
    virtual void Release();
};
struct ThisCall_00232660 {
    void BaseInit_00232660();
};
class CJointAction {
  public:
    virtual void V();
    char pad[0x18];
    Ref_18b90* ref;
    int value;
    int extra;
    CJointAction* Init(int, Ref_18b90*);
};
CJointAction* CJointAction::Init(int v, Ref_18b90* r) {
    ((ThisCall_00232660*)(this))->BaseInit_00232660();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f3390);
    ref = 0;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    value = v;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f33b8);
    extra = 0;
    return this;
}
} // namespace fn_00018b90


// 0x00018be0 FUN_00018be0 (61 B): matches/0x00018be0.cpp [wrapped: conflict: CSmartPropUpdateAttachmentAction]
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_00018be0@@QAEXXZ
namespace fn_00018be0 {
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char hulk_at_003f33b8[];
extern char vftableA[];

class RefObj_18be0 {
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
    RefObj_18be0* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_18be0* volatile mB; // 0x24
    void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)hulk_at_003f33b8;
    RefObj_18be0* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)((char*)DAT_003f3390);
    RefObj_18be0* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}
} // namespace fn_00018be0


// 0x00018c20 FUN_00018c20 (71 B): matches/0x00018c20.cpp [wrapped: conflict: CAction]
// sym: ??0CClimbingAction_18c20@fn_00018c20@@QAE@HPAVIRef_18c20@1@@Z
namespace fn_00018c20 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_18c20 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_18c20 {
  public:
    virtual void VFunc_00018b30();
    Action_18c20();
};

class CAction : public Action_18c20 {
  public:
    char m_pad[0x18];
    IRef_18c20* m_pRef;
    int m_param;
    virtual void Process_00018b40();
    CAction(int a, IRef_18c20* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CClimbingAction_18c20 : public CAction {
  public:
    virtual void* ProcessDrift_00021740(char);
    CClimbingAction_18c20(int a, IRef_18c20* p);
};

CClimbingAction_18c20::CClimbingAction_18c20(int a, IRef_18c20* p) : CAction(a, p) {}
} // namespace fn_00018c20

namespace fn_f7aff818 {

// 0x00018c70 FUN_00018c70 (36 B): matches/0x00018c70.cpp
// sym: ??1CAction_18c70@fn_f7aff818@@QAE@XZ
CAction_18c70::~CAction_18c70() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_18c70 *)this)->FUN_002326a0();
}

} // namespace fn_f7aff818

// 0x00018ca0 FUN_00018ca0 (89 B): matches/0x00018ca0.cpp [wrapped: conflict: CJumpAction; DAT_003f3390]
// sym: ?FUN_00018ca0@CJumpAction@fn_00018ca0@@QAEPAU12@IPAURef@2@@Z
namespace fn_00018ca0 {
struct Ref {
    virtual void addRef();
    virtual void release();
};
extern void* DAT_003f3390[];
extern void* DAT_003f3408[];
struct CJumpAction {
    void** vtable;
    char padding[0x18];
    Ref* reference;
    unsigned value;
    unsigned state[6];
    void FUN_00232660();
    CJumpAction* FUN_00018ca0(unsigned val, Ref* ref);
};
CJumpAction* CJumpAction::FUN_00018ca0(unsigned val, Ref* ref) {
    FUN_00232660();
    vtable = DAT_003f3390;
    reference = 0;
    if (ref)
        ref->addRef();
    if (reference)
        reference->release();
    reference = ref;
    for (int i = 0; i < 6; ++i)
        state[i] = 0;
    value = val;
    vtable = DAT_003f3408;
    return this;
}
} // namespace fn_00018ca0


// 0x00018d00 FUN_00018d00 (61 B): matches/0x00018d00.cpp [wrapped: conflict: CSmartPropUpdateAttachmentAction]
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_00018d00@@QAEXXZ
namespace fn_00018d00 {
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
extern char hulk_at_003f3408[];
extern char vftableA[];

class RefObj_18d00 {
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
    RefObj_18d00* volatile mA; // 0x1c
    char pad2[4];        // 0x20
    RefObj_18d00* volatile mB; // 0x24
    void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)hulk_at_003f3408;
    RefObj_18d00* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)((char*)DAT_003f3390);
    RefObj_18d00* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((Tidier*)this)->Tidy_002326a0();
}
} // namespace fn_00018d00


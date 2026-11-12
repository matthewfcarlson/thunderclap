// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00237b70..0x00238190 (kind game, layer engine, confidence high), dominant class fight::SequenceTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f55fdae2 {
#define TREE_TU_END }
namespace fn_f55fdae2 {} using namespace fn_f55fdae2;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f55fdae2 {
class Obj_237b70 {
  public:
    char pad[12];
    void* GetBranch_00237b70();
};
class A_237b80 {
  public:
    char pad[0x18];
    int mVal;
    bool SetPriority_00237b80(int x);
};
class O_237b90 {
  public:
    char pad[0x1c];
    int m;
    int* GetConditionGroup_00237b90();
};
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5c04;
class CCondition_237bc0 {
  public:
    virtual int vfunc_0(int);
};
class Track_237bd0 {
  public:
    Track_237bd0();
    virtual void f();
    char pad[4];
};
class SequenceTrack : public Track_237bd0 {
  public:
    SequenceTrack();
    virtual void f();
    int flag;
    PartA a;
    int other;
    PartB b;
};
extern float hulk_at_003f3388;
extern void* hulk_at_00428100[];
struct S1_237c20 {
    void Fin_00236fd0();
};
struct S2_237c20 {
    void Fin_00234150();
};
class Track_237c20 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class SequenceTrack_237c20 : public Track_237c20 {
  public:
    char pad0[8];
    S2_237c20 s2;
    char pad[0x1c - 0xd];
    S1_237c20 s1;
    void f();
};
struct RefObj_237c90 {
    virtual void AddRef();
    virtual void Release();
};
extern "C" char DAT_00428130[];
struct SequenceAction {
    hulk_intptr vptr;
    char pad04[0x18];
    RefObj_237c90 *f1c;
    int f20;
    RefObj_237c90 *f24;
    int f28;
    int f2c;
    int f30;
    RefObj_237c90 *f34;
    int f38;

    void FUN_00232660();
    SequenceAction *FUN_00237c90(RefObj_237c90 *a, int b, RefObj_237c90 *c, int d, int e, int f, RefObj_237c90 *g);
};
class Ref_237d30 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Action_237d30 {
    void* vf;
    void Dtor_002326a0() throw();
};
struct SequenceAction_237d30 : Action_237d30 {
    char pad[0x18];
    Ref_237d30* p1c;
    void* p20;
    Ref_237d30* p24;
    char pad2[0xc];
    Ref_237d30* p34;
    Ref_237d30* p38;
    void Dtor2() throw();
};
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class CStageCondition_237e60;
class ParamValue_237e60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_237e60 : public ParamValue_237e60 {
  public:
    int pad;
};
extern int hulk_at_0049850c;
extern char hulk_at_004281ac[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver_2380a0 {
    void Finish_002367c0(Track*);
};
} // namespace fn_f55fdae2
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f55fdae2 {
class TrackFactoryTemplate_2380d0 {
  public:
    TrackFactoryTemplate_2380d0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00237f40();
extern "C" char DAT_00428100[];
typedef unsigned int u32_238110;
void* __cdecl operator_new(unsigned int);
struct Obj_238110 {
    void Ctor_00236d40();
};
struct Sub1_238110 {
    void Init1_00233dd0();
};
struct Sub2_238110 {
    void Init2_00236e00();
};
extern int hulk_at_004281b8;


// 0x00237b70 FUN_00237b70 (4 B): matches/0x00237b70.cpp
// sym: ?GetBranch_00237b70@Obj_237b70@fn_f55fdae2@@QAEPAXXZ
void* Obj_237b70::GetBranch_00237b70() {
    return (char*)this + 12;
}


// 0x00237b80 FUN_00237b80 (12 B): matches/0x00237b80.cpp
// sym: ?SetPriority_00237b80@A_237b80@fn_f55fdae2@@QAE_NH@Z
bool A_237b80::SetPriority_00237b80(int x) {
    mVal = x;
    return true;
}


// 0x00237b90 FUN_00237b90 (4 B): matches/0x00237b90.cpp
// sym: ?GetConditionGroup_00237b90@O_237b90@fn_f55fdae2@@QAEPAHXZ
int* O_237b90::GetConditionGroup_00237b90() {
    return &m;
}


// 0x00237ba0 FUN_00237ba0 (19 B): matches/0x00237ba0.cpp
// sym: ?FUN_00237ba0@fn_f55fdae2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00237ba0() {
    FUN_00234810(((char*)&DAT_004e5c04), ((char*)&DAT_004e5c08));
}

} // namespace fn_f55fdae2

// 0x00237bc0 fight::SequenceTrack::vfunc_0 (16 B): matches/0x00237bc0.cpp
// sym: ?vfunc_0@SequenceTrack@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::SequenceTrack::vfunc_0(int index) {
    int* p = hulk_at_004e5c04;
    return p[index];
}

namespace fn_f55fdae2 {

// 0x00237bd0 FUN_00237bd0 (48 B): matches/0x00237bd0.cpp
// sym: ??0SequenceTrack@fn_f55fdae2@@QAE@XZ
SequenceTrack::SequenceTrack() : Track_237bd0(), a(), other(1), b() {
    flag = 1;
}

} // namespace fn_f55fdae2

// 0x00237c00 fight::SequenceTrack::vfunc_6 (7 B): matches/0x00237c00.cpp
// sym: ?vfunc_6@SequenceTrack@fight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg fight::SequenceTrack::vfunc_6() {
    return DAT_003f32e0;
}


// 0x00237c10 fight::SequenceTrack::vfunc_7 (7 B): matches/0x00237c10.cpp
// sym: ?vfunc_7@SequenceTrack@fight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg fight::SequenceTrack::vfunc_7() {
    return hulk_at_003f3388;
}

namespace fn_f55fdae2 {

// 0x00237c20 FUN_00237c20 (33 B): matches/0x00237c20.cpp
// sym: ?f@SequenceTrack_237c20@fn_f55fdae2@@QAEXXZ
void SequenceTrack_237c20::f() {
    vptr = hulk_at_00428100;
    s1.Fin_00236fd0();
    s2.Fin_00234150();
    Fin_00236d60();
}

} // namespace fn_f55fdae2

// 0x00237c50 fight::SequenceTrack::vfunc_5 (54 B): matches/0x00237c50.cpp [wrapped: conflict: SequenceTrack]
// sym: ?V5@SequenceTrack@fn_00237c50@@UAEPAV12@H@Z
namespace fn_00237c50 {
extern char SequenceTrack_vftable[];
class SubA_237c50 {
  public:
    void Init_00236fd0();
};
class SubB_237c50 {
  public:
    void Init_00234150();
};
class SequenceTrack {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual SequenceTrack* V5(int);
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    char p[8];
    SubB_237c50 b;
    char q[0xf];
    SubA_237c50 a1;
    char r[8];
    void Finish_00236d60();
};
void __cdecl thunk_FUN_00267090(SequenceTrack*);
SequenceTrack* SequenceTrack::V5(int x) {
    *(char**)this = ((char*)DAT_00428100);
    a1.Init_00236fd0();
    b.Init_00234150();
    Finish_00236d60();
    if (x & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00237c50

namespace fn_f55fdae2 {

// 0x00237c90 FUN_00237c90 (156 B): matches/0x00237c90.cpp
// sym: ?FUN_00237c90@SequenceAction@fn_f55fdae2@@QAEPAU12@PAURefObj_237c90@2@H0HHH0@Z
// FUN_00237c90 @ 0x00237c90
// FUN_00237c90: fight::SequenceAction constructor
SequenceAction *SequenceAction::FUN_00237c90(RefObj_237c90 *a, int b, RefObj_237c90 *c, int d, int e, int f, RefObj_237c90 *g)
{
    FUN_00232660();
    vptr = (hulk_intptr)DAT_00428130;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = d;
    f2c = e;
    f30 = f;
    f34 = 0;
    f38 = 0;
    if (a)
        a->AddRef();
    if (f1c)
        f1c->Release();
    f1c = a;
    f20 = b;
    if (c)
        c->AddRef();
    if (f24)
        f24->Release();
    f24 = c;
    if (g)
        g->AddRef();
    if (f34)
        f34->Release();
    f34 = g;
    return this;
}


// 0x00237d30 FUN_00237d30 (89 B): matches/0x00237d30.cpp
// sym: ?Dtor2@SequenceAction_237d30@fn_f55fdae2@@QAEXXZ
void SequenceAction_237d30::Dtor2() throw() {
    vf = vSeq;
    _ReadWriteBarrier();
    if (p38) {
        p38->Release();
        p38 = 0;
    }
    if (p34) {
        p34->Release();
        p34 = 0;
    }
    if (p24) {
        p24->Release();
        p24 = 0;
    }
    if (p20)
        p20 = 0;
    if (p1c) {
        p1c->Release();
        p1c = 0;
    }
    Action_237d30::Dtor_002326a0();
}

} // namespace fn_f55fdae2

// 0x00237d90 fight::SequenceAction::vfunc_4 (96 B): matches/0x00237d90.cpp [wrapped: conflict: SequenceAction]
// sym: ?vfunc_4@SequenceAction@fn_00237d90@@UAEXXZ
namespace fn_00237d90 {
class ResultObj {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    void init_00231ad0(int a, int b, int c);
};

class Creator {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual ResultObj* create(int a, int b);
};

class Sub_237d90 {
  public:
    char fn_00236f40(int a, int b, int c);
};

class SequenceAction {
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vfunc_4();
    virtual void vf5();

    char pad[0x18];
    int m1c;
    char pad2[4];
    Creator* mCreator;
    volatile int m28;
    Sub_237d90* m2c;
    volatile int m30;
    volatile int m34;
    ResultObj* volatile m38;
};

void SequenceAction::vfunc_4() {
    if (!mCreator)
        return;
    if (!m2c->fn_00236f40(m1c, m34, 0))
        return;
    ResultObj* edi = mCreator->create(m34, 0);
    if (!edi)
        return;
    edi->vfunc_0();
    ResultObj* cur = m38;
    if (cur)
        cur->vfunc_1();
    m38 = edi;
    edi->init_00231ad0(m30, m34, m28);
}
} // namespace fn_00237d90

namespace fn_f55fdae2 {

// 0x00237e10 fight::ParamBranch<fight::SequenceTrack>::vfunc_6 (12 B): matches/0x00237e10.cpp
// sym: ?vfunc_6@ParamBranch@fn_f55fdae2@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f55fdae2

// 0x00237e40 fight::ParamIntConstRange<fight::SequenceTrack>::vfunc_6 (26 B): matches/0x00237e40.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VSequenceTrack@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<fight::SequenceTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<fight::SequenceTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<fight::SequenceTrack>*)a)->*(*(bool (fight::ParamIntConstRange<fight::SequenceTrack>::**)(int))&this->f_10))(b);
}


// 0x00237e60 fight::ParamIntConstRange<fight::SequenceTrack>::vfunc_2 (11 B): matches/0x00237e60.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VSequenceTrack@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<fight::SequenceTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00237e90 fight::ParamConditionGroup<fight::SequenceTrack>::vfunc_6 (12 B): matches/0x00237e90.cpp [wrapped: same definition as 0x00237e10 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00237e90@@UAEXPAX@Z
namespace fn_00237e90 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_00237e90


// 0x00237eb0 fight::TrackFactoryCasterTemplate<fight::SequenceTrack>::vfunc_0 (36 B): matches/0x00237eb0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSequenceTrack@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<fight::SequenceTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00237ee0 fight::ParamBranch<fight::SequenceTrack>::vfunc_0 (30 B): matches/0x00237ee0.cpp
// sym: ??_G?$ParamBranch@VSequenceTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<fight::SequenceTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<fight::SequenceTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x237ee0)
#endif


// 0x00237f00 fight::ParamIntConstRange<fight::SequenceTrack>::vfunc_0 (30 B): matches/0x00237f00.cpp
// sym: ??_G?$ParamIntConstRange@VSequenceTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<fight::SequenceTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<fight::SequenceTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x237f00)
#endif


// 0x00237f20 fight::ParamConditionGroup<fight::SequenceTrack>::vfunc_0 (30 B): matches/0x00237f20.cpp
// sym: ??_G?$ParamConditionGroup@VSequenceTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamConditionGroup<fight::SequenceTrack>::~ParamConditionGroup() {}
#if defined(HULK_PTR64)
template class fight::ParamConditionGroup<fight::SequenceTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x237f20)
#endif


// 0x00237f40 FUN_00237f40 (213 B): equivalent/0x00237f40.cpp [wrapped: conflict: fight::ParamBranch; fight::ParamConditionGroup; fight::ParamIntConstRange]
// sym: ?target@fn_00237f40@@YAXXZ @c090cd98f637 @w5cffb4f32e98
namespace fn_00237f40 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00237f40 @ 0x00237f40


void* __cdecl FUN_0008d690(unsigned int);
void __cdecl GetBranch_00237b70(); void __cdecl SetPriority_00237b80(); void __cdecl GetConditionGroup_00237b90();
 
namespace fight {
class SequenceTrack;
template<class T> struct ParamBranch { virtual void v0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00235170(const char*); };
template<class T> struct ParamIntConstRange { virtual void v0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_002348e0(const char*); };
template<class T> struct ParamConditionGroup { virtual void v0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00235220(const char*); };
}
extern "C" void __cdecl FUN_002347b0(int*, void**, int);
void target() {
 if (!DAT_004e5c08) {
 void* values[3];
 fight::ParamBranch<fight::SequenceTrack>* a = (fight::ParamBranch<fight::SequenceTrack>*)FUN_0008d690((int)sizeof(fight::ParamBranch<fight::SequenceTrack>));
 if(a) { a->FUN_00235170("branch"); new(a) fight::ParamBranch<fight::SequenceTrack>; a->callback=GetBranch_00237b70; } values[0]=a;
 fight::ParamIntConstRange<fight::SequenceTrack>* b = (fight::ParamIntConstRange<fight::SequenceTrack>*)FUN_0008d690((int)sizeof(fight::ParamIntConstRange<fight::SequenceTrack>));
 if(b) { b->FUN_002348e0("priority"); new(b) fight::ParamIntConstRange<fight::SequenceTrack>; b->callback=SetPriority_00237b80; } values[1]=b;
 fight::ParamConditionGroup<fight::SequenceTrack>* c = (fight::ParamConditionGroup<fight::SequenceTrack>*)FUN_0008d690((int)sizeof(fight::ParamConditionGroup<fight::SequenceTrack>));
 if(c) { c->FUN_00235220("conditionGroup"); new(c) fight::ParamConditionGroup<fight::SequenceTrack>; c->callback=GetConditionGroup_00237b90; } values[2]=c;
 FUN_002347b0(&DAT_004e5c04,values,3);
 }
 ++DAT_004e5c08;
}
} // namespace fn_00237f40


// 0x00238020 fight::SequenceTrack::vfunc_10 (62 B): matches/0x00238020.cpp [wrapped: conflict: SequenceTrack]
// sym: ?vfunc_10@SequenceTrack@fn_00238020@@QAEIIII@Z
namespace fn_00238020 {
typedef unsigned int u32_238020;
extern void* Alloc_0008d690(unsigned int);
class Builder {
  public:
    u32_238020 Run_00237c90(u32_238020, hulk_uintptr, u32_238020, u32_238020, void*, u32_238020, u32_238020);
};
class Track {
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
    virtual void v9();
};
class SequenceTrack : public Track {
  public:
    char pad[8];
    u32_238020 field0c;
    char pad10[8];
    u32_238020 field18;
    char pad1c[4];
    u32_238020 vfunc_10(u32_238020, u32_238020, u32_238020);
};
u32_238020 SequenceTrack::vfunc_10(u32_238020 a, u32_238020 b, u32_238020 c) {
    Builder* p = (Builder*)Alloc_0008d690(0x3c);
    if (p) {
        u32_238020 x = field0c;
        return p->Run_00237c90(a, (hulk_uintptr)this, x, field18, &pad1c, b, c);
    }
    return 0;
}
} // namespace fn_00238020


// 0x00238060 fight::SequenceAction::vfunc_2 (30 B): matches/0x00238060.cpp
// sym: ??_GSequenceAction@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
fight::SequenceAction::~SequenceAction() {}

namespace fn_f55fdae2 {

// 0x002380a0 FUN_002380a0 (38 B): matches/0x002380a0.cpp
// sym: _FUN_002380a0
extern "C" void FUN_002380a0(Receiver_2380a0* c, int b) {
    Track t;
    *(void**)&t = hulk_at_004281ac;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish_002367c0(p);
}

} // namespace fn_f55fdae2

// 0x002380d0 fight::TrackFactoryCasterTemplate<fight::SequenceTrack>::vfunc_1 (60 B): matches/0x002380d0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VSequenceTrack@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<fight::SequenceTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_2380d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_2380d0* t = new (mem) TrackFactoryTemplate_2380d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00237f40();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00238110 fight::TrackFactoryTemplate<fight::SequenceTrack>::vfunc_5 (68 B): matches/0x00238110.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VSequenceTrack@fight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<fight::SequenceTrack>::vfunc_5() {
    Obj_238110* p = (Obj_238110*)operator_new(0x20);
    if (p) {
        p->Ctor_00236d40();
        Sub1_238110* s1 = (Sub1_238110*)((char*)p + 0xc);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00428100);
        s1->Init1_00233dd0();
        Sub2_238110* s2 = (Sub2_238110*)((char*)p + 0x1c);
        *(u32_238110*)((char*)p + 0x18) = 1;
        s2->Init2_00236e00();
        *(u32_238110*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f55fdae2 {

// 0x00238160 fight::TrackFactoryTemplate<fight::SequenceTrack>::vfunc_2 (43 B): matches/0x00238160.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f55fdae2@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004281b8;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f55fdae2

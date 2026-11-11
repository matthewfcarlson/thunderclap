// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023f0d0..0x0023f670 (kind game, layer engine, confidence high), dominant class fight::BreakPointTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f27320e9 {
#define TREE_TU_END }
namespace fn_f27320e9 {} using namespace fn_f27320e9;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f27320e9 {
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5c88;
class CCondition_23f110 {
  public:
    virtual int vfunc_0(int);
};
class Track_23f120 {
  public:
    Track_23f120();
    virtual void f();
};
class BreakPointTrack : public Track_23f120 {
  public:
    BreakPointTrack();
    virtual void f();
    int unused;
    int flag;
    int zero;
    Part part;
};
extern void* hulk_at_00428f70[];
struct Sub_23f170 {
    void Fin_00236fd0();
};
class Track_23f170 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class BreakPointTrack_23f170 : public Track_23f170 {
  public:
    char pad[0xc];
    Sub_23f170 sub;
    void f();
};
typedef unsigned int u32_23f1d0;
typedef unsigned char u8_23f1d0;
class BreakPointAction {
    char pad[0x20];

  public:
    u32_23f1d0 member;
    u8_23f1d0 vfunc_3(u32_23f1d0 a, u32_23f1d0 b);
};
extern char threat_vftable_23f1f0;
struct BreakPointTrack_nv_23f1f0 {
    void f1_00236fd0();
    void f2_00236d60();
};
extern void thunk_FUN_00267090(fight::BreakPointTrack*);
class BreakPointTrack_23f1f0 {
  public:
    void* vftable;
    char pad[0x0c];
    BreakPointTrack_23f1f0* vfunc_5(unsigned char);
};
struct Obj_23f220 {
    virtual void F();
    virtual void R();
};
extern int hulk_at_00428fa0;
struct BreakPointAction_23f220 {
    void* vf;
    int pad[6];
    int arg;
    Obj_23f220* object;
    void Init_00232660();
    BreakPointAction_23f220* Build(int, Obj_23f220*);
};
extern void* g_vftable_23f270[];
class Ref_23f270 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_23f270 {
  public:
    void* vptr;
};
class BreakPointAction_23f270 : public Action_23f270 {
  public:
    char pad[28];
    Ref_23f270* m;
    ~BreakPointAction_23f270();
};
class CStageCondition_23f2e0;
class ParamValue_23f2e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_23f2e0 : public ParamValue_23f2e0 {
  public:
    int pad;
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
extern int hulk_at_0049850c;
} // namespace fn_f27320e9
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_f27320e9 {
class Ref {
  public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};
} // namespace fn_f27320e9
namespace fight {
class Track_23f440 {
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
    virtual void* vfunc_10(int, int, Ref*);
};
}
namespace fight {
class Param_23f440 {};
}
namespace fight {
class BreakPointActionBase {
  public:
    BreakPointActionBase() throw();
    virtual void v0();
    char pad[0x18];
};
}
namespace fight {
class BreakPointAction_23f440 : public BreakPointActionBase {
  public:
    fight::BreakPointTrack* owner;
    Ref* ref;
    BreakPointAction_23f440(fight::BreakPointTrack* o, Ref* r) throw() : owner(o), ref(0) {
        if (r)
            r->AddRef();
        if (ref)
            ref->Release();
        ref = r;
    }
    virtual void v0();
};
}
namespace fn_f27320e9 {
extern void* g_vftable_23f4a0[];
class Ref_23f4a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_23f4a0 {
  public:
    void* vptr;
};
class BreakPointAction_23f4a0 : public Action_23f4a0 {
  public:
    char pad[0x1c];
    Ref_23f4a0* m;
    BreakPointAction_23f4a0* f2(unsigned char flags);
};
extern char hulk_at_00428ffc[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver_23f500 {
    void Finish_002367c0(Track*);
};
} // namespace fn_f27320e9
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f27320e9 {
class TrackFactoryTemplate_23f530 {
  public:
    TrackFactoryTemplate_23f530() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0023f3a0();
class Base_23f570 {
  public:
    void init_00236d40();
};
class Sub_23f570 {
  public:
    void init2_00236e00();
};
struct Obj_23f570 {
    hulk_intptr vf;
    int a;
    int b;
    int c;
};
extern int breakpoint_vftable;
extern "C" void* __cdecl alloc(hulk_uintptr);
extern int hulk_at_00429008;

} // namespace fn_f27320e9

// 0x0023f0d0 FUN_0023f0d0 (12 B): matches/0x0023f0d0.cpp
// sym: ?FUN_0023f0d0@Obj_23f0d0@owners@@QAE_NH@Z
bool owners::Obj_23f0d0::FUN_0023f0d0(int x) {
    value = x;
    return true;
}


// 0x0023f0e0 FUN_0023f0e0 (4 B): matches/0x0023f0e0.cpp
// sym: ?FUN_0023f0e0@Obj_23f0e0@owners@@QAEPAXXZ
void* owners::Obj_23f0e0::FUN_0023f0e0() {
    return (char*)this + 0x10;
}

namespace fn_f27320e9 {

// 0x0023f0f0 FUN_0023f0f0 (19 B): matches/0x0023f0f0.cpp
// sym: ?FUN_0023f0f0@fn_f27320e9@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0023f0f0() {
    FUN_00234810(((char*)&DAT_004e5c88), ((char*)&DAT_004e5c8c));
}

} // namespace fn_f27320e9

// 0x0023f110 fight::BreakPointTrack::vfunc_0 (16 B): matches/0x0023f110.cpp
// sym: ?vfunc_0@BreakPointTrack@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::BreakPointTrack::vfunc_0(int index) {
    int* p = hulk_at_004e5c88;
    return p[index];
}

namespace fn_f27320e9 {

// 0x0023f120 FUN_0023f120 (40 B): matches/0x0023f120.cpp
// sym: ??0BreakPointTrack@fn_f27320e9@@QAE@XZ
BreakPointTrack::BreakPointTrack() : Track_23f120(), zero(0), part() {
    flag = 1;
}

} // namespace fn_f27320e9

// 0x0023f150 fight::BreakPointTrack::vfunc_6 (4 B): matches/0x0023f150.cpp
// sym: ?vfunc_6@BreakPointTrack@fight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg fight::BreakPointTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0023f160 fight::BreakPointTrack::vfunc_7 (7 B): matches/0x0023f160.cpp
// sym: ?vfunc_7@BreakPointTrack@fight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg fight::BreakPointTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f27320e9 {

// 0x0023f170 FUN_0023f170 (25 B): matches/0x0023f170.cpp
// sym: ?f@BreakPointTrack_23f170@fn_f27320e9@@QAEXXZ
void BreakPointTrack_23f170::f() {
    vptr = hulk_at_00428f70;
    sub.Fin_00236fd0();
    Fin_00236d60();
}


// 0x0023f1a0 FUN_0023f1a0 (6 B): matches/0x0023f1a0.cpp
// sym: _FUN_0023f1a0
extern "C" int* FUN_0023f1a0() {
    return (*(int**)&DAT_004e5c94);
}


// 0x0023f1d0 fight::BreakPointAction::vfunc_3 (30 B): matches/0x0023f1d0.cpp
// sym: ?vfunc_3@BreakPointAction@fn_f27320e9@@QAEEII@Z
// data: g_arg = DAT_004e5c94
u8_23f1d0 BreakPointAction::vfunc_3(u32_23f1d0 a, u32_23f1d0 b) {
    if ((*(u32_23f1d0*)&DAT_004e5c90)) {
        typedef void(__cdecl * Fn)(u32_23f1d0, u32_23f1d0);
        ((Fn)(*(u32_23f1d0*)&DAT_004e5c90))(member, (*(u32_23f1d0*)&DAT_004e5c94));
    }
    return 0;
}


// 0x0023f1f0 fight::BreakPointTrack::vfunc_5 (46 B): matches/0x0023f1f0.cpp
// sym: ?vfunc_5@BreakPointTrack_23f1f0@fn_f27320e9@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
BreakPointTrack_23f1f0* BreakPointTrack_23f1f0::vfunc_5(unsigned char param) {
    BreakPointTrack_23f1f0* p = this;
    *(char**)p = &threat_vftable_23f1f0;
    ((BreakPointTrack_nv_23f1f0*)(((fight::BreakPointTrack*)((char*)p + 0x10))))->f1_00236fd0();
    ((BreakPointTrack_nv_23f1f0*)(((fight::BreakPointTrack*)p)))->f2_00236d60();
    if (param & 1)
        thunk_FUN_00267090((fight::BreakPointTrack*)p);
    return p;
}


// 0x0023f220 FUN_0023f220 (65 B): matches/0x0023f220.cpp
// sym: ?Build@BreakPointAction_23f220@fn_f27320e9@@QAEPAU12@HPAUObj_23f220@2@@Z
// Same code shape as 0x0012db50 (propagated; names are from that function)
BreakPointAction_23f220* BreakPointAction_23f220::Build(int a, Obj_23f220* p) {
    Init_00232660();
    vf = &hulk_at_00428fa0;
    object = 0;
    arg = a;
    if (p)
        p->F();
    if (object)
        object->R();
    object = p;
    return this;
}


// 0x0023f270 FUN_0023f270 (36 B): matches/0x0023f270.cpp
// sym: ??1BreakPointAction_23f270@fn_f27320e9@@QAE@XZ
BreakPointAction_23f270::~BreakPointAction_23f270() {
    vptr = g_vftable_23f270;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_23f270 *)this)->FUN_002326a0();
}

} // namespace fn_f27320e9

// 0x0023f2c0 fight::ParamFloatConstRange<fight::BreakPointTrack>::vfunc_6 (26 B): matches/0x0023f2c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VBreakPointTrack@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::BreakPointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<fight::BreakPointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<fight::BreakPointTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<fight::BreakPointTrack>::**)(int))&this->f_10))(b);
}


// 0x0023f2e0 fight::ParamFloatConstRange<fight::BreakPointTrack>::vfunc_2 (11 B): matches/0x0023f2e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VBreakPointTrack@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::BreakPointTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f27320e9 {

// 0x0023f310 fight::ParamConditionGroup<fight::BreakPointTrack>::vfunc_6 (12 B): matches/0x0023f310.cpp
// sym: ?vfunc_6@ParamBranch@fn_f27320e9@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f27320e9

// 0x0023f330 fight::TrackFactoryCasterTemplate<fight::BreakPointTrack>::vfunc_0 (36 B): matches/0x0023f330.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VBreakPointTrack@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<fight::BreakPointTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023f360 fight::ParamFloatConstRange<fight::BreakPointTrack>::vfunc_0 (30 B): matches/0x0023f360.cpp
// sym: ??_G?$ParamFloatConstRange@VBreakPointTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<fight::BreakPointTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<fight::BreakPointTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x23f360)
#endif


// 0x0023f380 fight::ParamConditionGroup<fight::BreakPointTrack>::vfunc_0 (30 B): matches/0x0023f380.cpp
// sym: ??_G?$ParamConditionGroup@VBreakPointTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamConditionGroup<fight::BreakPointTrack>::~ParamConditionGroup() {}
#if defined(HULK_PTR64)
template class fight::ParamConditionGroup<fight::BreakPointTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x23f380)
#endif


// 0x0023f440 fight::BreakPointTrack::vfunc_10 (86 B): matches/0x0023f440.cpp
// sym: ?vfunc_10@BreakPointTrack@fight@@UAEHHHH@Z
 // namespace fight
hulk_intptr fight::BreakPointTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr __p2) { Ref * r = (Ref *)__p2;

    return (hulk_intptr)(new BreakPointAction_23f440(this, r));
}

namespace fn_f27320e9 {

// 0x0023f4a0 fight::BreakPointAction::vfunc_2 (57 B): matches/0x0023f4a0.cpp
// sym: ?f2@BreakPointAction_23f4a0@fn_f27320e9@@QAEPAV12@E@Z
BreakPointAction_23f4a0* BreakPointAction_23f4a0::f2(unsigned char flags) {
    vptr = g_vftable_23f4a0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_23f4a0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x0023f500 FUN_0023f500 (38 B): matches/0x0023f500.cpp
// sym: _FUN_0023f500
extern "C" void FUN_0023f500(Receiver_23f500* c, int b) {
    Track t;
    *(void**)&t = hulk_at_00428ffc;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish_002367c0(p);
}

} // namespace fn_f27320e9

// 0x0023f530 fight::TrackFactoryCasterTemplate<fight::BreakPointTrack>::vfunc_1 (60 B): matches/0x0023f530.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VBreakPointTrack@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<fight::BreakPointTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_23f530));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_23f530* t = new (mem) TrackFactoryTemplate_23f530();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0023f3a0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0023f570 fight::TrackFactoryTemplate<fight::BreakPointTrack>::vfunc_5 (60 B): matches/0x0023f570.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VBreakPointTrack@fight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<fight::BreakPointTrack>::vfunc_5() {
    Obj_23f570* p = (Obj_23f570*)alloc(0x14);
    if (p) {
        ((Base_23f570*)p)->init_00236d40();
        p->vf = (hulk_intptr)&breakpoint_vftable;
        p->c = 0;
        ((Sub_23f570*)((char*)p + 0x10))->init2_00236e00();
        p->b = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f27320e9 {

// 0x0023f5b0 fight::TrackFactoryTemplate<fight::BreakPointTrack>::vfunc_2 (43 B): matches/0x0023f5b0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f27320e9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00429008;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f27320e9

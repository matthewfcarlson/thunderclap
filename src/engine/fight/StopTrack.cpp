// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023e4d0..0x0023ea20 (kind game, layer engine, confidence high), dominant class fight::StopTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fe4accdf {
#define TREE_TU_END }
namespace fn_fe4accdf {} using namespace fn_fe4accdf;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fe4accdf {
class Obj_23e4d0 {
  public:
    char pad[12];
    int mValue;
    bool SetTimeBegin_0023e4d0(int x);
};
class X_23e4e0 {
  public:
    char pad[0x10];
    int value;
    bool SetTimeEnd_0023e4e0(int value);
};
class Sub_23e4f0 {
  public:
    char pad[0x14];
};
class Obj_23e4f0 {
  public:
    char pad[0x14];
    Sub_23e4f0 sub;
    Sub_23e4f0* GetConditionGroup_0023e4f0();
};
extern "C" void FUN_00234810(void*, void*);
extern int* gTable_23e520;
class CCondition_23e520 {
  public:
    virtual int vfunc_0(int);
};
class Track_23e530 {
  public:
    Track_23e530();
    virtual void fn();
};
class StopTrack : public Track_23e530 {
  public:
    StopTrack();
    virtual void fn();
    char pad[8];
    int value;
    float speed;
    Part part;
};
struct Param_23e570 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_23e570 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class Inner_23e580 {
  public:
    void Init();
};
struct StopTrack_nv_23e580 {
    void Finish();
};
extern int StopTrack_vftable;
extern int gState_23e5a0;
class Helper_23e5a0 {
  public:
    bool Check(int, int, int);
};
class Finisher {
  public:
    void Finish();
};
class Ref_23e610 {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_23e610 {
  public:
    void Init();
};
extern int StopVtable;
class StopAction : public Action_23e610 {
  public:
    char pad[0x1c];
    Ref_23e610* mRef;
    int mValue;
    int mArg;
    Ref_23e610* mOther;
    StopAction(Ref_23e610*, int, int, Ref_23e610*);
};
extern void* vStop[];
class Ref_23e670 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Action_23e670 {
    void* vf;
    void Dtor() throw();
};
struct StopAction_23e670 : Action_23e670 {
    char pad[0x18];
    Ref_23e670* p1c;
    char pad2[8];
    Ref_23e670* p28;
    void Dtor2() throw();
};
class CStageCondition_23e6e0;
class ParamValue_23e6e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_23e6e0 : public ParamValue_23e6e0 {
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
extern int gTypeA_23e730;
typedef unsigned int U_23e880;
extern void* __cdecl FUN_0008d690(int);
class Helper_23e880 {
  public:
    U_23e880 FUN_0023e610(U_23e880, hulk_uintptr, U_23e880, U_23e880);
};
extern "C" char DAT_00428de0[];
class Ref_23e8c0 {
  public:
    virtual void f0();
    virtual void f1();
};
class StopAction_23e8c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual StopAction_23e8c0* vfunc_2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[0x18];
    Ref_23e8c0* m1c;
    char pad20[8];
    Ref_23e8c0* volatile m28;
};
void destroy(StopAction_23e8c0*);
extern char VT_23e930[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver_23e930 {
    void Finish(Track*);
};
extern "C" char DAT_00428db0[];
extern "C" void* __cdecl operator_new(unsigned int);
class Inner_23e9a0 {
  public:
    void init();
};
class StopTrack_23e9a0 {
  public:
    virtual void dummy();
    char pad4[4];
    int flag;
    int zero;
    float value;
    Inner_23e9a0 inner;
    void init();
};
extern int g_vftable_23e9f0;


// 0x0023e4d0 FUN_0023e4d0 (12 B): matches/0x0023e4d0.cpp
// sym: ?SetTimeBegin_0023e4d0@Obj_23e4d0@fn_fe4accdf@@QAE_NH@Z
bool Obj_23e4d0::SetTimeBegin_0023e4d0(int x) {
    mValue = x;
    return true;
}


// 0x0023e4e0 FUN_0023e4e0 (12 B): matches/0x0023e4e0.cpp
// sym: ?SetTimeEnd_0023e4e0@X_23e4e0@fn_fe4accdf@@QAE_NH@Z
bool X_23e4e0::SetTimeEnd_0023e4e0(int value) {
    this->value = value;
    return true;
}


// 0x0023e4f0 FUN_0023e4f0 (4 B): matches/0x0023e4f0.cpp
// sym: ?GetConditionGroup_0023e4f0@Obj_23e4f0@fn_fe4accdf@@QAEPAVSub_23e4f0@2@XZ
Sub_23e4f0* Obj_23e4f0::GetConditionGroup_0023e4f0() {
    return &sub;
}


// 0x0023e500 FUN_0023e500 (19 B): matches/0x0023e500.cpp
// sym: ?FUN_0023e500@fn_fe4accdf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0023e500() {
    FUN_00234810(((char*)&DAT_004e5c74), ((char*)&DAT_004e5c78));
}

} // namespace fn_fe4accdf

// 0x0023e520 fight::StopTrack::vfunc_0 (16 B): matches/0x0023e520.cpp
// sym: ?vfunc_0@StopTrack@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::StopTrack::vfunc_0(int index) {
    int* p = gTable_23e520;
    return p[index];
}

namespace fn_fe4accdf {

// 0x0023e530 FUN_0023e530 (47 B): matches/0x0023e530.cpp
// sym: ??0StopTrack@fn_fe4accdf@@QAE@XZ
StopTrack::StopTrack() : Track_23e530(), value(0), speed(-1.0f), part() {
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_fe4accdf

// 0x0023e560 fight::StopTrack::vfunc_6 (4 B): matches/0x0023e560.cpp
// sym: ?vfunc_6@StopTrack@fight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg fight::StopTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0023e570 fight::StopTrack::vfunc_7 (7 B): matches/0x0023e570.cpp
// sym: ?vfunc_7@StopTrack@fight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg fight::StopTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}


// 0x0023e580 FUN_0023e580 (25 B): matches/0x0023e580.cpp
// sym: ?FUN_0023e580@StopTrack@fight@@QAEXXZ
void fight::StopTrack::FUN_0023e580() {
    *(hulk_intptr*)this = (hulk_intptr)&StopTrack_vftable;
    ((Inner_23e580*)((char*)this + 0x14))->Init();
    ((StopTrack_nv_23e580*)this)->Finish();
}


// 0x0023e5a0 fight::StopAction::vfunc_5 (60 B): matches/0x0023e5a0.cpp
// sym: ?vfunc_5@StopAction@fight@@UAE_NHH@Z
 // namespace fight
bool fight::StopAction::vfunc_5(hulk_intptr value, int unused) {
    if (value == gState_23e5a0) {
        if (((char*)(*(Helper_23e5a0 * *)&this->f_20), ((Helper_23e5a0*)((char*)(*(Helper_23e5a0 * *)&this->f_20) + 0x14)))->Check(this->f_1c, this->f_28, 0)) {
            (*(Finisher * *)&this->f_24)->Finish();
            return false;
        }
    }
    return true;
}


// 0x0023e5e0 fight::StopTrack::vfunc_5 (46 B): matches/0x0023e5e0.cpp [wrapped: conflict: StopTrack]
// sym: ?vfunc_5@StopTrack@fn_0023e5e0@@UAEPAV12@E@Z
namespace fn_0023e5e0 {
extern "C" char DAT_00428db0[];
class Helper_23e5e0 {
  public:
    void first();
};
class StopTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual StopTrack* vfunc_5(unsigned char flag);
    char pad[0x14 - 4];
    Helper_23e5e0 h;
    void second();
};
void __cdecl destroy(StopTrack*);

StopTrack* StopTrack::vfunc_5(unsigned char flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_00428db0);
    h.first();
    second();
    if (flag & 1)
        destroy(this);
    return this;
}
} // namespace fn_0023e5e0

namespace fn_fe4accdf {

// 0x0023e610 FUN_0023e610 (83 B): matches/0x0023e610.cpp
// sym: ??0StopAction@fn_fe4accdf@@QAE@PAVRef_23e610@1@HH0@Z
StopAction::StopAction(Ref_23e610* a, int b, int c, Ref_23e610* d) {
    Init();
    *(hulk_intptr*)this = (hulk_intptr)&StopVtable;
    mArg = c;
    mOther = 0;
    mRef = a;
    a->Add();
    mValue = b;
    if (d)
        d->Add();
    if (mOther)
        mOther->Release();
    mOther = d;
}


// 0x0023e670 FUN_0023e670 (44 B): matches/0x0023e670.cpp
// sym: ?Dtor2@StopAction_23e670@fn_fe4accdf@@QAEXXZ
void StopAction_23e670::Dtor2() throw() {
    vf = vStop;
    _ReadWriteBarrier();
    if (p28) {
        p28->Release();
        p28 = 0;
    }
    p1c->Release();
    Action_23e670::Dtor();
}

} // namespace fn_fe4accdf

// 0x0023e6c0 fight::ParamFloatConstRange<fight::StopTrack>::vfunc_6 (26 B): matches/0x0023e6c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VStopTrack@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::StopTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<fight::StopTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<fight::StopTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<fight::StopTrack>::**)(int))&this->f_10))(b);
}


// 0x0023e6e0 fight::ParamFloatConstRange<fight::StopTrack>::vfunc_2 (11 B): matches/0x0023e6e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VStopTrack@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::StopTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_fe4accdf {

// 0x0023e710 fight::ParamConditionGroup<fight::StopTrack>::vfunc_6 (12 B): matches/0x0023e710.cpp
// sym: ?vfunc_6@ParamBranch@fn_fe4accdf@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fe4accdf

// 0x0023e730 fight::TrackFactoryCasterTemplate<fight::StopTrack>::vfunc_0 (36 B): matches/0x0023e730.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VStopTrack@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<fight::StopTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_23e730, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023e760 fight::ParamFloatConstRange<fight::StopTrack>::vfunc_0 (30 B): matches/0x0023e760.cpp
// sym: ??_G?$ParamFloatConstRange@VStopTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<fight::StopTrack>::~ParamFloatConstRange() {}


// 0x0023e780 fight::ParamConditionGroup<fight::StopTrack>::vfunc_0 (30 B): matches/0x0023e780.cpp
// sym: ??_G?$ParamConditionGroup@VStopTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamConditionGroup<fight::StopTrack>::~ParamConditionGroup() {}


// 0x0023e880 fight::StopTrack::vfunc_10 (50 B): matches/0x0023e880.cpp
// sym: ?vfunc_10@StopTrack@fight@@UAEHHHH@Z
hulk_intptr fight::StopTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { U_23e880 a = (U_23e880)__p0; U_23e880 b = (U_23e880)__p1; U_23e880 c = (U_23e880)__p2;

    Helper_23e880* p = (Helper_23e880*)FUN_0008d690(0x2c);
    if (p)
        return (int)(p->FUN_0023e610(a, (hulk_uintptr)this, b, c));
    return (int)(0);
}

namespace fn_fe4accdf {

// 0x0023e8c0 fight::StopAction::vfunc_2 (65 B): matches/0x0023e8c0.cpp
// sym: ?vfunc_2@StopAction_23e8c0@fn_fe4accdf@@UAEPAV12@E@Z
StopAction_23e8c0* StopAction_23e8c0::vfunc_2(unsigned char param) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_00428de0);
    Ref_23e8c0* r = m28;
    if (r) {
        r->f1();
        m28 = 0;
    }
    m1c->f1();
    ((fight::Action *)this)->FUN_002326a0();
    if (param & 1)
        destroy(this);
    return this;
}


// 0x0023e930 FUN_0023e930 (38 B): matches/0x0023e930.cpp
// sym: _FUN_0023e930
extern "C" void FUN_0023e930(Receiver_23e930* c, int b) {
    Track t;
    *(void**)&t = VT_23e930;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish(p);
}

} // namespace fn_fe4accdf

// 0x0023e9a0 fight::TrackFactoryTemplate<fight::StopTrack>::vfunc_5 (67 B): matches/0x0023e9a0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VStopTrack@fight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<fight::StopTrack>::vfunc_5() {
    StopTrack_23e9a0* p = (StopTrack_23e9a0*)operator_new(0x18);
    if (p) {
        p->init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00428db0);
        p->zero = 0;
        p->value = -1.0f;
        p->inner.init();
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fe4accdf {

// 0x0023e9f0 fight::TrackFactoryTemplate<fight::StopTrack>::vfunc_2 (43 B): matches/0x0023e9f0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fe4accdf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_23e9f0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fe4accdf

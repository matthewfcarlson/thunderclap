// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023ea20..0x0023f0d0 (kind game, layer engine, confidence high), dominant class fight::SpawnTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7aacfaa {
#define TREE_TU_END }
namespace fn_f7aacfaa {} using namespace fn_f7aacfaa;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f7aacfaa {
class Obj_23ea20 {
  public:
    char pad[0xc];
    int mVal;
    bool SetTimeBegin_0023ea20(int x);
};
class X_23ea30 {
  public:
    char pad[0x10];
    int m10;
    char SetTimeEnd_0023ea30(int value);
};
class A_23ea40 {
  public:
    char pad[0x14];
    int* GetBranch_0023ea40();
};
class O_23ea50 {
  public:
    char pad[32];
    void* GetConditionGroup_0023ea50();
};
extern "C" void FUN_00234810(void*, void*);
extern int* gTable_23ea80;
class CCondition_23ea80 {
  public:
    virtual int vfunc_0(int);
};
struct Param_23eae0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_23eae0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" char DAT_00428e80[];
struct SubA_23eaf0 {
    void A();
};
struct SubB_23eaf0 {
    void B();
};
struct SpawnTrack_nv_23eaf0 {
    void Fin();
};
struct Sub_23eb20 {
    void Set(int, int);
    bool Done();
};
struct Res_23eb20 {
    void Bind(Sub_23eb20*, int, int);
};
struct Inner_23eb20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Res_23eb20* Check(int, int);
};
struct Check20 {
    char p[0x20];
    bool Ready(int, int, int);
};
struct Obj_23eb20 {
    char p[0x14];
    Inner_23eb20* inner;
    char q[8];
    Check20 c;
};
struct SpawnAction {
    char p[0x1c];
    Obj_23eb20* owner;
    int a, b;
    Sub_23eb20 sub;
    char q[0x24];
    int saved;
    bool flag;
    bool vfunc_3(int, int);
};
extern void* vSpawn[];
class Ref_23ecb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Part_23ecb0 {
  public:
    void Fini() throw();
};
struct Action_23ecb0 {
    void* vf;
    void Dtor() throw();
};
struct SpawnAction_23ecb0 : Action_23ecb0 {
    char pad[0x1c];
    Ref_23ecb0* p20;
    Ref_23ecb0* p24;
    Part_23ecb0 part;
    void Dtor2() throw();
};
class CStageCondition_23ed30;
class ParamValue_23ed30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_23ed30 : public ParamValue_23ed30 {
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
extern int gTypeA_23edb0;
typedef unsigned int uint_23ef40;
struct Alloc_23ef40 {
    uint_23ef40 run(uint_23ef40, fight::SpawnTrack*, uint_23ef40);
};
extern Alloc_23ef40* FUN_0008d690(uint_23ef40);
extern void* g_vftable_23ef70[];
class Ref_23ef70 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class Sub_23ef70 {
  public:
    void Fn();
};
class Helper_23ef70 {
  public:
    void Fn();
};
class SpawnAction_23ef70 {
  public:
    void* vptr;
    char p[0x1c];
    Ref_23ef70* m20;
    Ref_23ef70* m24;
    Sub_23ef70 m28;
    SpawnAction_23ef70* f2(unsigned char flags);
};
class TrackFactoryCasterTemplate_23efe0 {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_23efe0*);
class Obj {
  public:
    void Set(void*);
};
extern int g_vftable_23f0a0;


// 0x0023ea20 FUN_0023ea20 (12 B): matches/0x0023ea20.cpp
// sym: ?SetTimeBegin_0023ea20@Obj_23ea20@fn_f7aacfaa@@QAE_NH@Z
bool Obj_23ea20::SetTimeBegin_0023ea20(int x) {
    mVal = x;
    return true;
}


// 0x0023ea30 FUN_0023ea30 (12 B): matches/0x0023ea30.cpp
// sym: ?SetTimeEnd_0023ea30@X_23ea30@fn_f7aacfaa@@QAEDH@Z
char X_23ea30::SetTimeEnd_0023ea30(int value) {
    m10 = value;
    return 1;
}


// 0x0023ea40 FUN_0023ea40 (4 B): matches/0x0023ea40.cpp
// sym: ?GetBranch_0023ea40@A_23ea40@fn_f7aacfaa@@QAEPAHXZ
int* A_23ea40::GetBranch_0023ea40() {
    return (int*)((char*)this + 0x14);
}


// 0x0023ea50 FUN_0023ea50 (4 B): matches/0x0023ea50.cpp
// sym: ?GetConditionGroup_0023ea50@O_23ea50@fn_f7aacfaa@@QAEPAXXZ
void* O_23ea50::GetConditionGroup_0023ea50() {
    return (char*)this + 32;
}


// 0x0023ea60 FUN_0023ea60 (19 B): matches/0x0023ea60.cpp
// sym: ?FUN_0023ea60@fn_f7aacfaa@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0023ea60() {
    FUN_00234810(((char*)&DAT_004e5c80), ((char*)&DAT_004e5c84));
}

} // namespace fn_f7aacfaa

// 0x0023ea80 fight::SpawnTrack::vfunc_0 (16 B): matches/0x0023ea80.cpp
// sym: ?vfunc_0@SpawnTrack@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::SpawnTrack::vfunc_0(int index) {
    int* p = gTable_23ea80;
    return p[index];
}


// 0x0023ea90 FUN_0023ea90 (55 B): matches/0x0023ea90.cpp [wrapped: merged class would differ: SpawnTrack: field a: Field(+0x14 PartA a) vs Field(+0x14 PartA a)]
// sym: ??0SpawnTrack@fn_0023ea90@@QAE@XZ
namespace fn_0023ea90 {
class Track_23ea90 {
  public:
    Track_23ea90();
    virtual void f();
    char pad[4];
};
class PartA {
  public:
    PartA();
    char pad[12];
};
class PartB {
  public:
    PartB();
};
class SpawnTrack : public Track_23ea90 {
  public:
    SpawnTrack();
    virtual void f();
    int flag;
    int n;
    float value;
    PartA a;
    PartB b;
};
SpawnTrack::SpawnTrack() : Track_23ea90(), n(0), value(-1.0f), a(), b() {
    flag = 1;
}
} // namespace fn_0023ea90


// 0x0023ead0 fight::SpawnTrack::vfunc_6 (4 B): matches/0x0023ead0.cpp
// sym: ?vfunc_6@SpawnTrack@fight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg fight::SpawnTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x0023eae0 fight::SpawnTrack::vfunc_7 (7 B): matches/0x0023eae0.cpp
// sym: ?vfunc_7@SpawnTrack@fight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg fight::SpawnTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}


// 0x0023eaf0 FUN_0023eaf0 (33 B): matches/0x0023eaf0.cpp
// sym: ?FUN_0023eaf0@SpawnTrack@fight@@QAEXXZ
void fight::SpawnTrack::FUN_0023eaf0() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00428e80);
    ((SubA_23eaf0*)((char*)this + 0x20))->A();
    ((SubB_23eaf0*)((char*)this + 0x14))->B();
    ((SpawnTrack_nv_23eaf0*)this)->Fin();
}

namespace fn_f7aacfaa {

// 0x0023eb20 fight::SpawnAction::vfunc_3 (116 B): matches/0x0023eb20.cpp
// sym: ?vfunc_3@SpawnAction@fn_f7aacfaa@@QAE_NHH@Z
bool SpawnAction::vfunc_3(int param, int next) {
    Obj_23eb20* o = owner;
    saved = param;
    Inner_23eb20* i = o->inner;
    if (!i)
        return false;
    if (!o->c.Ready(a, b, 0))
        return false;
    Res_23eb20* r = i->Check(b, 0);
    if (!r)
        return false;
    r->Bind(&sub, b, 0);
    sub.Set(param, next);
    flag = true;
    return sub.Done();
}

} // namespace fn_f7aacfaa

// 0x0023eba0 fight::SpawnAction::vfunc_5 (82 B): matches/0x0023eba0.cpp [wrapped: conflict: SpawnAction]
// sym: ?vfunc_5@SpawnAction@fn_0023eba0@@UAEHHH@Z
namespace fn_0023eba0 {
class Child_23eba0 {
    char pad[0x28];

  public:
    void Begin(int, int);
    void Update(int);
    void Finish(int);
    int End();
};
class SpawnAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int vfunc_5(int, int);
    char pad[0x28 - 4];
    Child_23eba0 child;
    int count;
    unsigned char flag;
};
int SpawnAction::vfunc_5(int index, int value) {
    if (index == 0 && !flag)
        child.Begin(count, value);
    flag = 0;
    child.Update(index);
    if (index == count - 1)
        child.Finish(1);
    return child.End();
}
} // namespace fn_0023eba0


// 0x0023ec00 fight::SpawnAction::vfunc_4 (8 B): matches/0x0023ec00.cpp [wrapped: conflict: SpawnAction]
// sym: ?vfunc_4@SpawnAction@fn_0023ec00@@UAEXXZ
namespace fn_0023ec00 {
class Inner_23ec00 {
  public:
    void f();
};
class SpawnAction {
    char pad[0x24];
    Inner_23ec00 inner;

  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
};
void SpawnAction::vfunc_4() {
    inner.f();
}
} // namespace fn_0023ec00


// 0x0023ec10 fight::SpawnTrack::vfunc_5 (54 B): matches/0x0023ec10.cpp [wrapped: conflict: fight::SpawnTrack; fight::Track]
// sym: ?vfunc_5@SpawnTrack@fight@fn_0023ec10@@QAEPAU123@E@Z
namespace fn_0023ec10 {
typedef unsigned char u8_23ec10;
extern int spawn_vftable;
struct A_23ec10 {
    void init();
};
struct B_23ec10 {
    void init();
};
struct SpawnTrack_23ec10 {
    void init();
};
namespace fight {
struct Track {
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
    virtual void v10();
};
struct SpawnTrack : Track {
    char pad[0x20 - sizeof(Track)];
    SpawnTrack* vfunc_5(u8_23ec10);
};
} // namespace fight
// at file scope: a block-scope extern in this member is ::del to MSVC but fight::del to clang (left unbound)
extern void del(fight::SpawnTrack*);
fight::SpawnTrack* fight::SpawnTrack::vfunc_5(u8_23ec10 flag) {
    *(hulk_intptr*)this = (hulk_intptr)&spawn_vftable;
    ((A_23ec10*)((char*)this + 0x20))->init();
    ((B_23ec10*)((char*)this + 0x14))->init();
    ((SpawnTrack_23ec10*)this)->init();
    if (flag & 1) {
        del(this);
    }
    return this;
}
} // namespace fn_0023ec10


// 0x0023ec50 FUN_0023ec50 (95 B): matches/0x0023ec50.cpp [wrapped: conflict: SpawnAction]
// sym: ??0SpawnAction@fn_0023ec50@@QAE@PAVOwner_23ec50@1@HPAVRef_23ec50@1@@Z
namespace fn_0023ec50 {
class Inner_23ec50 {
  public:
    Inner_23ec50();
    char d[0x28];
};
class Owner_23ec50 {
  public:
    virtual void F();
};
class Ref_23ec50 {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_23ec50 {
  public:
    Action_23ec50();
    virtual void B();
};
class SpawnAction : public Action_23ec50 {
  public:
    SpawnAction(Owner_23ec50* owner, int value, Ref_23ec50* ref);
    virtual void V();
    char p4[0x18];
    int m1c;
    hulk_intptr m20;
    hulk_intptr m24;
    Inner_23ec50 inner;
    int m50;
    char flag;
};
SpawnAction::SpawnAction(Owner_23ec50* owner, int value, Ref_23ec50* ref) : Action_23ec50(), m24(0), inner() {
    m50 = 0;
    flag = 0;
    m20 = (hulk_intptr)owner;
    owner->F();
    m1c = value;
    if (ref)
        ref->Add();
    if (m24)
        ((Ref_23ec50*)m24)->Release();
    m24 = (hulk_intptr)ref;
}
} // namespace fn_0023ec50

namespace fn_f7aacfaa {

// 0x0023ecb0 FUN_0023ecb0 (52 B): matches/0x0023ecb0.cpp
// sym: ?Dtor2@SpawnAction_23ecb0@fn_f7aacfaa@@QAEXXZ
void SpawnAction_23ecb0::Dtor2() throw() {
    vf = vSpawn;
    _ReadWriteBarrier();
    if (p24) {
        p24->Release();
        p24 = 0;
    }
    p20->Release();
    part.Fini();
    Action_23ecb0::Dtor();
}

} // namespace fn_f7aacfaa

// 0x0023ed10 fight::ParamFloatConstRange<fight::SpawnTrack>::vfunc_6 (26 B): matches/0x0023ed10.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VSpawnTrack@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::SpawnTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<fight::SpawnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<fight::SpawnTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<fight::SpawnTrack>::**)(int))&this->f_10))(b);
}


// 0x0023ed30 fight::ParamFloatConstRange<fight::SpawnTrack>::vfunc_2 (11 B): matches/0x0023ed30.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VSpawnTrack@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::SpawnTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f7aacfaa {

// 0x0023ed60 fight::ParamBranch<fight::SpawnTrack>::vfunc_6 (12 B): matches/0x0023ed60.cpp
// sym: ?vfunc_6@ParamBranch@fn_f7aacfaa@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f7aacfaa

// 0x0023ed90 fight::ParamConditionGroup<fight::SpawnTrack>::vfunc_6 (12 B): matches/0x0023ed90.cpp [wrapped: same definition as 0x0023ed60 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0023ed90@@UAEXPAX@Z
namespace fn_0023ed90 {
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
} // namespace fn_0023ed90


// 0x0023edb0 fight::TrackFactoryCasterTemplate<fight::SpawnTrack>::vfunc_0 (36 B): matches/0x0023edb0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VSpawnTrack@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<fight::SpawnTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_23edb0, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023ede0 fight::ParamFloatConstRange<fight::SpawnTrack>::vfunc_0 (30 B): matches/0x0023ede0.cpp
// sym: ??_G?$ParamFloatConstRange@VSpawnTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<fight::SpawnTrack>::~ParamFloatConstRange() {}


// 0x0023ee00 fight::ParamBranch<fight::SpawnTrack>::vfunc_0 (30 B): matches/0x0023ee00.cpp
// sym: ??_G?$ParamBranch@VSpawnTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<fight::SpawnTrack>::~ParamBranch() {}


// 0x0023ee20 fight::ParamConditionGroup<fight::SpawnTrack>::vfunc_0 (30 B): matches/0x0023ee20.cpp
// sym: ??_G?$ParamConditionGroup@VSpawnTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamConditionGroup<fight::SpawnTrack>::~ParamConditionGroup() {}


// 0x0023ef40 fight::SpawnTrack::vfunc_10 (45 B): matches/0x0023ef40.cpp
// sym: ?vfunc_10@SpawnTrack@fight@@UAEHHHH@Z
hulk_intptr fight::SpawnTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { uint_23ef40 a = (uint_23ef40)__p0; uint_23ef40 b = (uint_23ef40)__p1; uint_23ef40 c = (uint_23ef40)__p2;

    Alloc_23ef40* p = FUN_0008d690(0x58);
    if (p)
        return (int)(p->run(a, this, c));
    return (int)(0);
}

namespace fn_f7aacfaa {

// 0x0023ef70 fight::SpawnAction::vfunc_2 (73 B): matches/0x0023ef70.cpp
// sym: ?f2@SpawnAction_23ef70@fn_f7aacfaa@@QAEPAV12@E@Z
SpawnAction_23ef70* SpawnAction_23ef70::f2(unsigned char flags) {
    vptr = g_vftable_23ef70;
    _ReadWriteBarrier();
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    m20->f1();
    m28.Fn();
    ((Helper_23ef70*)this)->Fn();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x0023efe0 FUN_0023efe0 (38 B): matches/0x0023efe0.cpp
// sym: _FUN_0023efe0
extern "C" void FUN_0023efe0(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_23efe0 caster;
    obj->Set(Find(name, &caster));
}


// 0x0023f0a0 fight::TrackFactoryTemplate<fight::SpawnTrack>::vfunc_2 (43 B): matches/0x0023f0a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f7aacfaa@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_23f0a0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f7aacfaa

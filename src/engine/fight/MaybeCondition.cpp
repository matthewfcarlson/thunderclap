// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00238190..0x00238850 (kind game, layer engine, confidence high), dominant class fight::MaybeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc1ade79 {
#define TREE_TU_END }
namespace fn_fc1ade79 {} using namespace fn_fc1ade79;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fc1ade79 {
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5c0c;
class CCondition_238200 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e5c14;
class CCondition_238260 {
  public:
    virtual int vfunc_0(int);
};
struct RandomState { uint low; uint high; };
typedef float(__cdecl* Callback_238350)(unsigned int, unsigned int);
typedef float(__cdecl* Fn_2383a0)(int, int);
extern float zeroValue_2383a0;
extern void* hulk_at_004281f0[];
class Condition_2383f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class MaybeCondition_2383f0 : public Condition_2383f0 {
  public:
    MaybeCondition_2383f0* vfunc_5(signed char flags);
};
extern void* hulk_at_00428210[];
class Condition_238420 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class RandomCondition_238420 : public Condition_238420 {
  public:
    RandomCondition_238420* vfunc_5(signed char flags);
};
class CStageCondition_238490;
class ParamValue_238490 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_238490 : public ParamValue_238490 {
  public:
    int pad;
};
class CStageCondition_2384e0;
class ParamValue_2384e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_2384e0 : public ParamValue_2384e0 {
  public:
    int pad;
};
extern int hulk_at_00491ca8;
extern int gTypeA_238560;
class ConditionFactoryCasterTemplate_2386b0 {
  public:
    virtual void f();
};
class Owner {
  public:
    void apply_00236760(void*);
};
void* locate_002343e0(const char*, ConditionFactoryCasterTemplate_2386b0*);
class RandomCondition {
  public:
    virtual void F();
};
class Obj_2386e0 {
  public:
    virtual void A();
    void Use_00236760(void*);
};
extern void* Build_002343e0(void* arg, void* storage);
extern "C" char DAT_0042827c[];
} // namespace fn_fc1ade79
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc1ade79 {
class TrackFactoryTemplate_238710 {
  public:
    TrackFactoryTemplate_238710() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_004281f0[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class Obj {
  public:
    hulk_intptr vf;
    int a;
    int b;
    int c;
    Obj(int);
};
extern int hulk_at_00428288;
struct ConditionFactoryTemplate_238780 {
    void* m_vptr;
    void base1_dtor_002381e0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_2387b0 {
  public:
    TrackFactoryTemplate_2387b0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_00428210[];
extern "C" void* __cdecl alloc(hulk_uintptr);
struct RandomCondition_2387f0 {
    hulk_intptr vf;
    int pad[2];
    int value;
    void Init_00234590(int);
};
extern int hulk_at_004282a4;
struct ConditionFactoryTemplate_238820 {
    void* m_vptr;
    void base1_dtor_00238240();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};


// 0x00238190 FUN_00238190 (12 B): matches/0x00238190.cpp
// sym: _FUN_00238190
extern "C" int __cdecl FUN_00238190(int index) {
    return ((int*)&DAT_004caa14)[index];
}


// 0x002381a0 FUN_002381a0 (23 B): matches/0x002381a0.cpp
// sym: _FUN_002381a0
extern "C" int __cdecl FUN_002381a0(int index, int value) {
    int old = ((int*)&DAT_004caa14)[index];
    ((int*)&DAT_004caa14)[index] = value;
    return old;
}

} // namespace fn_fc1ade79

// 0x002381c0 FUN_002381c0 (12 B): matches/0x002381c0.cpp
// sym: ?FUN_002381c0@Obj_2381c0@owners@@QAE_NH@Z
bool owners::Obj_2381c0::FUN_002381c0(int v) {
    mX = v;
    return true;
}


// 0x002381d0 FUN_002381d0 (12 B): matches/0x002381d0.cpp
// sym: ?FUN_002381d0@A_2381d0@owners@@QAE_NH@Z
bool owners::A_2381d0::FUN_002381d0(int v) {
    mValue = v;
    return true;
}

namespace fn_fc1ade79 {

// 0x002381e0 FUN_002381e0 (19 B): matches/0x002381e0.cpp
// sym: ?FUN_002381e0@fn_fc1ade79@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_002381e0() {
    FUN_00234810(((char*)&DAT_004e5c0c), ((char*)&DAT_004e5c10));
}

} // namespace fn_fc1ade79

// 0x00238200 fight::MaybeCondition::vfunc_0 (16 B): matches/0x00238200.cpp
// sym: ?vfunc_0@MaybeCondition@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::MaybeCondition::vfunc_0(int index) {
    int* p = hulk_at_004e5c0c;
    return p[index];
}

namespace fn_fc1ade79 {

// 0x00238240 FUN_00238240 (19 B): matches/0x00238240.cpp
// sym: ?FUN_00238240@fn_fc1ade79@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00238240() {
    FUN_00234810(((char*)&DAT_004e5c14), ((char*)&DAT_004e5c18));
}

} // namespace fn_fc1ade79

// 0x00238260 fight::RandomCondition::vfunc_0 (16 B): matches/0x00238260.cpp
// sym: ?vfunc_0@RandomCondition@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::RandomCondition::vfunc_0(int index) {
    int* p = hulk_at_004e5c14;
    return p[index];
}

namespace fn_fc1ade79 {

// 0x002382a0 FUN_002382a0 (98 B): equivalent/0x002382a0.cpp
// sym: ?FUN_002382a0@fn_fc1ade79@@YAMXZ @09004bd526ac @w7d957d83f2d2
// STATUS: equivalent (tools/equiv.py level 3: 19809 inputs, branch coverage 0/0)
// FUN_002382a0 @ 0x002382a0
hulk_freg FUN_002382a0()
{
    RandomState* state = (*(RandomState**)&DAT_004e5acc);
    uint a = state->low;
    state->low = (a & 0xffff) * 0x9069 + (a >> 16);
    uint b = state->high;
    b = (b & 0xffff) * 0x4650 + (b >> 16);
    state->high = b;
    union { uint bits; float value; } result;
    result.bits = (((state->low << 16) + (b & 0xffff)) & 0x7fffff) | 0x3f800000;
    return result.value - DAT_003f32dc;
}


// 0x00238330 FUN_00238330 (20 B): matches/0x00238330.cpp
// sym: _FUN_00238330
// Same code shape as 0x00232d70 (propagated; names are from that function)
extern "C" void FUN_00238330(hulk_intptr a, int b) {
    (*(int*)&DAT_004caa24) = a;
    (*(int*)&DAT_004e5c1c) = b;
}


// 0x00238350 FUN_00238350 (37 B): matches/0x00238350.cpp
// sym: ?FUN_00238350@fn_fc1ade79@@YAMI@Z
// data: gFunction = DAT_004caa24, gValue_238350 = DAT_004e5c1c, gZero_238350 = DAT_003f32e0
hulk_freg __cdecl FUN_00238350(unsigned int param) {
    if ((*(Callback_238350*)&DAT_004caa24) == 0)
        return DAT_003f32e0;
    return (*(Callback_238350*)&DAT_004caa24)(param, (*(unsigned int*)&DAT_004e5c1c));
}

} // namespace fn_fc1ade79

// 0x00238380 fight::RandomCondition::vfunc_6 (20 B): matches/0x00238380.cpp
// sym: ?vfunc_6@RandomCondition@fight@@UAE_NPAX00@Z
bool fight::RandomCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; float * out = (float *)__p2;

    if (out)
        *out += this->f_0c;
    return true;
}


// 0x002383a0 fight::MaybeCondition::vfunc_6 (74 B): matches/0x002383a0.cpp
// sym: ?vfunc_6@MaybeCondition@fight@@UAE_NPAX00@Z
// data: globalArg = DAT_004e5c1c, globalFn = DAT_004caa24
bool fight::MaybeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; hulk_intptr c = (hulk_intptr)__p2;

    float x;
    if ((*(Fn_2383a0*)&DAT_004caa24) == 0)
        x = 0.0f;
    else
        x = (*(Fn_2383a0*)&DAT_004caa24)(b, (*(int*)&DAT_004e5c1c));
    return 100.0f * x < this->f_0c;
}

namespace fn_fc1ade79 {

// 0x002383f0 fight::MaybeCondition::vfunc_5 (36 B): matches/0x002383f0.cpp
// sym: ?vfunc_5@MaybeCondition_2383f0@fn_fc1ade79@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
MaybeCondition_2383f0* MaybeCondition_2383f0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004281f0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00238420 fight::RandomCondition::vfunc_5 (36 B): matches/0x00238420.cpp
// sym: ?vfunc_5@RandomCondition_238420@fn_fc1ade79@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
RandomCondition_238420* RandomCondition_238420::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00428210;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fc1ade79

// 0x00238470 fight::ParamFloatConstRange<fight::MaybeCondition>::vfunc_6 (26 B): matches/0x00238470.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VMaybeCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::MaybeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<fight::MaybeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<fight::MaybeCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<fight::MaybeCondition>::**)(int))&this->f_10))(b);
}


// 0x00238490 fight::ParamFloatConstRange<fight::MaybeCondition>::vfunc_2 (11 B): matches/0x00238490.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VMaybeCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::MaybeCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x002384c0 fight::ParamFloatConstRange<fight::RandomCondition>::vfunc_6 (26 B): matches/0x002384c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VMaybeCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::RandomCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<fight::RandomCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<fight::RandomCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<fight::RandomCondition>::**)(int))&this->f_10))(b);
}


// 0x002384e0 fight::ParamFloatConstRange<fight::RandomCondition>::vfunc_2 (11 B): matches/0x002384e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VMaybeCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::RandomCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00238500 fight::ConditionFactoryCasterTemplate<fight::MaybeCondition>::vfunc_0 (36 B): matches/0x00238500.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VMaybeCondition@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<fight::MaybeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00238530 fight::ParamFloatConstRange<fight::MaybeCondition>::vfunc_0 (30 B): matches/0x00238530.cpp
// sym: ??_G?$ParamFloatConstRange@VMaybeCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<fight::MaybeCondition>::~ParamFloatConstRange() {}


// 0x00238560 fight::ConditionFactoryCasterTemplate<fight::RandomCondition>::vfunc_0 (36 B): matches/0x00238560.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VRandomCondition@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<fight::RandomCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_238560, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00238590 fight::ParamFloatConstRange<fight::RandomCondition>::vfunc_0 (30 B): matches/0x00238590.cpp
// sym: ??_G?$ParamFloatConstRange@VRandomCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<fight::RandomCondition>::~ParamFloatConstRange() {}

namespace fn_fc1ade79 {

// 0x002386b0 FUN_002386b0 (38 B): matches/0x002386b0.cpp
// sym: _FUN_002386b0
extern "C" void FUN_002386b0(Owner* owner, const char* name) {
    ConditionFactoryCasterTemplate_2386b0 c;
    void* p = locate_002343e0(name, &c);
    owner->apply_00236760(p);
}


// 0x002386e0 FUN_002386e0 (38 B): matches/0x002386e0.cpp
// sym: _FUN_002386e0
extern "C" void FUN_002386e0(void* a, void* b) {
    RandomCondition local;
    *(hulk_intptr*)&local = (hulk_intptr)DAT_0042827c;
    void* r = Build_002343e0(b, &local);
    ((Obj_2386e0*)a)->Use_00236760(r);
}

} // namespace fn_fc1ade79

// 0x00238710 fight::ConditionFactoryCasterTemplate<fight::MaybeCondition>::vfunc_1 (60 B): matches/0x00238710.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VMaybeCondition@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<fight::MaybeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_238710));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_238710* t = new (mem) TrackFactoryTemplate_238710();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00238750 fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_5 (47 B): matches/0x00238750.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VMaybeCondition@fight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_5() {
    Obj* p = (Obj*)Alloc(0x10);
    if (p) {
        p->Obj::Obj(0);
        p->vf = ((hulk_intptr)DAT_004281f0);
        p->c = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc1ade79 {

// 0x00238780 fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_2 (43 B): matches/0x00238780.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_238780@fn_fc1ade79@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_238780::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00428288;
    base1_dtor_002381e0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc1ade79

// 0x002387b0 fight::ConditionFactoryCasterTemplate<fight::RandomCondition>::vfunc_1 (60 B): matches/0x002387b0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VRandomCondition@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<fight::RandomCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_2387b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_2387b0* t = new (mem) TrackFactoryTemplate_2387b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x002387f0 fight::ConditionFactoryTemplate<fight::RandomCondition>::vfunc_5 (47 B): matches/0x002387f0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VRandomCondition@fight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<fight::RandomCondition>::vfunc_5() {
    RandomCondition_2387f0* p = (RandomCondition_2387f0*)alloc(0x10);
    if (p) {
        p->Init_00234590(0);
        p->vf = ((hulk_intptr)DAT_00428210);
        p->value = 0;
    } else {
        p = 0;
    }
    return (void*)(p);
}

namespace fn_fc1ade79 {

// 0x00238820 fight::ConditionFactoryTemplate<fight::RandomCondition>::vfunc_2 (43 B): matches/0x00238820.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_238820@fn_fc1ade79@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_238820::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004282a4;
    base1_dtor_00238240();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc1ade79

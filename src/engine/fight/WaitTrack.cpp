// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023df40..0x0023e4d0 (kind game, layer engine, confidence high), dominant class fight::WaitTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3d35335 {
#define TREE_TU_END }
namespace fn_f3d35335 {} using namespace fn_f3d35335;
namespace fn_f3d35335 { extern "C" char DAT_00428cf4[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
namespace fn_f3d35335 { extern "C" char DAT_00428d24[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f3d35335 {
class Obj_23df40 {
  public:
    char pad[0xc];
    int mVal;
    char Set(int v);
};
class Obj {
  public:
    char pad[16];
    int value;
    bool Set(int x);
};
class Obj_23df80 {
  public:
    char pad[0x14];
    int mValue;
    char Fn(int x);
};
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5c6c;
class CCondition_23dfb0 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_00428cf4[];
class Track_23dfc0 {
  public:
    void* vptr;
    Track_23dfc0() throw();
};
class WaitTrack : public Track_23dfc0 {
  public:
    char pad[8];
    int m0c;
    int m10;
    int m14;
    WaitTrack() throw();
};
extern float hulk_at_003f3388;
extern void* Track_23e050_vftable[];
class Track_23e050 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class WaitTrack_23e050 : public Track_23e050 {
  public:
    WaitTrack_23e050* vfunc_5(signed char flags);
};
struct Obj_23e080 {
    virtual void F();
    virtual void R();
};
extern int hulk_at_00428d24;
struct WaitAction_23e080 {
    void* vf;
    int pad[6];
    int arg;
    Obj_23e080* object;
    void Init_00232660();
    WaitAction_23e080* Build(int, Obj_23e080*);
};
class Ref_23e0d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_23e0d0 {
  public:
    void* vptr;
};
class WaitAction_23e0d0 : public Action_23e0d0 {
  public:
    char pad[28];
    Ref_23e0d0* m;
    ~WaitAction_23e0d0() throw();
};
class CStageCondition_23e1e0;
class ParamValue_23e1e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_23e1e0 : public ParamValue_23e1e0 {
  public:
    int pad;
};
extern int hulk_at_0049850c;
extern "C" char DAT_00428d24[];
class Ref_23e330 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_23e330 {
  public:
    virtual void v0();
    void Init_00232660();
};
extern void* Alloc_0008d690(unsigned int);
extern void* g_vftable_23e390[];
class Ref_23e390 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_23e390 {
  public:
    void* vptr;
};
class WaitAction_23e390 : public Action_23e390 {
  public:
    char pad[28];
    Ref_23e390* m;
    WaitAction_23e390* f2(unsigned char flags);
};
extern "C" char DAT_00428d60[];
struct Temp_23e3f0 {
    void* vptr;
};
struct A_23e3f0 {
    void FnG_002367c0(void*);
};
struct B_23e3f0 {};
extern "C" void* FUN_00236ac0(B_23e3f0*, Temp_23e3f0*);
} // namespace fn_f3d35335
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f3d35335 {
class TrackFactoryTemplate_23e420 {
  public:
    TrackFactoryTemplate_23e420() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C++" __declspec(nothrow) void FUN_0023e250();
extern void __fastcall InitTrack_00236d40(void*);
extern int WaitTrackVtable;
struct WaitTrack_23e460 {
    int* vptr;
    int pad4[2];
    int x, y, z;
};
extern int hulk_at_00428d78;


// 0x0023df40 FUN_0023df40 (12 B): matches/0x0023df40.cpp
// sym: ?Set@Obj_23df40@fn_f3d35335@@QAEDH@Z
char Obj_23df40::Set(int v) {
    mVal = v;
    return 1;
}


// 0x0023df60 FUN_0023df60 (12 B): matches/0x0023df60.cpp
// sym: ?Set@Obj@fn_f3d35335@@QAE_NH@Z
bool Obj::Set(int x) {
    value = x;
    return true;
}


// 0x0023df80 FUN_0023df80 (12 B): matches/0x0023df80.cpp
// sym: ?Fn@Obj_23df80@fn_f3d35335@@QAEDH@Z
char Obj_23df80::Fn(int x) {
    mValue = x;
    return 1;
}


// 0x0023df90 FUN_0023df90 (19 B): matches/0x0023df90.cpp
// sym: ?FUN_0023df90@fn_f3d35335@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0023df90() {
    FUN_00234810(((char*)&DAT_004e5c6c), ((char*)&DAT_004e5c70));
}

} // namespace fn_f3d35335

// 0x0023dfb0 fight::WaitTrack::vfunc_0 (16 B): matches/0x0023dfb0.cpp
// sym: ?vfunc_0@WaitTrack@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::WaitTrack::vfunc_0(int index) {
    int* p = hulk_at_004e5c6c;
    return p[index];
}

namespace fn_f3d35335 {

// 0x0023dfc0 FUN_0023dfc0 (29 B): matches/0x0023dfc0.cpp
// sym: ??0WaitTrack@fn_f3d35335@@QAE@XZ
WaitTrack::WaitTrack() throw() : Track_23dfc0() {
    m0c = 0;
    m10 = 0;
    m14 = 0;
    vptr = hulk_at_00428cf4;
}

} // namespace fn_f3d35335

// 0x0023dfe0 fight::WaitTrack::vfunc_6 (4 B): matches/0x0023dfe0.cpp
// sym: ?vfunc_6@WaitTrack@fight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg fight::WaitTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0023dff0 fight::WaitTrack::vfunc_7 (7 B): matches/0x0023dff0.cpp
// sym: ?vfunc_7@WaitTrack@fight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg fight::WaitTrack::vfunc_7() {
    return hulk_at_003f3388;
}


// 0x0023e010 fight::WaitAction::vfunc_5 (49 B): matches/0x0023e010.cpp [wrapped: conflict: fight::WaitAction]
// sym: ?vfunc_5@WaitAction@fight@fn_0023e010@@UAEDHM@Z
namespace fn_0023e010 {
// data: gZero = DAT_003f32e0

namespace fight {
class WaitAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char vfunc_5(int, float);
    char pad[0x20];
    float time;
};
char WaitAction::vfunc_5(int flag, float dt) {
    if (!flag) {
        time -= dt;
        return time > DAT_003f32e0 ? 1 : 0;
    }
    return 1;
}
} // namespace fight
} // namespace fn_0023e010

namespace fn_f3d35335 {

// 0x0023e050 fight::WaitTrack::vfunc_5 (36 B): matches/0x0023e050.cpp
// sym: ?vfunc_5@WaitTrack_23e050@fn_f3d35335@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
WaitTrack_23e050* WaitTrack_23e050::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_00428cf4);
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0023e080 FUN_0023e080 (65 B): matches/0x0023e080.cpp
// sym: ?Build@WaitAction_23e080@fn_f3d35335@@QAEPAU12@HPAUObj_23e080@2@@Z
// Same code shape as 0x0012db50 (propagated; names are from that function)
WaitAction_23e080* WaitAction_23e080::Build(int a, Obj_23e080* p) {
    Init_00232660();
    vf = &hulk_at_00428d24;
    object = 0;
    arg = a;
    if (p)
        p->F();
    if (object)
        object->R();
    object = p;
    return this;
}


// 0x0023e0d0 FUN_0023e0d0 (36 B): matches/0x0023e0d0.cpp
// sym: ??1WaitAction_23e0d0@fn_f3d35335@@QAE@XZ
WaitAction_23e0d0::~WaitAction_23e0d0() throw() {
    vptr = (void**)DAT_00428d24;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_23e0d0 *)this)->FUN_002326a0();
}

} // namespace fn_f3d35335

// 0x0023e100 fight::WaitAction::vfunc_3 (159 B): equivalent/0x0023e100.cpp [wrapped: conflict: fight::WaitAction]
// sym: ?vfunc_3@WaitAction@fight@fn_0023e100@@UAE_NHH@Z @e5faedbaee91 @w33c440b2c872
namespace fn_0023e100 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// fight::WaitAction::vfunc_3 @ 0x0023e100
// fight::WaitAction::vfunc_3 @ 0x0023e100: interpolate between two offsets from a reference value
union FloatBits_23e100 {
    float f;
    unsigned int u;
};

hulk_freg __cdecl FUN_00238350(int v);

struct Range_23e100 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float Reference();
    char pad04[0xc];
    float lo;
    float hi;
};

namespace fight {

class WaitAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x1c - 4];
    Range_23e100 *range;
    int blend;
    float result;
};

bool WaitAction::vfunc_3(int a, int b)
{
    float ref = range->Reference();
    float t = range->lo - ref;
    double u = range->hi - ref;
    float d = t - u;
    FloatBits_23e100 ad;
    ad.f = d;
    ad.u &= 0x7fffffff;
    float x;
    float y;
    if (ad.f <= 1e-05f) {
        result = t;
        return true;
    }
    if (u > t) {
        x = u - t;
        y = t;
    } else {
        x = d;
        y = u;
    }
    result = FUN_00238350(blend) * x + y;
    return true;
}

}
} // namespace fn_0023e100


// 0x0023e1c0 fight::ParamFloatConstRange<fight::WaitTrack>::vfunc_6 (26 B): matches/0x0023e1c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VWaitTrack@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::WaitTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<fight::WaitTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<fight::WaitTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<fight::WaitTrack>::**)(int))&this->f_10))(b);
}


// 0x0023e1e0 fight::ParamFloatConstRange<fight::WaitTrack>::vfunc_2 (11 B): matches/0x0023e1e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VWaitTrack@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::WaitTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0023e200 fight::TrackFactoryCasterTemplate<fight::WaitTrack>::vfunc_0 (36 B): matches/0x0023e200.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VWaitTrack@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<fight::WaitTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023e230 fight::ParamFloatConstRange<fight::WaitTrack>::vfunc_0 (30 B): matches/0x0023e230.cpp
// sym: ??_G?$ParamFloatConstRange@VWaitTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<fight::WaitTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<fight::WaitTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x23e230)
#endif


// 0x0023e250 FUN_0023e250 (213 B): matches/0x0023e250.cpp [wrapped: conflict: fight::ParamFloatConstRange]
// sym: _FUN_0023e250
namespace fn_0023e250 {

void* __cdecl FUN_0008d690(unsigned int);

void __cdecl FUN_0023df40();
void __cdecl FUN_0023df60();
void __cdecl FUN_0023df80();
struct FUN_00234960 {
    virtual void placeholder();
    char data[12];
    void(__cdecl* callback)();
    char tail[4];
    FUN_00234960(const char*);
};
namespace fight {
class WaitTrack;
template <class T> struct ParamFloatConstRange : FUN_00234960 {
    ParamFloatConstRange(const char* s, void(__cdecl* f)()) : FUN_00234960(s) { callback = f; }
    virtual void placeholder();
};
} // namespace fight
extern "C" void __cdecl FUN_002347b0(int*, FUN_00234960**, int);
extern "C" void FUN_0023e250() {
    if (!DAT_004e5c70) {
        FUN_00234960* items[3];
        void* mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<fight::WaitTrack>));
        items[0] =
            mem ? new (mem) fight::ParamFloatConstRange<fight::WaitTrack>("timeBegin", FUN_0023df40) : 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<fight::WaitTrack>));
        items[1] =
            mem ? new (mem) fight::ParamFloatConstRange<fight::WaitTrack>("timeEndMin", FUN_0023df60) : 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<fight::WaitTrack>));
        items[2] =
            mem ? new (mem) fight::ParamFloatConstRange<fight::WaitTrack>("timeEndMax", FUN_0023df80) : 0;
        FUN_002347b0(&DAT_004e5c6c, items, 3);
    }
    ++DAT_004e5c70;
}
} // namespace fn_0023e250


// 0x0023e330 fight::WaitTrack::vfunc_10 (86 B): matches/0x0023e330.cpp
// sym: ?vfunc_10@WaitTrack@fight@@UAEHHHH@Z
hulk_intptr fight::WaitTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { void * p2 = (void *)__p0; void * p3 = (void *)__p1; Ref_23e330 * p4 = (Ref_23e330 *)__p2;

    Action_23e330* r = (Action_23e330*)Alloc_0008d690(0x28);
    if (r) {
        r->Init_00232660();
        *(void**)((char*)r + 0x1c) = this;
        *(hulk_ulongptr*)r = ((hulk_intptr)DAT_00428d24);
        *(unsigned long*)((char*)r + 0x20) = 0;
        if (p4)
            p4->AddRef();
        Ref_23e330* old = *(Ref_23e330**)((char*)r + 0x20);
        if (old)
            old->Release();
        *(Ref_23e330**)((char*)r + 0x20) = p4;
        return (hulk_intptr)(r);
    }
    return (int)(0);
}

namespace fn_f3d35335 {

// 0x0023e390 fight::WaitAction::vfunc_2 (57 B): matches/0x0023e390.cpp
// sym: ?f2@WaitAction_23e390@fn_f3d35335@@QAEPAV12@E@Z
WaitAction_23e390* WaitAction_23e390::f2(unsigned char flags) {
    vptr = ((void**)DAT_00428d24);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_23e390 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x0023e3f0 FUN_0023e3f0 (38 B): matches/0x0023e3f0.cpp
// sym: _FUN_0023e3f0
extern "C" void FUN_0023e3f0(A_23e3f0* a, B_23e3f0* b) {
    Temp_23e3f0 t;
    t.vptr = (void*)((hulk_intptr)DAT_00428d60);
    void* r = FUN_00236ac0(b, &t);
    a->FnG_002367c0(r);
}

} // namespace fn_f3d35335

// 0x0023e420 fight::TrackFactoryCasterTemplate<fight::WaitTrack>::vfunc_1 (60 B): matches/0x0023e420.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VWaitTrack@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<fight::WaitTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_23e420));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_23e420* t = new (mem) TrackFactoryTemplate_23e420();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0023e250();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0023e460 fight::TrackFactoryTemplate<fight::WaitTrack>::vfunc_5 (59 B): matches/0x0023e460.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VWaitTrack@fight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<fight::WaitTrack>::vfunc_5() {
    WaitTrack_23e460* p = (WaitTrack_23e460*)operator new(sizeof(WaitTrack_23e460));
    if (p) {
        InitTrack_00236d40(p);
        p->vptr = (int*)&WaitTrackVtable;
        p->x = 0;
        p->y = 0;
        p->z = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f3d35335 {

// 0x0023e4a0 fight::TrackFactoryTemplate<fight::WaitTrack>::vfunc_2 (43 B): matches/0x0023e4a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f3d35335@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00428d78;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f3d35335

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001a0ca0..0x001a1170 (kind game, layer game, confidence high), dominant class hulkfight::motion::FireBeamTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5715835 {
#define TREE_TU_END }
namespace fn_f5715835 {} using namespace fn_f5715835;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f5715835 {
typedef unsigned int u32_1a0ca0;
extern int __cdecl Check(void*, int, const void*, const void*, int);
extern void* __cdecl Alloc(hulk_uintptr);
struct NewThing {
    int Init(hulkfight::motion::FireBeamTrack*, void*);
};
extern int rttiA_1a0ca0;
extern int rttiB;
} // namespace fn_f5715835
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f5715835 {
class TrackFactoryTemplate_1a0cf0 {
  public:
    TrackFactoryTemplate_1a0cf0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0041b248[];
class Item_1a0d30 {
  public:
    void Init(int);
};
extern int g_vftable_1a0d60;
struct ConditionFactoryTemplate_1a0d60 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1a0d90 {
  public:
    TrackFactoryTemplate_1a0d90() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern void* __cdecl FUN_0008d690(unsigned int);
extern int missile_vftable[];
class Prop_1a0dd0 {
  public:
    hulk_intptr m0;
    int m4;
    char pad[4];
    int mC;
    unsigned char m10;
    void Init(int);
};
extern int g_vftable_1a0e10;
struct ConditionFactoryTemplate_1a0e10 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1a0e40 {
  public:
    TrackFactoryTemplate_1a0e40() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern void* __cdecl Allocate(unsigned int);
struct Track_1a0e80 {
    void* Init();
};
extern int g_vftable_1a0ea0;
class TrackFactoryTemplate_1a0ed0 {
  public:
    TrackFactoryTemplate_1a0ed0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0041b2e8[];
extern void* operator_new(unsigned int);
struct Sub_1a0f10 {
    void Init();
};
struct MPT {
    hulk_intptr vf;
    int a;
    int b;
    int c;
    float z;
    float w;
    Sub_1a0f10 sub;
    void BaseInit();
};
class TrackFactoryTemplate_1a0f90 {
  public:
    TrackFactoryTemplate_1a0f90() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0041b318[];
} // namespace fn_f5715835
namespace hulkfight { namespace motion {
class AccuracyLatencyTrack_1a0fd0 {
  public:
    virtual ~AccuracyLatencyTrack_1a0fd0();
    int field_4;
    int field_8;
    int field_c;
    float field_10;
    int field_14;
    float field_18;
    void Init();
};
} }
namespace fight {
class TrackFactory_1a0fd0 {};
}
namespace pure3d {
class Entity_1a0fd0 {};
}
namespace content {
class LoadObject_1a0fd0 {};
}
namespace core {
class IRefCount_1a0fd0 {};
}
namespace fn_f5715835 {
extern "C" void* __cdecl Allocator(unsigned int size);
class TrackFactoryTemplate_1a1050 {
  public:
    TrackFactoryTemplate_1a1050() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_1a1090;
class TrackFactory_1a1090 {
  public:
    virtual void a();
    virtual void b();
};
class Entity_1a1090 {
  public:
    virtual void c();
    virtual void d();
    virtual void e();
};
class LoadObject_1a1090 {
  public:
    virtual void f();
    virtual void g();
};
class IRefCount_1a1090 {
  public:
    virtual void h();
};
struct FireProjectileTrack_nv_1a1090 {
    u32_1a1090 init();
};
class Factory_1a1090 : public TrackFactory_1a1090, public Entity_1a1090, public LoadObject_1a1090, public IRefCount_1a1090 {
  public:
    virtual u32_1a1090 vfunc_5();
};
class TrackFactoryTemplate_1a10e0 {
  public:
    TrackFactoryTemplate_1a10e0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_1a1120;
struct Obj_1a1120 {
    hulk_uintptr Init();
};

} // namespace fn_f5715835

// 0x001a0ca0 hulkfight::motion::FireBeamTrack::vfunc_10 (73 B): matches/0x001a0ca0.cpp
// sym: ?vfunc_10@FireBeamTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::FireBeamTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1a0ca0 a = (u32_1a0ca0)__p0; u32_1a0ca0 b = (u32_1a0ca0)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &rttiA_1a0ca0, &rttiB, 0)) {
        NewThing* q = (NewThing*)Alloc(0x98);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}


// 0x001a0cf0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_1 (60 B): matches/0x001a0cf0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1a0cf0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1a0cf0* t = new (mem) TrackFactoryTemplate_1a0cf0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001a0d30 fight::ConditionFactoryTemplate<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_5 (44 B): matches/0x001a0d30.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_5() {
    Item_1a0d30* p = (Item_1a0d30*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041b248);
        *((char*)p + 0xc) = 1;
    } else {
        return (void*)(0);
    }
    return (void*)(p);
}

namespace fn_f5715835 {

// 0x001a0d60 fight::ConditionFactoryTemplate<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_2 (43 B): matches/0x001a0d60.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1a0d60@fn_f5715835@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1a0d60::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1a0d60;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5715835

// 0x001a0d90 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropIsMissileCondition>::vfunc_1 (60 B): matches/0x001a0d90.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropIsMissileCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1a0d90));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1a0d90* t = new (mem) TrackFactoryTemplate_1a0d90();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001a0dd0 fight::ConditionFactoryTemplate<hulkfight::motion::PropIsMissileCondition>::vfunc_5 (51 B): matches/0x001a0dd0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropIsMissileCondition>::vfunc_5() {
    Prop_1a0dd0* p = (Prop_1a0dd0*)FUN_0008d690((int)sizeof(Prop_1a0dd0));
    if (p) {
        p->Init(0);
        p->m0 = (hulk_intptr)missile_vftable;
        p->mC = 0;
        p->m10 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f5715835 {

// 0x001a0e10 fight::ConditionFactoryTemplate<hulkfight::motion::PropIsMissileCondition>::vfunc_2 (43 B): matches/0x001a0e10.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1a0e10@fn_f5715835@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1a0e10::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1a0e10;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5715835

// 0x001a0e40 fight::TrackFactoryCasterTemplate<hulkfight::motion::MissileThrowTrack>::vfunc_1 (60 B): matches/0x001a0e40.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMissileThrowTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::MissileThrowTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1a0e40));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1a0e40* t = new (mem) TrackFactoryTemplate_1a0e40();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001a0e80 fight::TrackFactoryTemplate<hulkfight::motion::MissileThrowTrack>::vfunc_5 (24 B): matches/0x001a0e80.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMissileThrowTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00070420 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::MissileThrowTrack>::vfunc_5() {
    void* p = Allocate(0x48);
    if (p)
        return (void*)(((Track_1a0e80*)p)->Init());
    return (void*)(0);
}

namespace fn_f5715835 {

// 0x001a0ea0 fight::TrackFactoryTemplate<hulkfight::motion::MissileThrowTrack>::vfunc_2 (43 B): matches/0x001a0ea0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f5715835@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1a0ea0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f5715835

// 0x001a0ed0 fight::TrackFactoryCasterTemplate<hulkfight::motion::MissilePunchTrack>::vfunc_1 (60 B): matches/0x001a0ed0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMissilePunchTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::MissilePunchTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1a0ed0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1a0ed0* t = new (mem) TrackFactoryTemplate_1a0ed0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001a0f10 fight::TrackFactoryTemplate<hulkfight::motion::MissilePunchTrack>::vfunc_5 (74 B): matches/0x001a0f10.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMissilePunchTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::MissilePunchTrack>::vfunc_5() {
    MPT* p = (MPT*)operator_new(0x24);
    if (p) {
        p->BaseInit();
        p->vf = ((hulk_intptr)DAT_0041b2e8);
        p->c = 0;
        p->z = -1.0f;
        p->w = 6.2831855f;
        p->sub.Init();
        p->b = 1;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x001a0f60 fight::TrackFactoryTemplate<hulkfight::motion::MissilePunchTrack>::vfunc_2 (43 B): matches/0x001a0f60.cpp [wrapped: same definition as 0x001a0ea0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001a0f60@@QAEPAXE@Z
namespace fn_001a0f60 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int g_vftable_1a0f60;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1a0f60;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}
} // namespace fn_001a0f60


// 0x001a0f90 fight::TrackFactoryCasterTemplate<hulkfight::motion::AccuracyLatencyTrack>::vfunc_1 (60 B): matches/0x001a0f90.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VAccuracyLatencyTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::AccuracyLatencyTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1a0f90));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1a0f90* t = new (mem) TrackFactoryTemplate_1a0f90();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001a0fd0 fight::TrackFactoryTemplate<hulkfight::motion::AccuracyLatencyTrack>::vfunc_5 (73 B): matches/0x001a0fd0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VAccuracyLatencyTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AccuracyLatencyTrack>::vfunc_5() {
    hulkfight::motion::AccuracyLatencyTrack_1a0fd0* track =
        (hulkfight::motion::AccuracyLatencyTrack_1a0fd0*)Allocator(0x1c);
    if (track) {
        track->Init();
        *(hulk_intptr*)track = ((hulk_intptr)DAT_0041b318);
        track->field_c = 0;
        track->field_10 = -1.0f;
        track->field_14 = 0;
        track->field_18 = 1.0f;
        track->field_8 = 1;
        return (void*)(track);
    }
    return (void*)(0);
}


// 0x001a1020 fight::TrackFactoryTemplate<hulkfight::motion::AccuracyLatencyTrack>::vfunc_2 (43 B): matches/0x001a1020.cpp [wrapped: same definition as 0x001a0ea0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001a1020@@QAEPAXE@Z
namespace fn_001a1020 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int g_vftable_1a1020;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1a1020;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}
} // namespace fn_001a1020


// 0x001a1050 fight::TrackFactoryCasterTemplate<hulkfight::motion::FireProjectileTrack>::vfunc_1 (60 B): matches/0x001a1050.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::FireProjectileTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1a1050));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1a1050* t = new (mem) TrackFactoryTemplate_1a1050();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_f5715835 {

// 0x001a1090 fight::TrackFactoryTemplate<hulkfight::motion::FireProjectileTrack>::vfunc_5 (27 B): matches/0x001a1090.cpp
// sym: ?vfunc_5@Factory_1a1090@fn_f5715835@@UAEIXZ
u32_1a1090 Factory_1a1090::vfunc_5() {
    hulkfight::motion::FireProjectileTrack* p = (hulkfight::motion::FireProjectileTrack*)operator_new(0xc0);
    if (p)
        return ((FireProjectileTrack_nv_1a1090*)(((hulkfight::motion::FireProjectileTrack*)(p))))->init();
    return 0;
}

} // namespace fn_f5715835

// 0x001a10b0 fight::TrackFactoryTemplate<hulkfight::motion::FireProjectileTrack>::vfunc_2 (43 B): matches/0x001a10b0.cpp [wrapped: same definition as 0x001a0ea0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001a10b0@@QAEPAXE@Z
namespace fn_001a10b0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int g_vftable_1a10b0;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1a10b0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}
} // namespace fn_001a10b0


// 0x001a10e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::FireBeamTrack>::vfunc_1 (60 B): matches/0x001a10e0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::FireBeamTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1a10e0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1a10e0* t = new (mem) TrackFactoryTemplate_1a10e0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001a1120 fight::TrackFactoryTemplate<hulkfight::motion::FireBeamTrack>::vfunc_5 (27 B): matches/0x001a1120.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FireBeamTrack>::vfunc_5() {
    Obj_1a1120* p = (Obj_1a1120*)Alloc(0x138);
    if (p)
        return (void*)(p->Init());
    return (void*)(0);
}


// 0x001a1140 fight::TrackFactoryTemplate<hulkfight::motion::FireBeamTrack>::vfunc_2 (43 B): matches/0x001a1140.cpp [wrapped: same definition as 0x001a0ea0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001a1140@@QAEPAXE@Z
namespace fn_001a1140 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int g_vftable_1a1140;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1a1140;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}
} // namespace fn_001a1140


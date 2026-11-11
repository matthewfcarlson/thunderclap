// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023c8a0..0x0023cb40 (kind game, layer engine, confidence high), dominant class fight::SubConditionGroupCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe0ef8b4 {
#define TREE_TU_END }
namespace fn_fe0ef8b4 {} using namespace fn_fe0ef8b4;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fe0ef8b4 {
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5c44;
class CCondition_23c8d0 {
  public:
    virtual int vfunc_0(int);
};
struct Member_23c900 {
    void Release_00236fd0();
};
struct Condition_23c900 {
    virtual hulk_intptr Fng_0023c8d0(int);
    void Shutdown_002345b0();
};
struct SubConditionGroupCondition_23c900 : Condition_23c900 {
    char pad[8];
    Member_23c900 m;
    ~SubConditionGroupCondition_23c900();
    virtual bool Fnf_00234270(void*);
};
class Condition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Param {
  public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
};
class Helper_23c920 {
  public:
    int Fnf_00236f40(int, int, int);
};
class SubConditionGroupCondition : public Condition, public Param {
  public:
    virtual void vfunc_5();
    virtual int vfunc_6(int, int, int);
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
extern int hulk_at_00491ca8;
class ConditionFactoryCasterTemplate_23ca70 {
  public:
    virtual bool dummy_0023c9a0(void*);
};
extern "C" void* __cdecl Find(void*, ConditionFactoryCasterTemplate_23ca70*);
} // namespace fn_fe0ef8b4
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe0ef8b4 {
class TrackFactoryTemplate_23caa0 {
  public:
    TrackFactoryTemplate_23caa0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0023c9f0();
extern "C" char DAT_004288fc[];
typedef unsigned int u32_23cae0;
extern "C" void* FUN_0008d690(unsigned int);
class Condition_23cae0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    void Init_00234590(int);
};
struct Tail_23cae0 {
    void InitTail_00236e00();
};
extern int hulk_at_00428948;
struct ConditionFactoryTemplate_23cb10 {
    void* m_vptr;
    void base1_dtor_0023c8b0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe0ef8b4

// 0x0023c8a0 FUN_0023c8a0 (4 B): matches/0x0023c8a0.cpp
// sym: ?FUN_0023c8a0@C_23c8a0@owners@@QAEPAXXZ
void* owners::C_23c8a0::FUN_0023c8a0() {
    return (char*)this + 12;
}

namespace fn_fe0ef8b4 {

// 0x0023c8b0 FUN_0023c8b0 (19 B): matches/0x0023c8b0.cpp
// sym: ?FUN_0023c8b0@fn_fe0ef8b4@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0023c8b0() {
    FUN_00234810(((char*)&DAT_004e5c44), ((char*)&DAT_004e5c48));
}

} // namespace fn_fe0ef8b4

// 0x0023c8d0 fight::SubConditionGroupCondition::vfunc_0 (16 B): matches/0x0023c8d0.cpp
// sym: ?vfunc_0@SubConditionGroupCondition@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::SubConditionGroupCondition::vfunc_0(int index) {
    int* p = hulk_at_004e5c44;
    return p[index];
}

namespace fn_fe0ef8b4 {

// 0x0023c900 FUN_0023c900 (25 B): matches/0x0023c900.cpp
// sym: ??1SubConditionGroupCondition_23c900@fn_fe0ef8b4@@QAE@XZ
// Same code shape as 0x0010c7d0 (propagated; names are from that function)
SubConditionGroupCondition_23c900::~SubConditionGroupCondition_23c900() {
    m.Release_00236fd0();
    Shutdown_002345b0();
}


// 0x0023c920 fight::SubConditionGroupCondition::vfunc_6 (8 B): matches/0x0023c920.cpp
// sym: ?vfunc_6@SubConditionGroupCondition@fn_fe0ef8b4@@UAEHHHH@Z
int SubConditionGroupCondition::vfunc_6(int a0, int a1, int a2) {
    return ((Helper_23c920*)((char*)this + 0xc))->Fnf_00236f40(a0, a1, a2);
}

} // namespace fn_fe0ef8b4

// 0x0023c930 fight::SubConditionGroupCondition::vfunc_5 (46 B): matches/0x0023c930.cpp [wrapped: conflict: SubConditionGroupCondition]
// sym: ?vfunc_5@SubConditionGroupCondition@fn_0023c930@@UAEPAV12@H@Z
namespace fn_0023c930 {
extern "C" char DAT_004288fc[];
class SubConditionGroupCondition;
struct Part_23c930 {
    char pad[12];
    void Init_00236fd0();
};
class SubConditionGroupCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual SubConditionGroupCondition* vfunc_5(int);
    virtual void v6();
    void Finalize_002345b0();
};
extern void __cdecl DestroySub_0008d330(SubConditionGroupCondition*);
SubConditionGroupCondition* SubConditionGroupCondition::vfunc_5(int flags) {
    Part_23c930* p = (Part_23c930*)((char*)this + 12);
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_004288fc);
    p->Init_00236fd0();
    Finalize_002345b0();
    if (flags & 1)
        DestroySub_0008d330(this);
    return this;
}
} // namespace fn_0023c930

namespace fn_fe0ef8b4 {

// 0x0023c980 fight::ParamConditionGroup<fight::SubConditionGroupCondition>::vfunc_6 (12 B): matches/0x0023c980.cpp
// sym: ?vfunc_6@ParamBranch@fn_fe0ef8b4@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fe0ef8b4

// 0x0023c9a0 fight::ConditionFactoryCasterTemplate<fight::SubConditionGroupCondition>::vfunc_0 (36 B): matches/0x0023c9a0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VSubConditionGroupCondition@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<fight::SubConditionGroupCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023c9d0 fight::ParamConditionGroup<fight::SubConditionGroupCondition>::vfunc_0 (30 B): matches/0x0023c9d0.cpp
// sym: ??_G?$ParamConditionGroup@VSubConditionGroupCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamConditionGroup<fight::SubConditionGroupCondition>::~ParamConditionGroup() {}
#if defined(HULK_PTR64)
template class fight::ParamConditionGroup<fight::SubConditionGroupCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x23c9d0)
#endif

namespace fn_fe0ef8b4 {

// 0x0023ca70 FUN_0023ca70 (38 B): matches/0x0023ca70.cpp
// sym: _FUN_0023ca70
extern "C" void FUN_0023ca70(Factory* f, void* p) {
    ConditionFactoryCasterTemplate_23ca70 c;
    f->Do(Find(p, &c));
}

} // namespace fn_fe0ef8b4

// 0x0023caa0 fight::ConditionFactoryCasterTemplate<fight::SubConditionGroupCondition>::vfunc_1 (60 B): matches/0x0023caa0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VSubConditionGroupCondition@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<fight::SubConditionGroupCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_23caa0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_23caa0* t = new (mem) TrackFactoryTemplate_23caa0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0023c9f0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0023cae0 fight::ConditionFactoryTemplate<fight::SubConditionGroupCondition>::vfunc_5 (48 B): matches/0x0023cae0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VSubConditionGroupCondition@fight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<fight::SubConditionGroupCondition>::vfunc_5() {
    Condition_23cae0* p = (Condition_23cae0*)FUN_0008d690(0x10);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_004288fc);
        ((Tail_23cae0*)((char*)p + 12))->InitTail_00236e00();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fe0ef8b4 {

// 0x0023cb10 fight::ConditionFactoryTemplate<fight::SubConditionGroupCondition>::vfunc_2 (43 B): matches/0x0023cb10.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_23cb10@fn_fe0ef8b4@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_23cb10::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00428948;
    base1_dtor_0023c8b0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fe0ef8b4

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001890a0..0x001899a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainShootTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f64d638a {
#define TREE_TU_END }
namespace fn_f64d638a {} using namespace fn_f64d638a;
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f64d638a {
typedef unsigned int u32_1890a0;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct Result_1890a0 {
    u32_1890a0 Init_001847e0(void*, void*);
};
extern Result_1890a0* Alloc_0008d690(int);
struct RefCounted_1890f0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00419790[];
class BallAndChainSpinAction_1890f0 {
  public:
    BallAndChainSpinAction_1890f0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_1890f0* m_20;
};
struct Allocated_189140 {
    int run_00184880(hulkfight::motion::BallAndChainShootTrack*, hulk_intptr);
};
extern Allocated_189140* alloc_0008d690(int);
extern int typeA_189140, typeB;
typedef unsigned int u32_1891f0;
struct Track_1891f0 {
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
    virtual u32_1891f0 v10(u32_1891f0 a, u32_1891f0 b, u32_1891f0 c);
};
struct Obj_1891f0 {
    u32_1891f0 Init_00184ef0(hulkfight::motion::BallAndChainReturnTrack*, hulk_uintptr);
};
extern void* Alloc(hulk_uintptr);
extern int typeA_1891f0, typeB;
struct RefCounted_189240 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_004197c8[];
class BallAndChainReturnAction_189240 {
  public:
    BallAndChainReturnAction_189240* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_189240* m_20;
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};

} // namespace fn_f64d638a

// 0x001890a0 hulkfight::motion::BallAndChainSpinTrack::vfunc_10 (70 B): matches/0x001890a0.cpp
// sym: ?vfunc_10@BallAndChainSpinTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::BallAndChainSpinTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1890a0 a = (u32_1890a0)__p0; u32_1890a0 b = (u32_1890a0)__p1; void * p = (void *)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0))) {
        Result_1890a0* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(q->Init_001847e0(this, p));
    }
    return (int)(0);
}

namespace fn_f64d638a {

// 0x001890f0 hulkfight::motion::BallAndChainSpinAction::vfunc_2 (71 B): matches/0x001890f0.cpp
// sym: ?vfunc_2@BallAndChainSpinAction_1890f0@fn_f64d638a@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
BallAndChainSpinAction_1890f0* BallAndChainSpinAction_1890f0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00419790;
    RefCounted_1890f0* q = *(RefCounted_1890f0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}

} // namespace fn_f64d638a

// 0x00189140 hulkfight::motion::BallAndChainShootTrack::vfunc_10 (70 B): matches/0x00189140.cpp
// sym: ?vfunc_10@BallAndChainShootTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::BallAndChainShootTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&typeA_189140), (void*)(&typeB), 0))) {
        Allocated_189140* q = alloc_0008d690(0x54);
        if (q)
            return q->run_00184880(this, c);
    }
    return 0;
}


// 0x00189190 hulkfight::motion::BallAndChainShootAction::vfunc_2 (90 B): matches/0x00189190.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?vfunc_2@AnimationAction@motion@hulkfight@fn_00189190@@QAEPAV1234@E@Z
namespace fn_00189190 {
// Same code shape as 0x0013bde0 (propagated; names are from that function)
extern "C" {
extern "C" char DAT_004197ac[];
extern "C++" { __declspec(nothrow) void __cdecl opdel_0008d330(void*); }
void _ReadWriteBarrier();
}

class RefObj_189190 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};

namespace hulkfight {
namespace motion {

class AnimationAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    AnimationAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    void Cleanup_002326a0();

    char pad[0x18];
    int m1c;
    RefObj_189190* m20;
    RefObj_189190* m24;
};

AnimationAction* AnimationAction::vfunc_2(unsigned char param) {
    *(hulk_intptr*)this = (hulk_intptr)DAT_004197ac;
    _ReadWriteBarrier();
    RefObj_189190* a = m20;
    if (a) {
        a->Release();
        m20 = 0;
    }
    int v = m1c;
    if (v) {
        m1c = 0;
    }
    RefObj_189190* b = m24;
    if (b) {
        b->Release();
        m24 = 0;
    }
    this->Cleanup_002326a0();
    if (param & 1) {
        opdel_0008d330(this);
    }
    return this;
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_00189190


// 0x001891f0 hulkfight::motion::BallAndChainReturnTrack::vfunc_10 (70 B): matches/0x001891f0.cpp
// sym: ?vfunc_10@BallAndChainReturnTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::BallAndChainReturnTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1891f0 a = (u32_1891f0)__p0; u32_1891f0 b = (u32_1891f0)__p1; hulk_uintptr c = (u32_1891f0)__p2;

    if (((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)((hulk_intptr)&typeB), (void*)((hulk_intptr)&typeA_1891f0), 0))) {
        Obj_1891f0* p = (Obj_1891f0*)Alloc_0008d690(0x48);
        if (p)
            return (int)(p->Init_00184ef0(this, c));
    }
    return (int)(0);
}

namespace fn_f64d638a {

// 0x00189240 hulkfight::motion::BallAndChainReturnAction::vfunc_2 (71 B): matches/0x00189240.cpp
// sym: ?vfunc_2@BallAndChainReturnAction_189240@fn_f64d638a@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
BallAndChainReturnAction_189240* BallAndChainReturnAction_189240::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_004197c8;
    RefCounted_189240* q = *(RefCounted_189240* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}


// 0x00189310 fight::ParamName<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_7 (12 B): matches/0x00189310.cpp
// sym: ?vfunc_6@ParamBranch@fn_f64d638a@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f64d638a

// 0x00189380 fight::ParamNameConstList<hulkfight::motion::PropMassCondition>::vfunc_7 (12 B): matches/0x00189380.cpp [wrapped: same definition as 0x00189310 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00189380@@UAEXPAX@Z
namespace fn_00189380 {
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
} // namespace fn_00189380


// 0x00189410 fight::ParamName<hulkfight::motion::PropStateByNameCondition>::vfunc_7 (12 B): matches/0x00189410.cpp [wrapped: same definition as 0x00189310 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00189410@@UAEXPAX@Z
namespace fn_00189410 {
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
} // namespace fn_00189410


// 0x00189520 fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>::vfunc_7 (12 B): matches/0x00189520.cpp [wrapped: same definition as 0x00189310 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00189520@@UAEXPAX@Z
namespace fn_00189520 {
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
} // namespace fn_00189520


// 0x001895b0 fight::ParamName<hulkfight::motion::PropAnimationTrack>::vfunc_7 (12 B): matches/0x001895b0.cpp [wrapped: same definition as 0x00189310 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001895b0@@UAEXPAX@Z
namespace fn_001895b0 {
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
} // namespace fn_001895b0


// 0x00189620 fight::ParamName<hulkfight::motion::PropThrowTrack>::vfunc_7 (12 B): matches/0x00189620.cpp [wrapped: same definition as 0x00189310 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00189620@@UAEXPAX@Z
namespace fn_00189620 {
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
} // namespace fn_00189620


// 0x00189670 fight::ParamName<hulkfight::motion::BallAndChainReturnTrack>::vfunc_7 (12 B): matches/0x00189670.cpp [wrapped: same definition as 0x00189310 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00189670@@UAEXPAX@Z
namespace fn_00189670 {
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
} // namespace fn_00189670


// 0x001896a0 fight::ParamNameConstList<hulkfight::motion::BallAndChainReturnTrack>::vfunc_7 (12 B): matches/0x001896a0.cpp [wrapped: same definition as 0x00189310 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001896a0@@UAEXPAX@Z
namespace fn_001896a0 {
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
} // namespace fn_001896a0


// 0x00189710 fight::ParamName<hulkfight::motion::BallAndChainShootTrack>::vfunc_7 (12 B): matches/0x00189710.cpp [wrapped: same definition as 0x00189310 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00189710@@UAEXPAX@Z
namespace fn_00189710 {
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
} // namespace fn_00189710


// 0x00189740 fight::ParamNameConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_7 (12 B): matches/0x00189740.cpp [wrapped: same definition as 0x00189310 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00189740@@UAEXPAX@Z
namespace fn_00189740 {
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
} // namespace fn_00189740


// 0x00189830 fight::ParamNameConstList<hulkfight::motion::PropSpawnTrack>::vfunc_7 (12 B): matches/0x00189830.cpp [wrapped: same definition as 0x00189310 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00189830@@UAEXPAX@Z
namespace fn_00189830 {
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
} // namespace fn_00189830


// 0x00189860 fight::ParamName<hulkfight::motion::GrapplePropStateByNameCondition>::vfunc_0 (30 B): matches/0x00189860.cpp
// sym: ??_G?$ParamName@VGrapplePropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::GrapplePropStateByNameCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::GrapplePropStateByNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x189860)
#endif


// 0x00189880 fight::ParamNameConstList<hulkfight::motion::PropMassCondition>::vfunc_0 (30 B): matches/0x00189880.cpp
// sym: ??_G?$ParamNameConstList@VPropMassCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::PropMassCondition>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::PropMassCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x189880)
#endif


// 0x001898a0 fight::ParamName<hulkfight::motion::PropStateByNameCondition>::vfunc_0 (30 B): matches/0x001898a0.cpp
// sym: ??_G?$ParamName@VPropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::PropStateByNameCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::PropStateByNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1898a0)
#endif


// 0x001898c0 fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0 (30 B): matches/0x001898c0.cpp
// sym: ??_G?$ParamName@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1898c0)
#endif


// 0x001898e0 fight::ParamName<hulkfight::motion::PropAnimationTrack>::vfunc_0 (30 B): matches/0x001898e0.cpp
// sym: ??_G?$ParamName@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::PropAnimationTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::PropAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1898e0)
#endif


// 0x00189900 fight::ParamName<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00189900.cpp
// sym: ??_G?$ParamName@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::PropThrowTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::PropThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x189900)
#endif


// 0x00189920 fight::ParamName<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x00189920.cpp
// sym: ??_G?$ParamName@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::BallAndChainReturnTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::BallAndChainReturnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x189920)
#endif


// 0x00189940 fight::ParamNameConstList<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x00189940.cpp
// sym: ??_G?$ParamNameConstList@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::BallAndChainReturnTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::BallAndChainReturnTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x189940)
#endif


// 0x00189960 fight::ParamName<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00189960.cpp
// sym: ??_G?$ParamName@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::BallAndChainShootTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::BallAndChainShootTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x189960)
#endif


// 0x00189980 fight::ParamNameConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00189980.cpp
// sym: ??_G?$ParamNameConstList@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::BallAndChainShootTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::BallAndChainShootTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x189980)
#endif


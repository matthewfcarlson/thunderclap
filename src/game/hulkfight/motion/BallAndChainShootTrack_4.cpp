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

// ---- declarations shared by the functions below
namespace fn_f64d638a {
typedef unsigned int u32_1890a0;
extern int TypeA_1890a0;
extern int TypeB_1890a0;
struct Result_1890a0 {
    u32_1890a0 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_1890a0* Alloc(int);
struct RefCounted_1890f0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_1890f0[];
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
    int run(hulkfight::motion::BallAndChainShootTrack*, hulk_intptr);
};
extern int check(void*, int, int*, int*, int);
extern Allocated_189140* alloc(int);
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
    u32_1891f0 Init(hulkfight::motion::BallAndChainReturnTrack*, hulk_uintptr);
};
extern int IsType(void*, int, hulk_intptr, hulk_intptr, int);
extern void* Alloc(hulk_uintptr);
extern int typeA_1891f0, typeB;
struct RefCounted_189240 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_189240[];
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

    if (Check(p, 0, &TypeA_1890a0, &TypeB_1890a0, 0)) {
        Result_1890a0* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}

namespace fn_f64d638a {

// 0x001890f0 hulkfight::motion::BallAndChainSpinAction::vfunc_2 (71 B): matches/0x001890f0.cpp
// sym: ?vfunc_2@BallAndChainSpinAction_1890f0@fn_f64d638a@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
BallAndChainSpinAction_1890f0* BallAndChainSpinAction_1890f0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_1890f0;
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
    if (check((void*)c, 0, &typeA_189140, &typeB, 0)) {
        Allocated_189140* q = alloc(0x54);
        if (q)
            return q->run(this, c);
    }
    return 0;
}


// 0x00189190 hulkfight::motion::BallAndChainShootAction::vfunc_2 (90 B): matches/0x00189190.cpp [wrapped: conflict: hulkfight::motion::AnimationAction]
// sym: ?vfunc_2@AnimationAction@motion@hulkfight@fn_00189190@@QAEPAV1234@E@Z
namespace fn_00189190 {
// Same code shape as 0x0013bde0 (propagated; names are from that function)
extern "C" {
extern "C" char DAT_004197ac[];
extern "C++" { __declspec(nothrow) void __cdecl opdel(void*); }
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

    void Cleanup();

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
    this->Cleanup();
    if (param & 1) {
        opdel(this);
    }
    return this;
}

} // namespace motion
} // namespace hulkfight
} // namespace fn_00189190


// 0x001891f0 hulkfight::motion::BallAndChainReturnTrack::vfunc_10 (70 B): matches/0x001891f0.cpp
// sym: ?vfunc_10@BallAndChainReturnTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::BallAndChainReturnTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_1891f0 a = (u32_1891f0)__p0; u32_1891f0 b = (u32_1891f0)__p1; hulk_uintptr c = (u32_1891f0)__p2;

    if (IsType((void*)c, 0, (hulk_intptr)&typeB, (hulk_intptr)&typeA_1891f0, 0)) {
        Obj_1891f0* p = (Obj_1891f0*)Alloc(0x48);
        if (p)
            return (int)(p->Init(this, c));
    }
    return (int)(0);
}

namespace fn_f64d638a {

// 0x00189240 hulkfight::motion::BallAndChainReturnAction::vfunc_2 (71 B): matches/0x00189240.cpp
// sym: ?vfunc_2@BallAndChainReturnAction_189240@fn_f64d638a@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
BallAndChainReturnAction_189240* BallAndChainReturnAction_189240::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_189240;
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


// 0x00189880 fight::ParamNameConstList<hulkfight::motion::PropMassCondition>::vfunc_0 (30 B): matches/0x00189880.cpp
// sym: ??_G?$ParamNameConstList@VPropMassCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::PropMassCondition>::~ParamNameConstList() {}


// 0x001898a0 fight::ParamName<hulkfight::motion::PropStateByNameCondition>::vfunc_0 (30 B): matches/0x001898a0.cpp
// sym: ??_G?$ParamName@VPropStateByNameCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::PropStateByNameCondition>::~ParamName() {}


// 0x001898c0 fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0 (30 B): matches/0x001898c0.cpp
// sym: ??_G?$ParamName@VPropSetStateByNameTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>::~ParamName() {}


// 0x001898e0 fight::ParamName<hulkfight::motion::PropAnimationTrack>::vfunc_0 (30 B): matches/0x001898e0.cpp
// sym: ??_G?$ParamName@VPropAnimationTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::PropAnimationTrack>::~ParamName() {}


// 0x00189900 fight::ParamName<hulkfight::motion::PropThrowTrack>::vfunc_0 (30 B): matches/0x00189900.cpp
// sym: ??_G?$ParamName@VPropThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::PropThrowTrack>::~ParamName() {}


// 0x00189920 fight::ParamName<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x00189920.cpp
// sym: ??_G?$ParamName@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::BallAndChainReturnTrack>::~ParamName() {}


// 0x00189940 fight::ParamNameConstList<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0 (30 B): matches/0x00189940.cpp
// sym: ??_G?$ParamNameConstList@VBallAndChainReturnTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::BallAndChainReturnTrack>::~ParamNameConstList() {}


// 0x00189960 fight::ParamName<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00189960.cpp
// sym: ??_G?$ParamName@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::BallAndChainShootTrack>::~ParamName() {}


// 0x00189980 fight::ParamNameConstList<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (30 B): matches/0x00189980.cpp
// sym: ??_G?$ParamNameConstList@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::BallAndChainShootTrack>::~ParamNameConstList() {}


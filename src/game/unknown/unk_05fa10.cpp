// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005fa10..0x000604d0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe2e62b7 {
#define TREE_TU_END }
namespace fn_fe2e62b7 {} using namespace fn_fe2e62b7;
#include "game/unknown.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fe2e62b7 {
extern "C" void* FUN_0008d690(unsigned int size);
class COpportunityBallTrack_5fa10 {
public:
    void FUN_0005d690();
    void FUN_0005d6a0();
    void FUN_0005d6b0();
    void FUN_0005d6c0();
    void FUN_0005d6e0();
    void FUN_0005d6f0();
    void FUN_00013050();
    void FUN_00013060();
};
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
template <class T>
class ParamBranch : public ParamBranchBase {
public:
    ParamBranch(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class CProceduralDurationAnimationTrack_5fbe0 {
public:
    void FUN_0005d700();
    void FUN_0005d710();
    void FUN_0005d720();
    void FUN_00013090();
    void FUN_0005d730();
    void FUN_0005d740();
    void FUN_0005d750();
    void FUN_0005d760();
    void FUN_0005d770();
    void FUN_000130f0();
    void FUN_0005d780();
    void FUN_0005d790();
    void FUN_0005d7a0();
    void FUN_0005d7b0();
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_fe2e62b7
namespace fight {
template <class T>
class ParamBool_5fbe0 : public ParamBoolBase {
public:
    ParamBool_5fbe0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_5fbe0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_5fbe0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_5fbe0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5fbe0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_5fbe0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5fbe0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_5fbe0 : public ParamNameBase {
public:
    ParamName_5fbe0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fe2e62b7 {
class CStunAnimationTrack_5fef0 {
public:
    void FUN_0005d7c0();
    void FUN_00013140();
    void FUN_0005d7d0();
    void FUN_0005d7e0();
    void FUN_0005d7f0();
    void FUN_0005d800();
    void FUN_0005d810();
    void FUN_000131a0();
    void FUN_0005d820();
    void FUN_0005d830();
    void FUN_0005d840();
};
} // namespace fn_fe2e62b7
namespace fight {
template <class T>
class ParamFloatConstRange_5fef0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5fef0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_5fef0 : public ParamNameBase {
public:
    ParamName_5fef0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_5fef0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5fef0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_5fef0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_5fef0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#endif
namespace fn_fe2e62b7 {
struct Sub_60170 {
    char data[8];
};
struct Object {
    char head[0x10c];
    int f10c, f110, f114, f118, f11c, f120, f124, f128, f12c, f130, f134, f138, f13c;
    Sub_60170 sub;
    char flag;
    void FUN_00060170();
};
class Sub_601f0 {
  public:
    void Call_0027af00();
};
struct Data_602a0 {
    int x;
};
class Obj_602a0 {
  public:
    char pad[0x58];
    Data_602a0* Get();
};
struct V {
    int a;
    int b;
    int c;
};
class T_602d0 {
  public:
    char Pad[0x6c];
    int m6c;
    int m70;
    int m74;
    char Set(V* v);
};
class Thing {
  public:
    char pad[0x9c];
    Src s;
    bool Set(const Src* p);
};
struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char _m_pad_0[0x84];
    int a;
    int b;
    int c;
    char _m_pad_90[0x20];
    int m_b0;
    int m_b4;
    int m_b8;
    bool Set(const V3* v);
    bool Set(const Vec3* v);
};
struct Vec3_60450 {
    int x, y, z;
};
class Obj_60450 {
  public:
    char pad[0x38];
    int a;
    int b;
    int c;
    bool Set(const Vec3_60450* v);
};


// 0x0005fa10 FUN_0005fa10 (460 B): equivalent/0x0005fa10.cpp
// sym: _FUN_0005fa10 @4b78b42fa8a2 @w1a62c898c9a9
// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 18/18)
// FUN_0005fa10 @ 0x0005fa10
extern "C" void FUN_0005fa10()
{
    if (DAT_004dc5dc == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COpportunityBallTrack_5fa10>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<COpportunityBallTrack_5fa10>("timeBegin", &COpportunityBallTrack_5fa10::FUN_0005d690);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COpportunityBallTrack_5fa10>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<COpportunityBallTrack_5fa10>("timeEnd", &COpportunityBallTrack_5fa10::FUN_0005d6a0);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<COpportunityBallTrack_5fa10>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamNameConstList<COpportunityBallTrack_5fa10>("joint", &COpportunityBallTrack_5fa10::FUN_0005d6b0);
        mem = FUN_0008d690((int)sizeof(ParamVector<COpportunityBallTrack_5fa10>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<COpportunityBallTrack_5fa10>("offset", &COpportunityBallTrack_5fa10::FUN_0005d6c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<COpportunityBallTrack_5fa10>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<COpportunityBallTrack_5fa10>("radius", &COpportunityBallTrack_5fa10::FUN_0005d6e0);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<COpportunityBallTrack_5fa10>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamIntConstRange<COpportunityBallTrack_5fa10>("maxHitCount", &COpportunityBallTrack_5fa10::FUN_0005d6f0);
        mem = FUN_0008d690((int)sizeof(ParamBranch<COpportunityBallTrack_5fa10>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamBranch<COpportunityBallTrack_5fa10>("receiver", &COpportunityBallTrack_5fa10::FUN_00013050);
        mem = FUN_0008d690((int)sizeof(ParamBranch<COpportunityBallTrack_5fa10>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamBranch<COpportunityBallTrack_5fa10>("giver", &COpportunityBallTrack_5fa10::FUN_00013060);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5d8), params, 8);
    }
    DAT_004dc5dc++;
}


// 0x0005fbe0 FUN_0005fbe0 (784 B): equivalent/0x0005fbe0.cpp
// sym: _FUN_0005fbe0 @fe8a8dc65ebc @wc92ed906f70c
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// FUN_0005fbe0 @ 0x0005fbe0
extern "C" void FUN_0005fbe0()
{
    if (DAT_004dc5e4 == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("timeBegin", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d700);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("timeScale", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d710);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("timeEndMin", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d720);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("animation", &CProceduralDurationAnimationTrack_5fbe0::FUN_00013090);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("speed", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d730);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("initFrame", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d740);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("startFrame", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d750);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("endFrame", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d760);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamEnumConstList_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("cyclic", ((const char**)&DAT_004abf70), (*(int*)&DAT_004123d4), &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d770);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("partition", &CProceduralDurationAnimationTrack_5fbe0::FUN_000130f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamIntConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("priority", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d780);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("blendInTime", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d790);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("blendOutTime", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d7a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_5fbe0<CProceduralDurationAnimationTrack_5fbe0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamBool_5fbe0<CProceduralDurationAnimationTrack_5fbe0>("useRootMotion", &CProceduralDurationAnimationTrack_5fbe0::FUN_0005d7b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5e0), params, 14);
    }
    DAT_004dc5e4++;
}


// 0x0005fef0 FUN_0005fef0 (631 B): equivalent/0x0005fef0.cpp
// sym: _FUN_0005fef0 @dcfa6e5b5b42 @wa801744abcc5
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 24/24)
// FUN_0005fef0 @ 0x0005fef0
extern "C" void FUN_0005fef0()
{
    if (DAT_004dc5ec == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>("timeBegin", &CStunAnimationTrack_5fef0::FUN_0005d7c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5fef0<CStunAnimationTrack_5fef0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName_5fef0<CStunAnimationTrack_5fef0>("animation", &CStunAnimationTrack_5fef0::FUN_00013140);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>("speed", &CStunAnimationTrack_5fef0::FUN_0005d7d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>("initFrame", &CStunAnimationTrack_5fef0::FUN_0005d7e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>("startFrame", &CStunAnimationTrack_5fef0::FUN_0005d7f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>("endFrame", &CStunAnimationTrack_5fef0::FUN_0005d800);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_5fef0<CStunAnimationTrack_5fef0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamEnumConstList_5fef0<CStunAnimationTrack_5fef0>("cyclic", ((const char**)&DAT_004abf70), (*(int*)&DAT_004123d4), &CStunAnimationTrack_5fef0::FUN_0005d810);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5fef0<CStunAnimationTrack_5fef0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamName_5fef0<CStunAnimationTrack_5fef0>("partition", &CStunAnimationTrack_5fef0::FUN_000131a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_5fef0<CStunAnimationTrack_5fef0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_5fef0<CStunAnimationTrack_5fef0>("priority", &CStunAnimationTrack_5fef0::FUN_0005d820);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>("blendInTime", &CStunAnimationTrack_5fef0::FUN_0005d830);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_5fef0<CStunAnimationTrack_5fef0>("blendOutTime", &CStunAnimationTrack_5fef0::FUN_0005d840);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5e8), params, 11);
    }
    DAT_004dc5ec++;
}


// 0x00060170 FUN_00060170 (118 B): equivalent/0x00060170.cpp
// sym: ?FUN_00060170@Object@fn_fe2e62b7@@QAEXXZ @b45888004883 @w90958a31a05c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00060170 @ 0x00060170
void Object::FUN_00060170() {
    memset(this, 0, 0x10c);
    f114 = 0;
    f110 = 0;
    f10c = 0;
    f118 = 0;
    f124 = 0;
    f120 = 0;
    f11c = 0;
    f130 = 0;
    f12c = 0;
    f128 = 0;
    ((owners::Target_27b040 *)&sub)->FUN_0027b040((hulk_uintptr)0);
    flag = 0;
    f13c = 0;
    f138 = 0;
    f134 = 0;
}

} // namespace fn_fe2e62b7

// 0x000601f0 FUN_000601f0 (25 B): matches/0x000601f0.cpp
// sym: ?FUN_000601f0@Obj_601f0@owners@@QAEPAU12@XZ
owners::Obj_601f0* owners::Obj_601f0::FUN_000601f0() {
    ((Sub_601f0*)((char*)this + 0x140))->Call_0027af00();
    G();
    return this;
}


// 0x00060210 FUN_00060210 (12 B): matches/0x00060210.cpp
// sym: ?FUN_00060210@A_60210@owners@@QAEDH@Z
char owners::A_60210::FUN_00060210(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}


// 0x00060220 FUN_00060220 (12 B): matches/0x00060220.cpp
// sym: ?FUN_00060220@Obj_60220@owners@@QAEDH@Z
char owners::Obj_60220::FUN_00060220(int x) {
    m10 = x;
    return 1;
}


// 0x00060230 FUN_00060230 (12 B): matches/0x00060230.cpp
// sym: ?FUN_00060230@Obj_60230@owners@@QAEDH@Z
char owners::Obj_60230::FUN_00060230(int x) {
    m = x;
    return 1;
}


// 0x00060240 FUN_00060240 (12 B): matches/0x00060240.cpp
// sym: ?FUN_00060240@Obj_60240@owners@@QAEDH@Z
char owners::Obj_60240::FUN_00060240(int v) {
    mVal = v;
    return 1;
}


// 0x00060250 FUN_00060250 (4 B): matches/0x00060250.cpp
// sym: ?FUN_00060250@Obj_60250@owners@@QAEPAXXZ
void* owners::Obj_60250::FUN_00060250() {
    return (char*)this + 0x30;
}


// 0x00060260 FUN_00060260 (4 B): matches/0x00060260.cpp
// sym: ?FUN_00060260@Obj_60260@owners@@QAEPADXZ
char* owners::Obj_60260::FUN_00060260() {
    return (char*)this + 0x38;
}


// 0x00060270 FUN_00060270 (4 B): matches/0x00060270.cpp
// sym: ?FUN_00060270@Obj_60270@owners@@QAEPADXZ
char* owners::Obj_60270::FUN_00060270() throw() {
    return pad + 0x40;
}


// 0x00060280 FUN_00060280 (4 B): matches/0x00060280.cpp
// sym: ?FUN_00060280@T_60280@owners@@QAEPAXXZ
void* owners::T_60280::FUN_00060280() {
    return (char*)this + 0x48;
}


// 0x00060290 FUN_00060290 (4 B): matches/0x00060290.cpp
// sym: ?FUN_00060290@Obj_60290@owners@@QAEPAHXZ
int* owners::Obj_60290::FUN_00060290() {
    return &value;
}

namespace fn_fe2e62b7 {

// 0x000602a0 FUN_000602a0 (4 B): matches/0x000602a0.cpp
// sym: ?Get@Obj_602a0@fn_fe2e62b7@@QAEPAUData_602a0@2@XZ
Data_602a0* Obj_602a0::Get() {
    return (Data_602a0*)((char*)this + 0x58);
}

} // namespace fn_fe2e62b7

// 0x000602b0 FUN_000602b0 (26 B): matches/0x000602b0.cpp
// sym: ?FUN_000602b0@Obj_602b0@owners@@QAE_NPBX@Z
bool owners::Obj_602b0::FUN_000602b0(const void* src) {
    a = *(const int*)src;
    b = *(const int*)((const char*)src + 4);
    c = *(const int*)((const char*)src + 8);
    return true;
}

namespace fn_fe2e62b7 {

// 0x000602d0 FUN_000602d0 (26 B): matches/0x000602d0.cpp
// sym: ?Set@T_602d0@fn_fe2e62b7@@QAEDPAUV@2@@Z
char T_602d0::Set(V* v) {
    m6c = v->a;
    m70 = v->b;
    m74 = v->c;
    return 1;
}

} // namespace fn_fe2e62b7

// 0x000602f0 FUN_000602f0 (29 B): matches/0x000602f0.cpp
// sym: ?FUN_000602f0@Obj_602f0@owners@@QAE_NPAH@Z
bool owners::Obj_602f0::FUN_000602f0(int* x) {
    a = x[0];
    b = x[1];
    c = x[2];
    return true;
}

namespace fn_fe2e62b7 {

// 0x00060310 FUN_00060310 (35 B): matches/0x00060310.cpp
// sym: ?Set@Obj@fn_fe2e62b7@@QAE_NPBUV3@2@@Z
bool Obj::Set(const V3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}

} // namespace fn_fe2e62b7

// 0x00060340 FUN_00060340 (35 B): matches/0x00060340.cpp
// sym: ?FUN_00060340@Obj_60340@owners@@QAEDPAX@Z
char owners::Obj_60340::FUN_00060340(void* p) {
    int* q = (int*)p;
    a = q[0];
    b = q[1];
    c = q[2];
    return 1;
}

namespace fn_fe2e62b7 {

// 0x00060370 FUN_00060370 (35 B): matches/0x00060370.cpp
// sym: ?Set@Thing@fn_fe2e62b7@@QAE_NPBUSrc@2@@Z
bool Thing::Set(const Src* p) {
    s.a = p->a;
    s.b = p->b;
    s.c = p->c;
    return true;
}


// 0x000603a0 FUN_000603a0 (35 B): matches/0x000603a0.cpp
// sym: ?Set@Obj@fn_fe2e62b7@@QAE_NPBUVec3@2@@Z
bool Obj::Set(const Vec3* v) {
    m_b0 = v->x;
    m_b4 = v->y;
    m_b8 = v->z;
    return true;
}

} // namespace fn_fe2e62b7

// 0x000603d0 FUN_000603d0 (15 B): matches/0x000603d0.cpp
// sym: ?FUN_000603d0@X_603d0@owners@@QAE_NH@Z
bool owners::X_603d0::FUN_000603d0(int v) {
    m = v;
    return true;
}


// 0x000603e0 FUN_000603e0 (15 B): matches/0x000603e0.cpp
// sym: ?FUN_000603e0@X_603e0@owners@@QAEDH@Z
char owners::X_603e0::FUN_000603e0(int v) {
    mVal = v;
    return 1;
}


// 0x000603f0 FUN_000603f0 (15 B): matches/0x000603f0.cpp
// sym: ?FUN_000603f0@T_603f0@owners@@QAE_NH@Z
bool owners::T_603f0::FUN_000603f0(int x) {
    m = x;
    return true;
}


// 0x00060400 FUN_00060400 (15 B): matches/0x00060400.cpp
// sym: ?FUN_00060400@Obj_60400@owners@@QAE_ND@Z
bool owners::Obj_60400::FUN_00060400(char c) {
    pad[0xc8] = c;
    return true;
}


// 0x00060410 FUN_00060410 (15 B): matches/0x00060410.cpp
// sym: ?FUN_00060410@Obj_60410@owners@@QAE_NE@Z
bool owners::Obj_60410::FUN_00060410(unsigned char v) {
    value = v;
    return true;
}


// 0x00060420 FUN_00060420 (15 B): matches/0x00060420.cpp
// sym: ?FUN_00060420@Obj_60420@owners@@QAE_NH@Z
bool owners::Obj_60420::FUN_00060420(int v) {
    mValue = v;
    return true;
}


// 0x00060430 FUN_00060430 (12 B): matches/0x00060430.cpp
// sym: ?FUN_00060430@Obj_60430@owners@@QAE_NH@Z
bool owners::Obj_60430::FUN_00060430(int v) {
    m = v;
    return true;
}


// 0x00060440 FUN_00060440 (12 B): matches/0x00060440.cpp
// sym: ?FUN_00060440@Obj_60440@owners@@QAE_NH@Z
bool owners::Obj_60440::FUN_00060440(int x) {
    value = x;
    return true;
}

namespace fn_fe2e62b7 {

// 0x00060450 FUN_00060450 (26 B): matches/0x00060450.cpp
// sym: ?Set@Obj_60450@fn_fe2e62b7@@QAE_NPBUVec3_60450@2@@Z
bool Obj_60450::Set(const Vec3_60450* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}

} // namespace fn_fe2e62b7

// 0x00060470 FUN_00060470 (12 B): matches/0x00060470.cpp
// sym: ?FUN_00060470@Obj_60470@owners@@QAE_NH@Z
bool owners::Obj_60470::FUN_00060470(int v) {
    m20 = v;
    return true;
}


// 0x00060480 FUN_00060480 (12 B): matches/0x00060480.cpp
// sym: ?FUN_00060480@Obj_60480@owners@@QAE_NH@Z
bool owners::Obj_60480::FUN_00060480(int x) {
    field = x;
    return true;
}


// 0x00060490 FUN_00060490 (12 B): matches/0x00060490.cpp
// sym: ?FUN_00060490@Obj_60490@owners@@QAEDD@Z
char owners::Obj_60490::FUN_00060490(char c) {
    m50 = c;
    return 1;
}


// 0x000604a0 FUN_000604a0 (12 B): matches/0x000604a0.cpp
// sym: ?FUN_000604a0@Obj_604a0@owners@@QAEEE@Z
unsigned char owners::Obj_604a0::FUN_000604a0(unsigned char x) {
    Value = x;
    return 1;
}


// 0x000604b0 FUN_000604b0 (12 B): matches/0x000604b0.cpp
// sym: ?FUN_000604b0@T_604b0@owners@@QAE_NH@Z
bool owners::T_604b0::FUN_000604b0(int v) {
    m54 = v;
    return true;
}


// 0x000604c0 FUN_000604c0 (12 B): matches/0x000604c0.cpp
// sym: ?FUN_000604c0@Obj_604c0@owners@@QAE_NH@Z
bool owners::Obj_604c0::FUN_000604c0(int v) {
    m58 = v;
    return true;
}


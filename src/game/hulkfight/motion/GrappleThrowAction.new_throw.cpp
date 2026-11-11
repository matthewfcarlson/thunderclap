// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00146900..0x0014c470 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleThrowAction
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f3a660e0 {
#define TREE_TU_END }
namespace fn_f3a660e0 {} using namespace fn_f3a660e0;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f3a660e0 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f3a660e0
namespace hulkfight { namespace motion {
class GrappleAttachedCondition_14a1e0 {
public:
    void FUN_00146920();
};
} }
namespace fn_f3a660e0 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamBool_14a1e0 : public ParamBoolBase {
public:
    ParamBool_14a1e0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3a660e0 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f3a660e0
namespace hulkfight { namespace motion {
class CivilianAttachedCondition_14a240 {
public:
    void FUN_00146930();
};
} }
namespace fight {
template <class T>
class ParamBool_14a240 : public ParamBoolBase {
public:
    ParamBool_14a240(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CivilianTargetCondition_14a2a0 {
public:
    void FUN_00146940();
};
} }
namespace fight {
template <class T>
class ParamBool_14a2a0 : public ParamBoolBase {
public:
    ParamBool_14a2a0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class GrappleOrientationCondition_14a300 {
public:
    void FUN_00146950();
    void FUN_00146970();
};
} }
namespace fn_f3a660e0 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamFloatConstRange_14a300 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14a300(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3a660e0 {
class GrappleThrowTrack {
public:
    void FUN_00146a40();
    void FUN_00146a70();
    void FUN_00146aa0();
    void FUN_00146ac0();
    void FUN_00146ae0();
    void FUN_00146b00();
    void FUN_00146b20();
    void FUN_00146b50();
    void FUN_00146b80();
    void FUN_00146bb0();
    void FUN_00146bd0();
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamFloatConstRange_14a480 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14a480(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_14a480 : public ParamVectorBase {
public:
    ParamVector_14a480(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3a660e0 {
class GrappleStruggleTrack {
public:
    void FUN_00146be0();
    void FUN_00146bf0();
    void FUN_00146c10();
    void FUN_00146c30();
    void FUN_00146c50();
    void FUN_00146c70();
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class CivilianThrowTrack {
public:
    void FUN_00146c80();
    void FUN_00146cb0();
    void FUN_00146ce0();
    void FUN_00146d00();
    void FUN_00146d20();
    void FUN_00146d40();
    void FUN_00146d60();
    void FUN_00146d90();
    void FUN_00146dc0();
    void FUN_00146df0();
    void FUN_00146e10();
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamFloatConstRange_14a860 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14a860(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_14a860 : public ParamVectorBase {
public:
    ParamVector_14a860(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CivilianAttachTrack_14aad0 {
public:
    void FUN_00146e20();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_14aad0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14aad0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f3a660e0 {
class GrappleExecuteTrack {
public:
    void FUN_00147030();
    void FUN_00147040();
    void FUN_00147050();
    void FUN_00147070();
    void FUN_00147080();
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
} // namespace fn_f3a660e0
namespace hulkfight { namespace motion {
class GrappleAttachJointCondition_14b340 {
public:
    void FUN_00146900();
    void FUN_00146910();
};
} }
namespace fn_f3a660e0 {
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamEnumConstList_14b340 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_14b340(const char* name, const char** n, int c, void (T::*s)())
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
class ParamNameConstList_14b340 : public ParamNameConstListBase {
public:
    ParamNameConstList_14b340(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class GrappleHitReactionTrack_14b5d0 {
public:
    void FUN_00146e30();
    void FUN_00146e50();
    void FUN_00146e70();
    void FUN_00146e90();
    void FUN_00146eb0();
    void FUN_00146ed0();
    void FUN_00146ef0();
    void FUN_00146f10();
    void FUN_00146f30();
    void FUN_00146f50();
    void FUN_00146f70();
    void FUN_00146f90();
    void FUN_00146fc0();
    void FUN_00146fe0();
    void FUN_00147000();
    void FUN_00147020();
};
} }
namespace fn_f3a660e0 {
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_f3a660e0
namespace fight {
template <class T>
class ParamBool_14b5d0 : public ParamBoolBase {
public:
    ParamBool_14b5d0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_14b5d0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_14b5d0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_14b5d0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14b5d0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_14b5d0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_14b5d0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_14b5d0 : public ParamNameBase {
public:
    ParamName_14b5d0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class CivilianAnimationTrack_14b9c0 {
public:
    void FUN_00147090();
    void FUN_001470b0();
    void FUN_001470c0();
    void FUN_001470e0();
    void FUN_00147100();
    void FUN_00147120();
    void FUN_00147140();
};
} }
namespace fn_f3a660e0 {
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};


// 0x0014a1e0 FUN_0014a1e0 (95 B): equivalent/0x0014a1e0.cpp
// sym: ?FUN_0014a1e0@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_0014a1e0 @ 0x0014a1e0
void FUN_0014a1e0()
{
    if (DAT_004e0fc8 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_14a1e0<hulkfight::motion::GrappleAttachedCondition_14a1e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_14a1e0<hulkfight::motion::GrappleAttachedCondition_14a1e0>("isAttached", &hulkfight::motion::GrappleAttachedCondition_14a1e0::FUN_00146920);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fc4), params, 1);
    }
    DAT_004e0fc8++;
}


// 0x0014a240 FUN_0014a240 (95 B): equivalent/0x0014a240.cpp
// sym: ?FUN_0014a240@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_0014a240 @ 0x0014a240
void FUN_0014a240()
{
    if (DAT_004e0fd0 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_14a240<hulkfight::motion::CivilianAttachedCondition_14a240>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_14a240<hulkfight::motion::CivilianAttachedCondition_14a240>("isAttached", &hulkfight::motion::CivilianAttachedCondition_14a240::FUN_00146930);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fcc), params, 1);
    }
    DAT_004e0fd0++;
}


// 0x0014a2a0 FUN_0014a2a0 (95 B): equivalent/0x0014a2a0.cpp
// sym: ?FUN_0014a2a0@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_0014a2a0 @ 0x0014a2a0
void FUN_0014a2a0()
{
    if (DAT_004e0fd8 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_14a2a0<hulkfight::motion::CivilianTargetCondition_14a2a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_14a2a0<hulkfight::motion::CivilianTargetCondition_14a2a0>("hasTarget", &hulkfight::motion::CivilianTargetCondition_14a2a0::FUN_00146940);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fd4), params, 1);
    }
    DAT_004e0fd8++;
}


// 0x0014a300 FUN_0014a300 (158 B): equivalent/0x0014a300.cpp
// sym: ?FUN_0014a300@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_0014a300 @ 0x0014a300
void FUN_0014a300()
{
    if (DAT_004e0fe0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a300<hulkfight::motion::GrappleOrientationCondition_14a300>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14a300<hulkfight::motion::GrappleOrientationCondition_14a300>("angle", &hulkfight::motion::GrappleOrientationCondition_14a300::FUN_00146950);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a300<hulkfight::motion::GrappleOrientationCondition_14a300>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_14a300<hulkfight::motion::GrappleOrientationCondition_14a300>("arc", &hulkfight::motion::GrappleOrientationCondition_14a300::FUN_00146970);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fdc), params, 2);
    }
    DAT_004e0fe0++;
}


// 0x0014a480 FUN_0014a480 (613 B): equivalent/0x0014a480.cpp
// sym: ?FUN_0014a480@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_0014a480 @ 0x0014a480
void FUN_0014a480()
{
    if (DAT_004e0ff0 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("timeBegin", &GrappleThrowTrack::FUN_00146a40);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_14a480<GrappleThrowTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector_14a480<GrappleThrowTrack>("direction", &GrappleThrowTrack::FUN_00146a70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("distanceMin", &GrappleThrowTrack::FUN_00146aa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("distanceMax", &GrappleThrowTrack::FUN_00146ac0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("velocityMin", &GrappleThrowTrack::FUN_00146ae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("velocityMax", &GrappleThrowTrack::FUN_00146b00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("trackingMin", &GrappleThrowTrack::FUN_00146b20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("trackingMax", &GrappleThrowTrack::FUN_00146b50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("yFixupAngle", &GrappleThrowTrack::FUN_00146b80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("stunTimeMin", &GrappleThrowTrack::FUN_00146bb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a480<GrappleThrowTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_14a480<GrappleThrowTrack>("stunTimeMax", &GrappleThrowTrack::FUN_00146bd0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fec), params, 11);
    }
    DAT_004e0ff0++;
}


// 0x0014a6f0 FUN_0014a6f0 (358 B): equivalent/0x0014a6f0.cpp
// sym: ?FUN_0014a6f0@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 14/14)
// FUN_0014a6f0 @ 0x0014a6f0
void FUN_0014a6f0()
{
    if (DAT_004e0ff8 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("timeBegin", &GrappleStruggleTrack::FUN_00146be0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("timeEnd", &GrappleStruggleTrack::FUN_00146bf0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("timeInput", &GrappleStruggleTrack::FUN_00146c10);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("chargeRateMin", &GrappleStruggleTrack::FUN_00146c30);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("chargeRateMax", &GrappleStruggleTrack::FUN_00146c50);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleStruggleTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<GrappleStruggleTrack>("chargeButtonRate", &GrappleStruggleTrack::FUN_00146c70);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ff4), params, 6);
    }
    DAT_004e0ff8++;
}


// 0x0014a860 FUN_0014a860 (613 B): equivalent/0x0014a860.cpp
// sym: ?FUN_0014a860@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_0014a860 @ 0x0014a860
void FUN_0014a860()
{
    if (DAT_004e1000 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("timeBegin", &CivilianThrowTrack::FUN_00146c80);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_14a860<CivilianThrowTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector_14a860<CivilianThrowTrack>("direction", &CivilianThrowTrack::FUN_00146cb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("distanceMin", &CivilianThrowTrack::FUN_00146ce0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("distanceMax", &CivilianThrowTrack::FUN_00146d00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("velocityMin", &CivilianThrowTrack::FUN_00146d20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("velocityMax", &CivilianThrowTrack::FUN_00146d40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("trackingMin", &CivilianThrowTrack::FUN_00146d60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("trackingMax", &CivilianThrowTrack::FUN_00146d90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("yFixupAngle", &CivilianThrowTrack::FUN_00146dc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("stunTimeMin", &CivilianThrowTrack::FUN_00146df0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14a860<CivilianThrowTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_14a860<CivilianThrowTrack>("stunTimeMax", &CivilianThrowTrack::FUN_00146e10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ffc), params, 11);
    }
    DAT_004e1000++;
}


// 0x0014aad0 FUN_0014aad0 (95 B): equivalent/0x0014aad0.cpp
// sym: ?FUN_0014aad0@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_0014aad0 @ 0x0014aad0
void FUN_0014aad0()
{
    if (DAT_004e1008 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14aad0<hulkfight::motion::CivilianAttachTrack_14aad0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14aad0<hulkfight::motion::CivilianAttachTrack_14aad0>("timeBegin", &hulkfight::motion::CivilianAttachTrack_14aad0::FUN_00146e20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1004), params, 1);
    }
    DAT_004e1008++;
}


// 0x0014ab30 FUN_0014ab30 (307 B): equivalent/0x0014ab30.cpp
// sym: ?FUN_0014ab30@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_0014ab30 @ 0x0014ab30
void FUN_0014ab30()
{
    if (DAT_004e1018 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleExecuteTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<GrappleExecuteTrack>("timeBegin", &GrappleExecuteTrack::FUN_00147030);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<GrappleExecuteTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<GrappleExecuteTrack>("timeEnd", &GrappleExecuteTrack::FUN_00147040);
        mem = FUN_0008d690((int)sizeof(ParamBranch<GrappleExecuteTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBranch<GrappleExecuteTrack>("branch", &GrappleExecuteTrack::FUN_00147050);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<GrappleExecuteTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<GrappleExecuteTrack>("priority", &GrappleExecuteTrack::FUN_00147070);
        mem = FUN_0008d690((int)sizeof(ParamConditionGroup<GrappleExecuteTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamConditionGroup<GrappleExecuteTrack>("conditionGroup", &GrappleExecuteTrack::FUN_00147080);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1014), params, 5);
    }
    DAT_004e1018++;
}


// 0x0014b340 FUN_0014b340 (176 B): equivalent/0x0014b340.cpp
// sym: ?FUN_0014b340@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_0014b340 @ 0x0014b340
void FUN_0014b340()
{
    if (DAT_004e0fc0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b340<hulkfight::motion::GrappleAttachJointCondition_14b340>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_14b340<hulkfight::motion::GrappleAttachJointCondition_14b340>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), &hulkfight::motion::GrappleAttachJointCondition_14b340::FUN_00146900);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_14b340<hulkfight::motion::GrappleAttachJointCondition_14b340>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamNameConstList_14b340<hulkfight::motion::GrappleAttachJointCondition_14b340>("joint", &hulkfight::motion::GrappleAttachJointCondition_14b340::FUN_00146910);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fbc), params, 2);
    }
    DAT_004e0fc0++;
}


// 0x0014b5d0 FUN_0014b5d0 (911 B): equivalent/0x0014b5d0.cpp
// sym: ?FUN_0014b5d0@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_0014b5d0 @ 0x0014b5d0
void FUN_0014b5d0()
{
    if (DAT_004e1010 == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("timeBegin", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e30);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("hitLocation", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e50);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("directionFrom", ((const char**)&DAT_004ae340), 2, &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("direction", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146e90);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("flag", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146eb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("damage", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146ed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("damageMax", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146ef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("interruptPriority", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f10);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("interrupt", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("hitReactionTime", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f50);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamEnumConstList_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackDirectionFrom", ((const char**)&DAT_004ae340), 2, &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackDirection", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146f90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackDistance", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146fc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("pushbackTime", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00146fe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("height", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00147000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_14b5d0<hulkfight::motion::GrappleHitReactionTrack_14b5d0>("stunTime", &hulkfight::motion::GrappleHitReactionTrack_14b5d0::FUN_00147020);
        FUN_002347b0(((ParamRegistry*)&DAT_004e100c), params, 16);
    }
    DAT_004e1010++;
}


// 0x0014b9c0 FUN_0014b9c0 (409 B): equivalent/0x0014b9c0.cpp
// sym: ?FUN_0014b9c0@fn_f3a660e0@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 16/16)
// FUN_0014b9c0 @ 0x0014b9c0
void FUN_0014b9c0()
{
    if ((*(int*)&DAT_004e1020) == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>("timeBegin", &hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_00147090);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>("timeEnd", &hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_001470b0);
        mem = FUN_0008d690((int)sizeof(ParamName<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<hulkfight::motion::CivilianAnimationTrack_14b9c0>("animation", &hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_001470c0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>("speed", &hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_001470e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>("startFrame", &hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_00147100);
        mem = FUN_0008d690((int)sizeof(ParamBool<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<hulkfight::motion::CivilianAnimationTrack_14b9c0>("cyclic", &hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_00147120);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack_14b9c0>("blendTime", &hulkfight::motion::CivilianAnimationTrack_14b9c0::FUN_00147140);
        FUN_002347b0(((ParamRegistry*)&DAT_004e101c), params, 7);
    }
    (*(int*)&DAT_004e1020)++;
}

} // namespace fn_f3a660e0

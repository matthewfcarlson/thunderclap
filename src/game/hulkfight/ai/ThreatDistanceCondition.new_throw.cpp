// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012b190..0x0012d920 (kind game, layer game, confidence high), dominant class hulkfight::ai::ThreatDistanceCondition
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f04af2f4 {
#define TREE_TU_END }
namespace fn_f04af2f4 {} using namespace fn_f04af2f4;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f04af2f4 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f04af2f4
namespace hulkfight { namespace ai {
class ShotFailCountCondition_12c8c0 {
public:
    void FUN_0012b260();
    void FUN_0012b270();
};
} }
namespace fn_f04af2f4 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f04af2f4
namespace fight {
template <class T>
class ParamEnumConstList_12c8c0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_12c8c0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamFloatConstRange_12c8c0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_12c8c0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f04af2f4 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f04af2f4
namespace hulkfight { namespace ai {
class ThreatBallTrack_12d140 {
public:
    void FUN_0012b280();
    void FUN_0012b290();
    void FUN_0012b2b0();
    void FUN_0012b2c0();
    void FUN_0012b2f0();
    void FUN_0012b320();
    void FUN_0012b330();
};
} }
namespace fn_f04af2f4 {
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
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class ThreatDodgeTrack {
public:
    void FUN_0012b340();
    void FUN_0012b350();
    void FUN_0012b370();
    void FUN_0012b390();
    void FUN_0012b3a0();
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};


// 0x0012c8c0 FUN_0012c8c0 (176 B): equivalent/0x0012c8c0.cpp
// sym: ?FUN_0012c8c0@fn_f04af2f4@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_0012c8c0 @ 0x0012c8c0
void FUN_0012c8c0()
{
    if (DAT_004e0e30 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_12c8c0<hulkfight::ai::ShotFailCountCondition_12c8c0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_12c8c0<hulkfight::ai::ShotFailCountCondition_12c8c0>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::ShotFailCountCondition_12c8c0::FUN_0012b260);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_12c8c0<hulkfight::ai::ShotFailCountCondition_12c8c0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_12c8c0<hulkfight::ai::ShotFailCountCondition_12c8c0>("count", &hulkfight::ai::ShotFailCountCondition_12c8c0::FUN_0012b270);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e2c), params, 2);
    }
    DAT_004e0e30++;
}


// 0x0012d140 FUN_0012d140 (409 B): equivalent/0x0012d140.cpp
// sym: ?FUN_0012d140@fn_f04af2f4@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 16/16)
// FUN_0012d140 @ 0x0012d140
void FUN_0012d140()
{
    if (DAT_004e0e38 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::ai::ThreatBallTrack_12d140>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::ai::ThreatBallTrack_12d140>("timeBegin", &hulkfight::ai::ThreatBallTrack_12d140::FUN_0012b280);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::ai::ThreatBallTrack_12d140>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::ai::ThreatBallTrack_12d140>("timeEnd", &hulkfight::ai::ThreatBallTrack_12d140::FUN_0012b290);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<hulkfight::ai::ThreatBallTrack_12d140>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamIntConstRange<hulkfight::ai::ThreatBallTrack_12d140>("attachmentIndex", &hulkfight::ai::ThreatBallTrack_12d140::FUN_0012b2b0);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<hulkfight::ai::ThreatBallTrack_12d140>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamNameConstList<hulkfight::ai::ThreatBallTrack_12d140>("joint", &hulkfight::ai::ThreatBallTrack_12d140::FUN_0012b2c0);
        mem = FUN_0008d690((int)sizeof(ParamVector<hulkfight::ai::ThreatBallTrack_12d140>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<hulkfight::ai::ThreatBallTrack_12d140>("offset", &hulkfight::ai::ThreatBallTrack_12d140::FUN_0012b2f0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::ai::ThreatBallTrack_12d140>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<hulkfight::ai::ThreatBallTrack_12d140>("radius", &hulkfight::ai::ThreatBallTrack_12d140::FUN_0012b320);
        mem = FUN_0008d690((int)sizeof(ParamName<hulkfight::ai::ThreatBallTrack_12d140>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamName<hulkfight::ai::ThreatBallTrack_12d140>("threatName", &hulkfight::ai::ThreatBallTrack_12d140::FUN_0012b330);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e34), params, 7);
    }
    DAT_004e0e38++;
}


// 0x0012d310 FUN_0012d310 (307 B): equivalent/0x0012d310.cpp
// sym: ?FUN_0012d310@fn_f04af2f4@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 12/12)
// FUN_0012d310 @ 0x0012d310
void FUN_0012d310()
{
    if (DAT_004e0e40 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ThreatDodgeTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<ThreatDodgeTrack>("timeBegin", &ThreatDodgeTrack::FUN_0012b340);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ThreatDodgeTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<ThreatDodgeTrack>("timeEnd", &ThreatDodgeTrack::FUN_0012b350);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ThreatDodgeTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<ThreatDodgeTrack>("speed", &ThreatDodgeTrack::FUN_0012b370);
        mem = FUN_0008d690((int)sizeof(ParamBool<ThreatDodgeTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<ThreatDodgeTrack>("threatRespondOnlyOnce", &ThreatDodgeTrack::FUN_0012b390);
        mem = FUN_0008d690((int)sizeof(ParamName<ThreatDodgeTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamName<ThreatDodgeTrack>("threatName", &ThreatDodgeTrack::FUN_0012b3a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e3c), params, 5);
    }
    DAT_004e0e40++;
}

} // namespace fn_f04af2f4

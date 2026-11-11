// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
#include "tree_prelude.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fccc5d95 {
#define TREE_TU_END }
namespace fn_fccc5d95 {} using namespace fn_fccc5d95;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fccc5d95 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_fccc5d95
namespace hulkfight {
class StatBeginTrialTrack_131850 {
public:
    void FUN_0012e0a0();
    void FUN_0012e8d0();
};
}
namespace fn_fccc5d95 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_fccc5d95
namespace fight {
template <class T>
class ParamFloatConstRange_131850 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_131850(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamString_131850 : public ParamStringBase {
public:
    ParamString_131850(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fccc5d95 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_fccc5d95
namespace hulkfight {
class DialogueTrack_1319f0 {
public:
    void FUN_0012e100();
    void FUN_0012ebc0();
    void FUN_0012ec20();
    void FUN_0012e130();
    void FUN_0012ec80();
    void FUN_0012ece0();
    void FUN_0012e170();
};
}
namespace fn_fccc5d95 {
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
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
} // namespace fn_fccc5d95
namespace hulkfight {
class StatEndTrialTrack_131c90 {
public:
    void FUN_0012e1c0();
    void FUN_0012ef40();
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_131c90 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_131c90(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamString_131c90 : public ParamStringBase {
public:
    ParamString_131c90(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight {
class StatTrack_131d30 {
public:
    void FUN_0012e1e0();
    void FUN_0012f030();
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_131d30 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_131d30(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamString_131d30 : public ParamStringBase {
public:
    ParamString_131d30(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight {
class XPTrack_131dd0 {
public:
    void FUN_0012e200();
    void FUN_0012e220();
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_131dd0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_131dd0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}


// 0x00131560 FUN_00131560 (158 B): equivalent/0x00131560.cpp [wrapped: conflict: fight::ParamString]
// sym: ?FUN_00131560@fn_00131560@@YAXXZ @a7127770efab @w23dbe306ac24
namespace fn_00131560 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00131560 @ 0x00131560


extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
class DebugPrintCondition {
public:
    void FUN_0012e5c0();
    void FUN_0012e620();
};
}

class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C++" __declspec(nothrow) void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00131560()
{
    if (DAT_004e0e68 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::DebugPrintCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString<hulkfight::DebugPrintCondition>("text", &hulkfight::DebugPrintCondition::FUN_0012e5c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString<hulkfight::DebugPrintCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString<hulkfight::DebugPrintCondition>("channel", &hulkfight::DebugPrintCondition::FUN_0012e620);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e64), params, 2);
    }
    DAT_004e0e68++;
}
} // namespace fn_00131560

namespace fn_fccc5d95 {

// 0x00131850 FUN_00131850 (158 B): equivalent/0x00131850.cpp
// sym: ?FUN_00131850@fn_fccc5d95@@YAXXZ @f116d437ab95 @wf294cb4cf34c
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00131850 @ 0x00131850
void FUN_00131850()
{
    if (DAT_004e0e80 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_131850<hulkfight::StatBeginTrialTrack_131850>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_131850<hulkfight::StatBeginTrialTrack_131850>("timeBegin", &hulkfight::StatBeginTrialTrack_131850::FUN_0012e0a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_131850<hulkfight::StatBeginTrialTrack_131850>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString_131850<hulkfight::StatBeginTrialTrack_131850>("stat", &hulkfight::StatBeginTrialTrack_131850::FUN_0012e8d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e7c), params, 2);
    }
    DAT_004e0e80++;
}


// 0x001319f0 FUN_001319f0 (409 B): equivalent/0x001319f0.cpp
// sym: ?FUN_001319f0@fn_fccc5d95@@YAXXZ @fd0d32b3b8df @wac316aaaefad
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 16/16)
// FUN_001319f0 @ 0x001319f0
void FUN_001319f0()
{
    if (DAT_004e0e90 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<hulkfight::DialogueTrack_1319f0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::DialogueTrack_1319f0>("timeBegin", &hulkfight::DialogueTrack_1319f0::FUN_0012e100);
        mem = FUN_0008d690((int)sizeof(ParamString<hulkfight::DialogueTrack_1319f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamString<hulkfight::DialogueTrack_1319f0>("dialogue", &hulkfight::DialogueTrack_1319f0::FUN_0012ebc0);
        mem = FUN_0008d690((int)sizeof(ParamString<hulkfight::DialogueTrack_1319f0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamString<hulkfight::DialogueTrack_1319f0>("desiredTemplate", &hulkfight::DialogueTrack_1319f0::FUN_0012ec20);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<hulkfight::DialogueTrack_1319f0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<hulkfight::DialogueTrack_1319f0>("priority", &hulkfight::DialogueTrack_1319f0::FUN_0012e130);
        mem = FUN_0008d690((int)sizeof(ParamString<hulkfight::DialogueTrack_1319f0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamString<hulkfight::DialogueTrack_1319f0>("duckMixer", &hulkfight::DialogueTrack_1319f0::FUN_0012ec80);
        mem = FUN_0008d690((int)sizeof(ParamString<hulkfight::DialogueTrack_1319f0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamString<hulkfight::DialogueTrack_1319f0>("instance", &hulkfight::DialogueTrack_1319f0::FUN_0012ece0);
        mem = FUN_0008d690((int)sizeof(ParamBool<hulkfight::DialogueTrack_1319f0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamBool<hulkfight::DialogueTrack_1319f0>("routeToHeld", &hulkfight::DialogueTrack_1319f0::FUN_0012e170);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e8c), params, 7);
    }
    DAT_004e0e90++;
}


// 0x00131c90 FUN_00131c90 (158 B): equivalent/0x00131c90.cpp
// sym: _FUN_00131c90 @cb16a66d54cd @w870b8295e5fd
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00131c90 @ 0x00131c90
extern "C" void FUN_00131c90()
{
    if (DAT_004e0ea0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_131c90<hulkfight::StatEndTrialTrack_131c90>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_131c90<hulkfight::StatEndTrialTrack_131c90>("timeBegin", &hulkfight::StatEndTrialTrack_131c90::FUN_0012e1c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_131c90<hulkfight::StatEndTrialTrack_131c90>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString_131c90<hulkfight::StatEndTrialTrack_131c90>("stat", &hulkfight::StatEndTrialTrack_131c90::FUN_0012ef40);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e9c), params, 2);
    }
    DAT_004e0ea0++;
}


// 0x00131d30 FUN_00131d30 (158 B): equivalent/0x00131d30.cpp
// sym: _FUN_00131d30 @97e49054967d @wf4af16387740
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00131d30 @ 0x00131d30
extern "C" void FUN_00131d30()
{
    if (DAT_004e0ea8 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_131d30<hulkfight::StatTrack_131d30>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_131d30<hulkfight::StatTrack_131d30>("timeBegin", &hulkfight::StatTrack_131d30::FUN_0012e1e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_131d30<hulkfight::StatTrack_131d30>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString_131d30<hulkfight::StatTrack_131d30>("stat", &hulkfight::StatTrack_131d30::FUN_0012f030);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ea4), params, 2);
    }
    DAT_004e0ea8++;
}


// 0x00131dd0 FUN_00131dd0 (158 B): equivalent/0x00131dd0.cpp
// sym: _FUN_00131dd0 @3f3ac862551c @w5a8548fd0fdd
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00131dd0 @ 0x00131dd0
extern "C" void FUN_00131dd0()
{
    if (DAT_004e0eb0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_131dd0<hulkfight::XPTrack_131dd0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_131dd0<hulkfight::XPTrack_131dd0>("timeBegin", &hulkfight::XPTrack_131dd0::FUN_0012e200);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_131dd0<hulkfight::XPTrack_131dd0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_131dd0<hulkfight::XPTrack_131dd0>("value", &hulkfight::XPTrack_131dd0::FUN_0012e220);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0eac), params, 2);
    }
    DAT_004e0eb0++;
}

} // namespace fn_fccc5d95

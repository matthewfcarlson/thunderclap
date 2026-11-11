// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001aace0..0x001acb90 (kind game, layer game, confidence high), dominant class hulkfight::scenario::Event_PathNameCondition
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/scenario.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fdc66084 {
#define TREE_TU_END }
namespace fn_fdc66084 {} using namespace fn_fdc66084;
#include "game/hulkfight/scenario.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fdc66084 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_fdc66084
namespace hulkfight { namespace scenario {
class Event_FirstTimeCondition_1abef0 {
public:
    void FUN_001aad00();
};
} }
namespace fn_fdc66084 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_fdc66084
namespace fight {
template <class T>
class ParamBool_1abef0 : public ParamBoolBase {
public:
    ParamBool_1abef0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fdc66084 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_fdc66084
namespace hulkfight { namespace scenario {
class Event_TriggerVolumeNameCondition_1ac250 {
public:
    void FUN_001aace0();
};
} }
namespace fn_fdc66084 {
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_fdc66084
namespace fight {
template <class T>
class ParamName_1ac250 : public ParamNameBase {
public:
    ParamName_1ac250(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace scenario {
class Event_PathNameCondition_1ac5b0 {
public:
    void FUN_001aada0();
    void FUN_001aadb0();
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_1ac5b0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1ac5b0(const char* name, const char** n, int c, void (T::*s)())
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
class ParamName_1ac5b0 : public ParamNameBase {
public:
    ParamName_1ac5b0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_fdc66084 {

// 0x001abef0 FUN_001abef0 (95 B): equivalent/0x001abef0.cpp
// sym: ?FUN_001abef0@fn_fdc66084@@YAXXZ @40bc0b1307a6 @wb53baec426d9
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_001abef0 @ 0x001abef0
void FUN_001abef0()
{
    if (DAT_004e1794 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1abef0<hulkfight::scenario::Event_FirstTimeCondition_1abef0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_1abef0<hulkfight::scenario::Event_FirstTimeCondition_1abef0>("firstTime", &hulkfight::scenario::Event_FirstTimeCondition_1abef0::FUN_001aad00);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1790), params, 1);
    }
    DAT_004e1794++;
}

} // namespace fn_fdc66084

// 0x001abf50 FUN_001abf50 (176 B): equivalent/0x001abf50.cpp [wrapped: conflict: fight::ParamEnumConstList; fight::ParamIntConstRange]
// sym: ?FUN_001abf50@fn_001abf50@@YAXXZ @aeb1e97c1ef0 @wd08d68253d15
namespace fn_001abf50 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_001abf50 @ 0x001abf50


extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace scenario {
class Event_WaypointCondition {
public:
    void FUN_001aad10();
    void FUN_001aad20();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



extern "C++" __declspec(nothrow) void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001abf50()
{
    if (DAT_004e179c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::scenario::Event_WaypointCondition>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::scenario::Event_WaypointCondition::FUN_001aad10);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange<hulkfight::scenario::Event_WaypointCondition>("waypoint", &hulkfight::scenario::Event_WaypointCondition::FUN_001aad20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1798), params, 2);
    }
    DAT_004e179c++;
}
} // namespace fn_001abf50

namespace fn_fdc66084 {

// 0x001ac250 FUN_001ac250 (95 B): equivalent/0x001ac250.cpp
// sym: ?FUN_001ac250@fn_fdc66084@@YAXXZ @2218499c49b3 @w75c90cd98023
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_001ac250 @ 0x001ac250
void FUN_001ac250()
{
    if (DAT_004e1784 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1ac250<hulkfight::scenario::Event_TriggerVolumeNameCondition_1ac250>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName_1ac250<hulkfight::scenario::Event_TriggerVolumeNameCondition_1ac250>("triggerVolumeName", &hulkfight::scenario::Event_TriggerVolumeNameCondition_1ac250::FUN_001aace0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1780), params, 1);
    }
    DAT_004e1784++;
}


// 0x001ac5b0 FUN_001ac5b0 (176 B): equivalent/0x001ac5b0.cpp
// sym: ?FUN_001ac5b0@fn_fdc66084@@YAXXZ @eaf83a706890 @w4e4090224b83
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001ac5b0 @ 0x001ac5b0
void FUN_001ac5b0()
{
    if ((*(int*)&DAT_004e17b4) == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1ac5b0<hulkfight::scenario::Event_PathNameCondition_1ac5b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_1ac5b0<hulkfight::scenario::Event_PathNameCondition_1ac5b0>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), &hulkfight::scenario::Event_PathNameCondition_1ac5b0::FUN_001aada0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1ac5b0<hulkfight::scenario::Event_PathNameCondition_1ac5b0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName_1ac5b0<hulkfight::scenario::Event_PathNameCondition_1ac5b0>("pathName", &hulkfight::scenario::Event_PathNameCondition_1ac5b0::FUN_001aadb0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e17b0), params, 2);
    }
    (*(int*)&DAT_004e17b4)++;
}

} // namespace fn_fdc66084

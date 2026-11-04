// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 26/26)
// FUN_00120a90 @ 0x00120a90
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class PathLocatorTestCondition_120a90 {
public:
    void FUN_0011c290();
    void FUN_0011b810();
    void FUN_0011b830();
    void FUN_0011b850();
    void FUN_0011b870();
    void FUN_0011b890();
    void FUN_0011b8b0();
    void FUN_0011b8d0();
    void FUN_0011b8f0();
    void FUN_0011b910();
    void FUN_0011b930();
    void FUN_0011b960();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamBool_120a90 : public ParamBoolBase {
public:
    ParamBool_120a90(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_120a90 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_120a90(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_120a90 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_120a90(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamString_120a90 : public ParamStringBase {
public:
    ParamString_120a90(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_120a90 : public ParamVectorBase {
public:
    ParamVector_120a90(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00120a90()
{
    if (DAT_004e0cac == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamString_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("locatorType", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011c290);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b810);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("distance", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b830);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("distanceTest", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b850);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("min", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b870);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("max", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b890);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("defendLocator", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b8b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("myLocator", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b8d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("namedLocator", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b8f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("testLocatorExists", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b910);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("defaulttoVicinityCheck", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b930);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamVector_120a90<hulkfight::ai::PathLocatorTestCondition_120a90>("vicinityLimits", &hulkfight::ai::PathLocatorTestCondition_120a90::FUN_0011b960);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ca8), params, 12);
    }
    DAT_004e0cac++;
}

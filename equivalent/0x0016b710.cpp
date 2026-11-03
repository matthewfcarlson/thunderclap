// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_0016b710 @ 0x0016b710
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class TargetHealthPercentCondition_16b710 {
public:
    void FUN_001656e0();
    void FUN_00165700();
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
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList_16b710 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_16b710(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_16b710 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16b710(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0016b710()
{
    if (DAT_004e1254 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_16b710<hulkfight::motion::TargetHealthPercentCondition_16b710>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), &hulkfight::motion::TargetHealthPercentCondition_16b710::FUN_001656e0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16b710<hulkfight::motion::TargetHealthPercentCondition_16b710>("percent", &hulkfight::motion::TargetHealthPercentCondition_16b710::FUN_00165700);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1250), params, 2);
    }
    DAT_004e1254++;
}

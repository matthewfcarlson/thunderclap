// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_001a96e0 @ 0x001a96e0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/scenario.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace scenario {
class Event_PropStateNameCondition {
public:
    void FUN_001a1f60();
};
}
}

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001a96e0()
{
    if (DAT_004e1744 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName<hulkfight::scenario::Event_PropStateNameCondition>("stateName", &hulkfight::scenario::Event_PropStateNameCondition::FUN_001a1f60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1740), params, 1);
    }
    DAT_004e1744++;
}

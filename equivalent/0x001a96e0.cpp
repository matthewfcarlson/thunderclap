// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_001a96e0 @ 0x001a96e0
#include "decls/data/game/hulkfight/scenario.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace scenario {
class Event_PropStateNameCondition_1a96e0 {
public:
    void FUN_001a1f60();
};
}
}

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamName_1a96e0 : public ParamNameBase {
public:
    ParamName_1a96e0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001a96e0()
{
    if (DAT_004e1744 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1a96e0<hulkfight::scenario::Event_PropStateNameCondition_1a96e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName_1a96e0<hulkfight::scenario::Event_PropStateNameCondition_1a96e0>("stateName", &hulkfight::scenario::Event_PropStateNameCondition_1a96e0::FUN_001a1f60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1740), params, 1);
    }
    DAT_004e1744++;
}

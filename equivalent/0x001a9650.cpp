// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_001a9650 @ 0x001a9650
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/scenario.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace scenario {
class Event_PropTypeCondition {
public:
    void FUN_001a1f50();
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

void FUN_001a9650()
{
    if (DAT_004e173c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName<hulkfight::scenario::Event_PropTypeCondition>("propType", &hulkfight::scenario::Event_PropTypeCondition::FUN_001a1f50);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1738), params, 1);
    }
    DAT_004e173c++;
}

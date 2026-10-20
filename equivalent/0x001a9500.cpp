// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001a9500 @ 0x001a9500
#include "decls/data/game/hulkfight/scenario.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace scenario {
class Event_StringCondition {
public:
    void FUN_001a1ee0();
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

void FUN_001a9500()
{
    if (DAT_004e1714 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName<hulkfight::scenario::Event_StringCondition>("string", &hulkfight::scenario::Event_StringCondition::FUN_001a1ee0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1710), params, 1);
    }
    DAT_004e1714++;
}

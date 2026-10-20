// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_001ac250 @ 0x001ac250
#include "decls/data/game/hulkfight/scenario.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace scenario {
class Event_TriggerVolumeNameCondition {
public:
    void FUN_001aace0();
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

void FUN_001ac250()
{
    if (DAT_004e1784 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName<hulkfight::scenario::Event_TriggerVolumeNameCondition>("triggerVolumeName", &hulkfight::scenario::Event_TriggerVolumeNameCondition::FUN_001aace0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1780), params, 1);
    }
    DAT_004e1784++;
}

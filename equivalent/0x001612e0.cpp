// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001612e0 @ 0x001612e0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PhaseCondition_1612e0 {
public:
    void FUN_0015a870();
    void FUN_0015a890();
};
}
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_1612e0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1612e0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_001612e0()
{
    if (DAT_004e116c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1612e0<hulkfight::motion::PhaseCondition_1612e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1612e0<hulkfight::motion::PhaseCondition_1612e0>("phase", &hulkfight::motion::PhaseCondition_1612e0::FUN_0015a870);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1612e0<hulkfight::motion::PhaseCondition_1612e0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1612e0<hulkfight::motion::PhaseCondition_1612e0>("arc", &hulkfight::motion::PhaseCondition_1612e0::FUN_0015a890);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1168), params, 2);
    }
    DAT_004e116c++;
}

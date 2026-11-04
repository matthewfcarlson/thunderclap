// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0016bb80 @ 0x0016bb80
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class VelocityAnimatedXZAngleCondition_16bb80 {
public:
    void FUN_00165900();
    void FUN_00165920();
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
class ParamFloatConstRange_16bb80 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_16bb80(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0016bb80()
{
    if (DAT_004e1294 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16bb80<hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_16bb80<hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80>("angle", &hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80::FUN_00165900);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16bb80<hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_16bb80<hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80>("arc", &hulkfight::motion::VelocityAnimatedXZAngleCondition_16bb80::FUN_00165920);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1290), params, 2);
    }
    DAT_004e1294++;
}

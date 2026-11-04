// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_00161280 @ 0x00161280
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class LocomotingCondition_161280 {
public:
    void FUN_0015a820();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_161280 : public ParamBoolBase {
public:
    ParamBool_161280(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00161280()
{
    if (DAT_004e115c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_161280<hulkfight::motion::LocomotingCondition_161280>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_161280<hulkfight::motion::LocomotingCondition_161280>("isLocomoting", &hulkfight::motion::LocomotingCondition_161280::FUN_0015a820);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1158), params, 1);
    }
    DAT_004e115c++;
}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0016b540 @ 0x0016b540
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class TargetingCondition_16b540 {
public:
    void FUN_00165690();
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
class ParamBool_16b540 : public ParamBoolBase {
public:
    ParamBool_16b540(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0016b540()
{
    if (DAT_004e123c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_16b540<hulkfight::motion::TargetingCondition_16b540>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_16b540<hulkfight::motion::TargetingCondition_16b540>("isTargeting", &hulkfight::motion::TargetingCondition_16b540::FUN_00165690);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1238), params, 1);
    }
    DAT_004e123c++;
}

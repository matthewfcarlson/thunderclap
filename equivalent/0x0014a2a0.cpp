// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_0014a2a0 @ 0x0014a2a0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class CivilianTargetCondition {
public:
    void FUN_00146940();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0014a2a0()
{
    if (DAT_004e0fd8 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool<hulkfight::motion::CivilianTargetCondition>("hasTarget", &hulkfight::motion::CivilianTargetCondition::FUN_00146940);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fd4), params, 1);
    }
    DAT_004e0fd8++;
}

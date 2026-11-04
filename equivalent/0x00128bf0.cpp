// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_00128bf0 @ 0x00128bf0
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class HasTargetCondition_128bf0 {
public:
    void FUN_001237e0();
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
class ParamBool_128bf0 : public ParamBoolBase {
public:
    ParamBool_128bf0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00128bf0()
{
    if (DAT_004e0db0 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_128bf0<hulkfight::ai::HasTargetCondition_128bf0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_128bf0<hulkfight::ai::HasTargetCondition_128bf0>("hasTarget", &hulkfight::ai::HasTargetCondition_128bf0::FUN_001237e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0dac), params, 1);
    }
    DAT_004e0db0++;
}

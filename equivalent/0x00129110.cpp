// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_00129110 @ 0x00129110
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class TargetFirstShotCondition_129110 {
public:
    void FUN_00123910();
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
class ParamBool_129110 : public ParamBoolBase {
public:
    ParamBool_129110(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00129110()
{
    if (DAT_004e0de8 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_129110<hulkfight::ai::TargetFirstShotCondition_129110>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_129110<hulkfight::ai::TargetFirstShotCondition_129110>("firstShot", &hulkfight::ai::TargetFirstShotCondition_129110::FUN_00123910);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0de4), params, 1);
    }
    DAT_004e0de8++;
}

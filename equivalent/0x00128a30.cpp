// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00128a30 @ 0x00128a30
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class TargetOrientationCondition_128a30 {
public:
    void FUN_00123740();
    void FUN_00123760();
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
class ParamFloatConstRange_128a30 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_128a30(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00128a30()
{
    if (DAT_004e0da0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_128a30<hulkfight::ai::TargetOrientationCondition_128a30>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_128a30<hulkfight::ai::TargetOrientationCondition_128a30>("orientation", &hulkfight::ai::TargetOrientationCondition_128a30::FUN_00123740);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_128a30<hulkfight::ai::TargetOrientationCondition_128a30>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_128a30<hulkfight::ai::TargetOrientationCondition_128a30>("arc", &hulkfight::ai::TargetOrientationCondition_128a30::FUN_00123760);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0d9c), params, 2);
    }
    DAT_004e0da0++;
}

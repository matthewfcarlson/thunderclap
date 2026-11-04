// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// FUN_0017a420 @ 0x0017a420
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class TargetBreakTrack_17a420 {
public:
    void FUN_0016f240();
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
class ParamFloatConstRange_17a420 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17a420(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0017a420()
{
    if (DAT_004e1354 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17a420<hulkfight::motion::TargetBreakTrack_17a420>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17a420<hulkfight::motion::TargetBreakTrack_17a420>("timeBegin", &hulkfight::motion::TargetBreakTrack_17a420::FUN_0016f240);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1350), params, 1);
    }
    DAT_004e1354++;
}

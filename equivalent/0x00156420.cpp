// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_00156420 @ 0x00156420
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class ClearFightParamsHitRecordTrack_156420 {
public:
    void FUN_0014cea0();
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
class ParamFloatConstRange_156420 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_156420(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00156420()
{
    if (DAT_004e111c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156420<hulkfight::motion::ClearFightParamsHitRecordTrack_156420>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_156420<hulkfight::motion::ClearFightParamsHitRecordTrack_156420>("timeBegin", &hulkfight::motion::ClearFightParamsHitRecordTrack_156420::FUN_0014cea0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1118), params, 1);
    }
    DAT_004e111c++;
}

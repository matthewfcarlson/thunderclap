// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_00155c30 @ 0x00155c30
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class InterruptAccumulatorSetTrack_155c30 {
public:
    void FUN_0014c760();
    void FUN_0014c780();
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
class ParamFloatConstRange_155c30 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_155c30(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00155c30()
{
    if (DAT_004e10d4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_155c30<hulkfight::motion::InterruptAccumulatorSetTrack_155c30>("timeBegin", &hulkfight::motion::InterruptAccumulatorSetTrack_155c30::FUN_0014c760);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_155c30<hulkfight::motion::InterruptAccumulatorSetTrack_155c30>("value", &hulkfight::motion::InterruptAccumulatorSetTrack_155c30::FUN_0014c780);
        FUN_002347b0(((ParamRegistry*)&DAT_004e10d0), params, 2);
    }
    DAT_004e10d4++;
}

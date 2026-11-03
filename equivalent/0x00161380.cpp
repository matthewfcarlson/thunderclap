// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00161380 @ 0x00161380
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class LocomotingTrack_161380 {
public:
    void FUN_0015a8a0();
    void FUN_0015a8b0();
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
class ParamFloatConstRange_161380 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_161380(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00161380()
{
    if (DAT_004e1174 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_161380<hulkfight::motion::LocomotingTrack_161380>("timeBegin", &hulkfight::motion::LocomotingTrack_161380::FUN_0015a8a0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_161380<hulkfight::motion::LocomotingTrack_161380>("timeEnd", &hulkfight::motion::LocomotingTrack_161380::FUN_0015a8b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1170), params, 2);
    }
    DAT_004e1174++;
}

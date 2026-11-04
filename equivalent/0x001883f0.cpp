// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001883f0 @ 0x001883f0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class ShieldArcTrack_1883f0 {
public:
    void FUN_00180300();
    void FUN_00180320();
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
class ParamFloatConstRange_1883f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1883f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_001883f0()
{
    if (DAT_004e14c4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1883f0<hulkfight::motion::ShieldArcTrack_1883f0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1883f0<hulkfight::motion::ShieldArcTrack_1883f0>("timeBegin", &hulkfight::motion::ShieldArcTrack_1883f0::FUN_00180300);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1883f0<hulkfight::motion::ShieldArcTrack_1883f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1883f0<hulkfight::motion::ShieldArcTrack_1883f0>("arc", &hulkfight::motion::ShieldArcTrack_1883f0::FUN_00180320);
        FUN_002347b0(((ParamRegistry*)&DAT_004e14c0), params, 2);
    }
    DAT_004e14c4++;
}

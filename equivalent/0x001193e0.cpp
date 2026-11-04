// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001193e0 @ 0x001193e0
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class MotionStopTrack_1193e0 {
public:
    void FUN_00115110();
    void FUN_00115120();
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
class ParamFloatConstRange_1193e0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1193e0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001193e0()
{
    if (DAT_004e0c50 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1193e0<hulkfight::ai::MotionStopTrack_1193e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1193e0<hulkfight::ai::MotionStopTrack_1193e0>("timeBegin", &hulkfight::ai::MotionStopTrack_1193e0::FUN_00115110);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1193e0<hulkfight::ai::MotionStopTrack_1193e0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1193e0<hulkfight::ai::MotionStopTrack_1193e0>("timeEnd", &hulkfight::ai::MotionStopTrack_1193e0::FUN_00115120);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c4c), params, 2);
    }
    DAT_004e0c50++;
}

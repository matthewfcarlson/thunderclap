// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00156480 @ 0x00156480
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class HitPushbackAddTrack_156480 {
public:
    void FUN_0014ceb0();
    void FUN_0014ced0();
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
class ParamFloatConstRange_156480 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_156480(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00156480()
{
    if (DAT_004e1124 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156480<hulkfight::motion::HitPushbackAddTrack_156480>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_156480<hulkfight::motion::HitPushbackAddTrack_156480>("timeBegin", &hulkfight::motion::HitPushbackAddTrack_156480::FUN_0014ceb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156480<hulkfight::motion::HitPushbackAddTrack_156480>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_156480<hulkfight::motion::HitPushbackAddTrack_156480>("weight", &hulkfight::motion::HitPushbackAddTrack_156480::FUN_0014ced0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1120), params, 2);
    }
    DAT_004e1124++;
}

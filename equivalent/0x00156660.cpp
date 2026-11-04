// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00156660 @ 0x00156660
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class HitDamageTrack_156660 {
public:
    void FUN_0014cf70();
    void FUN_0014cf90();
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
class ParamFloatConstRange_156660 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_156660(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00156660()
{
    if (DAT_004e1134 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156660<hulkfight::motion::HitDamageTrack_156660>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_156660<hulkfight::motion::HitDamageTrack_156660>("timeBegin", &hulkfight::motion::HitDamageTrack_156660::FUN_0014cf70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156660<hulkfight::motion::HitDamageTrack_156660>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_156660<hulkfight::motion::HitDamageTrack_156660>("weight", &hulkfight::motion::HitDamageTrack_156660::FUN_0014cf90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1130), params, 2);
    }
    DAT_004e1134++;
}

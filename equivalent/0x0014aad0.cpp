// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_0014aad0 @ 0x0014aad0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class CivilianAttachTrack_14aad0 {
public:
    void FUN_00146e20();
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
class ParamFloatConstRange_14aad0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_14aad0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0014aad0()
{
    if (DAT_004e1008 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_14aad0<hulkfight::motion::CivilianAttachTrack_14aad0>("timeBegin", &hulkfight::motion::CivilianAttachTrack_14aad0::FUN_00146e20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1004), params, 1);
    }
    DAT_004e1008++;
}

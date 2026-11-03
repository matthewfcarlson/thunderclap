// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00131dd0 @ 0x00131dd0
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
class XPTrack_131dd0 {
public:
    void FUN_0012e200();
    void FUN_0012e220();
};
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_131dd0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_131dd0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00131dd0()
{
    if (DAT_004e0eb0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_131dd0<hulkfight::XPTrack_131dd0>("timeBegin", &hulkfight::XPTrack_131dd0::FUN_0012e200);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_131dd0<hulkfight::XPTrack_131dd0>("value", &hulkfight::XPTrack_131dd0::FUN_0012e220);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0eac), params, 2);
    }
    DAT_004e0eb0++;
}

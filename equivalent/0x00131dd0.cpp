// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00131dd0 @ 0x00131dd0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
class XPTrack {
public:
    void FUN_0012e200();
    void FUN_0012e220();
};
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00131dd0()
{
    if (DAT_004e0eb0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::XPTrack>("timeBegin", &hulkfight::XPTrack::FUN_0012e200);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::XPTrack>("value", &hulkfight::XPTrack::FUN_0012e220);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0eac), params, 2);
    }
    DAT_004e0eb0++;
}

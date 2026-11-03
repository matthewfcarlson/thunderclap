// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00070620 @ 0x00070620
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CClimbingTrack_70620 {
public:
    void FUN_00067fc0();
    void FUN_00067fd0();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_70620 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_70620(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00070620()
{
    if (DAT_004dcf1c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_70620<::CClimbingTrack_70620>("timeBegin", &::CClimbingTrack_70620::FUN_00067fc0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_70620<::CClimbingTrack_70620>("timeEnd", &::CClimbingTrack_70620::FUN_00067fd0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf18), params, 2);
    }
    DAT_004dcf1c++;
}

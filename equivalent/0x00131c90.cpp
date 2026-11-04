// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_00131c90 @ 0x00131c90
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
class StatEndTrialTrack_131c90 {
public:
    void FUN_0012e1c0();
    void FUN_0012ef40();
};
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_131c90 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_131c90(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamString_131c90 : public ParamStringBase {
public:
    ParamString_131c90(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00131c90()
{
    if (DAT_004e0ea0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_131c90<hulkfight::StatEndTrialTrack_131c90>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_131c90<hulkfight::StatEndTrialTrack_131c90>("timeBegin", &hulkfight::StatEndTrialTrack_131c90::FUN_0012e1c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_131c90<hulkfight::StatEndTrialTrack_131c90>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString_131c90<hulkfight::StatEndTrialTrack_131c90>("stat", &hulkfight::StatEndTrialTrack_131c90::FUN_0012ef40);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0e9c), params, 2);
    }
    DAT_004e0ea0++;
}

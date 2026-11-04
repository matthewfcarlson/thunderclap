// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 24/24)
// FUN_000783a0 @ 0x000783a0
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class CHeliDeathSpiralTrack_783a0 {
public:
    void FUN_00077df0();
    void FUN_00077e00();
    void FUN_00077e10();
    void FUN_00077e20();
    void FUN_00077e40();
    void FUN_00077e60();
    void FUN_00077e70();
    void FUN_00077e80();
    void FUN_00077ea0();
    void FUN_00077eb0();
    void FUN_00077ec0();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_783a0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_783a0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamIntConstRange_783a0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_783a0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_000783a0()
{
    if (DAT_004dd034 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("timeBegin", &CHeliDeathSpiralTrack_783a0::FUN_00077df0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("timeEnd", &CHeliDeathSpiralTrack_783a0::FUN_00077e00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("weightRatio", &CHeliDeathSpiralTrack_783a0::FUN_00077e10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("minTurningVelocity", &CHeliDeathSpiralTrack_783a0::FUN_00077e20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("maxTurningVelocity", &CHeliDeathSpiralTrack_783a0::FUN_00077e40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("acceleration", &CHeliDeathSpiralTrack_783a0::FUN_00077e60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("gravity", &CHeliDeathSpiralTrack_783a0::FUN_00077e70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("tilt", &CHeliDeathSpiralTrack_783a0::FUN_00077e80);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_783a0<CHeliDeathSpiralTrack_783a0>("priority", &CHeliDeathSpiralTrack_783a0::FUN_00077ea0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("blendInTime", &CHeliDeathSpiralTrack_783a0::FUN_00077eb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("blendOutTime", &CHeliDeathSpiralTrack_783a0::FUN_00077ec0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dd030), params, 11);
    }
    DAT_004dd034++;
}

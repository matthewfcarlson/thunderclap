// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 24/24)
// FUN_000783a0 @ 0x000783a0
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CHeliDeathSpiralTrack {
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

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_000783a0()
{
    if (DAT_004dd034 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<CHeliDeathSpiralTrack>("timeBegin", &CHeliDeathSpiralTrack::FUN_00077df0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<CHeliDeathSpiralTrack>("timeEnd", &CHeliDeathSpiralTrack::FUN_00077e00);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<CHeliDeathSpiralTrack>("weightRatio", &CHeliDeathSpiralTrack::FUN_00077e10);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<CHeliDeathSpiralTrack>("minTurningVelocity", &CHeliDeathSpiralTrack::FUN_00077e20);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<CHeliDeathSpiralTrack>("maxTurningVelocity", &CHeliDeathSpiralTrack::FUN_00077e40);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<CHeliDeathSpiralTrack>("acceleration", &CHeliDeathSpiralTrack::FUN_00077e60);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<CHeliDeathSpiralTrack>("gravity", &CHeliDeathSpiralTrack::FUN_00077e70);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<CHeliDeathSpiralTrack>("tilt", &CHeliDeathSpiralTrack::FUN_00077e80);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange<CHeliDeathSpiralTrack>("priority", &CHeliDeathSpiralTrack::FUN_00077ea0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<CHeliDeathSpiralTrack>("blendInTime", &CHeliDeathSpiralTrack::FUN_00077eb0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<CHeliDeathSpiralTrack>("blendOutTime", &CHeliDeathSpiralTrack::FUN_00077ec0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dd030), params, 11);
    }
    DAT_004dd034++;
}

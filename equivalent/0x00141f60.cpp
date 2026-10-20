// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 24/24)
// FUN_00141f60 @ 0x00141f60
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class WallExitTrack {
public:
    void FUN_0013ecb0();
    void FUN_0013ecc0();
    void FUN_0013ece0();
    void FUN_0013ed00();
    void FUN_0013ed20();
    void FUN_0013ed40();
    void FUN_0013ed70();
    void FUN_0013eda0();
    void FUN_0013edd0();
    void FUN_0013edf0();
    void FUN_0013ee10();
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

void FUN_00141f60()
{
    if (DAT_004e0f5c == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<WallExitTrack>("timeBegin", &WallExitTrack::FUN_0013ecb0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<WallExitTrack>("timeEnd", &WallExitTrack::FUN_0013ecc0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<WallExitTrack>("velocityMin", &WallExitTrack::FUN_0013ece0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<WallExitTrack>("velocityMax", &WallExitTrack::FUN_0013ed00);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<WallExitTrack>("gravity", &WallExitTrack::FUN_0013ed20);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<WallExitTrack>("upAngleMin", &WallExitTrack::FUN_0013ed40);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<WallExitTrack>("upAngleMax", &WallExitTrack::FUN_0013ed70);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<WallExitTrack>("turningVelocity", &WallExitTrack::FUN_0013eda0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange<WallExitTrack>("priority", &WallExitTrack::FUN_0013edd0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<WallExitTrack>("blendInTime", &WallExitTrack::FUN_0013edf0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<WallExitTrack>("blendOutTime", &WallExitTrack::FUN_0013ee10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f58), params, 11);
    }
    DAT_004e0f5c++;
}

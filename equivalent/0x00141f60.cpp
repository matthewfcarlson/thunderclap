// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 24/24)
// FUN_00141f60 @ 0x00141f60
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

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
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_141f60 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_141f60(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_141f60 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_141f60(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00141f60()
{
    if (DAT_004e0f5c == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("timeBegin", &WallExitTrack::FUN_0013ecb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("timeEnd", &WallExitTrack::FUN_0013ecc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("velocityMin", &WallExitTrack::FUN_0013ece0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("velocityMax", &WallExitTrack::FUN_0013ed00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("gravity", &WallExitTrack::FUN_0013ed20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("upAngleMin", &WallExitTrack::FUN_0013ed40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("upAngleMax", &WallExitTrack::FUN_0013ed70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("turningVelocity", &WallExitTrack::FUN_0013eda0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_141f60<WallExitTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_141f60<WallExitTrack>("priority", &WallExitTrack::FUN_0013edd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("blendInTime", &WallExitTrack::FUN_0013edf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_141f60<WallExitTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_141f60<WallExitTrack>("blendOutTime", &WallExitTrack::FUN_0013ee10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f58), params, 11);
    }
    DAT_004e0f5c++;
}

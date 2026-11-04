// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 22/22)
// FUN_001386d0 @ 0x001386d0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class FlyingAutoTargetTrack {
public:
    void FUN_00133690();
    void FUN_001336a0();
    void FUN_001336c0();
    void FUN_00133700();
    void FUN_00133730();
    void FUN_00133750();
    void FUN_00133780();
    void FUN_001337a0();
    void FUN_001337c0();
    void FUN_001337e0();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_1386d0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1386d0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_1386d0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1386d0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamVector_1386d0 : public ParamVectorBase {
public:
    ParamVector_1386d0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001386d0()
{
    if (DAT_004e0efc == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>("timeBegin", &FlyingAutoTargetTrack::FUN_00133690);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>("timeEnd", &FlyingAutoTargetTrack::FUN_001336a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>("turningVelocity", &FlyingAutoTargetTrack::FUN_001336c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_1386d0<FlyingAutoTargetTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_1386d0<FlyingAutoTargetTrack>("offset", &FlyingAutoTargetTrack::FUN_00133700);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>("velocity", &FlyingAutoTargetTrack::FUN_00133730);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>("targetArc", &FlyingAutoTargetTrack::FUN_00133750);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>("targetDistance", &FlyingAutoTargetTrack::FUN_00133780);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_1386d0<FlyingAutoTargetTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_1386d0<FlyingAutoTargetTrack>("priority", &FlyingAutoTargetTrack::FUN_001337a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>("blendInTime", &FlyingAutoTargetTrack::FUN_001337c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_1386d0<FlyingAutoTargetTrack>("blendOutTime", &FlyingAutoTargetTrack::FUN_001337e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ef8), params, 10);
    }
    DAT_004e0efc++;
}

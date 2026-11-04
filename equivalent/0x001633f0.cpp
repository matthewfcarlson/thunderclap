// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_001633f0 @ 0x001633f0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class LocomotionSprintTrack_1633f0 {
public:
    void FUN_0015b4e0();
    void FUN_0015b4f0();
    void FUN_0015b510();
    void FUN_0015b530();
    void FUN_0015b560();
    void FUN_0015b590();
    void FUN_0015b5b0();
    void FUN_0015b5d0();
    void FUN_0015b5e0();
    void FUN_0015b5f0();
    void FUN_0015b600();
    void FUN_0015b610();
    void FUN_0015b620();
    void FUN_0015b640();
    void FUN_0015b660();
    void FUN_0015b680();
};
}
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_1633f0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1633f0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_1633f0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_1633f0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_1633f0 : public ParamNameBase {
public:
    ParamName_1633f0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_001633f0()
{
    if ((*(int*)&DAT_004e119c) == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("timeBegin", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b4e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("timeEnd", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b4f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("velocity", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b510);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("turnVelocity", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b530);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("turnAcceleration", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b560);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("leanThreshold", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b590);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("leanRate", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b5b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("phase", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b5d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("locomotion", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b5e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("animRun", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b5f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("animLeanEast", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b600);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("animLeanWest", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b610);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("partition", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b620);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("priority", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b640);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("blendInTime", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b660);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_1633f0<hulkfight::motion::LocomotionSprintTrack_1633f0>("blendOutTime", &hulkfight::motion::LocomotionSprintTrack_1633f0::FUN_0015b680);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1198), params, 16);
    }
    (*(int*)&DAT_004e119c)++;
}

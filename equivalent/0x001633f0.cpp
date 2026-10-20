// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_001633f0 @ 0x001633f0
#include "compat/ptr.h"
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class LocomotionSprintTrack {
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
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
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
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern ParamRegistry DAT_4e1198;
extern int DAT_4e119c;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001633f0()
{
    if (DAT_4e119c == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>("timeBegin", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b4e0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>("timeEnd", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b4f0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>("velocity", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b510);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>("turnVelocity", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b530);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>("turnAcceleration", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b560);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>("leanThreshold", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b590);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>("leanRate", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b5b0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>("phase", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b5d0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamName<hulkfight::motion::LocomotionSprintTrack>("locomotion", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b5e0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName<hulkfight::motion::LocomotionSprintTrack>("animRun", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b5f0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName<hulkfight::motion::LocomotionSprintTrack>("animLeanEast", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b600);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName<hulkfight::motion::LocomotionSprintTrack>("animLeanWest", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b610);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName<hulkfight::motion::LocomotionSprintTrack>("partition", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b620);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange<hulkfight::motion::LocomotionSprintTrack>("priority", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b640);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>("blendInTime", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b660);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSprintTrack>("blendOutTime", &hulkfight::motion::LocomotionSprintTrack::FUN_0015b680);
        FUN_002347b0(&DAT_4e1198, params, 16);
    }
    DAT_4e119c++;
}

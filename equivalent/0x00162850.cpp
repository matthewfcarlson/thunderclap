// STATUS: equivalent (tools/equiv.py level 3: 1031 inputs, branch coverage 76/76)
// FUN_00162850 @ 0x00162850
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class HeliLocomotionTrack {
public:
    void FUN_0015ad70();
    void FUN_0015ad80();
    void FUN_0015ada0();
    void FUN_0015adc0();
    void FUN_0015ade0();
    void FUN_0015ae10();
    void FUN_0015ae40();
    void FUN_0015ae70();
    void FUN_0015aea0();
    void FUN_0015aed0();
    void FUN_0015af00();
    void FUN_0015af20();
    void FUN_0015af40();
    void FUN_0015af70();
    void FUN_0015afa0();
    void FUN_0015afd0();
    void FUN_0015b000();
    void FUN_0015b030();
    void FUN_0015b060();
    void FUN_0015b080();
    void FUN_0015b0a0();
    void FUN_0015b0b0();
    void FUN_0015b0f0();
    void FUN_0015b140();
    void FUN_0015b180();
    void FUN_0015b1a0();
    void FUN_0015b1c0();
    void FUN_0015b1e0();
    void FUN_0015b1f0();
    void FUN_0015b210();
    void FUN_0015b220();
    void FUN_0015b250();
    void FUN_0015b270();
    void FUN_0015b290();
    void FUN_0015b2b0();
    void FUN_0015b2d0();
    void FUN_0015b310();
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
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
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
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00162850()
{
    if (DAT_004e118c == 0) {
        void* params[37];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("timeBegin", &hulkfight::motion::HeliLocomotionTrack::FUN_0015ad70);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("timeEnd", &hulkfight::motion::HeliLocomotionTrack::FUN_0015ad80);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("acceleration", &hulkfight::motion::HeliLocomotionTrack::FUN_0015ada0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("velocity", &hulkfight::motion::HeliLocomotionTrack::FUN_0015adc0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("turnAcceleration", &hulkfight::motion::HeliLocomotionTrack::FUN_0015ade0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("turnVelocity", &hulkfight::motion::HeliLocomotionTrack::FUN_0015ae10);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltXDesiredAtRest", &hulkfight::motion::HeliLocomotionTrack::FUN_0015ae40);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltXDesiredAtMaxSpeed", &hulkfight::motion::HeliLocomotionTrack::FUN_0015ae70);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltXMin", &hulkfight::motion::HeliLocomotionTrack::FUN_0015aea0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltXMax", &hulkfight::motion::HeliLocomotionTrack::FUN_0015aed0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltXMomentOfInertia", &hulkfight::motion::HeliLocomotionTrack::FUN_0015af00);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltXSpringConstant", &hulkfight::motion::HeliLocomotionTrack::FUN_0015af20);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltXDampingConstant", &hulkfight::motion::HeliLocomotionTrack::FUN_0015af40);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>("tiltXInertiaPoint", &hulkfight::motion::HeliLocomotionTrack::FUN_0015af70);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltZDesiredAtRest", &hulkfight::motion::HeliLocomotionTrack::FUN_0015afa0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltZDesiredAtMaxSpeed", &hulkfight::motion::HeliLocomotionTrack::FUN_0015afd0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltZMin", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b000);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltZMax", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b030);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltZMomentOfInertia", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b060);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltZSpringConstant", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b080);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("tiltZDampingConstant", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b0a0);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>("tiltZInertiaPoint", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b0b0);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>("minimum", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b0f0);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>("maximum", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b140);
        mem = FUN_0008d690(0x18);
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamIntConstRange<hulkfight::motion::HeliLocomotionTrack>("priority", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b180);
        mem = FUN_0008d690(0x18);
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("blendInTime", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b1a0);
        mem = FUN_0008d690(0x18);
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("blendOutTime", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b1c0);
        mem = FUN_0008d690(0x18);
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("riseUpSmoothingConstant", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b1e0);
        mem = FUN_0008d690(0x18);
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamName<hulkfight::motion::HeliLocomotionTrack>("riseUpJoint", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b1f0);
        mem = FUN_0008d690(0x18);
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("riseUpRayLength", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b210);
        mem = FUN_0008d690(0x18);
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>("riseUpOffset", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b220);
        mem = FUN_0008d690(0x18);
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("riseUpVelocity", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b250);
        mem = FUN_0008d690(0x18);
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("riseUpBoostAcceleration", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b270);
        mem = FUN_0008d690(0x18);
        params[33] = 0;
        if (mem)
            params[33] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("riseUpBoostXMax", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b290);
        mem = FUN_0008d690(0x18);
        params[34] = 0;
        if (mem)
            params[34] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("riseUpDecay", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b2b0);
        mem = FUN_0008d690(0x18);
        params[35] = 0;
        if (mem)
            params[35] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::HeliLocomotionTrack>("riseUpDecayCutOff", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b2d0);
        mem = FUN_0008d690(0x18);
        params[36] = 0;
        if (mem)
            params[36] = new (mem) fight::ParamVector<hulkfight::motion::HeliLocomotionTrack>("riseUpDifference", &hulkfight::motion::HeliLocomotionTrack::FUN_0015b310);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1188), params, 37);
    }
    DAT_004e118c++;
}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 38/38)
// FUN_00141b90 @ 0x00141b90
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class WallJumpTrack {
public:
    void FUN_0013ea20();
    void FUN_0013ea30();
    void FUN_0013ea50();
    void FUN_0013ea70();
    void FUN_0013ea90();
    void FUN_0013eab0();
    void FUN_0013ead0();
    void FUN_0013eb00();
    void FUN_0013eb30();
    void FUN_0013eb60();
    void FUN_0013eb90();
    void FUN_0013ebb0();
    void FUN_0013ebd0();
    void FUN_0013ec00();
    void FUN_0013ec30();
    void FUN_0013ec60();
    void FUN_0013ec80();
    void FUN_0013eca0();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
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
namespace fight {
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
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
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00141b90()
{
    if (DAT_004e0f54 == 0) {
        void* params[18];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("timeBegin", &hulkfight::motion::WallJumpTrack::FUN_0013ea20);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("timeEnd", &hulkfight::motion::WallJumpTrack::FUN_0013ea30);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("velocityMin", &hulkfight::motion::WallJumpTrack::FUN_0013ea50);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("velocityMax", &hulkfight::motion::WallJumpTrack::FUN_0013ea70);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("velocityXZMax", &hulkfight::motion::WallJumpTrack::FUN_0013ea90);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("gravity", &hulkfight::motion::WallJumpTrack::FUN_0013eab0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("upAngleMin", &hulkfight::motion::WallJumpTrack::FUN_0013ead0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("upAngleMax", &hulkfight::motion::WallJumpTrack::FUN_0013eb00);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("turningVelocity", &hulkfight::motion::WallJumpTrack::FUN_0013eb30);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("straightUpArc", &hulkfight::motion::WallJumpTrack::FUN_0013eb60);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("drift", &hulkfight::motion::WallJumpTrack::FUN_0013eb90);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamBool<hulkfight::motion::WallJumpTrack>("useCurrentMotionAngle", &hulkfight::motion::WallJumpTrack::FUN_0013ebb0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("angle", &hulkfight::motion::WallJumpTrack::FUN_0013ebd0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("arc", &hulkfight::motion::WallJumpTrack::FUN_0013ec00);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("minYAngle", &hulkfight::motion::WallJumpTrack::FUN_0013ec30);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamIntConstRange<hulkfight::motion::WallJumpTrack>("priority", &hulkfight::motion::WallJumpTrack::FUN_0013ec60);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("blendInTime", &hulkfight::motion::WallJumpTrack::FUN_0013ec80);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WallJumpTrack>("blendOutTime", &hulkfight::motion::WallJumpTrack::FUN_0013eca0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f50), params, 18);
    }
    DAT_004e0f54++;
}

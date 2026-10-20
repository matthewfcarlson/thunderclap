// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 32/32)
// FUN_0017a520 @ 0x0017a520
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

namespace hulkfight {
namespace motion {
class SurfTrack {
public:
    void FUN_0016f5e0();
    void FUN_0016f5f0();
    void FUN_0016f610();
    void FUN_0016f630();
    void FUN_0016f650();
    void FUN_0016f670();
    void FUN_0016f690();
    void FUN_0016f6c0();
    void FUN_0016f6f0();
    void FUN_0016f720();
    void FUN_0016f750();
    void FUN_0016f780();
    void FUN_0016f7b0();
    void FUN_0016f7d0();
    void FUN_0016f7f0();
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
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0017a520()
{
    if (DAT_004e1374 == 0) {
        void* params[15];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("timeBegin", &hulkfight::motion::SurfTrack::FUN_0016f5e0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("timeEnd", &hulkfight::motion::SurfTrack::FUN_0016f5f0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("minInitVelocity", &hulkfight::motion::SurfTrack::FUN_0016f610);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("minVelocity", &hulkfight::motion::SurfTrack::FUN_0016f630);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("deceleration", &hulkfight::motion::SurfTrack::FUN_0016f650);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("userDeceleration", &hulkfight::motion::SurfTrack::FUN_0016f670);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("turnVelocity", &hulkfight::motion::SurfTrack::FUN_0016f690);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("turnAcceleration", &hulkfight::motion::SurfTrack::FUN_0016f6c0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("leanMaxAngle", &hulkfight::motion::SurfTrack::FUN_0016f6f0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("leanActiveRate", &hulkfight::motion::SurfTrack::FUN_0016f720);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("leanPassiveRate", &hulkfight::motion::SurfTrack::FUN_0016f750);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("slopeRate", &hulkfight::motion::SurfTrack::FUN_0016f780);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange<hulkfight::motion::SurfTrack>("priority", &hulkfight::motion::SurfTrack::FUN_0016f7b0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("blendInTime", &hulkfight::motion::SurfTrack::FUN_0016f7d0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::SurfTrack>("blendOutTime", &hulkfight::motion::SurfTrack::FUN_0016f7f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1370), params, 15);
    }
    DAT_004e1374++;
}

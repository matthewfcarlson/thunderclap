// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 32/32)
// FUN_0013d070 @ 0x0013d070
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class AnimationVelocityScaledTrack {
public:
    void FUN_00139e70();
    void FUN_00139e80();
    void FUN_00139e90();
    void FUN_00139eb0();
    void FUN_00139ec0();
    void FUN_00139ee0();
    void FUN_00139f00();
    void FUN_00139f20();
    void FUN_00139f40();
    void FUN_00139f60();
    void FUN_00139f80();
    void FUN_00139f90();
    void FUN_00139fb0();
    void FUN_00139fd0();
    void FUN_00139ff0();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
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
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
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


void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0013d070()
{
    if (DAT_004e0f3c == 0) {
        void* params[15];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("timeBegin", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139e70);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("timeEnd", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139e80);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName<hulkfight::motion::AnimationVelocityScaledTrack>("animation", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139e90);
        mem = FUN_0008d690(0x20);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>("velocity", ((const char**)&DAT_004abf80), 6, &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139eb0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("scale", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139ec0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("speedMin", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139ee0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("speedMax", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139f00);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("initFrame", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139f20);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("startFrame", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139f40);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("endFrame", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139f60);
        mem = FUN_0008d690(0x20);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamEnumConstList<hulkfight::motion::AnimationVelocityScaledTrack>("cyclic", ((const char**)&DAT_004abf70), 4, &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139f80);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName<hulkfight::motion::AnimationVelocityScaledTrack>("partition", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139f90);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("priority", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139fb0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("blendInTime", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139fd0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::AnimationVelocityScaledTrack>("blendOutTime", &hulkfight::motion::AnimationVelocityScaledTrack::FUN_00139ff0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f38), params, 15);
    }
    DAT_004e0f3c++;
}

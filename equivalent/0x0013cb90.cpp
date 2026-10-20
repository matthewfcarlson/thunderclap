// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 22/22)
// FUN_0013cb90 @ 0x0013cb90
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class AnimationLinkedTrack {
public:
    void FUN_00139c70();
    void FUN_00139c80();
    void FUN_00139c90();
    void FUN_00139cb0();
    void FUN_00139cd0();
    void FUN_00139cf0();
    void FUN_00139d00();
    void FUN_00139d20();
    void FUN_00139d40();
    void FUN_00139d60();
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

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
namespace fight {
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

void FUN_0013cb90()
{
    if (DAT_004e0f2c == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<AnimationLinkedTrack>("timeBegin", &AnimationLinkedTrack::FUN_00139c70);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<AnimationLinkedTrack>("timeEnd", &AnimationLinkedTrack::FUN_00139c80);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName<AnimationLinkedTrack>("animation", &AnimationLinkedTrack::FUN_00139c90);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<AnimationLinkedTrack>("speed", &AnimationLinkedTrack::FUN_00139cb0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<AnimationLinkedTrack>("startFrame", &AnimationLinkedTrack::FUN_00139cd0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<AnimationLinkedTrack>("endFrame", &AnimationLinkedTrack::FUN_00139cf0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamName<AnimationLinkedTrack>("partition", &AnimationLinkedTrack::FUN_00139d00);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange<AnimationLinkedTrack>("priority", &AnimationLinkedTrack::FUN_00139d20);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<AnimationLinkedTrack>("blendInTime", &AnimationLinkedTrack::FUN_00139d40);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<AnimationLinkedTrack>("blendOutTime", &AnimationLinkedTrack::FUN_00139d60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f28), params, 10);
    }
    DAT_004e0f2c++;
}

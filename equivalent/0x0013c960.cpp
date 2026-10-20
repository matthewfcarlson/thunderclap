// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 20/20)
// FUN_0013c960 @ 0x0013c960
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class AnimationChargeTrack {
public:
    void FUN_00139b90();
    void FUN_00139ba0();
    void FUN_00139bb0();
    void FUN_00139bd0();
    void FUN_00139bf0();
    void FUN_00139c00();
    void FUN_00139c20();
    void FUN_00139c40();
    void FUN_00139c60();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamStringNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamStringNameBase(const char* name) { FUN_00234a90(name); }
};
template <class T>
class ParamStringName : public ParamStringNameBase {
public:
    ParamStringName(const char* name, void (T::*s)()) : ParamStringNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0013c960()
{
    if (DAT_004e0f24 == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("timeBegin", &AnimationChargeTrack::FUN_00139b90);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("timeEnd", &AnimationChargeTrack::FUN_00139ba0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamStringName<AnimationChargeTrack>("animation", &AnimationChargeTrack::FUN_00139bb0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("startFrame", &AnimationChargeTrack::FUN_00139bd0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("endFrame", &AnimationChargeTrack::FUN_00139bf0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamStringName<AnimationChargeTrack>("partition", &AnimationChargeTrack::FUN_00139c00);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamIntConstRange<AnimationChargeTrack>("priority", &AnimationChargeTrack::FUN_00139c20);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("blendInTime", &AnimationChargeTrack::FUN_00139c40);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("blendOutTime", &AnimationChargeTrack::FUN_00139c60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f20), params, 9);
    }
    DAT_004e0f24++;
}

// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 24/24)
// FUN_00156700 @ 0x00156700
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class GroundSlideTrack {
public:
    void FUN_0014cfa0();
    void FUN_0014cfb0();
    void FUN_0014cfd0();
    void FUN_0014d000();
    void FUN_0014d020();
    void FUN_0014d040();
    void FUN_0014d060();
    void FUN_0014d080();
    void FUN_0014d0a0();
    void FUN_0014d0c0();
    void FUN_0014d0e0();
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

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00156700()
{
    if (DAT_004e113c == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<GroundSlideTrack>("timeBegin", &GroundSlideTrack::FUN_0014cfa0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<GroundSlideTrack>("timeEnd", &GroundSlideTrack::FUN_0014cfb0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<GroundSlideTrack>("facing", &GroundSlideTrack::FUN_0014cfd0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<GroundSlideTrack>("friction", &GroundSlideTrack::FUN_0014d000);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<GroundSlideTrack>("deceleration", &GroundSlideTrack::FUN_0014d020);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<GroundSlideTrack>("minInitVelocity", &GroundSlideTrack::FUN_0014d040);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<GroundSlideTrack>("minVelocity", &GroundSlideTrack::FUN_0014d060);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<GroundSlideTrack>("maxVelocity", &GroundSlideTrack::FUN_0014d080);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange<GroundSlideTrack>("priority", &GroundSlideTrack::FUN_0014d0a0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<GroundSlideTrack>("blendInTime", &GroundSlideTrack::FUN_0014d0c0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<GroundSlideTrack>("blendOutTime", &GroundSlideTrack::FUN_0014d0e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1138), params, 11);
    }
    DAT_004e113c++;
}

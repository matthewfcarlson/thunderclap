// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 38/38)
// FUN_000706c0 @ 0x000706c0
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CJumpTrack {
public:
    void FUN_00067fe0();
    void FUN_00067ff0();
    void FUN_00068000();
    void FUN_00068010();
    void FUN_00068020();
    void FUN_00068030();
    void FUN_00068040();
    void FUN_00068050();
    void FUN_00068060();
    void FUN_000680e0();
    void FUN_00068070();
    void FUN_00068100();
    void FUN_00068080();
    void FUN_00068090();
    void FUN_000680a0();
    void FUN_000680b0();
    void FUN_000680c0();
    void FUN_000680d0();
};

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

void FUN_000706c0()
{
    if (DAT_004dcf24 == 0) {
        void* params[18];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("timeBegin", &CJumpTrack::FUN_00067fe0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("timeEnd", &CJumpTrack::FUN_00067ff0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("minFlightTime", &CJumpTrack::FUN_00068000);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("maxFlightTime", &CJumpTrack::FUN_00068010);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("upDistanceMin", &CJumpTrack::FUN_00068020);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("upDistanceMax", &CJumpTrack::FUN_00068030);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("forwardDistanceMin", &CJumpTrack::FUN_00068040);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("forwardDistanceMax", &CJumpTrack::FUN_00068050);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("drift", &CJumpTrack::FUN_00068060);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("turningVelocityMin", &CJumpTrack::FUN_000680e0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("turningVelocityMinForwardSpeedCap", &CJumpTrack::FUN_00068070);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("turningVelocityMax", &CJumpTrack::FUN_00068100);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("turningVelocityMaxForwardSpeedCap", &CJumpTrack::FUN_00068080);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange<CJumpTrack>("priority", &CJumpTrack::FUN_00068090);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("blendInTime", &CJumpTrack::FUN_000680a0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<CJumpTrack>("blendOutTime", &CJumpTrack::FUN_000680b0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool<CJumpTrack>("stopTrackAtApex", &CJumpTrack::FUN_000680c0);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamBool<CJumpTrack>("redirect", &CJumpTrack::FUN_000680d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf20), params, 18);
    }
    DAT_004dcf24++;
}

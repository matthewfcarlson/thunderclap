// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 38/38)
// FUN_000706c0 @ 0x000706c0
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CJumpTrack_706c0 {
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
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
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
namespace fight {
template <class T>
class ParamBool_706c0 : public ParamBoolBase {
public:
    ParamBool_706c0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange_706c0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_706c0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_706c0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_706c0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_000706c0()
{
    if (DAT_004dcf24 == 0) {
        void* params[18];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("timeBegin", &CJumpTrack_706c0::FUN_00067fe0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("timeEnd", &CJumpTrack_706c0::FUN_00067ff0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("minFlightTime", &CJumpTrack_706c0::FUN_00068000);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("maxFlightTime", &CJumpTrack_706c0::FUN_00068010);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("upDistanceMin", &CJumpTrack_706c0::FUN_00068020);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("upDistanceMax", &CJumpTrack_706c0::FUN_00068030);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("forwardDistanceMin", &CJumpTrack_706c0::FUN_00068040);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("forwardDistanceMax", &CJumpTrack_706c0::FUN_00068050);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("drift", &CJumpTrack_706c0::FUN_00068060);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("turningVelocityMin", &CJumpTrack_706c0::FUN_000680e0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("turningVelocityMinForwardSpeedCap", &CJumpTrack_706c0::FUN_00068070);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("turningVelocityMax", &CJumpTrack_706c0::FUN_00068100);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("turningVelocityMaxForwardSpeedCap", &CJumpTrack_706c0::FUN_00068080);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_706c0<CJumpTrack_706c0>("priority", &CJumpTrack_706c0::FUN_00068090);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("blendInTime", &CJumpTrack_706c0::FUN_000680a0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_706c0<CJumpTrack_706c0>("blendOutTime", &CJumpTrack_706c0::FUN_000680b0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool_706c0<CJumpTrack_706c0>("stopTrackAtApex", &CJumpTrack_706c0::FUN_000680c0);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamBool_706c0<CJumpTrack_706c0>("redirect", &CJumpTrack_706c0::FUN_000680d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf20), params, 18);
    }
    DAT_004dcf24++;
}

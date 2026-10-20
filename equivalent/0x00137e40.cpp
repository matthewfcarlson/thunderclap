// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 22/22)
// FUN_00137e40 @ 0x00137e40
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class BounceTrack {
public:
    void FUN_001331f0();
    void FUN_00133200();
    void FUN_00133220();
    void FUN_00133240();
    void FUN_00133260();
    void FUN_00133280();
    void FUN_001332a0();
    void FUN_001332d0();
    void FUN_001332f0();
    void FUN_00133310();
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

void FUN_00137e40()
{
    if (DAT_004e0edc == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<BounceTrack>("timeBegin", &BounceTrack::FUN_001331f0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<BounceTrack>("timeEnd", &BounceTrack::FUN_00133200);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<BounceTrack>("flightTime", &BounceTrack::FUN_00133220);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<BounceTrack>("upDistance", &BounceTrack::FUN_00133240);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<BounceTrack>("drift", &BounceTrack::FUN_00133260);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<BounceTrack>("minForwardVelocity", &BounceTrack::FUN_00133280);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<BounceTrack>("turningVelocity", &BounceTrack::FUN_001332a0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange<BounceTrack>("priority", &BounceTrack::FUN_001332d0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<BounceTrack>("blendInTime", &BounceTrack::FUN_001332f0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<BounceTrack>("blendOutTime", &BounceTrack::FUN_00133310);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ed8), params, 10);
    }
    DAT_004e0edc++;
}

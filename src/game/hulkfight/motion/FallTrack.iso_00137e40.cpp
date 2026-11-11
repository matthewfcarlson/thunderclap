// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
#include "tree_prelude.h"


// 0x00137e40 FUN_00137e40 (562 B): equivalent/0x00137e40.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called; on include/gen/ and not mergeable]
// sym: ?FUN_00137e40@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 22/22)
// FUN_00137e40 @ 0x00137e40
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(size_t, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

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
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_137e40 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_137e40(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_137e40 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_137e40(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00137e40()
{
    if (DAT_004e0edc == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137e40<BounceTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_137e40<BounceTrack>("timeBegin", &BounceTrack::FUN_001331f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137e40<BounceTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_137e40<BounceTrack>("timeEnd", &BounceTrack::FUN_00133200);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137e40<BounceTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_137e40<BounceTrack>("flightTime", &BounceTrack::FUN_00133220);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137e40<BounceTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_137e40<BounceTrack>("upDistance", &BounceTrack::FUN_00133240);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137e40<BounceTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_137e40<BounceTrack>("drift", &BounceTrack::FUN_00133260);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137e40<BounceTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_137e40<BounceTrack>("minForwardVelocity", &BounceTrack::FUN_00133280);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137e40<BounceTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_137e40<BounceTrack>("turningVelocity", &BounceTrack::FUN_001332a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_137e40<BounceTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_137e40<BounceTrack>("priority", &BounceTrack::FUN_001332d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137e40<BounceTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_137e40<BounceTrack>("blendInTime", &BounceTrack::FUN_001332f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_137e40<BounceTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_137e40<BounceTrack>("blendOutTime", &BounceTrack::FUN_00133310);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ed8), params, 10);
    }
    DAT_004e0edc++;
}


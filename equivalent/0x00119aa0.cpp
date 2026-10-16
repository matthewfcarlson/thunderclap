// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 24/24)
// FUN_00119aa0 @ 0x00119aa0
#include "decls/data/game/hulkfight/ai.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class MotionClosestWaypointTrack {
public:
    void FUN_00115560();
    void FUN_00115570();
    void FUN_00115590();
    void FUN_001155b0();
    void FUN_001155d0();
    void FUN_001155f0();
    void FUN_00115610();
    void FUN_00115630();
    void FUN_00115650();
    void FUN_00115670();
    void FUN_00115690();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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
}

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

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00119aa0()
{
    if (DAT_004e0c80 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<MotionClosestWaypointTrack>("timeBegin", &MotionClosestWaypointTrack::FUN_00115560);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<MotionClosestWaypointTrack>("timeEnd", &MotionClosestWaypointTrack::FUN_00115570);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<MotionClosestWaypointTrack>("speed", &MotionClosestWaypointTrack::FUN_00115590);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<MotionClosestWaypointTrack>("distanceMin", &MotionClosestWaypointTrack::FUN_001155b0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<MotionClosestWaypointTrack>("distanceMax", &MotionClosestWaypointTrack::FUN_001155d0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<MotionClosestWaypointTrack>("heightMin", &MotionClosestWaypointTrack::FUN_001155f0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<MotionClosestWaypointTrack>("heightMax", &MotionClosestWaypointTrack::FUN_00115610);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool<MotionClosestWaypointTrack>("useAvoidance", &MotionClosestWaypointTrack::FUN_00115630);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool<MotionClosestWaypointTrack>("setWaypointAsDriftPosition", &MotionClosestWaypointTrack::FUN_00115650);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<MotionClosestWaypointTrack>("maxTimeInSamePosition", &MotionClosestWaypointTrack::FUN_00115670);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<MotionClosestWaypointTrack>("minSpeedToKeepMoving", &MotionClosestWaypointTrack::FUN_00115690);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c7c), params, 11);
    }
    DAT_004e0c80++;
}

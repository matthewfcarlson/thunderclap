// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 24/24)
// FUN_00138080 @ 0x00138080
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class AirToGroundTargetTrack {
public:
    void FUN_00133320();
    void FUN_00133330();
    void FUN_00133350();
    void FUN_00133370();
    void FUN_00133390();
    void FUN_001333b0();
    void FUN_001333d0();
    void FUN_00133400();
    void FUN_00133420();
    void FUN_00133440();
    void FUN_00133460();
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

void FUN_00138080()
{
    if (DAT_004e0ee4 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<AirToGroundTargetTrack>("timeBegin", &AirToGroundTargetTrack::FUN_00133320);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<AirToGroundTargetTrack>("timeEnd", &AirToGroundTargetTrack::FUN_00133330);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<AirToGroundTargetTrack>("velocityXZMin", &AirToGroundTargetTrack::FUN_00133350);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<AirToGroundTargetTrack>("velocityXZMax", &AirToGroundTargetTrack::FUN_00133370);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<AirToGroundTargetTrack>("accelerationXZ", &AirToGroundTargetTrack::FUN_00133390);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<AirToGroundTargetTrack>("gravity", &AirToGroundTargetTrack::FUN_001333b0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<AirToGroundTargetTrack>("turningVelocity", &AirToGroundTargetTrack::FUN_001333d0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<AirToGroundTargetTrack>("targetOffset", &AirToGroundTargetTrack::FUN_00133400);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange<AirToGroundTargetTrack>("priority", &AirToGroundTargetTrack::FUN_00133420);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<AirToGroundTargetTrack>("blendInTime", &AirToGroundTargetTrack::FUN_00133440);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<AirToGroundTargetTrack>("blendOutTime", &AirToGroundTargetTrack::FUN_00133460);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ee0), params, 11);
    }
    DAT_004e0ee4++;
}

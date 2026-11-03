// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 24/24)
// FUN_00138080 @ 0x00138080
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

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
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_138080 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_138080(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_138080 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_138080(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00138080()
{
    if (DAT_004e0ee4 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_138080<AirToGroundTargetTrack>("timeBegin", &AirToGroundTargetTrack::FUN_00133320);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_138080<AirToGroundTargetTrack>("timeEnd", &AirToGroundTargetTrack::FUN_00133330);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_138080<AirToGroundTargetTrack>("velocityXZMin", &AirToGroundTargetTrack::FUN_00133350);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_138080<AirToGroundTargetTrack>("velocityXZMax", &AirToGroundTargetTrack::FUN_00133370);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_138080<AirToGroundTargetTrack>("accelerationXZ", &AirToGroundTargetTrack::FUN_00133390);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_138080<AirToGroundTargetTrack>("gravity", &AirToGroundTargetTrack::FUN_001333b0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_138080<AirToGroundTargetTrack>("turningVelocity", &AirToGroundTargetTrack::FUN_001333d0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_138080<AirToGroundTargetTrack>("targetOffset", &AirToGroundTargetTrack::FUN_00133400);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_138080<AirToGroundTargetTrack>("priority", &AirToGroundTargetTrack::FUN_00133420);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_138080<AirToGroundTargetTrack>("blendInTime", &AirToGroundTargetTrack::FUN_00133440);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_138080<AirToGroundTargetTrack>("blendOutTime", &AirToGroundTargetTrack::FUN_00133460);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ee0), params, 11);
    }
    DAT_004e0ee4++;
}

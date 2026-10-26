// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_00163050 @ 0x00163050
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class LocomotionSteerTrack {
public:
    void FUN_0015b340();
    void FUN_0015b350();
    void FUN_0015b370();
    void FUN_0015b390();
    void FUN_0015b3c0();
    void FUN_0015b3e0();
    void FUN_0015b400();
    void FUN_0015b410();
    void FUN_0015b420();
    void FUN_0015b430();
    void FUN_0015b440();
    void FUN_0015b460();
    void FUN_0015b470();
    void FUN_0015b490();
    void FUN_0015b4b0();
    void FUN_0015b4d0();
};
}
}

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
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
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

void FUN_00163050()
{
    if ((*(int*)&DAT_004e1194) == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>("timeBegin", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b340);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>("timeEnd", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b350);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>("acceleration", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b370);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>("turningVelocity", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b390);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>("velocityWalk", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b3c0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>("velocityRun", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b3e0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>("phase", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b400);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamName<hulkfight::motion::LocomotionSteerTrack>("locomotion", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b410);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamName<hulkfight::motion::LocomotionSteerTrack>("animIdle", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b420);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName<hulkfight::motion::LocomotionSteerTrack>("animWalk", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b430);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName<hulkfight::motion::LocomotionSteerTrack>("animRun", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b440);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamBool<hulkfight::motion::LocomotionSteerTrack>("locomoting", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b460);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName<hulkfight::motion::LocomotionSteerTrack>("partition", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b470);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange<hulkfight::motion::LocomotionSteerTrack>("priority", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b490);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>("blendInTime", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b4b0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::LocomotionSteerTrack>("blendOutTime", &hulkfight::motion::LocomotionSteerTrack::FUN_0015b4d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1190), params, 16);
    }
    (*(int*)&DAT_004e1194)++;
}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_00163050 @ 0x00163050
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class LocomotionSteerTrack_163050 {
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
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamBool_163050 : public ParamBoolBase {
public:
    ParamBool_163050(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange_163050 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_163050(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_163050 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_163050(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_163050 : public ParamNameBase {
public:
    ParamName_163050(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00163050()
{
    if ((*(int*)&DAT_004e1194) == 0) {
        void* params[16];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("timeBegin", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b340);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("timeEnd", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b350);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("acceleration", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b370);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("turningVelocity", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b390);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("velocityWalk", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b3c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("velocityRun", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b3e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("phase", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b400);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("locomotion", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b410);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("animIdle", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b420);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("animWalk", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b430);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("animRun", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b440);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamBool_163050<hulkfight::motion::LocomotionSteerTrack_163050>("locomoting", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b460);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName_163050<hulkfight::motion::LocomotionSteerTrack_163050>("partition", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b470);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("priority", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b490);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("blendInTime", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b4b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_163050<hulkfight::motion::LocomotionSteerTrack_163050>("blendOutTime", &hulkfight::motion::LocomotionSteerTrack_163050::FUN_0015b4d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1190), params, 16);
    }
    (*(int*)&DAT_004e1194)++;
}

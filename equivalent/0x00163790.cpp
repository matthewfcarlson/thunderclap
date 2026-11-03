// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 22/22)
// FUN_00163790 @ 0x00163790
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class GrappleLocomotionSteerTrack {
public:
    void FUN_0015b690();
    void FUN_0015b6a0();
    void FUN_0015b6b0();
    void FUN_0015b6c0();
    void FUN_0015b6d0();
    void FUN_0015b6e0();
    void FUN_0015b6f0();
    void FUN_0015b710();
    void FUN_0015b730();
    void FUN_0015b750();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_163790 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_163790(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_163790 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_163790(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamName_163790 : public ParamNameBase {
public:
    ParamName_163790(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00163790()
{
    if (DAT_004e11a4 == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("timeBegin", &GrappleLocomotionSteerTrack::FUN_0015b690);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("timeEnd", &GrappleLocomotionSteerTrack::FUN_0015b6a0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_163790<GrappleLocomotionSteerTrack>("locomotion", &GrappleLocomotionSteerTrack::FUN_0015b6b0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_163790<GrappleLocomotionSteerTrack>("animIdle", &GrappleLocomotionSteerTrack::FUN_0015b6c0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName_163790<GrappleLocomotionSteerTrack>("animWalk", &GrappleLocomotionSteerTrack::FUN_0015b6d0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamName_163790<GrappleLocomotionSteerTrack>("animRun", &GrappleLocomotionSteerTrack::FUN_0015b6e0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamName_163790<GrappleLocomotionSteerTrack>("partition", &GrappleLocomotionSteerTrack::FUN_0015b6f0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_163790<GrappleLocomotionSteerTrack>("priority", &GrappleLocomotionSteerTrack::FUN_0015b710);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("blendInTime", &GrappleLocomotionSteerTrack::FUN_0015b730);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_163790<GrappleLocomotionSteerTrack>("blendOutTime", &GrappleLocomotionSteerTrack::FUN_0015b750);
        FUN_002347b0(((ParamRegistry*)&DAT_004e11a0), params, 10);
    }
    DAT_004e11a4++;
}

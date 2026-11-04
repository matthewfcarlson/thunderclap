// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 32/32)
// FUN_0013d070 @ 0x0013d070
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class AnimationVelocityScaledTrack_13d070 {
public:
    void FUN_00139e70();
    void FUN_00139e80();
    void FUN_00139e90();
    void FUN_00139eb0();
    void FUN_00139ec0();
    void FUN_00139ee0();
    void FUN_00139f00();
    void FUN_00139f20();
    void FUN_00139f40();
    void FUN_00139f60();
    void FUN_00139f80();
    void FUN_00139f90();
    void FUN_00139fb0();
    void FUN_00139fd0();
    void FUN_00139ff0();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
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
class ParamEnumConstList_13d070 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_13d070(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_13d070 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_13d070(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_13d070 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_13d070(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_13d070 : public ParamNameBase {
public:
    ParamName_13d070(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};


extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0013d070()
{
    if (DAT_004e0f3c == 0) {
        void* params[15];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("timeBegin", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139e70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("timeEnd", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139e80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("animation", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139e90);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamEnumConstList_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("velocity", ((const char**)&DAT_004abf80), 6, &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139eb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("scale", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139ec0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("speedMin", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139ee0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("speedMax", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("initFrame", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("startFrame", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("endFrame", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f60);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamEnumConstList_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("cyclic", ((const char**)&DAT_004abf70), 4, &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("partition", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f90);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("priority", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139fb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("blendInTime", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139fd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("blendOutTime", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139ff0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f38), params, 15);
    }
    DAT_004e0f3c++;
}

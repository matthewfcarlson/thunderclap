// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 22/22)
// FUN_0017ddf0 @ 0x0017ddf0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class FootPivotTrack {
public:
    void FUN_0016fad0();
    void FUN_0016fae0();
    void FUN_0016faf0();
    void FUN_0016fb20();
    void FUN_0016fb50();
    void FUN_0016fb80();
    void FUN_0016fbb0();
    void FUN_0016fbd0();
    void FUN_0016fbf0();
    void FUN_0016fc10();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_17ddf0 : public ParamBoolBase {
public:
    ParamBool_17ddf0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_17ddf0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17ddf0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_17ddf0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17ddf0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
namespace fight {
template <class T>
class ParamNameConstList_17ddf0 : public ParamNameConstListBase {
public:
    ParamNameConstList_17ddf0(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamVector_17ddf0 : public ParamVectorBase {
public:
    ParamVector_17ddf0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0017ddf0()
{
    if (DAT_004e13bc == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("timeBegin", &FootPivotTrack::FUN_0016fad0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("timeEnd", &FootPivotTrack::FUN_0016fae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17ddf0<FootPivotTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_17ddf0<FootPivotTrack>("joint", &FootPivotTrack::FUN_0016faf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17ddf0<FootPivotTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_17ddf0<FootPivotTrack>("offset", &FootPivotTrack::FUN_0016fb20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("facing", &FootPivotTrack::FUN_0016fb50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("turningVelocity", &FootPivotTrack::FUN_0016fb80);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17ddf0<FootPivotTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_17ddf0<FootPivotTrack>("useTarget", &FootPivotTrack::FUN_0016fbb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17ddf0<FootPivotTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_17ddf0<FootPivotTrack>("priority", &FootPivotTrack::FUN_0016fbd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("blendInTime", &FootPivotTrack::FUN_0016fbf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17ddf0<FootPivotTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17ddf0<FootPivotTrack>("blendOutTime", &FootPivotTrack::FUN_0016fc10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e13b8), params, 10);
    }
    DAT_004e13bc++;
}

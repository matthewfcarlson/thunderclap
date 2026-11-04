// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 24/24)
// FUN_00120fe0 @ 0x00120fe0
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class PathFormationTrack {
public:
    void FUN_0011bad0();
    void FUN_0011bae0();
    void FUN_0011baf0();
    void FUN_0011bb00();
    void FUN_0011bb20();
    void FUN_0011bb30();
    void FUN_0011bb40();
    void FUN_0011bb60();
    void FUN_0011bb80();
    void FUN_0011bba0();
    void FUN_0011c470();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_120fe0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_120fe0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_120fe0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_120fe0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
template <class T>
class ParamString_120fe0 : public ParamStringBase {
public:
    ParamString_120fe0(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00120fe0()
{
    if (DAT_004e0cbc == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("timeBegin", &PathFormationTrack::FUN_0011bad0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("timeEnd", &PathFormationTrack::FUN_0011bae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("distance", &PathFormationTrack::FUN_0011baf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("turnRate", &PathFormationTrack::FUN_0011bb00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("heightMin", &PathFormationTrack::FUN_0011bb20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("heightMax", &PathFormationTrack::FUN_0011bb30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("speed", &PathFormationTrack::FUN_0011bb40);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_120fe0<PathFormationTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_120fe0<PathFormationTrack>("minMembers", &PathFormationTrack::FUN_0011bb60);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_120fe0<PathFormationTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_120fe0<PathFormationTrack>("maxMembers", &PathFormationTrack::FUN_0011bb80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_120fe0<PathFormationTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_120fe0<PathFormationTrack>("engagementDistance", &PathFormationTrack::FUN_0011bba0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_120fe0<PathFormationTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamString_120fe0<PathFormationTrack>("tactic", &PathFormationTrack::FUN_0011c470);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cb8), params, 11);
    }
    DAT_004e0cbc++;
}

// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 26/26)
// FUN_00120d40 @ 0x00120d40
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class RoutTrack {
public:
    void FUN_0011b980();
    void FUN_0011b990();
    void FUN_0011b9a0();
    void FUN_0011b9d0();
    void FUN_0011b9f0();
    void FUN_0011ba10();
    void FUN_0011ba30();
    void FUN_0011ba50();
    void FUN_0011ba70();
    void FUN_0011ba90();
    void FUN_0011bab0();
    void FUN_0011bac0();
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

void FUN_00120d40()
{
    if (DAT_004e0cb4 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<RoutTrack>("timeBegin", &RoutTrack::FUN_0011b980);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<RoutTrack>("timeEnd", &RoutTrack::FUN_0011b990);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<RoutTrack>("turnRate", &RoutTrack::FUN_0011b9a0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<RoutTrack>("speed", &RoutTrack::FUN_0011b9d0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<RoutTrack>("routRadius", &RoutTrack::FUN_0011b9f0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<RoutTrack>("maxTimeInSamePosition", &RoutTrack::FUN_0011ba10);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<RoutTrack>("minSpeedToKeepRunning", &RoutTrack::FUN_0011ba30);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool<RoutTrack>("useAvoidanceCode", &RoutTrack::FUN_0011ba50);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<RoutTrack>("seperationBufferStart", &RoutTrack::FUN_0011ba70);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<RoutTrack>("seperationBufferStop", &RoutTrack::FUN_0011ba90);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<RoutTrack>("width", &RoutTrack::FUN_0011bab0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<RoutTrack>("formationWidth", &RoutTrack::FUN_0011bac0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0cb0), params, 12);
    }
    DAT_004e0cb4++;
}

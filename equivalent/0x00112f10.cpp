// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 14/14)
// FUN_00112f10 @ 0x00112f10
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class SemaphoreWaitTrack {
public:
    void FUN_0010c680();
    void FUN_0010c690();
    void FUN_0010c6a0();
    void FUN_0010c6c0();
    void FUN_0010c6e0();
    void FUN_0010c700();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00112f10()
{
    if (DAT_004e0ba4 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SemaphoreWaitTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<SemaphoreWaitTrack>("timeBegin", &SemaphoreWaitTrack::FUN_0010c680);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SemaphoreWaitTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<SemaphoreWaitTrack>("timeEnd", &SemaphoreWaitTrack::FUN_0010c690);
        mem = FUN_0008d690((int)sizeof(ParamName<SemaphoreWaitTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<SemaphoreWaitTrack>("semaphore", &SemaphoreWaitTrack::FUN_0010c6a0);
        mem = FUN_0008d690((int)sizeof(ParamBool<SemaphoreWaitTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<SemaphoreWaitTrack>("interuptable", &SemaphoreWaitTrack::FUN_0010c6c0);
        mem = FUN_0008d690((int)sizeof(ParamBool<SemaphoreWaitTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<SemaphoreWaitTrack>("useCharacterTimeout", &SemaphoreWaitTrack::FUN_0010c6e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<SemaphoreWaitTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<SemaphoreWaitTrack>("timeoutOverride", &SemaphoreWaitTrack::FUN_0010c700);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ba0), params, 6);
    }
    DAT_004e0ba4++;
}

// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 14/14)
// FUN_00112f10 @ 0x00112f10
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/ai.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

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
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
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
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
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

void FUN_00112f10()
{
    if (DAT_004e0ba4 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<SemaphoreWaitTrack>("timeBegin", &SemaphoreWaitTrack::FUN_0010c680);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<SemaphoreWaitTrack>("timeEnd", &SemaphoreWaitTrack::FUN_0010c690);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<SemaphoreWaitTrack>("semaphore", &SemaphoreWaitTrack::FUN_0010c6a0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<SemaphoreWaitTrack>("interuptable", &SemaphoreWaitTrack::FUN_0010c6c0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<SemaphoreWaitTrack>("useCharacterTimeout", &SemaphoreWaitTrack::FUN_0010c6e0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<SemaphoreWaitTrack>("timeoutOverride", &SemaphoreWaitTrack::FUN_0010c700);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ba0), params, 6);
    }
    DAT_004e0ba4++;
}

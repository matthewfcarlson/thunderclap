// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 14/14)
// FUN_00145540 @ 0x00145540
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class SlowMotionTrack {
public:
    void FUN_00143230();
    void FUN_00143250();
    void FUN_00143270();
    void FUN_00143290();
    void FUN_001432b0();
    void FUN_001432d0();
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

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00145540()
{
    if (DAT_004e0f8c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<SlowMotionTrack>("timeBegin", &SlowMotionTrack::FUN_00143230);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<SlowMotionTrack>("timeOn", &SlowMotionTrack::FUN_00143250);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<SlowMotionTrack>("timeOff", &SlowMotionTrack::FUN_00143270);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<SlowMotionTrack>("timeEnd", &SlowMotionTrack::FUN_00143290);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<SlowMotionTrack>("simulationRate", &SlowMotionTrack::FUN_001432b0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<SlowMotionTrack>("fromScenario", &SlowMotionTrack::FUN_001432d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f88), params, 6);
    }
    DAT_004e0f8c++;
}

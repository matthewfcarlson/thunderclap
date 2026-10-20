// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_0011ab30 @ 0x0011ab30
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/ai.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class MotionLocatorTrack {
public:
    void FUN_00115290();
    void FUN_001152a0();
    void FUN_001152c0();
    void FUN_001152e0();
    void FUN_00115300();
    void FUN_00115320();
    void FUN_00115340();
    void FUN_00115360();
    void FUN_00115380();
    void FUN_001153a0();
    void FUN_001153c0();
    void FUN_001153d0();
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

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
namespace fight {
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

void FUN_0011ab30()
{
    if (DAT_004e0c68 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<MotionLocatorTrack>("timeBegin", &MotionLocatorTrack::FUN_00115290);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<MotionLocatorTrack>("timeEnd", &MotionLocatorTrack::FUN_001152a0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<MotionLocatorTrack>("speed", &MotionLocatorTrack::FUN_001152c0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<MotionLocatorTrack>("distanceMin", &MotionLocatorTrack::FUN_001152e0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<MotionLocatorTrack>("distanceMax", &MotionLocatorTrack::FUN_00115300);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<MotionLocatorTrack>("heightMin", &MotionLocatorTrack::FUN_00115320);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<MotionLocatorTrack>("heightMax", &MotionLocatorTrack::FUN_00115340);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool<MotionLocatorTrack>("stringParamLocator", &MotionLocatorTrack::FUN_00115360);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool<MotionLocatorTrack>("myLocator", &MotionLocatorTrack::FUN_00115380);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool<MotionLocatorTrack>("defendLocator", &MotionLocatorTrack::FUN_001153a0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool<MotionLocatorTrack>("namedLocator", &MotionLocatorTrack::FUN_001153c0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName<MotionLocatorTrack>("locatorName", &MotionLocatorTrack::FUN_001153d0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0c64), params, 12);
    }
    DAT_004e0c68++;
}

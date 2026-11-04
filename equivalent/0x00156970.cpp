// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 22/22)
// FUN_00156970 @ 0x00156970
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class HitPushbackTrack {
public:
    void FUN_0014d0f0();
    void FUN_0014d100();
    void FUN_0014d120();
    void FUN_0014d140();
    void FUN_0014d160();
    void FUN_0014d180();
    void FUN_0014d1b0();
    void FUN_0014d1e0();
    void FUN_0014d200();
    void FUN_0014d220();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_156970 : public ParamBoolBase {
public:
    ParamBool_156970(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
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
class ParamFloatConstRange_156970 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_156970(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_156970 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_156970(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00156970()
{
    if (DAT_004e1144 == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("timeBegin", &HitPushbackTrack::FUN_0014d0f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("timeEnd", &HitPushbackTrack::FUN_0014d100);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("weight", &HitPushbackTrack::FUN_0014d120);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("maxDistance", &HitPushbackTrack::FUN_0014d140);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_156970<HitPushbackTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_156970<HitPushbackTrack>("snapToPushback", &HitPushbackTrack::FUN_0014d160);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("orientation", &HitPushbackTrack::FUN_0014d180);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("proneSpin", &HitPushbackTrack::FUN_0014d1b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_156970<HitPushbackTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_156970<HitPushbackTrack>("priority", &HitPushbackTrack::FUN_0014d1e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("blendInTime", &HitPushbackTrack::FUN_0014d200);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_156970<HitPushbackTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_156970<HitPushbackTrack>("blendOutTime", &HitPushbackTrack::FUN_0014d220);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1140), params, 10);
    }
    DAT_004e1144++;
}

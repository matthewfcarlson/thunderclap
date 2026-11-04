// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 24/24)
// FUN_001a9800 @ 0x001a9800
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/scenario.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class EffectTrack {
public:
    void FUN_001a1f80();
    void FUN_001a1fa0();
    void FUN_001a1fb0();
    void FUN_001a1fc0();
    void FUN_001a1fe0();
    void FUN_001a1ff0();
    void FUN_001a2020();
    void FUN_001a2060();
    void FUN_001a20b0();
    void FUN_001a20c0();
    void FUN_001a20e0();
};

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList_1a9800 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1a9800(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
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
class ParamFloatConstRange_1a9800 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1a9800(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamName_1a9800 : public ParamNameBase {
public:
    ParamName_1a9800(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
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
class ParamNameConstList_1a9800 : public ParamNameConstListBase {
public:
    ParamNameConstList_1a9800(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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
class ParamVector_1a9800 : public ParamVectorBase {
public:
    ParamVector_1a9800(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001a9800()
{
    if (DAT_004e1754 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1a9800<EffectTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1a9800<EffectTrack>("timeBegin", &EffectTrack::FUN_001a1f80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1a9800<EffectTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1a9800<EffectTrack>("timeEnd", &EffectTrack::FUN_001a1fa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1a9800<EffectTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_1a9800<EffectTrack>("characterName", &EffectTrack::FUN_001a1fb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1a9800<EffectTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_1a9800<EffectTrack>("effectName", &EffectTrack::FUN_001a1fc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1a9800<EffectTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamEnumConstList_1a9800<EffectTrack>("emitSpace", ((const char**)&DAT_00495d60), (*(int*)&DAT_003fa9e8), &EffectTrack::FUN_001a1fe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_1a9800<EffectTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamNameConstList_1a9800<EffectTrack>("emitJoint", &EffectTrack::FUN_001a1ff0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_1a9800<EffectTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_1a9800<EffectTrack>("offset", &EffectTrack::FUN_001a2020);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_1a9800<EffectTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_1a9800<EffectTrack>("orientation", &EffectTrack::FUN_001a2060);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1a9800<EffectTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamEnumConstList_1a9800<EffectTrack>("attachSpace", ((const char**)&DAT_00495d50), (*(int*)&DAT_003fa9e4), &EffectTrack::FUN_001a20b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_1a9800<EffectTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamNameConstList_1a9800<EffectTrack>("attachJoint", &EffectTrack::FUN_001a20c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1a9800<EffectTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_1a9800<EffectTrack>("scale", &EffectTrack::FUN_001a20e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1750), params, 11);
    }
    DAT_004e1754++;
}

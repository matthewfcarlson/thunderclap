// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 22/22)
// FUN_00065630 @ 0x00065630
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CSmartPropSpawnTrack_65630 {
public:
    void FUN_00061dc0();
    void FUN_000626c0();
    void FUN_000127d0();
    void FUN_00061e20();
    void FUN_000127e0();
    void FUN_000127f0();
    void FUN_00061dd0();
    void FUN_00061de0();
    void FUN_00062680();
    void FUN_00061e10();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_65630 : public ParamBoolBase {
public:
    ParamBool_65630(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
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
class ParamFloatConstRange_65630 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_65630(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_65630 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_65630(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
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
class ParamName_65630 : public ParamNameBase {
public:
    ParamName_65630(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
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
class ParamNameConstList_65630 : public ParamNameConstListBase {
public:
    ParamNameConstList_65630(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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
class ParamString_65630 : public ParamStringBase {
public:
    ParamString_65630(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
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
class ParamVector_65630 : public ParamVectorBase {
public:
    ParamVector_65630(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00065630()
{
    if (DAT_004dc634 == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_65630<CSmartPropSpawnTrack_65630>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_65630<CSmartPropSpawnTrack_65630>("timeBegin", &CSmartPropSpawnTrack_65630::FUN_00061dc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_65630<CSmartPropSpawnTrack_65630>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString_65630<CSmartPropSpawnTrack_65630>("name", &CSmartPropSpawnTrack_65630::FUN_000626c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_65630<CSmartPropSpawnTrack_65630>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_65630<CSmartPropSpawnTrack_65630>("initialState", &CSmartPropSpawnTrack_65630::FUN_000127d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_65630<CSmartPropSpawnTrack_65630>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamIntConstRange_65630<CSmartPropSpawnTrack_65630>("attachmentIndex", &CSmartPropSpawnTrack_65630::FUN_00061e20);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_65630<CSmartPropSpawnTrack_65630>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamNameConstList_65630<CSmartPropSpawnTrack_65630>("joint", &CSmartPropSpawnTrack_65630::FUN_000127e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_65630<CSmartPropSpawnTrack_65630>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamNameConstList_65630<CSmartPropSpawnTrack_65630>("channel", &CSmartPropSpawnTrack_65630::FUN_000127f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_65630<CSmartPropSpawnTrack_65630>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_65630<CSmartPropSpawnTrack_65630>("useOffset", &CSmartPropSpawnTrack_65630::FUN_00061dd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_65630<CSmartPropSpawnTrack_65630>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_65630<CSmartPropSpawnTrack_65630>("offset", &CSmartPropSpawnTrack_65630::FUN_00061de0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_65630<CSmartPropSpawnTrack_65630>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_65630<CSmartPropSpawnTrack_65630>("orientation", &CSmartPropSpawnTrack_65630::FUN_00062680);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_65630<CSmartPropSpawnTrack_65630>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_65630<CSmartPropSpawnTrack_65630>("minDistance", &CSmartPropSpawnTrack_65630::FUN_00061e10);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc630), params, 10);
    }
    DAT_004dc634++;
}

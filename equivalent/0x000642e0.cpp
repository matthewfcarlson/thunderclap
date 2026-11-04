// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 22/22)
// FUN_000642e0 @ 0x000642e0
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CSmartPropThrowTrack_642e0 {
public:
    void FUN_00061e60();
    void FUN_00061e70();
    void FUN_00061e80();
    void FUN_00061ea0();
    void FUN_00061ec0();
    void FUN_00061ee0();
    void FUN_00061ef0();
    void FUN_00061f00();
    void FUN_00061f10();
    void FUN_00061f20();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_642e0 : public ParamBoolBase {
public:
    ParamBool_642e0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
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
class ParamFloatConstRange_642e0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_642e0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_642e0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_642e0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
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
class ParamVector_642e0 : public ParamVectorBase {
public:
    ParamVector_642e0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_000642e0()
{
    if (DAT_004dc64c == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("timeBegin", &CSmartPropThrowTrack_642e0::FUN_00061e60);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange_642e0<CSmartPropThrowTrack_642e0>("attachmentIndex", &CSmartPropThrowTrack_642e0::FUN_00061e70);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_642e0<CSmartPropThrowTrack_642e0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamVector_642e0<CSmartPropThrowTrack_642e0>("direction", &CSmartPropThrowTrack_642e0::FUN_00061e80);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_642e0<CSmartPropThrowTrack_642e0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_642e0<CSmartPropThrowTrack_642e0>("offset", &CSmartPropThrowTrack_642e0::FUN_00061ea0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("arc", &CSmartPropThrowTrack_642e0::FUN_00061ec0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("minDistance", &CSmartPropThrowTrack_642e0::FUN_00061ee0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("maxDistance", &CSmartPropThrowTrack_642e0::FUN_00061ef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("velocity", &CSmartPropThrowTrack_642e0::FUN_00061f00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_642e0<CSmartPropThrowTrack_642e0>("naturalDistance", &CSmartPropThrowTrack_642e0::FUN_00061f10);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_642e0<CSmartPropThrowTrack_642e0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_642e0<CSmartPropThrowTrack_642e0>("useYVelocity", &CSmartPropThrowTrack_642e0::FUN_00061f20);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc648), params, 10);
    }
    DAT_004dc64c++;
}

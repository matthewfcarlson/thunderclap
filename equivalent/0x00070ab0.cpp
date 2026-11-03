// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 26/26)
// FUN_00070ab0 @ 0x00070ab0
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CDropTrack_70ab0 {
public:
    void FUN_00068120();
    void FUN_00068130();
    void FUN_00068140();
    void FUN_00068160();
    void FUN_00068180();
    void FUN_000681a0();
    void FUN_000681b0();
    void FUN_000681c0();
    void FUN_000681d0();
    void FUN_000681e0();
    void FUN_000681f0();
    void FUN_00068200();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_70ab0 : public ParamBoolBase {
public:
    ParamBool_70ab0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
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
class ParamFloatConstRange_70ab0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_70ab0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_70ab0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_70ab0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00070ab0()
{
    if (DAT_004dcf2c == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("timeBegin", &CDropTrack_70ab0::FUN_00068120);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("timeEnd", &CDropTrack_70ab0::FUN_00068130);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("facing", &CDropTrack_70ab0::FUN_00068140);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("facingVelocity", &CDropTrack_70ab0::FUN_00068160);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("turningVelocity", &CDropTrack_70ab0::FUN_00068180);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool_70ab0<CDropTrack_70ab0>("useInitialVelocity", &CDropTrack_70ab0::FUN_000681a0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("initialVelocity", &CDropTrack_70ab0::FUN_000681b0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("gravity", &CDropTrack_70ab0::FUN_000681c0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("maxVelocity", &CDropTrack_70ab0::FUN_000681d0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamIntConstRange_70ab0<CDropTrack_70ab0>("priority", &CDropTrack_70ab0::FUN_000681e0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("rootBlendInTime", &CDropTrack_70ab0::FUN_000681f0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_70ab0<CDropTrack_70ab0>("rootBlendOutTime", &CDropTrack_70ab0::FUN_00068200);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf28), params, 12);
    }
    DAT_004dcf2c++;
}

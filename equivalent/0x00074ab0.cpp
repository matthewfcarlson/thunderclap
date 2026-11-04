// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 22/22)
// FUN_00074ab0 @ 0x00074ab0
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class CJointTrack_74ab0 {
public:
    void FUN_00067f30();
    void FUN_00067f40();
    void FUN_00011ce0();
    void FUN_00067f50();
    void FUN_00067f60();
    void FUN_00067f80();
    void FUN_00068d90();
    void FUN_00067f90();
    void FUN_00067fa0();
    void FUN_00067fb0();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_74ab0 : public ParamBoolBase {
public:
    ParamBool_74ab0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
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
class ParamFloatConstRange_74ab0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_74ab0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_74ab0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_74ab0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
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
class ParamNameConstList_74ab0 : public ParamNameConstListBase {
public:
    ParamNameConstList_74ab0(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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
class ParamVector_74ab0 : public ParamVectorBase {
public:
    ParamVector_74ab0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00074ab0()
{
    if (DAT_004dcf0c == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>("timeBegin", &CJointTrack_74ab0::FUN_00067f30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>("timeEnd", &CJointTrack_74ab0::FUN_00067f40);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_74ab0<CJointTrack_74ab0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_74ab0<CJointTrack_74ab0>("joint", &CJointTrack_74ab0::FUN_00011ce0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_74ab0<CJointTrack_74ab0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_74ab0<CJointTrack_74ab0>("hasTranslation", &CJointTrack_74ab0::FUN_00067f50);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_74ab0<CJointTrack_74ab0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_74ab0<CJointTrack_74ab0>("translation", &CJointTrack_74ab0::FUN_00067f60);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_74ab0<CJointTrack_74ab0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool_74ab0<CJointTrack_74ab0>("hasRotation", &CJointTrack_74ab0::FUN_00067f80);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_74ab0<CJointTrack_74ab0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_74ab0<CJointTrack_74ab0>("rotation", &CJointTrack_74ab0::FUN_00068d90);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_74ab0<CJointTrack_74ab0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_74ab0<CJointTrack_74ab0>("priority", &CJointTrack_74ab0::FUN_00067f90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>("blendInTime", &CJointTrack_74ab0::FUN_00067fa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_74ab0<CJointTrack_74ab0>("blendOutTime", &CJointTrack_74ab0::FUN_00067fb0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dcf08), params, 10);
    }
    DAT_004dcf0c++;
}

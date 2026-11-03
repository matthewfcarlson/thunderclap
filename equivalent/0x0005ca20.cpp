// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 30/30)
// FUN_0005ca20 @ 0x0005ca20
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class CGrappleAttachTrack_5ca20 {
public:
    void FUN_0005a120();
    void FUN_000129e0();
    void FUN_000129f0();
    void FUN_0005a130();
    void FUN_0005a140();
    void FUN_0005a160();
    void FUN_0005a180();
    void FUN_00012a60();
    void FUN_0005a1b0();
    void FUN_0005a1d0();
    void FUN_0005a1e0();
    void FUN_0005a1f0();
    void FUN_0005a200();
    void FUN_0005a210();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_5ca20 : public ParamBoolBase {
public:
    ParamBool_5ca20(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
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
class ParamFloatConstRange_5ca20 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5ca20(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_5ca20 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5ca20(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
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
class ParamNameConstList_5ca20 : public ParamNameConstListBase {
public:
    ParamNameConstList_5ca20(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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
class ParamVector_5ca20 : public ParamVectorBase {
public:
    ParamVector_5ca20(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0005ca20()
{
    if (DAT_004dc59c == 0) {
        void* params[14];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>("timeBegin", &CGrappleAttachTrack_5ca20::FUN_0005a120);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamNameConstList_5ca20<CGrappleAttachTrack_5ca20>("joint", &CGrappleAttachTrack_5ca20::FUN_000129e0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_5ca20<CGrappleAttachTrack_5ca20>("channel", &CGrappleAttachTrack_5ca20::FUN_000129f0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_5ca20<CGrappleAttachTrack_5ca20>("useOffset", &CGrappleAttachTrack_5ca20::FUN_0005a130);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_5ca20<CGrappleAttachTrack_5ca20>("offsetPosition", &CGrappleAttachTrack_5ca20::FUN_0005a140);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>("offsetOrientation", &CGrappleAttachTrack_5ca20::FUN_0005a160);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_5ca20<CGrappleAttachTrack_5ca20>("offsetAngle", &CGrappleAttachTrack_5ca20::FUN_0005a180);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamNameConstList_5ca20<CGrappleAttachTrack_5ca20>("orientJoint", &CGrappleAttachTrack_5ca20::FUN_00012a60);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_5ca20<CGrappleAttachTrack_5ca20>("orientJointOffset", &CGrappleAttachTrack_5ca20::FUN_0005a1b0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>("orientJointMinDistance", &CGrappleAttachTrack_5ca20::FUN_0005a1d0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>("orientJointMaxDistance", &CGrappleAttachTrack_5ca20::FUN_0005a1e0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamBool_5ca20<CGrappleAttachTrack_5ca20>("attachToGrapplee", &CGrappleAttachTrack_5ca20::FUN_0005a1f0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange_5ca20<CGrappleAttachTrack_5ca20>("rootPriority", &CGrappleAttachTrack_5ca20::FUN_0005a200);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_5ca20<CGrappleAttachTrack_5ca20>("rootBlendInTime", &CGrappleAttachTrack_5ca20::FUN_0005a210);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc598), params, 14);
    }
    DAT_004dc59c++;
}

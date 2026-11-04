// STATUS: equivalent (tools/equiv.py level 3: 1986 inputs, branch coverage 50/50)
// FUN_0018a340 @ 0x0018a340
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PropThrowTrack_18a340 {
public:
    void FUN_0017f900();
    void FUN_0017f910();
    void FUN_0017f930();
    void FUN_0017f950();
    void FUN_0017f980();
    void FUN_0017f9b0();
    void FUN_0017f9d0();
    void FUN_0017f9f0();
    void FUN_0017fa10();
    void FUN_0017fa30();
    void FUN_0017fa60();
    void FUN_0017fa90();
    void FUN_0017fac0();
    void FUN_0017faf0();
    void FUN_0017fb10();
    void FUN_0017fb30();
    void FUN_0017fb60();
    void FUN_0017fb80();
    void FUN_0017fba0();
    void FUN_0017fbc0();
    void FUN_0017fbe0();
    void FUN_0017fbf0();
    void FUN_0017fc00();
    void FUN_0017fc20();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamBool_18a340 : public ParamBoolBase {
public:
    ParamBool_18a340(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBranch_18a340 : public ParamBranchBase {
public:
    ParamBranch_18a340(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange_18a340 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18a340(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_18a340 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18a340(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_18a340 : public ParamNameBase {
public:
    ParamName_18a340(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_18a340 : public ParamVectorBase {
public:
    ParamVector_18a340(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0018a340()
{
    if (DAT_004e149c == 0) {
        void* params[24];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("timeBegin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f900);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("timeEnd", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f910);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("attachmentIndex", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f930);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_18a340<hulkfight::motion::PropThrowTrack_18a340>("useCameraDirection", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f950);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_18a340<hulkfight::motion::PropThrowTrack_18a340>("direction", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f980);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("distanceMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f9b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("distanceMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f9d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("velocityMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017f9f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("velocityMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fa10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("spinMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fa30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("spinMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fa60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("trackingMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fa90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("trackingMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fac0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("bounceMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017faf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("bounceMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fb10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("yFixupAngle", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fb30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("forceMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fb60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("forceMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fb80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("damageMin", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fba0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("damageMax", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fbc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamIntConstRange_18a340<hulkfight::motion::PropThrowTrack_18a340>("interruptPriority", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fbe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamBranch_18a340<hulkfight::motion::PropThrowTrack_18a340>("hitBranch", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fbf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamName_18a340<hulkfight::motion::PropThrowTrack_18a340>("hitEffect", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fc00);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_18a340<hulkfight::motion::PropThrowTrack_18a340>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamBool_18a340<hulkfight::motion::PropThrowTrack_18a340>("clearCharge", &hulkfight::motion::PropThrowTrack_18a340::FUN_0017fc20);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1498), params, 24);
    }
    DAT_004e149c++;
}

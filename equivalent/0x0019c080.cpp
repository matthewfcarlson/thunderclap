// STATUS: equivalent (tools/equiv.py level 3: 1655 inputs, branch coverage 60/60)
// FUN_0019c080 @ 0x0019c080
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class FireProjectileTrack_19c080 {
public:
    void FUN_00192190();
    void FUN_001921a0();
    void FUN_001921b0();
    void FUN_001921e0();
    void FUN_00192210();
    void FUN_00192230();
    void FUN_00192240();
    void FUN_00192270();
    void FUN_001922b0();
    void FUN_001922e0();
    void FUN_00192310();
    void FUN_00192330();
    void FUN_00192350();
    void FUN_00192370();
    void FUN_001923a0();
    void FUN_001923c0();
    void FUN_001923f0();
    void FUN_00192400();
    void FUN_00192410();
    void FUN_00192430();
    void FUN_00192450();
    void FUN_00192470();
    void FUN_00192480();
    void FUN_001924c0();
    void FUN_001924f0();
    void FUN_00192500();
    void FUN_00192520();
    void FUN_00192540();
    void FUN_00192560();
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
class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
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
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
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
class ParamBool_19c080 : public ParamBoolBase {
public:
    ParamBool_19c080(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBranch_19c080 : public ParamBranchBase {
public:
    ParamBranch_19c080(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_19c080 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_19c080(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_19c080 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_19c080(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_19c080 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_19c080(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_19c080 : public ParamNameBase {
public:
    ParamName_19c080(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList_19c080 : public ParamNameConstListBase {
public:
    ParamNameConstList_19c080(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_19c080 : public ParamVectorBase {
public:
    ParamVector_19c080(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0019c080()
{
    if (DAT_004e155c == 0) {
        void* params[29];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("timeBegin", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192190);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("timeEnd", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001921a0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_19c080<hulkfight::motion::FireProjectileTrack_19c080>("effect", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001921b0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>("effectAxis", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001921e0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("rateOfFire", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192210);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("originAttachment", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192230);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamNameConstList_19c080<hulkfight::motion::FireProjectileTrack_19c080>("originJoint", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192240);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>("originOffset", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192270);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>("direction", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001922b0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("spread", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001922e0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("initVelocity", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192310);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("maxVelocity", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192330);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("acceleration", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192350);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("targetArc", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192370);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("targetDistance", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001923a0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("tracking", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001923c0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool_19c080<hulkfight::motion::FireProjectileTrack_19c080>("trackInitLockon", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001923f0);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamBool_19c080<hulkfight::motion::FireProjectileTrack_19c080>("usesFirstShotFailureOnTracking", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192400);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamBool_19c080<hulkfight::motion::FireProjectileTrack_19c080>("ifFirstShotFailureUsesInitLockon", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192410);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("lifeTime", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192430);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamIntConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("projectilePriority", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192450);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamIntConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("interruptPriority", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192470);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamName_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitEffect", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192480);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamVector_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitEffectAxis", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001924c0);
        mem = FUN_0008d690(0x18);
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamBranch_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitBranch", &hulkfight::motion::FireProjectileTrack_19c080::FUN_001924f0);
        mem = FUN_0008d690(0x18);
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamBranch_19c080<hulkfight::motion::FireProjectileTrack_19c080>("giverBranch", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192500);
        mem = FUN_0008d690(0x18);
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitPropDamage", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192520);
        mem = FUN_0008d690(0x18);
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamFloatConstRange_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitPropForce", &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192540);
        mem = FUN_0008d690(0x20);
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamEnumConstList_19c080<hulkfight::motion::FireProjectileTrack_19c080>("hitDamageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), &hulkfight::motion::FireProjectileTrack_19c080::FUN_00192560);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1558), params, 29);
    }
    DAT_004e155c++;
}

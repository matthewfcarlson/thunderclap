// STATUS: equivalent (tools/equiv.py level 3: 918 inputs, branch coverage 120/120)
// FUN_0019d160 @ 0x0019d160
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class FireMissileTrack_19d160 {
public:
    void FUN_00192f80();
    void FUN_00192f90();
    void FUN_00192fa0();
    void FUN_00192fb0();
    void FUN_00192fe0();
    void FUN_00193010();
    void FUN_00193020();
    void FUN_00193050();
    void FUN_00193090();
    void FUN_001930c0();
    void FUN_001930e0();
    void FUN_00193100();
    void FUN_00193120();
    void FUN_00193140();
    void FUN_00193170();
    void FUN_00193190();
    void FUN_001931c0();
    void FUN_001931e0();
    void FUN_00193200();
    void FUN_00193220();
    void FUN_00193240();
    void FUN_00193260();
    void FUN_00193280();
    void FUN_001932b0();
    void FUN_001932e0();
    void FUN_00193300();
    void FUN_00193320();
    void FUN_00193340();
    void FUN_00193360();
    void FUN_00193380();
    void FUN_001933a0();
    void FUN_001933c0();
    void FUN_001933f0();
    void FUN_00193410();
    void FUN_00193430();
    void FUN_00193450();
    void FUN_00193480();
    void FUN_001934a0();
    void FUN_001934c0();
    void FUN_001934d0();
    void FUN_001934e0();
    void FUN_00193500();
    void FUN_00193520();
    void FUN_00194510();
    void FUN_00193550();
    void FUN_00193560();
    void FUN_001935a0();
    void FUN_001935e0();
    void FUN_001935f0();
    void FUN_00193610();
    void FUN_00193630();
    void FUN_00193650();
    void FUN_00193690();
    void FUN_001936d0();
    void FUN_001936e0();
    void FUN_00193720();
    void FUN_00193760();
    void FUN_00193780();
    void FUN_001937a0();
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
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
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
class ParamBool_19d160 : public ParamBoolBase {
public:
    ParamBool_19d160(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBranch_19d160 : public ParamBranchBase {
public:
    ParamBranch_19d160(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_19d160 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_19d160(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_19d160 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_19d160(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_19d160 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_19d160(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_19d160 : public ParamNameBase {
public:
    ParamName_19d160(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList_19d160 : public ParamNameConstListBase {
public:
    ParamNameConstList_19d160(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamString_19d160 : public ParamStringBase {
public:
    ParamString_19d160(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_19d160 : public ParamVectorBase {
public:
    ParamVector_19d160(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0019d160()
{
    if (DAT_004e1584 == 0) {
        void* params[59];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("timeBegin", &hulkfight::motion::FireMissileTrack_19d160::FUN_00192f80);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>("propName", &hulkfight::motion::FireMissileTrack_19d160::FUN_00192f90);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>("propInitState", &hulkfight::motion::FireMissileTrack_19d160::FUN_00192fa0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>("propHitState", &hulkfight::motion::FireMissileTrack_19d160::FUN_00192fb0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("propAxis", &hulkfight::motion::FireMissileTrack_19d160::FUN_00192fe0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("originAttachment", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193010);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamNameConstList_19d160<hulkfight::motion::FireMissileTrack_19d160>("originJoint", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193020);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("originOffset", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193050);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("direction", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193090);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("inheritVelocityFromCharacter", &hulkfight::motion::FireMissileTrack_19d160::FUN_001930c0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("initVelocity", &hulkfight::motion::FireMissileTrack_19d160::FUN_001930e0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("maxVelocity", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193100);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("acceleration", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193120);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("targetArc", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193140);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("targetDistance", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193170);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("tracking", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193190);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("trackInitLockon", &hulkfight::motion::FireMissileTrack_19d160::FUN_001931c0);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("usesFirstShotFailureOnTracking", &hulkfight::motion::FireMissileTrack_19d160::FUN_001931e0);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("ifFirstShotFailureUsesInitLockon", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193200);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("sway", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193220);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayTimeBegin", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193240);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayTimeDuration", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193260);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAngle", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193280);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAnglePerFrameReduction", &hulkfight::motion::FireMissileTrack_19d160::FUN_001932b0);
        mem = FUN_0008d690(0x18);
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayResetTime", &hulkfight::motion::FireMissileTrack_19d160::FUN_001932e0);
        mem = FUN_0008d690(0x18);
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayResetTimeScaler", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193300);
        mem = FUN_0008d690(0x18);
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swaySideStart", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193320);
        mem = FUN_0008d690(0x18);
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("swaySideStartRandom", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193340);
        mem = FUN_0008d690(0x18);
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("swaySideSkipZero", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193360);
        mem = FUN_0008d690(0x18);
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamBool_19d160<hulkfight::motion::FireMissileTrack_19d160>("swaySideNextRandom", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193380);
        mem = FUN_0008d690(0x18);
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayThresholdDistance", &hulkfight::motion::FireMissileTrack_19d160::FUN_001933a0);
        mem = FUN_0008d690(0x18);
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAfterDurationTracking", &hulkfight::motion::FireMissileTrack_19d160::FUN_001933c0);
        mem = FUN_0008d690(0x18);
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAfterDurationTrackingTime", &hulkfight::motion::FireMissileTrack_19d160::FUN_001933f0);
        mem = FUN_0008d690(0x18);
        params[33] = 0;
        if (mem)
            params[33] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAfterThresholdTracking", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193410);
        mem = FUN_0008d690(0x18);
        params[34] = 0;
        if (mem)
            params[34] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayAfterThresholdTrackingTime", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193430);
        mem = FUN_0008d690(0x18);
        params[35] = 0;
        if (mem)
            params[35] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("swayDuringSwayTracking", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193450);
        mem = FUN_0008d690(0x18);
        params[36] = 0;
        if (mem)
            params[36] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("lifeTime", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193480);
        mem = FUN_0008d690(0x18);
        params[37] = 0;
        if (mem)
            params[37] = new (mem) fight::ParamIntConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("projectilePriority", &hulkfight::motion::FireMissileTrack_19d160::FUN_001934a0);
        mem = FUN_0008d690(0x18);
        params[38] = 0;
        if (mem)
            params[38] = new (mem) fight::ParamIntConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("interruptPriority", &hulkfight::motion::FireMissileTrack_19d160::FUN_001934c0);
        mem = FUN_0008d690(0x18);
        params[39] = 0;
        if (mem)
            params[39] = new (mem) fight::ParamBranch_19d160<hulkfight::motion::FireMissileTrack_19d160>("hitBranch", &hulkfight::motion::FireMissileTrack_19d160::FUN_001934d0);
        mem = FUN_0008d690(0x18);
        params[40] = 0;
        if (mem)
            params[40] = new (mem) fight::ParamBranch_19d160<hulkfight::motion::FireMissileTrack_19d160>("giverBranch", &hulkfight::motion::FireMissileTrack_19d160::FUN_001934e0);
        mem = FUN_0008d690(0x18);
        params[41] = 0;
        if (mem)
            params[41] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("hitPropDamage", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193500);
        mem = FUN_0008d690(0x18);
        params[42] = 0;
        if (mem)
            params[42] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("hitPropForce", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193520);
        mem = FUN_0008d690(0x18);
        params[43] = 0;
        if (mem)
            params[43] = new (mem) fight::ParamString_19d160<hulkfight::motion::FireMissileTrack_19d160>("hitPropSound", &hulkfight::motion::FireMissileTrack_19d160::FUN_00194510);
        mem = FUN_0008d690(0x20);
        params[44] = 0;
        if (mem)
            params[44] = new (mem) fight::ParamEnumConstList_19d160<hulkfight::motion::FireMissileTrack_19d160>("hitDamageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), &hulkfight::motion::FireMissileTrack_19d160::FUN_00193550);
        mem = FUN_0008d690(0x18);
        params[45] = 0;
        if (mem)
            params[45] = new (mem) fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionEffect", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193560);
        mem = FUN_0008d690(0x18);
        params[46] = 0;
        if (mem)
            params[46] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionEffectAxis", &hulkfight::motion::FireMissileTrack_19d160::FUN_001935a0);
        mem = FUN_0008d690(0x18);
        params[47] = 0;
        if (mem)
            params[47] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionRadius", &hulkfight::motion::FireMissileTrack_19d160::FUN_001935e0);
        mem = FUN_0008d690(0x18);
        params[48] = 0;
        if (mem)
            params[48] = new (mem) fight::ParamBranch_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionHitBranch", &hulkfight::motion::FireMissileTrack_19d160::FUN_001935f0);
        mem = FUN_0008d690(0x18);
        params[49] = 0;
        if (mem)
            params[49] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionHitPropDamage", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193610);
        mem = FUN_0008d690(0x18);
        params[50] = 0;
        if (mem)
            params[50] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("explosionHitPropForce", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193630);
        mem = FUN_0008d690(0x18);
        params[51] = 0;
        if (mem)
            params[51] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailWidth", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193650);
        mem = FUN_0008d690(0x18);
        params[52] = 0;
        if (mem)
            params[52] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailOffset", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193690);
        mem = FUN_0008d690(0x18);
        params[53] = 0;
        if (mem)
            params[53] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailFadeOutTime", &hulkfight::motion::FireMissileTrack_19d160::FUN_001936d0);
        mem = FUN_0008d690(0x18);
        params[54] = 0;
        if (mem)
            params[54] = new (mem) fight::ParamName_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailShader", &hulkfight::motion::FireMissileTrack_19d160::FUN_001936e0);
        mem = FUN_0008d690(0x18);
        params[55] = 0;
        if (mem)
            params[55] = new (mem) fight::ParamVector_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailShrinkOffset", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193720);
        mem = FUN_0008d690(0x18);
        params[56] = 0;
        if (mem)
            params[56] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailShrinkTime", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193760);
        mem = FUN_0008d690(0x18);
        params[57] = 0;
        if (mem)
            params[57] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailFadeTime", &hulkfight::motion::FireMissileTrack_19d160::FUN_00193780);
        mem = FUN_0008d690(0x18);
        params[58] = 0;
        if (mem)
            params[58] = new (mem) fight::ParamFloatConstRange_19d160<hulkfight::motion::FireMissileTrack_19d160>("motionTrailTextureTime", &hulkfight::motion::FireMissileTrack_19d160::FUN_001937a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1580), params, 59);
    }
    DAT_004e1584++;
}

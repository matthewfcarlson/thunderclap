// STATUS: equivalent (tools/equiv.py level 3: 1295 inputs, branch coverage 94/94)
// FUN_0019c750 @ 0x0019c750
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight { namespace motion {
class FireBeamTrack {
public:
    void FUN_00192830();
    void FUN_00192840();
    void FUN_00192850();
    void FUN_00192860();
    void FUN_00192890();
    void FUN_001928a0();
    void FUN_001928d0();
    void FUN_00192910();
    void FUN_00192940();
    void FUN_00192960();
    void FUN_00192990();
    void FUN_001929b0();
    void FUN_001929e0();
    void FUN_00192a00();
    void FUN_00192a20();
    void FUN_00192a30();
    void FUN_00192a60();
    void FUN_00192a80();
    void FUN_00192aa0();
    void FUN_00192ac0();
    void FUN_00192ae0();
    void FUN_00192b00();
    void FUN_00192b20();
    void FUN_00192b40();
    void FUN_00192b60();
    void FUN_00192b80();
    void FUN_00192b90();
    void FUN_00192ba0();
    void FUN_00192be0();
    void FUN_00192c40();
    void FUN_00192ca0();
    void FUN_00192ce0();
    void FUN_00192d00();
    void FUN_00192d20();
    void FUN_00192d50();
    void FUN_00192d70();
    void FUN_00192d90();
    void FUN_00192db0();
    void FUN_00192df0();
    void FUN_00192e50();
    void FUN_00192e90();
    void FUN_00192ed0();
    void FUN_00192f10();
    void FUN_00192f30();
    void FUN_00192f50();
    void FUN_00192f70();
};
} }

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00235170(const char* name);
    ParamBranchBase(const char* name) { FUN_00235170(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
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
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBranch : public ParamBranchBase {
public:
    ParamBranch(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
using namespace fight;
struct ParamRegistry {
};
extern ParamRegistry DAT_004e1578;
extern int DAT_004e157c;
extern const char* DAT_004ad788[8];
extern int DAT_00412ed4;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0019c750()
{
    if (DAT_004e157c == 0) {
        void* params[46];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("timeBegin", &hulkfight::motion::FireBeamTrack::FUN_00192830);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("timeEnd", &hulkfight::motion::FireBeamTrack::FUN_00192840);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName<hulkfight::motion::FireBeamTrack>("effect", &hulkfight::motion::FireBeamTrack::FUN_00192850);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector<hulkfight::motion::FireBeamTrack>("effectAxis", &hulkfight::motion::FireBeamTrack::FUN_00192860);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>("originAttachment", &hulkfight::motion::FireBeamTrack::FUN_00192890);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamNameConstList<hulkfight::motion::FireBeamTrack>("originJoint", &hulkfight::motion::FireBeamTrack::FUN_001928a0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector<hulkfight::motion::FireBeamTrack>("originOffset", &hulkfight::motion::FireBeamTrack::FUN_001928d0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector<hulkfight::motion::FireBeamTrack>("direction", &hulkfight::motion::FireBeamTrack::FUN_00192910);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("maxLength", &hulkfight::motion::FireBeamTrack::FUN_00192940);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("targetArc", &hulkfight::motion::FireBeamTrack::FUN_00192960);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("targetDistance", &hulkfight::motion::FireBeamTrack::FUN_00192990);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("tracking", &hulkfight::motion::FireBeamTrack::FUN_001929b0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamBool<hulkfight::motion::FireBeamTrack>("trackInitLockon", &hulkfight::motion::FireBeamTrack::FUN_001929e0);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("lifeTime", &hulkfight::motion::FireBeamTrack::FUN_00192a00);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>("interruptPriority", &hulkfight::motion::FireBeamTrack::FUN_00192a20);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamName<hulkfight::motion::FireBeamTrack>("hitEffect", &hulkfight::motion::FireBeamTrack::FUN_00192a30);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamVector<hulkfight::motion::FireBeamTrack>("hitEffectAxis", &hulkfight::motion::FireBeamTrack::FUN_00192a60);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamBranch<hulkfight::motion::FireBeamTrack>("hitBranch", &hulkfight::motion::FireBeamTrack::FUN_00192a80);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("hitPropDamage", &hulkfight::motion::FireBeamTrack::FUN_00192aa0);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("hitDamage", &hulkfight::motion::FireBeamTrack::FUN_00192ac0);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("hitSameAlignmentDamageFactor", &hulkfight::motion::FireBeamTrack::FUN_00192ae0);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamBool<hulkfight::motion::FireBeamTrack>("hitBranchOnlyOnSameAlignment", &hulkfight::motion::FireBeamTrack::FUN_00192b00);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("hitPropForce", &hulkfight::motion::FireBeamTrack::FUN_00192b20);
        mem = FUN_0008d690(0x20);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>("hitDamageType", DAT_004ad788, DAT_00412ed4, &hulkfight::motion::FireBeamTrack::FUN_00192b40);
        mem = FUN_0008d690(0x18);
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("hitTraceWidth", &hulkfight::motion::FireBeamTrack::FUN_00192b60);
        mem = FUN_0008d690(0x18);
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamBool<hulkfight::motion::FireBeamTrack>("ignoreCollisionOnSameAlignment", &hulkfight::motion::FireBeamTrack::FUN_00192b80);
        mem = FUN_0008d690(0x18);
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamBranch<hulkfight::motion::FireBeamTrack>("giverBranch", &hulkfight::motion::FireBeamTrack::FUN_00192b90);
        mem = FUN_0008d690(0x18);
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamName<hulkfight::motion::FireBeamTrack>("propName", &hulkfight::motion::FireBeamTrack::FUN_00192ba0);
        mem = FUN_0008d690(0x18);
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamVector<hulkfight::motion::FireBeamTrack>("initialAbsoluteOffset", &hulkfight::motion::FireBeamTrack::FUN_00192be0);
        mem = FUN_0008d690(0x18);
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamVector<hulkfight::motion::FireBeamTrack>("initialRandomOffset", &hulkfight::motion::FireBeamTrack::FUN_00192c40);
        mem = FUN_0008d690(0x18);
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamVector<hulkfight::motion::FireBeamTrack>("initialRelativeOffset", &hulkfight::motion::FireBeamTrack::FUN_00192ca0);
        mem = FUN_0008d690(0x18);
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("initialPositionScaler", &hulkfight::motion::FireBeamTrack::FUN_00192ce0);
        mem = FUN_0008d690(0x18);
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamBool<hulkfight::motion::FireBeamTrack>("catchUpUseSweep", &hulkfight::motion::FireBeamTrack::FUN_00192d00);
        mem = FUN_0008d690(0x18);
        params[33] = 0;
        if (mem)
            params[33] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("catchUpSweepAngle", &hulkfight::motion::FireBeamTrack::FUN_00192d20);
        mem = FUN_0008d690(0x18);
        params[34] = 0;
        if (mem)
            params[34] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("catchUpSweepAngleDirection", &hulkfight::motion::FireBeamTrack::FUN_00192d50);
        mem = FUN_0008d690(0x18);
        params[35] = 0;
        if (mem)
            params[35] = new (mem) fight::ParamBool<hulkfight::motion::FireBeamTrack>("catchUpSweepAngleRandomDirection", &hulkfight::motion::FireBeamTrack::FUN_00192d70);
        mem = FUN_0008d690(0x18);
        params[36] = 0;
        if (mem)
            params[36] = new (mem) fight::ParamBool<hulkfight::motion::FireBeamTrack>("catchUpHulkDynamic", &hulkfight::motion::FireBeamTrack::FUN_00192d90);
        mem = FUN_0008d690(0x18);
        params[37] = 0;
        if (mem)
            params[37] = new (mem) fight::ParamBool<hulkfight::motion::FireBeamTrack>("catchUpHulkVelocity", &hulkfight::motion::FireBeamTrack::FUN_00192db0);
        mem = FUN_0008d690(0x18);
        params[38] = 0;
        if (mem)
            params[38] = new (mem) fight::ParamVector<hulkfight::motion::FireBeamTrack>("catchUpAbsoluteOffset", &hulkfight::motion::FireBeamTrack::FUN_00192df0);
        mem = FUN_0008d690(0x18);
        params[39] = 0;
        if (mem)
            params[39] = new (mem) fight::ParamVector<hulkfight::motion::FireBeamTrack>("catchUpRandomOffset", &hulkfight::motion::FireBeamTrack::FUN_00192e50);
        mem = FUN_0008d690(0x18);
        params[40] = 0;
        if (mem)
            params[40] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("catchUpDistanceScaler", &hulkfight::motion::FireBeamTrack::FUN_00192e90);
        mem = FUN_0008d690(0x18);
        params[41] = 0;
        if (mem)
            params[41] = new (mem) fight::ParamVector<hulkfight::motion::FireBeamTrack>("catchUpRelativeOffset", &hulkfight::motion::FireBeamTrack::FUN_00192ed0);
        mem = FUN_0008d690(0x18);
        params[42] = 0;
        if (mem)
            params[42] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("catchUpIncrementScaler", &hulkfight::motion::FireBeamTrack::FUN_00192f10);
        mem = FUN_0008d690(0x18);
        params[43] = 0;
        if (mem)
            params[43] = new (mem) fight::ParamBool<hulkfight::motion::FireBeamTrack>("catchUpByEndOfTrack", &hulkfight::motion::FireBeamTrack::FUN_00192f30);
        mem = FUN_0008d690(0x18);
        params[44] = 0;
        if (mem)
            params[44] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("catchUpMultiplier", &hulkfight::motion::FireBeamTrack::FUN_00192f50);
        mem = FUN_0008d690(0x18);
        params[45] = 0;
        if (mem)
            params[45] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>("catchUpPercentage", &hulkfight::motion::FireBeamTrack::FUN_00192f70);
        FUN_002347b0(&DAT_004e1578, params, 46);
    }
    DAT_004e157c++;
}

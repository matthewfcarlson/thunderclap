// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0019c050..0x0019e430 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x0019c750 FUN_0019c750 (2518 B): equivalent/0x0019c750.cpp [isolated: using-directive; on include/gen/ and not mergeable]
// sym: ?FUN_0019c750@@YAXXZ @c08ae614b1c3 @w40591ae8b465
// STATUS: equivalent (tools/equiv.py level 3: 1295 inputs, branch coverage 94/94)
// FUN_0019c750 @ 0x0019c750
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(size_t, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight { namespace motion {
class FireBeamTrack_19c750 {
public:
    bool FUN_00192830(int); /* (unb4) as defined; address taken only */
    bool FUN_00192840(int); /* (unb4) as defined; address taken only */
    void FUN_00192850();
    char FUN_00192860(void*); /* (unb4) as defined; address taken only */
    bool FUN_00192890(int); /* (unb4) as defined; address taken only */
    void FUN_001928a0();
    char FUN_001928d0(void*); /* (unb4) as defined; address taken only */
    char FUN_00192910(void*); /* (unb4) as defined; address taken only */
    char FUN_00192940(int); /* (unb4) as defined; address taken only */
    char FUN_00192960(float); /* (unb4) as defined; address taken only */
    bool FUN_00192990(int); /* (unb4) as defined; address taken only */
    char FUN_001929b0(float); /* (unb4) as defined; address taken only */
    bool FUN_001929e0(char); /* (unb4) as defined; address taken only */
    bool FUN_00192a00(int); /* (unb4) as defined; address taken only */
    bool FUN_00192a20(int); /* (unb4) as defined; address taken only */
    void FUN_00192a30();
    bool FUN_00192a60(void*); /* (unb4) as defined; address taken only */
    void FUN_00192a80();
    char FUN_00192aa0(int); /* (unb4) as defined; address taken only */
    bool FUN_00192ac0(int); /* (unb4) as defined; address taken only */
    bool FUN_00192ae0(int); /* (unb4) as defined; address taken only */
    char FUN_00192b00(char); /* (unb4) as defined; address taken only */
    char FUN_00192b20(int); /* (unb4) as defined; address taken only */
    char FUN_00192b40(int); /* (unb4) as defined; address taken only */
    char FUN_00192b60(int); /* (unb4) as defined; address taken only */
    char FUN_00192b80(char); /* (unb4) as defined; address taken only */
    void FUN_00192b90();
    void FUN_00192ba0();
    bool FUN_00192be0(void*); /* (unb4) as defined; address taken only */
    bool FUN_00192c40(void*); /* (unb4) as defined; address taken only */
    bool FUN_00192ca0(void*); /* (unb4) as defined; address taken only */
    bool FUN_00192ce0(int); /* (unb4) as defined; address taken only */
    char FUN_00192d00(char); /* (unb4) as defined; address taken only */
    bool FUN_00192d20(float); /* (unb4) as defined; address taken only */
    char FUN_00192d50(int); /* (unb4) as defined; address taken only */
    char FUN_00192d70(char); /* (unb4) as defined; address taken only */
    char FUN_00192d90(char); /* (unb4) as defined; address taken only */
    char FUN_00192db0(char); /* (unb4) as defined; address taken only */
    char FUN_00192df0(void*); /* (unb4) as defined; address taken only */
    bool FUN_00192e50(void*); /* (unb4) as defined; address taken only */
    bool FUN_00192e90(int); /* (unb4) as defined; address taken only */
    bool FUN_00192ed0(void*); /* (unb4) as defined; address taken only */
    char FUN_00192f10(int); /* (unb4) as defined; address taken only */
    char FUN_00192f30(char); /* (unb4) as defined; address taken only */
    bool FUN_00192f50(int); /* (unb4) as defined; address taken only */
    bool FUN_00192f70(int); /* (unb4) as defined; address taken only */
};
} }

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
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
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
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
class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_19c750 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_19c750(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_19c750 : public ParamVectorBase {
public:
    ParamVector_19c750(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_19c750 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_19c750(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBool_19c750 : public ParamBoolBase {
public:
    ParamBool_19c750(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBranch_19c750 : public ParamBranchBase {
public:
    ParamBranch_19c750(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_19c750 : public ParamNameBase {
public:
    ParamName_19c750(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList_19c750 : public ParamNameConstListBase {
public:
    ParamNameConstList_19c750(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_19c750 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_19c750(const char* name, const char** n, int c, void (T::*s)())
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
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0019c750()
{
    if (DAT_004e157c == 0) {
        void* params[46];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("timeBegin", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192830);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("timeEnd", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192840);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_19c750<hulkfight::motion::FireBeamTrack_19c750>("effect", &hulkfight::motion::FireBeamTrack_19c750::FUN_00192850);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>("effectAxis", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192860);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamIntConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("originAttachment", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192890);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamNameConstList_19c750<hulkfight::motion::FireBeamTrack_19c750>("originJoint", &hulkfight::motion::FireBeamTrack_19c750::FUN_001928a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>("originOffset", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_001928d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>("direction", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192910);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("maxLength", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192940);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("targetArc", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192960);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("targetDistance", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192990);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("tracking", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_001929b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>("trackInitLockon", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_001929e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("lifeTime", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192a00);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamIntConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("interruptPriority", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192a20);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamName_19c750<hulkfight::motion::FireBeamTrack_19c750>("hitEffect", &hulkfight::motion::FireBeamTrack_19c750::FUN_00192a30);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>("hitEffectAxis", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192a60);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamBranch_19c750<hulkfight::motion::FireBeamTrack_19c750>("hitBranch", &hulkfight::motion::FireBeamTrack_19c750::FUN_00192a80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("hitPropDamage", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192aa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("hitDamage", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192ac0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("hitSameAlignmentDamageFactor", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192ae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>("hitBranchOnlyOnSameAlignment", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192b00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("hitPropForce", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192b20);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamEnumConstList_19c750<hulkfight::motion::FireBeamTrack_19c750>("hitDamageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192b40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("hitTraceWidth", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192b60);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>("ignoreCollisionOnSameAlignment", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192b80);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamBranch_19c750<hulkfight::motion::FireBeamTrack_19c750>("giverBranch", &hulkfight::motion::FireBeamTrack_19c750::FUN_00192b90);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamName_19c750<hulkfight::motion::FireBeamTrack_19c750>("propName", &hulkfight::motion::FireBeamTrack_19c750::FUN_00192ba0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>("initialAbsoluteOffset", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192be0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>("initialRandomOffset", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192c40);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>("initialRelativeOffset", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192ca0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("initialPositionScaler", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192ce0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpUseSweep", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192d00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[33] = 0;
        if (mem)
            params[33] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpSweepAngle", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192d20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[34] = 0;
        if (mem)
            params[34] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpSweepAngleDirection", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192d50);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[35] = 0;
        if (mem)
            params[35] = new (mem) fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpSweepAngleRandomDirection", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192d70);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[36] = 0;
        if (mem)
            params[36] = new (mem) fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpHulkDynamic", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192d90);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[37] = 0;
        if (mem)
            params[37] = new (mem) fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpHulkVelocity", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192db0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[38] = 0;
        if (mem)
            params[38] = new (mem) fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpAbsoluteOffset", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192df0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[39] = 0;
        if (mem)
            params[39] = new (mem) fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpRandomOffset", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192e50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[40] = 0;
        if (mem)
            params[40] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpDistanceScaler", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192e90);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[41] = 0;
        if (mem)
            params[41] = new (mem) fight::ParamVector_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpRelativeOffset", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192ed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[42] = 0;
        if (mem)
            params[42] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpIncrementScaler", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192f10);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[43] = 0;
        if (mem)
            params[43] = new (mem) fight::ParamBool_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpByEndOfTrack", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192f30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[44] = 0;
        if (mem)
            params[44] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpMultiplier", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192f50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>));
        params[45] = 0;
        if (mem)
            params[45] = new (mem) fight::ParamFloatConstRange_19c750<hulkfight::motion::FireBeamTrack_19c750>("catchUpPercentage", (void (hulkfight::motion::FireBeamTrack_19c750::*)())&hulkfight::motion::FireBeamTrack_19c750::FUN_00192f70);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1578), params, 46);
    }
    DAT_004e157c++;
}


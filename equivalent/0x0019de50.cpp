// STATUS: equivalent (tools/equiv.py level 3: 1980 inputs, branch coverage 54/54)
// FUN_0019de50 @ 0x0019de50
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class FireGroundShockwaveTrack_19de50 {
public:
    void FUN_001937b0();
    void FUN_001937e0();
    void FUN_00193820();
    void FUN_00193850();
    void FUN_00193870();
    void FUN_00193890();
    void FUN_001938b0();
    void FUN_001938d0();
    void FUN_001938f0();
    void FUN_00193900();
    void FUN_00193930();
    void FUN_00193960();
    void FUN_00193980();
    void FUN_001939a0();
    void FUN_001939c0();
    void FUN_001939e0();
    void FUN_00193a00();
    void FUN_00193a30();
    void FUN_00193a50();
    void FUN_00193a70();
    void FUN_00193a90();
    void FUN_00193ab0();
    void FUN_00193af0();
    void FUN_00193b50();
    void FUN_00193b80();
    void FUN_00193b90();
};
}
}

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
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamBranch_19de50 : public ParamBranchBase {
public:
    ParamBranch_19de50(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_19de50 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_19de50(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_19de50 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_19de50(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_19de50 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_19de50(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_19de50 : public ParamNameBase {
public:
    ParamName_19de50(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_19de50 : public ParamVectorBase {
public:
    ParamVector_19de50(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0019de50()
{
    if ((*(int*)&DAT_004e158c) == 0) {
        void* params[26];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("timeBegin", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001937b0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("origin", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001937e0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("direction", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193820);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("distance", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193850);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("lifeTime", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193870);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("projectilePriority", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193890);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("radius", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001938b0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("maxAffectedHeight", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001938d0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("maxYChange", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001938f0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("effect", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193900);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("effectAxis", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193930);
        mem = FUN_0008d690(0x20);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamEnumConstList_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("decalDamageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193960);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("decalScale", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193980);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("decalDistance", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001939a0);
        mem = FUN_0008d690(0x20);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamEnumConstList_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("coneDamageType", ((const char**)&DAT_004ad788), (*(int*)&DAT_00412ed4), &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001939c0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("coneRadius", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_001939e0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("coneArc", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193a00);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamIntConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("coneDecalCount", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193a30);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("coneDecalScale", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193a50);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamIntConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("interruptPriority", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193a70);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("damage", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193a90);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("damageMax", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193ab0);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("force", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193af0);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamVector_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("forceMax", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193b50);
        mem = FUN_0008d690(0x18);
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamBranch_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("hitBranch", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193b80);
        mem = FUN_0008d690(0x18);
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamName_19de50<hulkfight::motion::FireGroundShockwaveTrack_19de50>("hitEffect", &hulkfight::motion::FireGroundShockwaveTrack_19de50::FUN_00193b90);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1588), params, 26);
    }
    (*(int*)&DAT_004e158c)++;
}

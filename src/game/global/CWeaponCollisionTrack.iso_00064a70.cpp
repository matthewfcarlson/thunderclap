// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
#include "tree_prelude.h"


// 0x00064a70 FUN_00064a70 (1809 B): equivalent/0x00064a70.cpp [isolated: conflict: ParamBoolBase; ParamFloatConstRangeBase; on include/gen/ and not mergeable]
// sym: _FUN_00064a70
// STATUS: equivalent (tools/equiv.py level 3: 1734 inputs, branch coverage 68/68)
// FUN_00064a70 @ 0x00064a70
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CWeaponCollisionTrack_64a70 {
public:
    void FUN_00061b40();
    void FUN_00061b50();
    void FUN_00061b60();
    void FUN_00061b70();
    void FUN_00061b80();
    void FUN_00061b90();
    void FUN_00061ca0();
    void FUN_00061ba0();
    void FUN_00061bb0();
    void FUN_00012530();
    void FUN_00012540();
    void FUN_00012550();
    void FUN_00062180();
    void FUN_00061bc0();
    void FUN_00061bd0();
    void FUN_00061be0();
    void FUN_00061c10();
    void FUN_00061c40();
    void FUN_00061c50();
    void FUN_00061c60();
    void FUN_00061c90();
    char pad[0xcc];
    bool smallInterrupt;
    char pad_smallInterrupt[3];
    float smallHitReactionTime;
    float smallPushbackDistance;
    float smallPushbackTime;
    float smallHeight;
    float smallStunTime;
    bool largeInterrupt;
    char pad_largeInterrupt[3];
    float largeHitReactionTime;
    float largePushbackDistance;
    float largePushbackTime;
    float largeHeight;
    float largeStunTime;
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
class __declspec(novtable) ParamBoolPtrBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolPtrBase(const char* name) { FUN_00234860(name); }
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
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
class __declspec(novtable) ParamFloatPtrConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatPtrConstRangeBase(const char* name) { FUN_00234960(name); }
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
class ParamBool_64a70 : public ParamBoolBase {
public:
    ParamBool_64a70(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBoolPtr_64a70 : public ParamBoolPtrBase {
public:
    ParamBoolPtr_64a70(const char* name, bool T::*m) : ParamBoolPtrBase(name) { member = m; }
    virtual void v0();
    bool T::*member;
    int unused14;
};
template <class T>
class ParamBranch_64a70 : public ParamBranchBase {
public:
    ParamBranch_64a70(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_64a70 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_64a70(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_64a70 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_64a70(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatPtrConstRange_64a70 : public ParamFloatPtrConstRangeBase {
public:
    ParamFloatPtrConstRange_64a70(const char* name, float T::*m) : ParamFloatPtrConstRangeBase(name) { member = m; }
    virtual void v0();
    float T::*member;
    int unused14;
};
template <class T>
class ParamIntConstRange_64a70 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_64a70(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_64a70 : public ParamNameBase {
public:
    ParamName_64a70(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamString_64a70 : public ParamStringBase {
public:
    ParamString_64a70(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_64a70 : public ParamVectorBase {
public:
    ParamVector_64a70(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};


void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00064a70()
{
    if (DAT_004dc61c == 0) {
        void* params[33];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>("timeBegin", &CWeaponCollisionTrack_64a70::FUN_00061b40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>("timeEnd", &CWeaponCollisionTrack_64a70::FUN_00061b50);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange_64a70<CWeaponCollisionTrack_64a70>("attachmentIndex", &CWeaponCollisionTrack_64a70::FUN_00061b60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>("scale", &CWeaponCollisionTrack_64a70::FUN_00061b70);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamIntConstRange_64a70<CWeaponCollisionTrack_64a70>("smallMaxHitCount", &CWeaponCollisionTrack_64a70::FUN_00061b80);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_64a70<CWeaponCollisionTrack_64a70>("largeMaxHitCount", &CWeaponCollisionTrack_64a70::FUN_00061b90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>("damageReceived", &CWeaponCollisionTrack_64a70::FUN_00061ca0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_64a70<CWeaponCollisionTrack_64a70>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool_64a70<CWeaponCollisionTrack_64a70>("missilePunch", &CWeaponCollisionTrack_64a70::FUN_00061ba0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_64a70<CWeaponCollisionTrack_64a70>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamEnumConstList_64a70<CWeaponCollisionTrack_64a70>("hitTypes", ((const char**)&DAT_00495480), (*(int*)&DAT_003fa110), &CWeaponCollisionTrack_64a70::FUN_00061bb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_64a70<CWeaponCollisionTrack_64a70>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBranch_64a70<CWeaponCollisionTrack_64a70>("receiver", &CWeaponCollisionTrack_64a70::FUN_00012530);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_64a70<CWeaponCollisionTrack_64a70>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBranch_64a70<CWeaponCollisionTrack_64a70>("giver", &CWeaponCollisionTrack_64a70::FUN_00012540);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_64a70<CWeaponCollisionTrack_64a70>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_64a70<CWeaponCollisionTrack_64a70>("flag", &CWeaponCollisionTrack_64a70::FUN_00012550);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_64a70<CWeaponCollisionTrack_64a70>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamString_64a70<CWeaponCollisionTrack_64a70>("sound", &CWeaponCollisionTrack_64a70::FUN_00062180);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>("damage", &CWeaponCollisionTrack_64a70::FUN_00061bc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_64a70<CWeaponCollisionTrack_64a70>("damageMax", &CWeaponCollisionTrack_64a70::FUN_00061bd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_64a70<CWeaponCollisionTrack_64a70>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamVector_64a70<CWeaponCollisionTrack_64a70>("force", &CWeaponCollisionTrack_64a70::FUN_00061be0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_64a70<CWeaponCollisionTrack_64a70>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamVector_64a70<CWeaponCollisionTrack_64a70>("forceMax", &CWeaponCollisionTrack_64a70::FUN_00061c10);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_64a70<CWeaponCollisionTrack_64a70>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamEnumConstList_64a70<CWeaponCollisionTrack_64a70>("direction", ((const char**)&DAT_004954b4), (*(int*)&DAT_003fa118), &CWeaponCollisionTrack_64a70::FUN_00061c40);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamIntConstRange_64a70<CWeaponCollisionTrack_64a70>("interruptPriority", &CWeaponCollisionTrack_64a70::FUN_00061c50);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_64a70<CWeaponCollisionTrack_64a70>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamVector_64a70<CWeaponCollisionTrack_64a70>("hitFreezeTime", &CWeaponCollisionTrack_64a70::FUN_00061c60);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_64a70<CWeaponCollisionTrack_64a70>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamEnumConstList_64a70<CWeaponCollisionTrack_64a70>("location", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &CWeaponCollisionTrack_64a70::FUN_00061c90);
        mem = FUN_0008d690((int)sizeof(fight::ParamBoolPtr_64a70<CWeaponCollisionTrack_64a70>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamBoolPtr_64a70<CWeaponCollisionTrack_64a70>("smallInterrupt", &CWeaponCollisionTrack_64a70::smallInterrupt);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>("smallHitReactionTime", &CWeaponCollisionTrack_64a70::smallHitReactionTime);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>("smallPushbackDistance", &CWeaponCollisionTrack_64a70::smallPushbackDistance);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>("smallPushbackTime", &CWeaponCollisionTrack_64a70::smallPushbackTime);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>("smallHeight", &CWeaponCollisionTrack_64a70::smallHeight);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>("smallStunTime", &CWeaponCollisionTrack_64a70::smallStunTime);
        mem = FUN_0008d690((int)sizeof(fight::ParamBoolPtr_64a70<CWeaponCollisionTrack_64a70>));
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamBoolPtr_64a70<CWeaponCollisionTrack_64a70>("largeInterrupt", &CWeaponCollisionTrack_64a70::largeInterrupt);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>("largeHitReactionTime", &CWeaponCollisionTrack_64a70::largeHitReactionTime);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>("largePushbackDistance", &CWeaponCollisionTrack_64a70::largePushbackDistance);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>("largePushbackTime", &CWeaponCollisionTrack_64a70::largePushbackTime);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>("largeHeight", &CWeaponCollisionTrack_64a70::largeHeight);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>));
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamFloatPtrConstRange_64a70<CWeaponCollisionTrack_64a70>("largeStunTime", &CWeaponCollisionTrack_64a70::largeStunTime);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc618), params, 33);
    }
    DAT_004dc61c++;
}


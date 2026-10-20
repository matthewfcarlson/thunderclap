// STATUS: equivalent (tools/equiv.py level 3: 1734 inputs, branch coverage 68/68)
// FUN_00064a70 @ 0x00064a70
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CWeaponCollisionTrack {
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
    void FUN_00235170(const char* name);
    ParamBranchBase(const char* name) { FUN_00235170(name); }
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
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
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
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBoolPtr : public ParamBoolPtrBase {
public:
    ParamBoolPtr(const char* name, bool T::*m) : ParamBoolPtrBase(name) { member = m; }
    virtual void v0();
    bool T::*member;
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
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatPtrConstRange : public ParamFloatPtrConstRangeBase {
public:
    ParamFloatPtrConstRange(const char* name, float T::*m) : ParamFloatPtrConstRangeBase(name) { member = m; }
    virtual void v0();
    float T::*member;
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
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
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
}

struct ParamRegistry {
};


void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00064a70()
{
    if (DAT_004dc61c == 0) {
        void* params[33];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<CWeaponCollisionTrack>("timeBegin", &CWeaponCollisionTrack::FUN_00061b40);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<CWeaponCollisionTrack>("timeEnd", &CWeaponCollisionTrack::FUN_00061b50);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange<CWeaponCollisionTrack>("attachmentIndex", &CWeaponCollisionTrack::FUN_00061b60);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<CWeaponCollisionTrack>("scale", &CWeaponCollisionTrack::FUN_00061b70);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamIntConstRange<CWeaponCollisionTrack>("smallMaxHitCount", &CWeaponCollisionTrack::FUN_00061b80);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange<CWeaponCollisionTrack>("largeMaxHitCount", &CWeaponCollisionTrack::FUN_00061b90);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<CWeaponCollisionTrack>("damageReceived", &CWeaponCollisionTrack::FUN_00061ca0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool<CWeaponCollisionTrack>("missilePunch", &CWeaponCollisionTrack::FUN_00061ba0);
        mem = FUN_0008d690(0x20);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamEnumConstList<CWeaponCollisionTrack>("hitTypes", ((const char**)&DAT_00495480), (*(int*)&DAT_003fa110), &CWeaponCollisionTrack::FUN_00061bb0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBranch<CWeaponCollisionTrack>("receiver", &CWeaponCollisionTrack::FUN_00012530);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBranch<CWeaponCollisionTrack>("giver", &CWeaponCollisionTrack::FUN_00012540);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName<CWeaponCollisionTrack>("flag", &CWeaponCollisionTrack::FUN_00012550);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamString<CWeaponCollisionTrack>("sound", &CWeaponCollisionTrack::FUN_00062180);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<CWeaponCollisionTrack>("damage", &CWeaponCollisionTrack::FUN_00061bc0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange<CWeaponCollisionTrack>("damageMax", &CWeaponCollisionTrack::FUN_00061bd0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamVector<CWeaponCollisionTrack>("force", &CWeaponCollisionTrack::FUN_00061be0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamVector<CWeaponCollisionTrack>("forceMax", &CWeaponCollisionTrack::FUN_00061c10);
        mem = FUN_0008d690(0x20);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamEnumConstList<CWeaponCollisionTrack>("direction", ((const char**)&DAT_004954b4), (*(int*)&DAT_003fa118), &CWeaponCollisionTrack::FUN_00061c40);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamIntConstRange<CWeaponCollisionTrack>("interruptPriority", &CWeaponCollisionTrack::FUN_00061c50);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamVector<CWeaponCollisionTrack>("hitFreezeTime", &CWeaponCollisionTrack::FUN_00061c60);
        mem = FUN_0008d690(0x20);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamEnumConstList<CWeaponCollisionTrack>("location", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), &CWeaponCollisionTrack::FUN_00061c90);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamBoolPtr<CWeaponCollisionTrack>("smallInterrupt", &CWeaponCollisionTrack::smallInterrupt);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>("smallHitReactionTime", &CWeaponCollisionTrack::smallHitReactionTime);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>("smallPushbackDistance", &CWeaponCollisionTrack::smallPushbackDistance);
        mem = FUN_0008d690(0x18);
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>("smallPushbackTime", &CWeaponCollisionTrack::smallPushbackTime);
        mem = FUN_0008d690(0x18);
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>("smallHeight", &CWeaponCollisionTrack::smallHeight);
        mem = FUN_0008d690(0x18);
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>("smallStunTime", &CWeaponCollisionTrack::smallStunTime);
        mem = FUN_0008d690(0x18);
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamBoolPtr<CWeaponCollisionTrack>("largeInterrupt", &CWeaponCollisionTrack::largeInterrupt);
        mem = FUN_0008d690(0x18);
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>("largeHitReactionTime", &CWeaponCollisionTrack::largeHitReactionTime);
        mem = FUN_0008d690(0x18);
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>("largePushbackDistance", &CWeaponCollisionTrack::largePushbackDistance);
        mem = FUN_0008d690(0x18);
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>("largePushbackTime", &CWeaponCollisionTrack::largePushbackTime);
        mem = FUN_0008d690(0x18);
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>("largeHeight", &CWeaponCollisionTrack::largeHeight);
        mem = FUN_0008d690(0x18);
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamFloatPtrConstRange<CWeaponCollisionTrack>("largeStunTime", &CWeaponCollisionTrack::largeStunTime);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc618), params, 33);
    }
    DAT_004dc61c++;
}

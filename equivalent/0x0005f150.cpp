// STATUS: equivalent (tools/equiv.py level 3: 948 inputs, branch coverage 82/82)
// FUN_0005f150 @ 0x0005f150
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CCollisionTrack {
public:
    void FUN_0005d4b0();
    void FUN_0005d4c0();
    void FUN_0005d4d0();
    void FUN_0005d4e0();
    void FUN_0005d500();
    void FUN_0005d510();
    void FUN_0005d520();
    void FUN_0005d530();
    void FUN_0005d540();
    void FUN_0005d550();
    void FUN_0005d560();
    void FUN_0005d570();
    void FUN_0005d580();
    void FUN_0005d590();
    void FUN_0005d5a0();
    void FUN_00012ee0();
    void FUN_00012ef0();
    void FUN_00012f00();
    void FUN_00012f10();
    void FUN_0005dad0();
    void FUN_0005d5b0();
    void FUN_0005d5c0();
    void FUN_0005d5d0();
    void FUN_0005d600();
    void FUN_0005d630();
    void FUN_0005d640();
    void FUN_0005d650();
    void FUN_0005d680();
    char pad[0xf0];
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
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
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
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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
extern ParamRegistry DAT_004dc5d0;
extern int DAT_004dc5d4;

extern const char* DAT_00495470[1];
extern const char* DAT_00495480[1];
extern const char* DAT_0049548c[1];
extern const char* DAT_004954b4[1];
extern const char* DAT_0048f6cc[1];
extern int DAT_003f5ed0;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0005f150()
{
    if (DAT_004dc5d4 == 0) {
        void* params[40];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<CCollisionTrack>("timeBegin", &CCollisionTrack::FUN_0005d4b0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<CCollisionTrack>("timeEnd", &CCollisionTrack::FUN_0005d4c0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList<CCollisionTrack>("joint", &CCollisionTrack::FUN_0005d4d0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector<CCollisionTrack>("offset", &CCollisionTrack::FUN_0005d4e0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<CCollisionTrack>("radius", &CCollisionTrack::FUN_0005d500);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange<CCollisionTrack>("smallMaxHitCount", &CCollisionTrack::FUN_0005d510);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamIntConstRange<CCollisionTrack>("largeMaxHitCount", &CCollisionTrack::FUN_0005d520);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool<CCollisionTrack>("projectile", &CCollisionTrack::FUN_0005d530);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool<CCollisionTrack>("missilePunch", &CCollisionTrack::FUN_0005d540);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool<CCollisionTrack>("bumper", &CCollisionTrack::FUN_0005d550);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool<CCollisionTrack>("devastator", &CCollisionTrack::FUN_0005d560);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamBool<CCollisionTrack>("overrideArmor", &CCollisionTrack::FUN_0005d570);
        mem = FUN_0008d690(0x20);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamEnumConstList<CCollisionTrack>("steelFists", DAT_00495470, 4, &CCollisionTrack::FUN_0005d580);
        mem = FUN_0008d690(0x20);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamEnumConstList<CCollisionTrack>("hitTypes", DAT_00495480, 3, &CCollisionTrack::FUN_0005d590);
        mem = FUN_0008d690(0x20);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamEnumConstList<CCollisionTrack>("crusher", DAT_0049548c, 10, &CCollisionTrack::FUN_0005d5a0);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamBranch<CCollisionTrack>("receiver", &CCollisionTrack::FUN_00012ee0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBranch<CCollisionTrack>("giver", &CCollisionTrack::FUN_00012ef0);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamName<CCollisionTrack>("flag", &CCollisionTrack::FUN_00012f00);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamName<CCollisionTrack>("entityOffset", &CCollisionTrack::FUN_00012f10);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamString<CCollisionTrack>("sound", &CCollisionTrack::FUN_0005dad0);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange<CCollisionTrack>("damage", &CCollisionTrack::FUN_0005d5b0);
        mem = FUN_0008d690(0x18);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange<CCollisionTrack>("damageMax", &CCollisionTrack::FUN_0005d5c0);
        mem = FUN_0008d690(0x18);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamVector<CCollisionTrack>("force", &CCollisionTrack::FUN_0005d5d0);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamVector<CCollisionTrack>("forceMax", &CCollisionTrack::FUN_0005d600);
        mem = FUN_0008d690(0x20);
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamEnumConstList<CCollisionTrack>("direction", DAT_004954b4, 3, &CCollisionTrack::FUN_0005d630);
        mem = FUN_0008d690(0x18);
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamIntConstRange<CCollisionTrack>("interruptPriority", &CCollisionTrack::FUN_0005d640);
        mem = FUN_0008d690(0x18);
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamVector<CCollisionTrack>("hitFreezeTime", &CCollisionTrack::FUN_0005d650);
        mem = FUN_0008d690(0x20);
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamEnumConstList<CCollisionTrack>("location", DAT_0048f6cc, DAT_003f5ed0, &CCollisionTrack::FUN_0005d680);
        mem = FUN_0008d690(0x18);
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamBoolPtr<CCollisionTrack>("smallInterrupt", &CCollisionTrack::smallInterrupt);
        mem = FUN_0008d690(0x18);
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamFloatPtrConstRange<CCollisionTrack>("smallHitReactionTime", &CCollisionTrack::smallHitReactionTime);
        mem = FUN_0008d690(0x18);
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamFloatPtrConstRange<CCollisionTrack>("smallPushbackDistance", &CCollisionTrack::smallPushbackDistance);
        mem = FUN_0008d690(0x18);
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatPtrConstRange<CCollisionTrack>("smallPushbackTime", &CCollisionTrack::smallPushbackTime);
        mem = FUN_0008d690(0x18);
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamFloatPtrConstRange<CCollisionTrack>("smallHeight", &CCollisionTrack::smallHeight);
        mem = FUN_0008d690(0x18);
        params[33] = 0;
        if (mem)
            params[33] = new (mem) fight::ParamFloatPtrConstRange<CCollisionTrack>("smallStunTime", &CCollisionTrack::smallStunTime);
        mem = FUN_0008d690(0x18);
        params[34] = 0;
        if (mem)
            params[34] = new (mem) fight::ParamBoolPtr<CCollisionTrack>("largeInterrupt", &CCollisionTrack::largeInterrupt);
        mem = FUN_0008d690(0x18);
        params[35] = 0;
        if (mem)
            params[35] = new (mem) fight::ParamFloatPtrConstRange<CCollisionTrack>("largeHitReactionTime", &CCollisionTrack::largeHitReactionTime);
        mem = FUN_0008d690(0x18);
        params[36] = 0;
        if (mem)
            params[36] = new (mem) fight::ParamFloatPtrConstRange<CCollisionTrack>("largePushbackDistance", &CCollisionTrack::largePushbackDistance);
        mem = FUN_0008d690(0x18);
        params[37] = 0;
        if (mem)
            params[37] = new (mem) fight::ParamFloatPtrConstRange<CCollisionTrack>("largePushbackTime", &CCollisionTrack::largePushbackTime);
        mem = FUN_0008d690(0x18);
        params[38] = 0;
        if (mem)
            params[38] = new (mem) fight::ParamFloatPtrConstRange<CCollisionTrack>("largeHeight", &CCollisionTrack::largeHeight);
        mem = FUN_0008d690(0x18);
        params[39] = 0;
        if (mem)
            params[39] = new (mem) fight::ParamFloatPtrConstRange<CCollisionTrack>("largeStunTime", &CCollisionTrack::largeStunTime);
        FUN_002347b0(&DAT_004dc5d0, params, 40);
    }
    DAT_004dc5d4++;
}

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005d850..0x0005fa10 (kind game, layer game, confidence high), dominant class CCollisionTrack
#include "tree_prelude.h"


// 0x0005f150 FUN_0005f150 (2229 B): equivalent/0x0005f150.cpp [isolated: conflict: ParamBoolBase; ParamFloatConstRangeBase; on include/gen/ and not mergeable]
// sym: _FUN_0005f150 @bff235ed4c1e @wa0537c545126
// STATUS: equivalent (tools/equiv.py level 3: 948 inputs, branch coverage 82/82)
// FUN_0005f150 @ 0x0005f150
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

inline void* operator new(size_t, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class CCollisionTrack_5f150 {
public:
    bool FUN_0005d4b0(int); /* (unb4) as defined; address taken only */
    char FUN_0005d4c0(int); /* (unb4) as defined; address taken only */
    void FUN_0005d4d0();
    char FUN_0005d4e0(void*); /* (unb4) as defined; address taken only */
    bool FUN_0005d500(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d510(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d520(int); /* (unb4) as defined; address taken only */
    char FUN_0005d530(char); /* (unb4) as defined; address taken only */
    char FUN_0005d540(char); /* (unb4) as defined; address taken only */
    char FUN_0005d550(char); /* (unb4) as defined; address taken only */
    char FUN_0005d560(char); /* (unb4) as defined; address taken only */
    char FUN_0005d570(char); /* (unb4) as defined; address taken only */
    bool FUN_0005d580(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d590(int); /* (unb4) as defined; address taken only */
    char FUN_0005d5a0(int); /* (unb4) as defined; address taken only */
    void FUN_00012ee0();
    void FUN_00012ef0();
    void FUN_00012f00();
    void FUN_00012f10();
    char FUN_0005dad0(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d5b0(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d5c0(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d5d0(void*); /* (unb4) as defined; address taken only */
    bool FUN_0005d600(void*); /* (unb4) as defined; address taken only */
    char FUN_0005d630(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d640(int); /* (unb4) as defined; address taken only */
    bool FUN_0005d650(void*); /* (unb4) as defined; address taken only */
    char FUN_0005d680(int); /* (unb4) as defined; address taken only */
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
class ParamBool_5f150 : public ParamBoolBase {
public:
    ParamBool_5f150(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamBoolPtr_5f150 : public ParamBoolPtrBase {
public:
    ParamBoolPtr_5f150(const char* name, bool T::*m) : ParamBoolPtrBase(name) { member = m; }
    virtual void v0();
    bool T::*member;
    int unused14;
};
template <class T>
class ParamBranch_5f150 : public ParamBranchBase {
public:
    ParamBranch_5f150(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList_5f150 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_5f150(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange_5f150 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5f150(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatPtrConstRange_5f150 : public ParamFloatPtrConstRangeBase {
public:
    ParamFloatPtrConstRange_5f150(const char* name, float T::*m) : ParamFloatPtrConstRangeBase(name) { member = m; }
    virtual void v0();
    float T::*member;
    int unused14;
};
template <class T>
class ParamIntConstRange_5f150 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_5f150(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamName_5f150 : public ParamNameBase {
public:
    ParamName_5f150(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamNameConstList_5f150 : public ParamNameConstListBase {
public:
    ParamNameConstList_5f150(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamString_5f150 : public ParamStringBase {
public:
    ParamString_5f150(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector_5f150 : public ParamVectorBase {
public:
    ParamVector_5f150(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};


extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0005f150()
{
    if (DAT_004dc5d4 == 0) {
        void* params[40];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5f150<CCollisionTrack_5f150>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_5f150<CCollisionTrack_5f150>("timeBegin", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d4b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5f150<CCollisionTrack_5f150>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_5f150<CCollisionTrack_5f150>("timeEnd", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d4c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_5f150<CCollisionTrack_5f150>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_5f150<CCollisionTrack_5f150>("joint", &CCollisionTrack_5f150::FUN_0005d4d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_5f150<CCollisionTrack_5f150>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector_5f150<CCollisionTrack_5f150>("offset", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d4e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5f150<CCollisionTrack_5f150>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_5f150<CCollisionTrack_5f150>("radius", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d500);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_5f150<CCollisionTrack_5f150>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamIntConstRange_5f150<CCollisionTrack_5f150>("smallMaxHitCount", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d510);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_5f150<CCollisionTrack_5f150>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamIntConstRange_5f150<CCollisionTrack_5f150>("largeMaxHitCount", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d520);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_5f150<CCollisionTrack_5f150>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool_5f150<CCollisionTrack_5f150>("projectile", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d530);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_5f150<CCollisionTrack_5f150>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_5f150<CCollisionTrack_5f150>("missilePunch", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d540);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_5f150<CCollisionTrack_5f150>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_5f150<CCollisionTrack_5f150>("bumper", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d550);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_5f150<CCollisionTrack_5f150>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool_5f150<CCollisionTrack_5f150>("devastator", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d560);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_5f150<CCollisionTrack_5f150>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamBool_5f150<CCollisionTrack_5f150>("overrideArmor", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d570);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_5f150<CCollisionTrack_5f150>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamEnumConstList_5f150<CCollisionTrack_5f150>("steelFists", ((const char**)&DAT_00495470), 4, (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d580);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_5f150<CCollisionTrack_5f150>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamEnumConstList_5f150<CCollisionTrack_5f150>("hitTypes", ((const char**)&DAT_00495480), 3, (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d590);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_5f150<CCollisionTrack_5f150>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamEnumConstList_5f150<CCollisionTrack_5f150>("crusher", ((const char**)&DAT_0049548c), 10, (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d5a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_5f150<CCollisionTrack_5f150>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamBranch_5f150<CCollisionTrack_5f150>("receiver", &CCollisionTrack_5f150::FUN_00012ee0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBranch_5f150<CCollisionTrack_5f150>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamBranch_5f150<CCollisionTrack_5f150>("giver", &CCollisionTrack_5f150::FUN_00012ef0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5f150<CCollisionTrack_5f150>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamName_5f150<CCollisionTrack_5f150>("flag", &CCollisionTrack_5f150::FUN_00012f00);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_5f150<CCollisionTrack_5f150>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamName_5f150<CCollisionTrack_5f150>("entityOffset", &CCollisionTrack_5f150::FUN_00012f10);
        mem = FUN_0008d690((int)sizeof(fight::ParamString_5f150<CCollisionTrack_5f150>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamString_5f150<CCollisionTrack_5f150>("sound", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005dad0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5f150<CCollisionTrack_5f150>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_5f150<CCollisionTrack_5f150>("damage", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d5b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5f150<CCollisionTrack_5f150>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamFloatConstRange_5f150<CCollisionTrack_5f150>("damageMax", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d5c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_5f150<CCollisionTrack_5f150>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamVector_5f150<CCollisionTrack_5f150>("force", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d5d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_5f150<CCollisionTrack_5f150>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamVector_5f150<CCollisionTrack_5f150>("forceMax", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d600);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_5f150<CCollisionTrack_5f150>));
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamEnumConstList_5f150<CCollisionTrack_5f150>("direction", ((const char**)&DAT_004954b4), 3, (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d630);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_5f150<CCollisionTrack_5f150>));
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamIntConstRange_5f150<CCollisionTrack_5f150>("interruptPriority", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d640);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_5f150<CCollisionTrack_5f150>));
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamVector_5f150<CCollisionTrack_5f150>("hitFreezeTime", (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d650);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_5f150<CCollisionTrack_5f150>));
        params[27] = 0;
        if (mem)
            params[27] = new (mem) fight::ParamEnumConstList_5f150<CCollisionTrack_5f150>("location", ((const char**)&DAT_0048f6cc), (*(int*)&DAT_003f5ed0), (void (CCollisionTrack_5f150::*)())&CCollisionTrack_5f150::FUN_0005d680);
        mem = FUN_0008d690((int)sizeof(fight::ParamBoolPtr_5f150<CCollisionTrack_5f150>));
        params[28] = 0;
        if (mem)
            params[28] = new (mem) fight::ParamBoolPtr_5f150<CCollisionTrack_5f150>("smallInterrupt", &CCollisionTrack_5f150::smallInterrupt);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>));
        params[29] = 0;
        if (mem)
            params[29] = new (mem) fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>("smallHitReactionTime", &CCollisionTrack_5f150::smallHitReactionTime);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>));
        params[30] = 0;
        if (mem)
            params[30] = new (mem) fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>("smallPushbackDistance", &CCollisionTrack_5f150::smallPushbackDistance);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>));
        params[31] = 0;
        if (mem)
            params[31] = new (mem) fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>("smallPushbackTime", &CCollisionTrack_5f150::smallPushbackTime);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>));
        params[32] = 0;
        if (mem)
            params[32] = new (mem) fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>("smallHeight", &CCollisionTrack_5f150::smallHeight);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>));
        params[33] = 0;
        if (mem)
            params[33] = new (mem) fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>("smallStunTime", &CCollisionTrack_5f150::smallStunTime);
        mem = FUN_0008d690((int)sizeof(fight::ParamBoolPtr_5f150<CCollisionTrack_5f150>));
        params[34] = 0;
        if (mem)
            params[34] = new (mem) fight::ParamBoolPtr_5f150<CCollisionTrack_5f150>("largeInterrupt", &CCollisionTrack_5f150::largeInterrupt);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>));
        params[35] = 0;
        if (mem)
            params[35] = new (mem) fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>("largeHitReactionTime", &CCollisionTrack_5f150::largeHitReactionTime);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>));
        params[36] = 0;
        if (mem)
            params[36] = new (mem) fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>("largePushbackDistance", &CCollisionTrack_5f150::largePushbackDistance);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>));
        params[37] = 0;
        if (mem)
            params[37] = new (mem) fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>("largePushbackTime", &CCollisionTrack_5f150::largePushbackTime);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>));
        params[38] = 0;
        if (mem)
            params[38] = new (mem) fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>("largeHeight", &CCollisionTrack_5f150::largeHeight);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>));
        params[39] = 0;
        if (mem)
            params[39] = new (mem) fight::ParamFloatPtrConstRange_5f150<CCollisionTrack_5f150>("largeStunTime", &CCollisionTrack_5f150::largeStunTime);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5d0), params, 40);
    }
    DAT_004dc5d4++;
}


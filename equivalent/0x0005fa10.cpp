// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 18/18)
// FUN_0005fa10 @ 0x0005fa10
#include "compat/ptr.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class COpportunityBallTrack {
public:
    void FUN_0005d690();
    void FUN_0005d6a0();
    void FUN_0005d6b0();
    void FUN_0005d6c0();
    void FUN_0005d6e0();
    void FUN_0005d6f0();
    void FUN_00013050();
    void FUN_00013060();
};

class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00235170(const char* name);
    ParamBranchBase(const char* name) { FUN_00235170(name); }
};
template <class T>
class ParamBranch : public ParamBranchBase {
public:
    ParamBranch(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0005fa10()
{
    if (DAT_004dc5dc == 0) {
        void* params[8];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<COpportunityBallTrack>("timeBegin", &COpportunityBallTrack::FUN_0005d690);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<COpportunityBallTrack>("timeEnd", &COpportunityBallTrack::FUN_0005d6a0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamNameConstList<COpportunityBallTrack>("joint", &COpportunityBallTrack::FUN_0005d6b0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<COpportunityBallTrack>("offset", &COpportunityBallTrack::FUN_0005d6c0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<COpportunityBallTrack>("radius", &COpportunityBallTrack::FUN_0005d6e0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamIntConstRange<COpportunityBallTrack>("maxHitCount", &COpportunityBallTrack::FUN_0005d6f0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamBranch<COpportunityBallTrack>("receiver", &COpportunityBallTrack::FUN_00013050);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamBranch<COpportunityBallTrack>("giver", &COpportunityBallTrack::FUN_00013060);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5d8), params, 8);
    }
    DAT_004dc5dc++;
}

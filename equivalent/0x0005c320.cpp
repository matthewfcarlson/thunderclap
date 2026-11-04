// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_0005c320 @ 0x0005c320
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

class CGrappleOpportunityTrack_5c320 {
public:
    void FUN_0005a2d0();
    void FUN_0005a2e0();
    void FUN_0005a2f0();
    void FUN_0005a300();
    void FUN_0005a310();
    void FUN_0005a320();
};

class __declspec(novtable) ParamBranchBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBranchBase(const char* name) { ((fight::ParamValueBranch *)this)->FUN_00235170(name); }
};
template <class T>
class ParamBranch : public ParamBranchBase {
public:
    ParamBranch(const char* name, void (T::*s)()) : ParamBranchBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamConditionGroupBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00235220(const char* name);
    ParamConditionGroupBase(const char* name) { FUN_00235220(name); }
};
template <class T>
class ParamConditionGroup : public ParamConditionGroupBase {
public:
    ParamConditionGroup(const char* name, void (T::*s)()) : ParamConditionGroupBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
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

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0005c320()
{
    if (DAT_004dc5b4 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CGrappleOpportunityTrack_5c320>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CGrappleOpportunityTrack_5c320>("timeBegin", &CGrappleOpportunityTrack_5c320::FUN_0005a2d0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CGrappleOpportunityTrack_5c320>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CGrappleOpportunityTrack_5c320>("timeEnd", &CGrappleOpportunityTrack_5c320::FUN_0005a2e0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CGrappleOpportunityTrack_5c320>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<CGrappleOpportunityTrack_5c320>("timeHook", &CGrappleOpportunityTrack_5c320::FUN_0005a2f0);
        mem = FUN_0008d690((int)sizeof(ParamBranch<CGrappleOpportunityTrack_5c320>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBranch<CGrappleOpportunityTrack_5c320>("branch", &CGrappleOpportunityTrack_5c320::FUN_0005a300);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<CGrappleOpportunityTrack_5c320>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamIntConstRange<CGrappleOpportunityTrack_5c320>("priority", &CGrappleOpportunityTrack_5c320::FUN_0005a310);
        mem = FUN_0008d690((int)sizeof(ParamConditionGroup<CGrappleOpportunityTrack_5c320>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamConditionGroup<CGrappleOpportunityTrack_5c320>("conditionGroup", &CGrappleOpportunityTrack_5c320::FUN_0005a320);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5b0), params, 6);
    }
    DAT_004dc5b4++;
}

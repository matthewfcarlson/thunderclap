// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_0005c320 @ 0x0005c320
#include "compat/ptr.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class CGrappleOpportunityTrack {
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

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0005c320()
{
    if (DAT_004dc5b4 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CGrappleOpportunityTrack>("timeBegin", &CGrappleOpportunityTrack::FUN_0005a2d0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CGrappleOpportunityTrack>("timeEnd", &CGrappleOpportunityTrack::FUN_0005a2e0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<CGrappleOpportunityTrack>("timeHook", &CGrappleOpportunityTrack::FUN_0005a2f0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBranch<CGrappleOpportunityTrack>("branch", &CGrappleOpportunityTrack::FUN_0005a300);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamIntConstRange<CGrappleOpportunityTrack>("priority", &CGrappleOpportunityTrack::FUN_0005a310);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamConditionGroup<CGrappleOpportunityTrack>("conditionGroup", &CGrappleOpportunityTrack::FUN_0005a320);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5b0), params, 6);
    }
    DAT_004dc5b4++;
}

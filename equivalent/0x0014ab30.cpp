// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_0014ab30 @ 0x0014ab30
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class GrappleExecuteTrack {
public:
    void FUN_00147030();
    void FUN_00147040();
    void FUN_00147050();
    void FUN_00147070();
    void FUN_00147080();
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

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0014ab30()
{
    if (DAT_004e1018 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<GrappleExecuteTrack>("timeBegin", &GrappleExecuteTrack::FUN_00147030);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<GrappleExecuteTrack>("timeEnd", &GrappleExecuteTrack::FUN_00147040);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBranch<GrappleExecuteTrack>("branch", &GrappleExecuteTrack::FUN_00147050);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<GrappleExecuteTrack>("priority", &GrappleExecuteTrack::FUN_00147070);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamConditionGroup<GrappleExecuteTrack>("conditionGroup", &GrappleExecuteTrack::FUN_00147080);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1014), params, 5);
    }
    DAT_004e1018++;
}

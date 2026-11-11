// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00236e00..0x00237b70 (kind game, layer engine, confidence high), dominant class fight::OpportunityTrack
#include "tree_prelude.h"
#include "decls/data/engine/fight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6d21d72 {
#define TREE_TU_END }
namespace fn_f6d21d72 {} using namespace fn_f6d21d72;
#include "engine/fight.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f6d21d72 {
extern "C" void* FUN_0008d690(unsigned int size);
class OpportunityTrack {
public:
    void FUN_00237230();
    void FUN_00237240();
    void FUN_00237250();
    void FUN_00237260();
    void FUN_00237270();
    void FUN_00237280();
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
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);


// 0x00237870 FUN_00237870 (358 B): equivalent/0x00237870.cpp
// sym: _FUN_00237870
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_00237870 @ 0x00237870
extern "C" void FUN_00237870()
{
    if (DAT_004e5bf8 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<OpportunityTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<OpportunityTrack>("timeBegin", &OpportunityTrack::FUN_00237230);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<OpportunityTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<OpportunityTrack>("timeEnd", &OpportunityTrack::FUN_00237240);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<OpportunityTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<OpportunityTrack>("timeHook", &OpportunityTrack::FUN_00237250);
        mem = FUN_0008d690((int)sizeof(ParamBranch<OpportunityTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBranch<OpportunityTrack>("branch", &OpportunityTrack::FUN_00237260);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<OpportunityTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamIntConstRange<OpportunityTrack>("priority", &OpportunityTrack::FUN_00237270);
        mem = FUN_0008d690((int)sizeof(ParamConditionGroup<OpportunityTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamConditionGroup<OpportunityTrack>("conditionGroup", &OpportunityTrack::FUN_00237280);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5bf4), params, 6);
    }
    DAT_004e5bf8++;
}

} // namespace fn_f6d21d72

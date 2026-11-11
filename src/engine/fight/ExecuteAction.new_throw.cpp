// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002393a0..0x00239d50 (kind game, layer engine, confidence high), dominant class fight::ExecuteAction
#include "tree_prelude.h"
#include "decls/data/engine/fight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f8699fb8 {
#define TREE_TU_END }
namespace fn_f8699fb8 {} using namespace fn_f8699fb8;
#include "engine/fight.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f8699fb8 {
extern "C" void* FUN_0008d690(unsigned int size);
class ExecuteTrack {
public:
    void FUN_002393a0();
    void FUN_002393b0();
    void FUN_002393c0();
    void FUN_002393e0();
    void FUN_002393f0();
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
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);


// 0x00239a90 FUN_00239a90 (307 B): equivalent/0x00239a90.cpp
// sym: _FUN_00239a90 @142827ab5a04 @w07ca77b76e07
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 12/12)
// FUN_00239a90 @ 0x00239a90
extern "C" void FUN_00239a90()
{
    if (DAT_004e5c3c == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ExecuteTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<ExecuteTrack>("timeBegin", &ExecuteTrack::FUN_002393a0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ExecuteTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<ExecuteTrack>("timeEnd", &ExecuteTrack::FUN_002393b0);
        mem = FUN_0008d690((int)sizeof(ParamBranch<ExecuteTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBranch<ExecuteTrack>("branch", &ExecuteTrack::FUN_002393c0);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<ExecuteTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<ExecuteTrack>("priority", &ExecuteTrack::FUN_002393e0);
        mem = FUN_0008d690((int)sizeof(ParamConditionGroup<ExecuteTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamConditionGroup<ExecuteTrack>("conditionGroup", &ExecuteTrack::FUN_002393f0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c38), params, 5);
    }
    DAT_004e5c3c++;
}

} // namespace fn_f8699fb8

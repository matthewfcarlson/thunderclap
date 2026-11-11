// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a740..0x0005c6b0 (kind game, layer game, confidence high), dominant class CGrappleOpportunityTrack
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ffaff42e {
#define TREE_TU_END }
namespace fn_ffaff42e {} using namespace fn_ffaff42e;
#include "game/global.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_ffaff42e {
extern "C" void* FUN_0008d690(unsigned int size);
class CGrappleDetachTrack_5c280 {
public:
    void FUN_0005a2b0();
    void FUN_0005a2c0();
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_ffaff42e
namespace fight {
template <class T>
class ParamFloatConstRange_5c280 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_5c280(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_ffaff42e {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
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
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};


// 0x0005c280 FUN_0005c280 (158 B): equivalent/0x0005c280.cpp
// sym: _FUN_0005c280
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_0005c280 @ 0x0005c280
extern "C" void FUN_0005c280()
{
    if (DAT_004dc5ac == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5c280<::CGrappleDetachTrack_5c280>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_5c280<::CGrappleDetachTrack_5c280>("timeBegin", &::CGrappleDetachTrack_5c280::FUN_0005a2b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_5c280<::CGrappleDetachTrack_5c280>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_5c280<::CGrappleDetachTrack_5c280>("rootBlendOutTime", &::CGrappleDetachTrack_5c280::FUN_0005a2c0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5a8), params, 2);
    }
    DAT_004dc5ac++;
}


// 0x0005c320 FUN_0005c320 (358 B): equivalent/0x0005c320.cpp
// sym: _FUN_0005c320
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_0005c320 @ 0x0005c320
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

} // namespace fn_ffaff42e

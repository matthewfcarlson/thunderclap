// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023c8a0..0x0023cb40 (kind game, layer engine, confidence high), dominant class fight::SubConditionGroupCondition
#include "tree_prelude.h"
#include "decls/data/engine/fight.h"
#define TREE_TU_BEGIN namespace fn_f27352bf {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f27352bf {} using namespace fn_f27352bf;
#include "engine/fight.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f27352bf {
extern "C" void* FUN_0008d690(unsigned int size);
namespace fight {
class SubConditionGroupCondition {
public:
    void FUN_0023c8a0();
};
}
namespace fight {
template <class T>
class ParamConditionGroup : public ParamConditionGroupBase {
public:
    ParamConditionGroup(const char* name, void (T::*s)()) : ParamConditionGroupBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);


// 0x0023c9f0 FUN_0023c9f0 (95 B): equivalent/0x0023c9f0.cpp
// sym: _FUN_0023c9f0 @556978b3e643 @w65b1721d8978
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_0023c9f0 @ 0x0023c9f0
extern "C" void FUN_0023c9f0()
{
    if (DAT_004e5c48 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamConditionGroup<fight::SubConditionGroupCondition>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamConditionGroup<fight::SubConditionGroupCondition>("conditionGroup", &fight::SubConditionGroupCondition::FUN_0023c8a0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c44), params, 1);
    }
    DAT_004e5c48++;
}

} // namespace fn_f27352bf

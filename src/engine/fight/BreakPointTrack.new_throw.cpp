// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023f0d0..0x0023f670 (kind game, layer engine, confidence high), dominant class fight::BreakPointTrack
#include "tree_prelude.h"
#include "decls/data/engine/fight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f19c4fc3 {
#define TREE_TU_END }
namespace fn_f19c4fc3 {} using namespace fn_f19c4fc3;
#include "engine/fight.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f19c4fc3 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f19c4fc3
namespace fight {
class BreakPointTrack_23f3a0 {
public:
    void FUN_0023f0d0();
    void FUN_0023f0e0();
};
}
namespace fn_f19c4fc3 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f19c4fc3
namespace fight {
template <class T>
class ParamConditionGroup_23f3a0 : public ParamConditionGroupBase {
public:
    ParamConditionGroup_23f3a0(const char* name, void (T::*s)()) : ParamConditionGroupBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_23f3a0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_23f3a0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f19c4fc3 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);


// 0x0023f3a0 FUN_0023f3a0 (158 B): equivalent/0x0023f3a0.cpp
// sym: _FUN_0023f3a0 @275692dbdeaf @w11ec09501970
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0023f3a0 @ 0x0023f3a0
extern "C" void FUN_0023f3a0()
{
    if (DAT_004e5c8c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_23f3a0<fight::BreakPointTrack_23f3a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_23f3a0<fight::BreakPointTrack_23f3a0>("timeBegin", &fight::BreakPointTrack_23f3a0::FUN_0023f0d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamConditionGroup_23f3a0<fight::BreakPointTrack_23f3a0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamConditionGroup_23f3a0<fight::BreakPointTrack_23f3a0>("conditionGroup", &fight::BreakPointTrack_23f3a0::FUN_0023f0e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e5c88), params, 2);
    }
    DAT_004e5c8c++;
}

} // namespace fn_f19c4fc3
